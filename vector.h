/**
 * @file vector.h
 * @brief Declaration of a structure similar to the C++ std::vector class.
 * @author CykusBlyatus
 * @date 2024-06-10
 */

#ifndef C_GENERIC_VECTOR_H
#define C_GENERIC_VECTOR_H

#include <stddef.h>

#define vector(T)\
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
#define vector_init_cap(self,init_cap) vector_init_(self,sizeof(*(self)->at),init_cap)
#define vector_init(self) vector_init_cap(self,8)

/**
 * @brief Vector destructor (frees its array).
 * @param self Pointer to the vector to destruct.
 */
void vector_destruct(void *self);

/**
 * @brief Adds an uninitialized element to the vector.
 * @return A pointer to the added element on success, NULL otherwise.
 * @note In case of failure, the vector remains unchanged.
 * @details It merely increments the vector's size, reallocating its buffer if needed.
 */
#define vector_extend(self) vector_extend_(self, sizeof(*(self)->at))

/**
 * @brief Adds a new element to the end of the vector with the contents at the address 'from'.
 * @param self Pointer to a vector struct.
 * @param from Address of the element to add.
 * @return 0 on success, non-zero otherwise.
 */
#define vector_push(self,from) vector_push_(self,sizeof(*(self)->at),from)

/**
 * @brief Makes sure the vector has enough capacity for the given size.
 * @param self Pointer to a vector struct.
 * @param size Capacity desired.
 * @return 0 on success, non-zero otherwise.
 */
#define vector_reserve(self,size) vector_reserve_(self,sizeof(*(self)->at),size)

/**
 * @brief Resizes the vector to the given size.
 *        If the new size is bigger than the vector's size, the new elements are not initialized.
 *        If the new size is smaller than the vector's capacity, the capacity remains unchanged.
 * @param self Pointer to a vector struct
 * @param size New size
 * @return 0 on success, non-zero otherwise
 */
#define vector_resize(self,size) vector_resize_(self,sizeof(*(self)->at),size)

/**
 * @brief Removes the element at the given index.
 * @param self Pointer to a vector struct.
 * @param idx Index of element to remove.
 * @return 0 on success, non-zero otherwise.
 */
#define vector_remove(self,idx) vector_remove_(self,sizeof(*(self)->at),idx)

/**
 * @brief Removes all elements of the vector. Its capacity is not altered, nor the buffer contents.
 * @param self The vector to clear
 * @return 0 on success, non-zero otherwise
 */
void vector_clear(void* self);



// The functions below should not be used and only serve for the actual implementation

int vector_init_(void *self, size_t type_size, size_t init_cap);
void* vector_extend_(void *self, size_t type_size);
int vector_push_(void *self, size_t type_size, void *from);
int vector_reserve_(void *self, size_t type_size, size_t size);
int vector_resize_(void *self, size_t type_size, size_t size);
int vector_remove_(void *self, size_t type_size, size_t idx);

#endif /* C_GENERIC_VECTOR_H */