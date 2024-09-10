//
// Created by Emanuel on 09.09.2024.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct ArrayList *ArrayList;

/**
 * @brief Creates a new ArrayList.
 *
 * @param al_capacity The initial capacity
 * @param value_size The sizeof value of the value
 * @return A new ArrayList
 */
ArrayList al_create(size_t al_capacity, size_t value_size);

/**
 * @brief Destroys the ArrayList.
 *
 * @param al The ArrayList
 * @return Success code
 */
int al_destroy(ArrayList al);

/**
 * @brief Adds a new value to the ArrayList.
 *
 * @param al The ArrayList
 * @param data The data to be added
 * @return Success code
 */
int al_add(ArrayList al, const void *data);

/**
 * @brief Insert a new value in the ArrayList.
 *
 * @param al The ArrayList
 * @param index The index where the item should be inserted
 * @param data The data to be added
 * @return Success code
 */
int al_insert(ArrayList al, size_t index, const void *data);

/**
 * @brief Removes the item at the specified index from the ArrayList.
 *
 * @param al The ArrayList
 * @param index The index where the item should be removed
 * @return The removed item
 */
void* al_remove(ArrayList al, size_t index);

/**
 * @brief Removes the last item from the ArrayList.
 *
 * @param al The ArrayList
 * @return The removed item
 */
void* al_remove_last(ArrayList al);

/**
 * @brief Gets the item at the specified index.
 *
 * @param al The ArrayList
 * @param index The index of the item
 * @return The item
 */
void* al_get(ArrayList al, size_t index);

/**
 * @brief Returns the size of the ArrayList.
 *
 * @param al The ArrayList
 * @return The size
 */
size_t al_size(ArrayList al);

/**
 * @brief Checks if the ArrayList is empty.
 *
 * @param al The ArrayList
 * @return True or falsehood
 */
bool al_is_empty(ArrayList al);

#endif //ARRAYLIST_H
