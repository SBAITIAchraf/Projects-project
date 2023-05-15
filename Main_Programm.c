#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Skill struct
typedef struct 
{
    char *name;
    int level;
    
}Skill;

//Contributer struct
typedef struct 
{
    char *name;
    int skillc; //Number of skills
    Skill *skills;

}Contributer;


// Fubnction copies a word from source to destination from start index
void cpywrd(char *destination, char *source, int *start)
{
    int i = 0;
    while (source[(*start)] != ' ' && source[(*start)] != '\0' && source[(*start)] != '\n')
            {
                destination[i] = source[*start];
                i++;
                (*start)++;
            }
    source[i] = '\0';
}


int main(int argc, char *argv[])
{
    // Open the input file
    FILE *input = fopen("project.txt", "r");
    
        char buffer[50]; // This will contain one line of the input each time
        char number[8]; // This will contain any number as a string
        int index = 0; // Index of buffer

        //Read the first line
            fgets(buffer, 50, input); //get the first line

            int c, p;

            //Convert the first number (Contributers)
            cpywrd(number, buffer, &index);
            c = atoi(number);

            //Convert the second number (Projects)
            index++;
            cpywrd(number, buffer, &index);
            p = atoi(number);

        //Store contributers in an array
            Contributer *contributers = (Contributer *) malloc(c * sizeof(Contributer));
            for (int i = 0; i < c; i++)
            {
                Contributer new_contrib;

                //Get name
                    new_contrib.name = (char *) malloc(30 * sizeof(char));
                    fgets(buffer, 50, input); // Line of name
                    index = 0;
                    cpywrd(new_contrib.name, buffer, &index);
                
                //Get number of skills
                    fgets(buffer, 50, input); // Line of skill number
                    index = 0;
                    cpywrd(number, buffer, &index);
                    new_contrib.skillc = atoi(number);

                //Set the skills
                    new_contrib.skills = (Skill *) malloc(new_contrib.skillc * sizeof(Skill));
                    for (int j = 0; j < new_contrib.skillc; j++)
                    {
                        Skill new_skill;

                        // get name of skill
                            new_skill.name = (char *) malloc(30 * sizeof(char));
                            fgets(buffer, 50, input); // Line of skill name
                            index = 0;
                            cpywrd(new_skill.name, buffer, &index);

                        // get level of skill
                            index++;
                            cpywrd(number, buffer, &index);
                            new_skill.level = atoi(number);

                        new_contrib.skills[j] = new_skill; //insert skill into the array

                    }
                contributers[i] = new_contrib;
            }
    fclose(input);


    for (int i = 0; i<c; i++)
    {
        printf("%s\n", contributers[i].skills[0].name);
    }
}