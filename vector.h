/**
 * @file vector.h
 * @brief Declaration of a structure similar to the C++ std::vector class.
 * @author CykusBlyatus
 * @date 2024-06-10
 */

#ifndef C_GENERIC_VECTOR_H
#define C_GENERIC_VECTOR_H

#include <stddef.h>

#define VECTOR(T)\
    struct\
    {\
        T *at;\
        size_t cap,size;\
    }

/**
 * @brief Initializes a vector.
 * @param self pointer to a vector struct.
 * @param init_cap initial number of elements that the vector is able to hold.
 * @return 0 on success, non-zero otherwise.
 */
#define VECTOR_INIT_CAP(self,init_cap) vector_init(self,sizeof(*(self)->at),init_cap)
#define VECTOR_INIT(self) VECTOR_INIT_CAP(self,8)

/**
 * @brief Vector destructor (frees its array).
 * @param self Pointer to the vector to destruct.
 */
 #define VECTOR_DESTRUCT vector_destruct
void vector_destruct(void *self);

/**
 * @brief Adds an uninitialized element to the vector.
 * @return A pointer to the added element on success, NULL otherwise.
 * @note In case of failure, the vector remains unchanged.
 * @details It merely increments the vector's size, reallocating its buffer if needed.
 */
#define VECTOR_EXTEND(self) vector_extend(self, sizeof(*(self)->at))

/**
 * @brief Adds a new element to the end of the vector with the contents at the address 'from'.
 * @param self Pointer to a vector struct.
 * @param val Value
 * @return 0 on success, non-zero otherwise.
 */
#define VECTOR_PUSH(self,val) do {\
    *((typeof((self)->at)) VECTOR_EXTEND(self)) = val;\
} while(0)

/**
 * @brief Makes sure the vector has enough capacity for the given size.
 * @param self Pointer to a vector struct.
 * @param size Capacity desired.
 * @return 0 on success, non-zero otherwise.
 */
#define VECTOR_RESERVE(self,size) vector_reserve(self,sizeof(*(self)->at),size)

/**
 * @brief Resizes the vector to the given size.
 *        If the new size is bigger than the vector's size, the new elements are not initialized.
 *        If the new size is smaller than the vector's capacity, the capacity remains unchanged.
 * @param self Pointer to a vector struct
 * @param size New size
 * @return 0 on success, non-zero otherwise
 */
#define VECTOR_RESIZE(self,size) vector_resize(self,sizeof(*(self)->at),size)

/**
 * @brief Removes the element at the given index.
 * @param self Pointer to a vector struct.
 * @param idx Index of element to remove.
 * @return 0 on success, non-zero otherwise.
 */
#define VECTOR_REMOVE(self,idx) vector_remove(self,sizeof(*(self)->at),idx)

/**
 * @brief Removes all elements of the vector. Its capacity is not altered, nor the buffer contents.
 * @param self The vector to clear
 * @return 0 on success, non-zero otherwise
 */
#define VECTOR_CLEAR vector_clear
void vector_clear(void* self);

/**
 * @brief Takes a pointer to a vector and a name to give the pointer that will iterate over the vector.
 * @example Assuming v is a vector of int, these two lines of code are equivalent:
 *              for (int *ptr = v.at; ptr < v.at + v.size; ++ptr)
 *              vector_foreach(&v, ptr)
 * @see examples/3foreach.c
 */
#define VECTOR_FOREACH(self,elem) for(typeof((self)->at) elem = (self)->at; elem < (self)->at + (self)->size; ++elem)


// The functions below may be used, for instance, with function pointers
// While their respective macros automatically detect the type size, these functions require it as an argument

int vector_init(void *self, size_t type_size, size_t init_cap);
void* vector_extend(void *self, size_t type_size);
int vector_reserve(void *self, size_t type_size, size_t size);
int vector_resize(void *self, size_t type_size, size_t size);
int vector_remove(void *self, size_t type_size, size_t idx);

#endif /* C_GENERIC_VECTOR_H */
