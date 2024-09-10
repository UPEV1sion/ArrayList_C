//
// Created by Emanuel on 09.09.2024.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ArrayList *ArrayList;

ArrayList al_create(size_t al_capacity, size_t value_size);
int al_destroy(ArrayList al);
int al_add(ArrayList al, const void *data);
int al_insert(ArrayList al, size_t index, const void *data);
void* al_remove(ArrayList al, size_t index);
void* al_remove_last(ArrayList al);
void* al_get(ArrayList al, size_t index);
size_t al_size(ArrayList al);
bool al_is_empty(ArrayList al);

#endif //ARRAYLIST_H
