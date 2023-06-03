#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../INCLUDE/Strcuts.h"
#include "../INCLUDE/Functions.h"


//Implement a other function to make the project's contri available


struct list
{
    int*arr;
    int len;
    int allocated;
};
void append2(struct list *A,int elem){
    if(A->len==A->allocated){
        A->allocated*=2;
          int*newarr=(int*)malloc(sizeof(int)*(A->allocated));
          for(int i=0;i<A->len;i++){
            newarr[i]=A->arr[i];
          }
          free(A->arr);
          A->arr=newarr;
    }
    A->arr[A->len]=elem;
    A->len+=1;
}






int compareProjects(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;
    return projA->best_bfor - projB->best_bfor;
}
    

//implement an assign function
void assign(Array *contributers_array, Project *projects, int index_project,struct list *A) {
    for (int i = 0; i < contributers_array->len; i++) {
        contributers_array->arr[i].is_assigned = 1;
        if (contributers_array->arr[i].skills[A->arr[i]]->level <= projects[index_project].req_skills[A->arr[i]].level) {
            change_data(contributers_array->arr[i].skills,projects[index_project].req_skills[A->arr[i]].name,contributers_array->arr[i].skills[A->arr[i]])->level+1; //look how to change the data of this contrib        
    }
}
}

//Implementing the make_available function
void make_availble(Array *contributers_array){
    for(int i=0;i< contributers_array->len;i++){
        contributers_array->arr[i].is_assigned=0;
    }
}





//implement a calculate_score function
int calculate_total_score(Project *projects,int project_index,int score,int day){
    if(projects[project_index].best_bfor<day){
        score=score+max(0,score-(day-projects[project_index].best_bfor));
    }
    else{
        score=score+projects[project_index].score;
    }
    return score;
}


//implement the mentoring function
int is_mentor(const char* skillName, int requiredLeve,Array *coontrib){
    for(int i=0; coontrib->len; i++){
        if(find_s(coontrib->arr[i].skills,skillName)==true && ret_lvl(coontrib->arr[i].skills,skillName)>=requiredLeve){
            return true;    
    }
    else{
        return false;
    }
}
}


int main(){

Nd *search_map;
qsort(projects,p ,sizeof(Project), compareProjects);

int day=0;
int score=0;

for(int i=0; i<p ;i++){                 //p is the number of projects
    Array contributers_project = newArray();
    struct list A;
    A.len=0;
    A.allocated=1;  
    A.arr=(int*)malloc(sizeof(int)*A.allocated);
    int assigned_contributors= 0;
    for(int j=0; j<projects[i].rolles;j++){
        if(find(search_map, Projects[i].req_skills[j]->name)==false){ 
            free(contributers_project.arr);
            break;   //the project can not be excecuted
        }
        else{
                Contributer *a=ret_cntr(search_map,projects[i].req_skills[j]->name);
                int contrib_level=ret_lvl(a->skills,Projects[i].req_skills[j]->name);
                if(contrib_level>=projects[i].req_skills[j]->level){
                    assigned_contributors++;
                    append(&contributers_project,*a); //append this contributer to project_contributors I should implement a append function that appends a string to ana array or allocate dynimically a pointer and each time add an element
                    append2(&A,j);//append the skill index as well
                    };
                    //considering the mentorship
                else if (contrib_level==projects[i].req_skills[j]->level-1 && a->is_assigned==0 && is_mentor(projects[i].req_skills[j]->name,projects[i].req_skills[j]->level,&contributers_project)==1){
                    append(&contributers_project,contributers[i]); //append this contributer to project_contributors
                    append2(&A,j);
                    }

        
                if(assigned_contributors==projects[i]->rolles){ //the project is assigned
                    assign(&contributers_project,projects,i,&A);
                    day=day+projects[i]->req_days;
                    //make_project's_contributer_available is_assigned==0
                    calculate_total_score(projects[i]);
                    free(contributers_project.arr);
                    }

        }

    }

}
return 0;

}
