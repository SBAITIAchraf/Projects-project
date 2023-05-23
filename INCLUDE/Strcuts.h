//Skill struct
typedef struct 
{
    char name[30];
    int level;
    
}Skill;

//Contributer struct
typedef struct 
{
    Skill *skills;
    char name[30];
    int skillc; //Number of skills

}Contributer;

// Project struct
typedef struct
{
    int roles; // number of required roles
    Skill *req_skills; // the required skills
    int req_days; // duration of the project
    int score;
    int best_bfor; // deadline
    char name[30];
}Project;
