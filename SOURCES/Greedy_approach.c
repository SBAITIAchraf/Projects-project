#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "../INCLUDE/Functions.h"




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
int assign(Array *contributers_array, Project *projects, int index_project,struct list *A) {
    int ending_day=0;
    for (int i = 0; i < contributers_array->len; i++) {
        contributers_array->arr[i].is_assigned = 1;
        contributers_array->arr[i].day=contributers_array->arr[i].day+projects[index_project].req_days;
        int contrib_lvl = ret_lvl(contributers_array->arr[i].skills, projects[index_project].req_skills[A->arr[i]].name);
        if (contrib_lvl <= projects[index_project].req_skills[A->arr[i]].level) {
            new_s(&contributers_array->arr[i].skills,projects[index_project].req_skills[A->arr[i]].name,contrib_lvl+1); //look how to change the data of this contrib     

    }
    }

    for(int j=0;j<contributers_array->len;j++){
        if(contributers_array->arr[j].day>ending_day){
            ending_day=contributers_array->arr[j].day;
        }
    }

    return ending_day;
}

//Implementing the make_available function
void make_availble(Array *contributers_array){
    for(int i=0;i< contributers_array->len;i++){
        contributers_array->arr[i].is_assigned=0;
    }
}
int Binary_search(Array *a,int first,int last,char *skill){ // binary search to find the best contributer 
    int x = (first+last)/2;
    int contrib_level=ret_lvl(a->arr[x].skills,skill);
    if (contrib_level >= x-1){
        int contrib_level_next=ret_lvl(a->arr[x+1].skills,skill);
        if (contrib_level_next >= x-1)
            return Binary_search(a,x,last,skill);
        return x;
    }
    return Binary_search(a,first,x,skill);
}
//choosing the best contributer for the role
Contributer *choose(Array *a,char *skill){
    int i = Binary_search(a,0,a->len-1,skill);
    while((a->arr[i].is_assigned == 1)&&(i >= 0)){  //checking if the contr is available
        i--;
    }
    if (i == -1)
        return NULL;
    return i;  
}



//implement a caalculate_score function to score the projects
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
int is_mentor(Project *projects,struct list *ment,Array *coontrib,int k){
    int mentor=0;
    for(int i=0;i<coontrib->len;i++){
        for(int j=0;j<ment->len;j++){
            if(find_s(coontrib->arr[i].skills,projects[k].req_skills[ment->arr[j]].name)==true && ret_lvl(coontrib->arr[i].skills,projects[k].req_skills[ment->arr[j]].name)>=projects[k].req_skills[ment->arr[j]].level/*check the level*/ ){
                mentor++;
            }

        }
    }
    if(mentor==ment->len){
        return 1;
    }
    else{
        return 0;
    }

}





void printing_function(int pro_done,assignement *projec){
    FILE *fp;
    fp = fopen ("submission_file.txt", "w");
    fprintf(fp,"%d\n",pro_done);
    for(int i=0;i<pro_done;i++){ /*the projec is one indexed*/
        fprintf(fp,"%s\n",projec[i+1].name);
        for(int j=0;j<projec[i+1].assign_cont.len;j++){
            if(j<projec[i+1].assign_cont.len-1)
                {fprintf(fp, "%s ", projec[i+1].assign_cont.arr[j].name);}
            else
                {fprintf(fp, "%s", projec[i+1].assign_cont.arr[j].name);}

        }

    }
    fclose (fp);
}



void greedy_approach(int p,int c,Project *projects,Nd *search_map){

qsort(projects,p ,sizeof(Project), compareProjects);
int excecuted_projects=0;
int day=0;
int score=0;
assignement *assigned_pro=(assignement*)malloc(p*sizeof(assignement));
arrayse non_assign=newwArray();

for(int i=0; i<p ;i++){    //p is the number of projects
    Array contributers_project = newArray();
    struct list A;
    A.len=0;
    A.allocated=1;  
    A.arr=(int*)malloc(sizeof(int)*A.allocated);
    struct list mentee;
    mentee.len=0;
    mentee.allocated=1;
    mentee.arr=(int*)malloc(sizeof(int)*mentee.allocated);
    int assigned_contributors= 0;
    for(int j=0; j<projects[i].roles;j++){
        if(find(search_map, projects[i].req_skills[j].name)==false && projects[i].req_skills[j].level>1){ 
            append3(&non_assign,projects[i]);
            free(contributers_project.arr);
            free(A.arr);
            free(mentee.arr);
            break;   //the project can not be excecuted
        }else if(find(search_map, projects[i].req_skills[j].name)==false && projects[i].req_skills[j].level==1){
            srand(time(NULL));
            int index=rand()%c;
            Contributer a=search_map->data.arr[index];
            while(a.is_assigned==1){
                srand(time(NULL));
                int index=rand()%c;
                Contributer a=search_map->data.arr[index];
            }
            assigned_contributors++;
            a.is_assigned=1;
            append(&contributers_project, a); //append this contributer to project_contributors I should implement a append function that appends a string to ana array or allocate dynimically a pointer and each time add an element
            append2(&A,j);


        }
        else{
                Array *arr= ret_cntr(search_map,projects[i].req_skills[j].name);
                int contrib_level=ret_lvl(arr->arr[0].skills,projects[i].req_skills[j].name);
                if (contrib_level <projects[i].req_skills[j].level-1 ){
                    break;
                }
                else {
                    Contributer *a = choose(arr,projects[i].req_skills[j].name);
                    if (a == NULL)  //No one is available
                        break;
                    contrib_level=ret_lvl(a->skills,projects[i].req_skills[j].name);
                    if(contrib_level>=projects[i].req_skills[j].level){
                    assigned_contributors++;
                    a->is_assigned=1;
                    append(&contributers_project, (*a)); //append this contributer to project_contributors I should implement a append function that appends a string to ana array or allocate dynimically a pointer and each time add an element
                    append2(&A,j);//append the skill index as well
                    }
                    //considering the mentorship
                    else if(contrib_level==projects[i].req_skills[j].level-1 && a->is_assigned==0){
                    assigned_contributors++;
                    a->is_assigned=1;
                    append(&contributers_project, (*a)); //append this contributer to project_contributors
                    append2(&A,j);
                    append2(&mentee,j);
                    }
                    else{
                        append3(&non_assign,projects[i]);
                        make_availble(&contributers_project);
                        free(contributers_project.arr);
                        free(A.arr);
                        free(mentee.arr);
                        break;
                        //the project can not be assigned
                    }
                }
                

        
                if(assigned_contributors==projects[i].roles){ //the project is assigned
                    if(is_mentor(projects,&mentee,&contributers_project,i)==1){
                        excecuted_projects++;
                        assignement proj1;
                        assigned_pro[excecuted_projects]=proj1;
                        strcpy(proj1.name, projects[i].name);
                        proj1.assign_cont=contributers_project;
                        int end=assign(&contributers_project,projects,i,&A);
                        //make_project's_contributer_available is_assigned==0
                        score=calculate_total_score(projects,i,score,end);
                        make_availble(&contributers_project);
                        free(contributers_project.arr);
                        free(A.arr);
                        free(mentee.arr);
                    }
                    else{
                        append3(&non_assign,projects[i]);
                        make_availble(&contributers_project);
                        free(contributers_project.arr);
                        free(A.arr);
                        free(mentee.arr);
                    }   
        }
    }
}
}

/*while(p!=non_assign.len){
    greedy_approach(non_assign.len,c,non_assign.arr,&search_map);

}*/
printing_function(excecuted_projects, assigned_pro);

}