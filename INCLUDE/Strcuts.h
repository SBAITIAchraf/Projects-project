//Skill struct
typedef struct 
{
    char name[30];
    int level;
    
}Skill;

//Contributer struct
typedef struct 
{
    char name[30];
    int skillc; //Number of skills
    Skill *skills;

}Contributer;

// Project struct