#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../INCLUDE/Functions.h"

void merge(Contributer *arr, char *key,  int left, int right)
{
    int i, j, k;
    int mid = left + ((right-left)/2);
    int len1 = mid - left + 1;
    int len2 = right - mid;
 
    Contributer *arr1 = (Contributer *) malloc(len1 * sizeof(Contributer));
    Contributer *arr2 = (Contributer *) malloc(len2 * sizeof(Contributer));
 
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
        int lvl1 = ret_lvl(arr1[i].skills, key);
        int lvl2 = ret_lvl(arr2[j].skills, key);
        if (lvl1  > lvl2)
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

int max(int a, int b) /*the max of 2 integers*/
{
    return a > b ? a : b;
}
char* chmax(char *s1, char*s2)/*the max of 2 strings*/
{
    int i = 0;
    while(s1[i]==s2[i]){
        i++;
    }
    if (s1[i] > s2[i])
        return s1;
    return s2;
}
bool compare(char *s1, char*s2)/*checking if 2 strings are equal or not*/
{
    int i = 0;
    while(s1[i] != '\0'){
        if ((s2[i] != s1[i]))
        return false;
        i++;
    }
    if (s2[i] != '\0')
        return false;
    return true;
}
Nd* newNode(char* key,Contributer data)/*creating a new node*/
{
    Nd* node = (Nd *) malloc(sizeof(Nd));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->key = key;
    node->data = newArray();
    append(&node->data, data);
    return node;
}

int height(Nd* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void rightRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* leftChild = root->left;
    Nd* leftChildRightChild = leftChild->right;
    leftChild->right = root;
    root->left = leftChildRightChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
    *root_adr = leftChild;
}

void leftRotation(Nd** root_adr)
{
    Nd* root = *root_adr;
    Nd* rightChild = root->right;
    Nd* rightChildLeftChild = rightChild->left;
    rightChild->left = root;
    root->right = rightChildLeftChild;
    root->height = max(height(root->left), height(root->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
    *root_adr = rightChild;
}

void insert(Nd** root_adr, char* key,Contributer data)/*inserting a node*/
{
    Nd *root = *root_adr;
    if (root == NULL)
    {
        root = newNode(key, data);
        *root_adr = root;
        return;
    }
    if (compare(root->key, key)== true)
        return;
    if (chmax(root->key, key) == root->key)
        insert(&(root->left), key,data);
    else if (chmax(root->key, key) == key)
        insert(&(root->right), key,data);
    root->height = max(height(root->left), 
                       height(root->right)) +1;
    int balance = height(root->left) - height(root->right);
    if (balance > 1)
    {
        if (chmax(key ,root->left->key) == key)
        {
            leftRotation(&(root->left));
            rightRotation(&root);
        }
        else
            rightRotation(&root);
    }
    if (balance < -1)
    {
        if (chmax(key ,root->right->key) == root->right->key)
        {
            rightRotation(&(root->right));
            leftRotation(&root);
        }
        else
            leftRotation(&root);
    }
    *root_adr = root;
}
bool find(Nd* root, char* key)/*checking the existence of a key*/
{
    if (root == NULL)
        return false;
    if (compare(root->key,key) == true)
        return true;
    else if (chmax(root->key,key) == root->key)
        return find(root->left, key);
    else
        return find(root->right, key);
}
Array *ret_cntr(Nd* root, char* key)/*return the value of a key*/
{
    if (compare(root->key,key) == true)
        return &root->data;
    else if (chmax(root->key,key) == root->key)
        return ret_cntr(root->left, key);
    else
        return ret_cntr(root->right, key);
}
void add_data(Nd*root,char* key,Contributer data)/*adding the data to key*/
{
    if (compare(root->key,key) == true)
        {
            append(&root->data, data);
            merge(root->data.arr, key, 0, root->data.len - 1);
        }
    else if (chmax(root->key,key) == root->key)
        add_data(root->left, key,data);
    else
        add_data(root->right, key,data);
}
void new(Nd**root, char* key, Contributer data)/*the function that we will use instead of others u give it a key and it create a new node or just changing the data if the key exist*/
{
    Nd *my_root = *root;
    bool k = find(my_root,key);
    if (k == false)
        insert(&my_root,key,data);
    else{
        add_data(my_root, key,data);
    }
    *root = my_root;
}
