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
    getContributers(input ,c, &srch_map, contributers);
    Project *projects = getProjects(input ,p);
    /*Contributer first;
    char nam[] = "Hello";
    first.day = 0;
    first.is_assigned = 0;
    first.name = nam;
    first.skillc = 2;
    first.skills = NULL;

    char skl[] = "Python";

    new(&srch_map, skl, &first);*/
    printf("%s\n", srch_map->key);
    
    fclose(input);
    
}