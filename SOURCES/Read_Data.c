#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Functions.h"

Contributer *getContributers(FILE *input, int c, Nd **map)
{
    //Store contributers in an array and creat skill-contributer map
        Contributer *contributers = (Contributer *) malloc(c * sizeof(Contributer));
        Nd *our_map = NULL;
            for (int i = 0; i < c; i++)
            {
                Contributer new_contrib;

                //Get name
                    fscanf(input, "%s", new_contrib.name);
                
                //Get number of skills
                    fscanf(input, "%d", &new_contrib.skillc);

                //Set the skills
                    new_contrib.skills = NULL;

                    char **names = (char **) malloc(new_contrib.skillc * sizeof(char *)); // array of all skill names
                    
                    for (int j = 0; j < new_contrib.skillc; j++)
                    {
                        char name[23];
                        int level;
                        // get name of skill
                            fscanf(input, "%s", name);

                        // get level of skill
                            fscanf(input, "%d", &level);

                        new_s(new_contrib.skills, name, level);//insert skill into the map
                        names[j] = name;

                    }

                // insert skills and contributers to map
                for (int j = 0; j < new_contrib.skillc; j++)
                {
                    new(our_map, names[j], new_contrib);
                }

                free(names); // remove the names array (we don't need it anymore)

                *map = our_map;
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