#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Functions.h"


int main(int argc, char **argv)
{
        /*if (argc<2)
        {
            fprintf(stderr ,"No input was fed to the programm!");
            return 1;
        }*/
    FILE *input = fopen("..\\TESTS\\project.txt", "r");
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
    int excecuted_project = 0;
    int day = 0;
    int score = 0;
    assignement *assigned_pro = (assignement *) malloc(p*sizeof(assignement));
    greedy_approach(p, c, score, excecuted_project, assigned_pro, projects, srch_map);
    fclose(input);
    
}