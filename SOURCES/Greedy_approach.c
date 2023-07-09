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

void merge_sklls(Contributer **arr, int left, int right)
{
    int i, j, k;
    int mid = left + ((right-left)/2);
    int len1 = mid - left + 1;
    int len2 = right - mid;
 
    Contributer **arr1 = (Contributer **) malloc(len1 * sizeof(Contributer *));
    Contributer **arr2 = (Contributer **) malloc(len2 * sizeof(Contributer *));
 
    for (int i = 0; i <len1; i++)
    {
        arr1[i] = arr[left + i];
    }
 
    for (int j = 0; j <len2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = left;
    
    while(i<len1 && j<len2)
    {
        int skll1 = arr1[i]->skillc;
        int skll2 = arr2[j]->skillc;
        if (skll1  < skll2)
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i<len1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j<len2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    
    
}

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



    
//implement an assign function
int assign(Array *contributers_array, Project *projects, int index_project,struct list *A, Nd **srch_mp) {
    int ending_day=0;
    for (int i = 0; i < contributers_array->len; i++) {
        contributers_array->ptr_arr[i]->is_assigned = 1;
        contributers_array->ptr_arr[i]->day=contributers_array->ptr_arr[i]->day+projects[index_project].req_days;
        if (find_s(contributers_array->ptr_arr[i]->skills, projects[index_project].req_skills[A->arr[i]].name) == false)
        {
            if (projects[index_project].req_skills[A->arr[i]].level == 1)
            {
                new_s(&contributers_array->ptr_arr[i]->skills, projects[index_project].req_skills[A->arr[i]].name, 1);
                new(srch_mp, projects[index_project].req_skills[A->arr[i]].name, contributers_array->ptr_arr[i]);
            }
        }
        else
        {
            int contrib_lvl = ret_lvl(contributers_array->ptr_arr[i]->skills, projects[index_project].req_skills[A->arr[i]].name);
            if (contrib_lvl <= projects[index_project].req_skills[A->arr[i]].level) {
                new_s(&contributers_array->ptr_arr[i]->skills,projects[index_project].req_skills[A->arr[i]].name,contrib_lvl+1); //look how to change the data of this contrib     
            }
        }

    }

    for(int j=0;j<contributers_array->len;j++){
        if(contributers_array->ptr_arr[j]->day>ending_day){
            ending_day=contributers_array->ptr_arr[j]->day;
        }
    }
    return ending_day;
}

//Implementing the make_available function
void make_availble(Array *contributers_array){
    for(int i=0;i< contributers_array->len;i++){
        contributers_array->ptr_arr[i]->is_assigned=0;
    }
}

int Binary_search(Array *a,int first,int last,char *skill, int needed_levl){ // binary search to find the best contributer 
    int x = last + ((first-last)/2);
    if (x == last || x == first)
        return x;
    int contrib_level=ret_lvl(a->ptr_arr[x]->skills,skill);
    if (contrib_level >= needed_levl){
        if (x == a->len-1)
        {
            return x;
        }
        else
        {
            int contrib_level_next=ret_lvl(a->ptr_arr[x+1]->skills,skill);
            if (contrib_level_next >= needed_levl)
                return Binary_search(a,x,last,skill, needed_levl);
            else
                return x;
        }
    }
    return Binary_search(a,first,x,skill, needed_levl);
}

//choosing the best contributer for the role
Contributer *choose(Array *a,char *skill, int needed_levl){
    if (ret_lvl(a->ptr_arr[0]->skills,skill) == needed_levl-1){ //there is no contrib with a higher or equal lvl to needed level
        int bi = 0;
        while(ret_lvl(a->ptr_arr[bi]->skills,skill) == needed_levl-1 && a->ptr_arr[bi]->is_assigned == 1 && bi < a->len){
                bi++;
            }
        if (bi == a->len || ret_lvl(a->ptr_arr[bi]->skills,skill) != needed_levl-1) 
            return NULL;
        return (a->ptr_arr[bi]);
    }
    int i = Binary_search(a,0,a->len-1,skill, needed_levl);
    int bi = i;
    while((a->ptr_arr[i]->is_assigned == 1)&&(i >= 0)){  //checking if the contr is available
        i--;
    }
    if (i == -1){ //no contr with a higher or equal lvl to required lvl is available
        int current_lvl = ret_lvl(a->ptr_arr[bi]->skills,skill);
        if (bi == a->len-1) //no cont is available
        return NULL;
        else
        {
            int next_lvl = ret_lvl(a->ptr_arr[bi+1]->skills,skill);
            if (next_lvl == needed_levl-1){ //mentorship
                bi++;
                current_lvl = ret_lvl(a->ptr_arr[bi]->skills,skill);
                while(ret_lvl(a->ptr_arr[bi]->skills,skill) == needed_levl-1 && a->ptr_arr[bi]->is_assigned == 1 && bi < a->len){
                    bi++;
                    current_lvl = ret_lvl(a->ptr_arr[bi]->skills,skill);
                }
                if (bi == a->len || current_lvl != needed_levl-1) 
                return NULL;
                return (a->ptr_arr[bi]);
            }
        }
        return NULL;
    }
    return a->ptr_arr[i];  
}



//implement a caalculate_score function to score the projects
void calculate_total_score(Project *projects,int project_index,int* score,int day){
    if(projects[project_index].best_bfor<day){
        *score=(*score)+max(0,projects[project_index].score-(day-projects[project_index].best_bfor));
    }
    else{
        *score=(*score)+projects[project_index].score;
    }
}


//implement the mentoring function
int is_mentor(Project *projects,struct list *ment,Array *coontrib,int k){
    int mentor=0;
    for(int i=0;i<coontrib->len;i++){
        for(int j=0;j<ment->len;j++){
            if(find_s(coontrib->ptr_arr[i]->skills,projects[k].req_skills[ment->arr[j]].name)==true && ret_lvl(coontrib->ptr_arr[i]->skills,projects[k].req_skills[ment->arr[j]].name)>=projects[k].req_skills[ment->arr[j]].level/*check the level*/ ){
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
    for(int i=0;i<pro_done;i++){
        fprintf(fp,"%s\n",projec[i].name);
        for(int j=0;j<projec[i].assign_cont.len;j++){
            if(j<projec[i].assign_cont.len-1)
                {fprintf(fp, "%s ", projec[i].assign_cont.ptr_arr[j]->name);}
            else
                {fprintf(fp, "%s\n", projec[i].assign_cont.ptr_arr[j]->name);}

        }
    }
    //free the memory
    for(int k=0;k<pro_done;k++){
        free(projec[k].assign_cont.ptr_arr);
    }

    fclose (fp);
}


// MAIN FUNCTION!
arrayse greedy_approach(int p,int c,int* score,int *excecuted_projects,assignement *assigned_pro,Project *projects,Nd *search_map, Contributer **contributers){
arrayse non_assign=newwArray();

for(int i=0; i<p ;i++){    //p is the number of projects

    Array contributers_project = newArray_ptr();

    struct list A; // array of roles indexs
    A.len=0;
    A.allocated=1;  
    A.arr=(int*)malloc(sizeof(int)*A.allocated);

    struct list mentee;
    mentee.len=0;
    mentee.allocated=1;
    mentee.arr=(int*)malloc(sizeof(int)*mentee.allocated);

    int assigned_contributors= 0;

    for(int j=0; j<projects[i].roles;j++){

        // if the no one has the required skill
        if(find(search_map, projects[i].req_skills[j].name)==false && projects[i].req_skills[j].level>1){ 
            append3(&non_assign,projects[i]);
            make_availble(&contributers_project);
            free(contributers_project.ptr_arr);
            free(A.arr);
            free(mentee.arr);
            break;   //the project can not be excecuted

        //if the skill is lvl 1
        }
        // if someone has the skill of lvl is 1
        else{
                if(projects[i].req_skills[j].level==1){
                    int index=0;
                    Contributer *a= contributers[index];

                    while(index < c && a->is_assigned==1){
                        index++;
                        a= contributers[index];
                    }//all the contributers can be assigned to the projects so we will choose randomly one of them
            
                    if (index == c)
                    {
                        append3(&non_assign,projects[i]);
                        make_availble(&contributers_project);
                        free(contributers_project.ptr_arr);
                        free(A.arr);
                        free(mentee.arr);
                        break;//the project can not be excecuted
                    }
                
                    else
                    {
                        assigned_contributors++;
                        a->is_assigned=1;
                        append_ptr(&contributers_project, a); //append this contributer to project_contributors I should implement a append function that appends a string to ana array or allocate dynimically a pointer and each time add an element
                        append2(&A,j);
                        append2(&mentee,j);
                    }


            }
            else
            {
                //get the first contrib who has the highest lvl
                Array *arr= ret_cntr(search_map,projects[i].req_skills[j].name);
                int contrib_level=ret_lvl(arr->ptr_arr[0]->skills,projects[i].req_skills[j].name);
                if (contrib_level <projects[i].req_skills[j].level-1 ){
                     append3(&non_assign,projects[i]);
                     make_availble(&contributers_project);
                     free(contributers_project.ptr_arr);
                     free(A.arr);
                     free(mentee.arr);
                    break;//the project can not be excecuted

                }
                else {
                    //get the contributer who has the the smallest lvl and still can do the job
                    Contributer *a = choose(arr,projects[i].req_skills[j].name, projects[i].req_skills[j].level);
                    if (a == NULL){//No one is available
                        append3(&non_assign,projects[i]);
                        make_availble(&contributers_project);
                        free(contributers_project.ptr_arr);
                        free(A.arr);
                        free(mentee.arr);
                        break;

                    }  
                    contrib_level=ret_lvl(a->skills,projects[i].req_skills[j].name);
                    if(contrib_level>=projects[i].req_skills[j].level){
                    assigned_contributors++;
                    a->is_assigned=1;
                    append_ptr(&contributers_project, a); //append this contributer to project_contributors I should implement a append function that appends a string to ana array or allocate dynimically a pointer and each time add an element
                    append2(&A,j);//append the skill index as well
                    }
                    //considering the mentorship
                    else if(contrib_level==projects[i].req_skills[j].level-1){
                    assigned_contributors++;
                    a->is_assigned=1;
                    append_ptr(&contributers_project, a); //append this contributer to project_contributors
                    append2(&A,j);
                    append2(&mentee,j);
                    }
                    else{
                        append3(&non_assign,projects[i]);
                        make_availble(&contributers_project);
                        free(contributers_project.ptr_arr);
                        free(A.arr);
                        free(mentee.arr);
                        break;
                        //the project can not be assigned
                    }
                }
                
            }
    
            if(assigned_contributors==projects[i].roles){ //the project is assigned
                //check if we can mentor
                if(is_mentor(projects,&mentee,&contributers_project,i)==1){
                    (*excecuted_projects)++;
                    assignement proj1;
                    strcpy(proj1.name, projects[i].name);
                    proj1.assign_cont=newArray_ptr();
                    for (int j = 0; j < contributers_project.len; j++){
                        append_ptr(&proj1.assign_cont, contributers_project.ptr_arr[j]);
                    };
                    assigned_pro[(*excecuted_projects)-1]=proj1;
                    int end=assign(&contributers_project,projects,i,&A, &search_map);
                    calculate_total_score(projects,i,score,end);
                    make_availble(&contributers_project);
                    free(contributers_project.ptr_arr);
                    free(A.arr);
                    free(mentee.arr);
                }
                else{
                    append3(&non_assign,projects[i]);
                    make_availble(&contributers_project);
                    free(contributers_project.ptr_arr);
                    free(A.arr);
                    free(mentee.arr); // can't mentor so can't do project
                }  
            }
            
        }
}
}
return non_assign;
}