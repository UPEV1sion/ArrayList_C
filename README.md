# ArrayList implementation in C

A very performant, fairly lightweight `ArrayList` implementation in C.

> [!NOTE]
> This `ArrayList` implementation only implements methods that are performant. The contains method was ditched because of the catastrophical performance of generically comparing items. This `ArrayList` implmentation does all memory management and cleanup internally.

 
This document provides an overview and detailed description of the functions available in this `ArrayList` implementation.

## Overview

This `LinkedList` implementation provides a flexible hash map with functions to create, manipulate, and destroy hash maps. It supports both default and custom hash functions.

## Typedefs
```c
typedef struct ArrayList *ArrayList;
```

## Function Overview
```c
ArrayList al_create(size_t al_capacity, size_t value_size);
int al_destroy(ArrayList al);
int al_add(ArrayList al, const void *data);
int al_insert(ArrayList al, size_t index, const void *data);
void* al_remove(ArrayList al, size_t index);
void* al_remove_last(ArrayList al);
void* al_get(ArrayList al, size_t index);
size_t al_size(ArrayList al);
bool al_is_empty(ArrayList al);
```

## Function Reference

```c
ArrayList al_create(size_t al_capacity, size_t value_size);
```

**Description**: Creates a new `ArrayList`.

- **Parameters**:
  - `al_capacity`: The initial capacity of the `ArrayList`.
  - `value_size`: The size of the value.

- **Returns**: A new `ArrayList`.

---

```c
int al_destroy(ArrayList al);
```

**Description**: Destroys the `ArrayList`.

- **Parameters**:
  - `al`: The `ArrayList` to be destroyed.
    
- **Returns**: A success code.

---

```c
int al_add(ArrayList al, const void *data);
```

**Description**: Adds a new item to the `ArrayList`.

- **Parameters**:
  - `al`: The `ArrayList`.
  - `data`: The value to be added.
    
- **Returns**: A success code.

---

```c
int al_insert(ArrayList al, size_t index, const void *data);
```

**Description**: Inserts a new item in the `ArrayList` at the specified index.

- **Parameters**:
  - `al`: The `ArrayList`.
  - `index`: The index where the item should be inserted.
  - `data`: The value to be added.
    
- **Returns**: A success code.

---

```c
void* al_remove(ArrayList al, size_t index);
```

**Description**: Removes the item in the `ArrayList` at the specified index.

- **Parameters**:
  - `al`: The `ArrayList`.
  - `index`: The index where the item should be removed.
    
- **Returns**: The removed item.

---

```c
void* al_remove_last(ArrayList al);
```

**Description**: Removes the last item from the `ArrayList`.

- **Parameters**:
  - `al`: The `ArrayList`.
    
- **Returns**: The removed item.

---

```c
void* al_get(ArrayList al, size_t index);
```

**Description**: Retrieves the item from the `ArrayList` at the specified index.

- **Parameters**:
  - `al`: The `ArrayList`.
  - `index`: The index of the item which should be retrieved.
    
- **Returns**: The retrieved item.

---

```c
size_t al_size(ArrayList al);
```

**Description**: Returns the size of the `ArrayList`.

- **Parameters**:
  - `al`: The `ArrayList`.
    
- **Returns**: The size.

---

```c
bool al_is_empty(ArrayList al);
```

**Description**: Checks if the `ArrayList` is empty.

- **Parameters**:
  - `al`: The `ArrayList`.
    
- **Returns**: True or falsehood.

---

## Error Codes

- `0`: Success.
- Non-zero values indicate errors.

---

## Example

Here is a basic example demonstrating how to use the `ArrayList` functions:

```c
#include "arraylist.h"

int main()
{
	// Create a ArrayList
	ArrayList al = al_create(20, sizeof(int));
	
	// Add a value
	int value = 23;
	al_add(al, &value);
	
	// Retrieve the value
	int *retrieved_value = al_get(al, 0);

	// Destroy the ArrayList
	al_destroy(al);
	
	return 0;
}
```

  

