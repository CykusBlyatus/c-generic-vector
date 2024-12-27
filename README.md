# Generic Vector in C
This is a fairly simple yet elegant and flexible implementation of dynamic arrays in C. All you really need to know about how it is implemented is this macro:

```h
#define vector(T)\
    struct\
    {\
        T *at;\
        size_t cap,size;\
    }
```

This allows not only the creation of variables that are dynamic arrays, but also types that can then be used for things such as function arguments. Examples of both use cases below:

```c
// This variable can then be initialized and used
vector(int) v;
```

```c
typedef vector(int) int_vector_t;

// Every variable declared as an int_vector_t can later be used as an argument to this function
void print_int_vector(const int_vector_t *v);
```

More detailed usage of this vector implementation can be found in the `examples/` directory.
