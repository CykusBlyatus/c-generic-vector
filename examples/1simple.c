#include <vector.h>
#include <stdio.h>

// This example just shows how you can create a vector, add values to it, and access those values.
// For readibility, there is no error checking, but it's always good practice to check if
//     vector_init and vector_extend actually succeed!

int main() {
    vector(int) v; // create our vector that will hold values of type 'int'
    vector_init(&v); // initialize its values so that we can actually use it

    // add 0,1,2,3,...,9 to the vector using two methods
    for (int n = 0; n < 10; ++n) {
        // First Method: Use vector_push. It's simple and elegant.
        vector_push(&v, n);

        // Second Method: If needed, vector_extend merely adds an unitialized element to the vector and returns a pointer to it.
        int *next = vector_extend(&v); // make room for a new element
        *next = n; // equivalent to "v.at[v.size-1] = n;"
    }

    for (size_t i = 0; i < v.size; ++i)
        printf("%d\n", v.at[i]);

    vector_destruct(&v); // always remember to free memory!
    return 0;
}
