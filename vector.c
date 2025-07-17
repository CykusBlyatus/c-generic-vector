#include "vector.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef VECTOR(void) aux_vector_t;

/**
 * @brief Calculates the address of an element at index 'idx', for a vector 'self' with elements of size 'type_size'
 */
#define vector_at__(this, type_size, idx) ((void*)(((uint8_t*)(this)->at) + (type_size) * (idx)))


int vector_init(void *self, size_t type_size, size_t init_cap) {
    if (init_cap == 0) {
        errno = EINVAL;
        return -1;
    }

    aux_vector_t *this = self;

    this->at = malloc(init_cap * type_size);
    if (this->at == NULL) return -1;

    this->cap = init_cap;
    this->size = 0;
    return 0;
}


void vector_destruct(void *self) {
    if (self == NULL) return;
    free(((aux_vector_t*) self)->at);
}


void* vector_extend(void *self, size_t type_size) {
    aux_vector_t *this = self;
    if (this->size >= this->cap) {
        void *tmp = realloc(this->at, 2 * this->cap * type_size);
        if (tmp == NULL) return NULL;
        this->at = tmp;
        this->cap *= 2;
    }

    ++this->size;
    return vector_at__(this, type_size, this->size - 1);
}


int vector_reserve(void *self, size_t type_size, size_t size) {
    aux_vector_t *this = self;
    if (size > this->cap) {
        void *tmp = realloc(this->at, size * type_size);
        if (tmp == NULL) return -1;
        this->at = tmp;
        this->cap = size;
    }
    return 0;
}


int vector_resize(void *self, size_t type_size, size_t size) {
    aux_vector_t *this = self;
    if (vector_reserve(self,type_size,size))
        return -1;
    this->size = size;
    return 0;
}


int vector_remove(void *self, size_t type_size, size_t idx) {
    aux_vector_t *this = self;
    if (idx >= this->size) {
        errno = EINVAL;
        return -1;
    }

    uint8_t *dest = vector_at__(this,type_size,idx);
    uint8_t *src = dest + type_size;
    memmove(dest, src, type_size * (this->size - idx - 1));
    --this->size;
    return 0;
}


void vector_clear(void* self) {
    ((aux_vector_t*)self)->size = 0;
}
