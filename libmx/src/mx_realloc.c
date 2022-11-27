#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new;
    size_t prev_size;

    if (!ptr) {
        return malloc(size);
    }
    
    prev_size = malloc_size(ptr); 
    if (prev_size >= size) {
        return ptr;
    }

    new = mx_memcpy(malloc(size), ptr, prev_size);
    free(ptr);
    return new;
}



