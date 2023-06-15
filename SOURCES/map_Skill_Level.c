#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../INCLUDE/Strcuts.h"


int max_s(int a, int b) /*the max of 2 integers*/
{
    return a > b ? a : b;
}
char* chmax_s(char *s1, char*s2)/*the max of 2 strings*/
{
    int i = 0;
    while(s1[i]==s2[i]){
        i++;
    }
    if (s1[i] > s2[i])
        return s1;
    return s2;
}
bool compare_s(char *s1, char*s2)/*checking if 2 strings are equal or not*/
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
Nds* newNode_s(char* key,int data)/*creating a new node*/
{
    Nds* node = (Nds*)malloc(sizeof(Nds));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->key = key;
    node->data = data;
    return node;
}

int height_s(Nds* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

void rightRotation_s(Nds** root_adr)
{
    Nds* root = *root_adr;
    Nds* leftChild = root->left;
    Nds* leftChildRightChild = leftChild->right;
    leftChild->right = root;
    root->left = leftChildRightChild;
    root->height = max_s(height_s(root->left), height_s(root->right)) + 1;
    leftChild->height = max_s(height_s(leftChild->left), height_s(leftChild->right)) + 1;
    *root_adr = leftChild;
}

void leftRotation_s(Nds** root_adr)
{
    Nds* root = *root_adr;
    Nds* rightChild = root->right;
    Nds* rightChildLeftChild = rightChild->left;
    rightChild->left = root;
    root->right = rightChildLeftChild;
    root->height = max_s(height_s(root->left), height_s(root->right)) + 1;
    rightChild->height = max_s(height_s(rightChild->left), height_s(rightChild->right)) + 1;
    *root_adr = rightChild;
}

void insert_s(Nds** root_adr, char* key,int data)/*inserting a node*/
{
    Nds *root = *root_adr;
    if (root == NULL)
    {
        root = newNode_s(key,data);
        *root_adr = root;
        return;
    }
    if (compare_s(root->key, key)== true)
        return;
    if (chmax_s(root->key, key) == root->key)
        insert_s(&(root->left), key,data);
    else if (chmax_s(root->key, key) == key)
        insert_s(&(root->right), key,data);
    root->height = max_s(height_s(root->left), 
                       height_s(root->right)) +1;
    int balance = height_s(root->left) - height_s(root->right);
    if (balance > 1)
    {
        if (chmax_s(key ,root->left->key) == key)
        {
            leftRotation_s(&(root->left));
            rightRotation_s(&root);
        }
        else
            rightRotation_s(&root);
    }
    if (balance < -1)
    {
        if (chmax_s(key ,root->right->key) == root->right->key)
        {
            rightRotation_s(&(root->right));
            leftRotation_s(&root);
        }
        else
            leftRotation_s(&root);
    }
    *root_adr = root;
}
bool find_s(Nds* root, char* key)/*checking the existence of a key*/
{
    if (root == NULL)
        return false;
    if (compare_s(root->key,key) == true)
        return true;
    else if (chmax_s(root->key,key) == root->key)
        return find_s(root->left, key);
    else
        return find_s(root->right, key);
}
int ret_lvl(Nds* root, char* key)/*return the value of a key*/
{
    if (compare_s(root->key,key) == true)
        return root->data;
    else if (chmax_s(root->key,key) == root->key)
        return ret_lvl(root->left, key);
    else
        return ret_lvl(root->right, key);
}
void change_data(Nds*root,char* key,int data)/*changing the data of key*/
{
    if (compare_s(root->key,key) == true)
        root->data = data;
    else if (chmax_s(root->key,key) == root->key)
        change_data(root->left, key,data);
    else
        change_data(root->right, key,data);
}
void new_s(Nds**root, char* key, int data)/*the function that we will use instead of others u give it a key and it create a new node or just changing the data if the key exist*/
{
    Nds *my_root = *root;
    bool k = find_s(my_root,key);
    if (k == false)
        insert_s(&my_root,key,data);
    else{
        change_data(my_root, key,data);
    }
    *root = my_root;
}
