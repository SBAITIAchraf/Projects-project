#include "Strcuts.h"

// Read Data
Contributer * getContributers(FILE *input, int c); //Return a list of contributers
Project *getProjects(FILE *input, int p);

//Dynamic array
void *append(Array *my_arr, Contributer elem); // Append element to dynamic array
Array newArray();

// Skill and level map
void new_s(Nds**root, char* key, int data); /*u give it a key and it create a new node or just adds the data if the key exist*/
int ret_lvl(Nds* root, char* key); /*return the level of a skill*/

// Skill and contributer map
void new(Nd**root, char* key, Contributer data);
Contributer *ret_cntr(Nd* root, char* key);/*return the contributer array of skill key*/


