/*map (dictionary in py) of skill keys and level values*/
typedef struct Nodes
{
    struct Nodes *left;
    struct Nodes *right;
    int height;
    char *key;
    int data;
}Nds;

//Contributer struct
typedef struct 
{
    Nds *skills;
    char name[30];
    int skillc; //Number of skills
    int is_assigned;
    int day;

}Contributer;

// Dynamic contributer array
typedef struct 
{
    Contributer *arr;
    int len;
    int mal;
}Array;

/*map (dictionary in py) of skill keys and contributer array values*/
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    char *key;
    Array data;
}Nd;

//Skill struct
typedef struct 
{
    char name[30];
    int level;
    
}Skill;

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

typedef struct {
    char name[30];
    Array assign_cont;
    
}assignement;
