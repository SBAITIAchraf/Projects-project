#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Functions.h"

// The make file is set for windows system
int main(int argc, char **argv)
{
        if (argc<2)
        {
            fprintf(stderr ,"No input was fed to the programm!");
            return 1;
        }
    FILE *input = fopen(argv[1], "r");
        if (input == NULL)
        {
            fprintf(stderr, "File not found!");
            return 1;
        }
            //Read the first line
            int c, p;
            fscanf(input, "%d %d", &c, &p); //get the first line

    Nd *srch_map = NULL;


    Contributer *contributers = (Contributer *) malloc(c * sizeof(Contributer));
    Contributer **contributers_ptr = (Contributer **) malloc(c * sizeof(Contributer *));
    for (int i = 0; i<c; i++)
    {
        contributers_ptr[i] = (contributers+i);
    }
    setContributers(input ,c, &srch_map, contributers);
    Project *projects = getProjects(input ,p);
    int best_excecuted_projects = 0;
    int maxscore = 0;
    assignement *best_assigned_pro=(assignement*)malloc(p*sizeof(assignement));
    for (int i = 0; i<8; i++)
    {
        int score = 0;
        int excecuted_projects = 0;
        assignement *assigned_pro=(assignement*)malloc(p*sizeof(assignement));
        sort_projs(projects, p, i);
        arrayse undone = greedy_approach(p,c, &score, &excecuted_projects,assigned_pro, projects, srch_map, contributers_ptr);
        if (undone.len != 0)
        {
            int start_len;
            do{
                start_len = undone.len;
                undone = greedy_approach(undone.len,c, &score, &excecuted_projects,assigned_pro, undone.arr, srch_map, contributers_ptr);
            }while (start_len != undone.len);
        }
        printf("score: %d\n", score);
        if (score >= maxscore)
        {    
            maxscore = score;
            best_excecuted_projects = excecuted_projects;
            best_assigned_pro = assigned_pro;
        }    
    }
    printf("%d\n", maxscore);
    printing_function(best_excecuted_projects, best_assigned_pro);
    fclose(input);
}