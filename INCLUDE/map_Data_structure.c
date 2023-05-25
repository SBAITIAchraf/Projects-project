#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node /*map (dictionary in py) wiht string keys and each key has a int data*/
{
    struct Node *left;
    struct Node *right;
    int height;
    char *key;
    int data;
}Nd;

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
Nd* newNode(char* key,int data)/*creating a new node*/
{
    Nd* node = (Nd*)malloc(sizeof(Nd));
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->key = key;
    node->data = data;
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

void insert(Nd** root_adr, char* key,int data)/*inserting a node*/
{
    Nd *root = *root_adr;
    if (root == NULL)
    {
        root = newNode(key,data);
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
            rightRotation(&(root->left));
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
int ret(Nd* root, char* key)/*return the value of a key*/
{
    if (compare(root->key,key) == true)
        return root->data;
    else if (chmax(root->key,key) == root->key)
        return ret(root->left, key);
    else
        return ret(root->right, key);
}
void change_data(Nd*root,char* key,int data)/*changing the data of key*/
{
    if (compare(root->key,key) == true)
        root->data = data;
    else if (chmax(root->key,key) == root->key)
        change_data(root->left, key,data);
    else
        change_data(root->right, key,data);
}
void new(Nd*root, char* key, int data)/*the function that we will use instead of others u give it a key and it create a new node or just changing the data if the key exist*/
{
    bool k = find(root,key); 
    if (k == false)
        insert(&root,key,data);
    else{
        change_data(root, key,data);
    }
}
int main(){
    /*example of a test to understand the functions ret and new*/
    Nd *hh;
    insert(&hh,"C",1);
    insert(&hh,"C++",0);
    insert(&hh,"Java",5);
    int x = ret(hh,"Java");
    printf("%d \n",x);
    new(hh,"html",7);
    new(hh,"Java",9);
    x = ret(hh,"html");
    printf("%d",x);
    x = ret(hh,"Java");
    printf("%d",x);
}
