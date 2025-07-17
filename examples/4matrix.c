#include <vector.h>
#include <stdio.h>

//   Here is where this implementation starts getting complicated.
//   In this example, we create a simple vector of vectors.
//   The issue here is that the programmer is responsible for initializing and destructing each element,
// which can easily become hard to manage and lead to mistakes.

int main() {
    VECTOR(VECTOR(int)) m;
    VECTOR_INIT(&m);

    int n = 10;
    VECTOR_RESIZE(&m, n); // N uninitialized rows

    VECTOR_FOREACH(&m, row) {
        VECTOR_INIT(row); // initialize row
        int i = row - m.at; // could have just used a normal for loop
        for (int j = 0; j <= i; ++j)
            VECTOR_PUSH(row, i - j);
    }

    VECTOR_FOREACH(&m, row) {
        VECTOR_FOREACH(row, ptr)
            printf("%-2d ", *ptr);
        putchar('\n');
        vector_destruct(row);
    }
    vector_destruct(&m);
}

// Output:
// 0  
// 1  0  
// 2  1  0  
// 3  2  1  0  
// 4  3  2  1  0  
// 5  4  3  2  1  0  
// 6  5  4  3  2  1  0  
// 7  6  5  4  3  2  1  0  
// 8  7  6  5  4  3  2  1  0  
// 9  8  7  6  5  4  3  2  1  0
