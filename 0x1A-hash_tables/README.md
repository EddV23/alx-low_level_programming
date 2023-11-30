# 0x1A. C - Hash tables
# Hash Table Implementation in C

This project implements a basic hash table data structure in C, along with various operations like insertion, retrieval, and deletion. Additionally, it includes a sorted hash table implementation with doubly linked lists for maintaining a sorted order.

## Table of Contents

- [Overview](#overview)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Compilation](#compilation)
- [Example](#example)
- [Advanced Feature](#advanced-feature)
- [License](#license)

## Overview

A hash table is a data structure that allows efficient insertion, retrieval, and deletion of key-value pairs. It uses a hash function to map keys to indices in an array, providing constant-time average case complexity for these operations.

This project consists of the following components:
- **Basic Hash Table:** Implements a hash table with separate chaining for collision resolution.
- **djb2 Hash Function:** Utilizes the djb2 hash function for converting keys into hash values.
- **Sorted Hash Table (Advanced Feature):** Implements a sorted hash table using doubly linked lists to maintain a sorted order of keys.

## File Structure

- **hash_tables.h:** Header file containing the data structures and function prototypes.
- **0-hash_table_create.c:** Creates a hash table.
- **1-djb2.c:** Implements the djb2 hash function.
- **2-key_index.c:** Retrieves the index of a key in the hash table.
- **3-hash_table_set.c:** Adds or updates a key-value pair in the hash table.
- **4-hash_table_get.c:** Retrieves the value associated with a key in the hash table.
- **5-hash_table_print.c:** Prints the contents of the hash table.
- **6-hash_table_delete.c:** Deletes the hash table.
- **100-sorted_hash_table.c (Advanced Feature):** Implements a sorted hash table.

## Usage

To use the hash table, include the "hash_tables.h" header in your C program and compile it with the provided source files. See the [Compilation](#compilation) section for details.

## Compilation

Compile the C files using a C compiler. For example, using `gcc`:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hash_table

---

## Example
```c
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "key1", "value1");
    hash_table_set(ht, "key2", "value2");
    hash_table_set(ht, "key3", "value3");

    printf("Value for key 'key2': %s\n", hash_table_get(ht, "key2"));

    hash_table_print(ht);

    hash_table_delete(ht);

    return (0);
}

---

## Advanced Feature
The project includes an advanced feature: a sorted hash table. To use this feature, include the "hash_tables.h" header and compile the provided source files, including "100-sorted_hash_table.c".

## License
This project is licensed under the MIT License - see the LICENSE file for details.