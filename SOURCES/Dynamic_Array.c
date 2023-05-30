#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Strcuts.h"

void *append(Array *my_arr, Contributer elem)
{
    if (my_arr->len == my_arr->mal)
    {
        my_arr->mal *= 2;
        Contributer *new_arr =(Contributer *) malloc(my_arr->mal * sizeof(Contributer));
        for (int i = 0; i < my_arr->len; i++)
        {
            new_arr[i] = my_arr->arr[i];
        }
        free(my_arr->arr);
        my_arr->arr = new_arr;
    }
    my_arr->arr[my_arr->len] = elem;
    my_arr->len++;
}

Array newArray()
{
    Array my_array;

    my_array.arr = (Contributer *) malloc(sizeof(Contributer));
    my_array.len = 0;
    my_array.mal = 1;

    return my_array;
}