#include <vector.h>
#include <stdio.h>

//   Here is where this implementation starts getting complicated.
//   In this example, we create a simple vector of vectors.
//   The issue here is that the programmer is responsible for initializing and destructing each element,
// which can easily become hard to manage and lead to mistakes.

int main() {
    vector(vector(int)) m;
    vector_init(&m);

    int n = 10;
    vector_resize(&m, n); // N uninitialized rows

    vector_foreach(&m, row) {
        vector_init(row); // initialize row
        int i = row - m.at; // could have just used a normal for loop
        for (int j = 0; j <= i; ++j)
            vector_push(row, i - j);
    }

    vector_foreach(&m, row) {
        vector_foreach(row, ptr)
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
