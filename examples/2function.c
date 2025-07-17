#include <vector.h>
#include <stdio.h>

// This example will show how to use vector types in multiple places, like functions, by simply using typedef

typedef VECTOR(int) int_vector_t; // vector type for holding int values

int sum(const int_vector_t *v) {
    int result = 0;
    for (size_t i = 0; i < v->size; ++i) {
        printf("%2d + %-2d = %d\n", result, v->at[i], result + v->at[i]);
        result += v->at[i];
    }
    return result;
}

int main() {
    int_vector_t vec;
    VECTOR_INIT(&vec);

    VECTOR_RESIZE(&vec, 5);
    vec.at[0] = 1;
    vec.at[1] = 3;
    vec.at[2] = 6;
    vec.at[3] = 7;
    vec.at[4] = 10;

    printf("sum = %d\n", sum(&vec));

    vector_destruct(&vec);
    return 0;
}

// Output:
//  0 + 1  = 1
//  1 + 3  = 4
//  4 + 6  = 10
// 10 + 7  = 17
// 17 + 10 = 27
// sum = 27
