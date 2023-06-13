#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Functions.h"



Contributer *getContributers(FILE *input, int c, Nd **search_map)
{
    Nd *srch_mp = *search_map;
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
                    new_contrib.skills = NULL;

                    for (int j = 0; j < new_contrib.skillc; j++)
                    {
                        char *name = (char *) malloc(23 * sizeof(char));
                        int lvl;

                        // get name of skill
                            fscanf(input, "%s", name);

                        // get level of skill
                            fscanf(input, "%d", &lvl);

                        new_s(&new_contrib.skills, name, lvl) ; //insert skill into the map
                        new(&srch_mp, name, (contributers + i));
                    }
                contributers[i] = new_contrib;
            }
    *search_map = srch_mp;
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