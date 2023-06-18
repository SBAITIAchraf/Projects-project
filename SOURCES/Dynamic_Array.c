#include <stdio.h>
#include <stdlib.h>
#include "../INCLUDE/Strcuts.h"

void append(Array *my_arr, Contributer elem)
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
    my_array.ptr_arr = NULL;
    my_array.len = 0;
    my_array.mal = 1;

    return my_array;
}

void append_ptr(Array *my_arr, Contributer *elem)
{
    if (my_arr->len == my_arr->mal)
    {
        my_arr->mal *= 2;
        Contributer **new_arr =(Contributer **) malloc(my_arr->mal * sizeof(Contributer *));
        for (int i = 0; i < my_arr->len; i++)
        {
            new_arr[i] = my_arr->ptr_arr[i];
        }
        free(my_arr->arr);
        my_arr->ptr_arr = new_arr;
    }
    my_arr->ptr_arr[my_arr->len] = elem;
    my_arr->len++;
}

Array newArray_ptr()
{
    Array my_array;

    my_array.ptr_arr = (Contributer **) malloc(sizeof(Contributer *));
    my_array.arr = NULL;
    my_array.len = 0;
    my_array.mal = 1;

    return my_array;
}

void append3(arrayse *my_arr, Project elem)
{
    if (my_arr->len == my_arr->mal)
    {
        my_arr->mal *= 2;
        Project *new_arr =(Project *) malloc(my_arr->mal * sizeof(Project));
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

arrayse newwArray()
{
    arrayse my_array;

    my_array.arr = (Project *) malloc(sizeof(Project));
    my_array.len = 0;
    my_array.mal = 1;

    return my_array;
}