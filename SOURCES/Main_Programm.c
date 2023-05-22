#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Fuctions.h"


int main()
{
    //Read the first line
        int c, p;
        scanf("%d %d", &c, &p); //get the first line

    Contributer *contributers = getContributers(c);

    for (int i = 0; i<c; i++)
    {
        printf("%s\n", contributers[i].name);
    }
}