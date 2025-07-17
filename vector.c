#include "vector.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

typedef VECTOR(void) aux_vector_t;

/**
 * @brief Calculates the address of an element at index 'idx', for a vector 'self' with elements of size 'type_size'
 */
#define vector_at__(self, type_size, idx) ((void*)(((uint8_t*)(self)->at) + (type_size) * (idx)))


int vector_init(void *self_, size_t type_size, size_t init_cap) {
    if (init_cap == 0) {
        errno = EINVAL;
        return -1;
    }

    aux_vector_t *self = (aux_vector_t*) (aux_vector_t*) self_;

    self->at = malloc(init_cap * type_size);
    if (self->at == NULL) return -1;

    self->cap = init_cap;
    self->size = 0;
    return 0;
}


void vector_destruct(void *self_) {
    if (self_ == NULL) return;
    free(((aux_vector_t*) self_)->at);
}


void* vector_extend(void *self_, size_t type_size) {
    aux_vector_t *self = (aux_vector_t*) self_;
    if (self->size >= self->cap) {
        void *tmp = realloc(self->at, 2 * self->cap * type_size);
        if (tmp == NULL) return NULL;
        self->at = tmp;
        self->cap *= 2;
    }

    ++self->size;
    return vector_at__(self, type_size, self->size - 1);
}


int vector_reserve(void *self_, size_t type_size, size_t size) {
    aux_vector_t *self = (aux_vector_t*) self_;
    if (size > self->cap) {
        void *tmp = realloc(self->at, size * type_size);
        if (tmp == NULL) return -1;
        self->at = tmp;
        self->cap = size;
    }
    return 0;
}


int vector_resize(void *self_, size_t type_size, size_t size) {
    aux_vector_t *self = (aux_vector_t*) self_;
    if (vector_reserve(self_,type_size,size))
        return -1;
    self->size = size;
    return 0;
}


int vector_remove(void *self_, size_t type_size, size_t idx) {
    aux_vector_t *self = (aux_vector_t*) self_;
    if (idx >= self->size) {
        errno = EINVAL;
        return -1;
    }

    uint8_t *dest = (uint8_t*) vector_at__(self,type_size,idx);
    uint8_t *src = dest + type_size;
    memmove(dest, src, type_size * (self->size - idx - 1));
    --self->size;
    return 0;
}


void vector_clear(void* self_) {
    ((aux_vector_t*)self_)->size = 0;
}
