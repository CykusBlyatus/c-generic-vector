#include <vector.h>
#include <stdio.h>

// This example shows the usage of vector_foreach

int main() {
    VECTOR(int) v;
    VECTOR_INIT(&v);

    for (int i = 0; i < 10; ++i)
        VECTOR_PUSH(&v, i);

    // It takes a pointer to a vector and a name for the pointer that iterates over the vector
    VECTOR_FOREACH(&v, ptr) {
        *ptr *= 2;
        printf("%d ", *ptr);
    }
    putchar('\n');

    vector_destruct(&v); // always remember to free memory!
    return 0;
}

// Output: 0 2 4 6 8 10 12 14 16 18
