#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Strcuts.h"

Contributer *getContributers(int c)
{
    //Store contributers in an array
        Contributer *contributers = (Contributer *) malloc(c * sizeof(Contributer));
        for (int i = 0; i < c; i++)
        {
            Contributer new_contrib;

            //Get name
                scanf("%s", new_contrib.name);
            
            //Get number of skills
                scanf("%d", &new_contrib.skillc);

            //Set the skills
                new_contrib.skills = (Skill *) malloc(new_contrib.skillc * sizeof(Skill));
                for (int j = 0; j < new_contrib.skillc; j++)
                {
                    Skill new_skill;

                    // get name of skill
                        scanf("%s", new_skill.name);

                    // get level of skill
                        scanf("%d", &new_skill.level);

                    new_contrib.skills[j] = new_skill; //insert skill into the array

                }
            contributers[i] = new_contrib;
        }

    return contributers;
}