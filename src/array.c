#include <string.h>
#include <stdlib.h> 
#include "array.h"

struct array *
array_alloc(int entry_size, int size) {
    struct array *arr;
    if (entry_size <= 0 || size < 0) {
        return NULL;
    }
    arr = malloc(sizeof(struct array) + entry_size * size);
    arr->used = 0;
    arr->size = size;
    arr->entry_size = entry_size;
    // FIXME: out of memory
    return arr;
}

int
array_used(struct array *arr) {
    if (arr) {
        return arr->used;
    }
    return 0;
}

char *
array_push(struct array *arr) {
    int new_size;
    char *element;

    if (!arr) {
        return NULL;
    }
    if (arr->used == arr->size) { // array is full
        new_size = arr->size * 2;
        arr = realloc(arr, sizeof(struct array) + arr->entry_size * new_size);
        arr->size = new_size;
    }
    element = ((char *)arr->entries + arr->used * arr->entry_size);
    arr->used++;
    return element;
}

char *
array_pos(struct array *arr, int pos) {
    if (!arr || pos < 0 || pos >= arr->used) return NULL;
    return ((char *)arr->entries + pos * arr->entry_size);
}

void
array_dealloc(struct array *arr) {
    if (!arr) return free(arr);
}
