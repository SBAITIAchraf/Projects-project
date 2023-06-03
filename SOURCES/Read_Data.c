#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Strcuts.h"



Contributer *getContributers(FILE *input, int c)
{
    //Store contributers in an array
        Contributer *contributers = (Contributer *) malloc(c * sizeof(Contributer));
            for (int i = 0; i < c; i++)
            {
                Contributer new_contrib;
                new_contrib.is_assigned=0;

                //Get name
                    fscanf(input, "%s", new_contrib.name);
                
                //Get number of skills
                    fscanf(input, "%d", &new_contrib.skillc);

                //Set the skills
                    new_contrib.skills = (Skill *) malloc(new_contrib.skillc * sizeof(Skill));
                    for (int j = 0; j < new_contrib.skillc; j++)
                    {
                        Skill new_skill;

                        // get name of skill
                            fscanf(input, "%s", new_skill.name);

                        // get level of skill
                            fscanf(input, "%d", &new_skill.level);

                        new_contrib.skills[j] = new_skill; //insert skill into the array

                    }
                contributers[i] = new_contrib;
            }
    return contributers;
}

Project *getProjects(FILE *input, int p)
{
    //Store contributers in an array
        Project *projects = (Project *) malloc(p * sizeof(Project));

            for (int i = 0; i<p; i++)
            {
                Project new_project;

                // Get name
                fscanf(input, "%s", new_project.name);

                //Get requiered days
                fscanf(input, "%d", &new_project.req_days);

                //Get score
                fscanf(input, "%d", &new_project.score);

                //Get best before
                fscanf(input, "%d", &new_project.best_bfor);

                //Get nuber of roles requiered
                fscanf(input, "%d", &new_project.roles);

                //Set the skills
                new_project.req_skills = (Skill *) malloc(new_project.roles * sizeof(Skill));
                for (int j = 0; j < new_project.roles; j++)
                {
                    Skill new_skill;

                    // get name of skill
                        fscanf(input, "%s", new_skill.name);

                    // get level of skill
                        fscanf(input, "%d", &new_skill.level);

                    new_project.req_skills[j] = new_skill; //insert skill into the array
                }
                projects[i] = new_project;
            }
       return projects;
}