#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "arraylist.h"


//
// Created by Emanuel on 09.09.2024.
//

#define MIN_CAPACITY (1 << 4)
#define MAX_CAPACITY (1 << 30)

struct ArrayList
{
    size_t size;
    size_t capacity;
    size_t rm_capacity;
    size_t value_size;
    size_t index;
    size_t rm_index;
    void *data;
    void *rm_data;
};

static int al_resize(const ArrayList al)
{
    const size_t new_size = al->capacity * 2;
    if (new_size >= MAX_CAPACITY) return 1;
    al->data     = realloc(al->data, new_size * al->value_size);
    assert(al->data != NULL);
    al->capacity = new_size;

    return 0;
}

static int al_rm_resize(const ArrayList al)
{
    const size_t new_size = al->rm_capacity * 2;
    if (new_size >= MAX_CAPACITY) return 1;
    al->rm_data     = realloc(al->rm_data, new_size * al->value_size);
    assert(al->rm_data != NULL);
    al->rm_capacity = new_size;

    return 0;
}

ArrayList al_create(const size_t al_capacity, const size_t value_size)
{
    const ArrayList al = malloc(sizeof(*al));
    assert(al != NULL);
    al->size        = 0;
    al->index       = 0;
    al->rm_index       = 0;
    al->capacity    = al_capacity > MIN_CAPACITY ? al_capacity : MIN_CAPACITY;
    al->value_size  = value_size;
    al->data        = calloc(al->capacity, al->value_size);
    al->rm_data     = calloc(al->capacity, al->value_size);
    al->rm_capacity = al->capacity;
    assert(al->data != NULL);

    return al;
}

int al_destroy(const ArrayList al)
{
    free(al->rm_data);
    free(al->data);
    free(al);

    return 0;
}

int al_add(const ArrayList al, const void *data)
{
    if (al->index == al->capacity)
        if(al_resize(al) != 0) return 1;
    memcpy((char *) al->data + al->index * al->value_size, data, al->value_size);
    al->size++;
    al->index++;

    return 0;
}

int al_insert(ArrayList al, size_t index, const void *data)
{
    assert(index < al->size);
    if (al->size == al->capacity)
        if (al_resize(al) != 0) return 1;

    memmove((char *)al->data + (index + 1) * al->value_size,
            (char *)al->data + index * al->value_size,
            (al->size - index) * al->value_size);
    memcpy((char *)al->data + index * al->value_size, data, al->value_size);
    al->size++;
    al->index++;

    return 0;
}


void* al_remove(const ArrayList al, const size_t index)
{
    assert(index < al->size);
    if (al->rm_index == al->rm_capacity)
        if(al_rm_resize(al) != 0) return NULL;
    memcpy((char *) al->rm_data + al->rm_index * al->value_size, (char *) al->data + index * al->value_size,
           al->value_size);
    memmove((char *) al->data + index * al->value_size,
            (char *) al->data + (index + 1) * al->value_size,
            (al->size - index - 1) * al->value_size);
    al->size--;
    al->index--;
    return (char *) al->rm_data + al->rm_index++ * al->value_size;
}

void* al_remove_last(const ArrayList al)
{
    al->index--;
    al->size--;
    return (char *) al->data + al->index * al->value_size;
}

void* al_get(const ArrayList al, const size_t index)
{
    assert(index < al->size);

    return (char *)al->data + index * al->value_size;
}

size_t al_size(const ArrayList al)
{
    return al->size;
}


bool al_is_empty(const ArrayList al)
{
    return al->size == 0;
}
