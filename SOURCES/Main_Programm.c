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
    Contributer *contributers = getContributers(input ,c, &srch_map);
    Project *projects = getProjects(input ,p);

    for (int i = 0; i<c; i++)
    {
        printf("%s\n", srch_map->key);
    }
    fclose(input);
    
}