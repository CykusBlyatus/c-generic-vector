#include <vector.h>
#include <stdio.h>

// This example just shows how you can create a vector, add values to it, and access those values.
// For readibility, there is no error checking, but it's always good practice to check if
//     VECTOR_INIT and VECTOR_EXTEND actually succeed!

int main() {
    VECTOR(int) v; // create our vector that will hold values of type 'int'
    VECTOR_INIT(&v); // initialize its values so that we can actually use it

    // add 0,1,2,3,...,9 to the vector using two methods
    for (int n = 0; n < 10; ++n) {
        // First Method: Use vector_push. It's simple and elegant.
        VECTOR_PUSH(&v, n);

        // Second Method: If needed, vector_extend merely adds an unitialized element to the vector and returns a pointer to it.
        int *next = VECTOR_EXTEND(&v); // make room for a new element
        *next = n; // equivalent to "v.at[v.size-1] = n;"
    }

    for (size_t i = 0; i < v.size; ++i)
        printf("%d ", v.at[i]);
    putchar('\n');

    vector_destruct(&v); // always remember to free memory!
    return 0;
}

// Output: 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
