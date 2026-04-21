# Generic Vector in C
This is a fairly simple yet elegant and flexible implementation of dynamic arrays in C. All you really need to know about how it is implemented is this macro:

```h
#define VECTOR(T)\
    struct\
    {\
        T *at;\
        size_t cap,size;\
    }
```

This allows not only the creation of variables that are dynamic arrays, but also types that can then be used for things such as function arguments. Examples of both use cases below:

```c
// This variable can then be initialized and used
VECTOR(int) v;
```

```c
typedef VECTOR(int) int_vector_t;

// Every variable declared as an int_vector_t can later be used as an argument to this function
void print_int_vector(const int_vector_t *v);
```

More detailed usage of this vector implementation can be found in the `examples/` directory.

## Note
`vector.h` uses non-standard C features (some compilers do not support them):
- The `VECTOR_PUSH` macro uses a [statement expression](https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html) to return a result. Alternatives include using `VECTOR_PUSH_NO_STMT_EXPR` or `VECTOR_EXTEND`, but the former leads to more verbose error checking and the latter leads to overall more verbose code
- (If you are using a standard before C23) `VECTOR_PUSH` and `VECTOR_FOREACH` need `typeof` to work
