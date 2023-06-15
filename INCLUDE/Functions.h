#include <stdbool.h>
#include "Strcuts.h"

// Read Data
void setContributers(FILE *input, int c, Nd **search_map, Contributer *contributers); //Return a list of contributers
Project *getProjects(FILE *input, int p);

//Dynamic array
void append(Array *my_arr, Contributer elem); // Append element to dynamic array
Array newArray();

// Skill and level map
void new_s(Nds**root, char* key, int data); /*u give it a key and it create a new node or just adds the data if the key exist*/
int ret_lvl(Nds* root, char* key); /*return the level of a skill*/
bool find_s(Nds* root, char* key);/*checking the existence of a key*/

// Skill and contributer map
void new(Nd**root, char* key, Contributer data);
Contributer *ret_cntr(Nd* root, char* key);/*return the contributer array of skill key*/
int max(int a, int b); /*the max of 2 integers*/
bool find(Nd* root, char* key);/*checking the existence of a key*/

// Greedy approach
void greedy_approach(int p,Project *projects,Nd *search_map);

