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
    FILE *input = fopen("TESTS\\project.txt", "r");
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
    greedy_approach(p, c, projects, srch_map);
    fclose(input);
    
}