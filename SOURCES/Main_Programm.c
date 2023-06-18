#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Functions.h"


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
    setContributers(input ,c, &srch_map, contributers);
    Project *projects = getProjects(input ,p);
    int excecuted_projects = 0;
    int score=0;
    assignement *assigned_pro=(assignement*)malloc(p*sizeof(assignement));
    arrayse undone = greedy_approach(p,c, &score, &excecuted_projects,assigned_pro, projects, srch_map);
    if (undone.len != 0)
    {
        int start_len;
        do{
            start_len = undone.len;
            undone = greedy_approach(undone.len,c, &score, &excecuted_projects,assigned_pro, undone.arr, srch_map);
        }while (start_len != undone.len);
    }
    printf("%d\n", score);
    printing_function(excecuted_projects, assigned_pro);
    fclose(input);
}