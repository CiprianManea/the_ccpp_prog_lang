/*
 * Data : 15-03-2015
 * -----------------
 *  File to hold all the different correct returning array implementations.
 * Each of the method in a different function.
 */

/* (1) String Literal */
char *return_string_literal() 
{
    char *string_literal = "This is a string literal";
    
    return string_literal;
}

/* (2) Global Array */
char global_arr[SIZE];
char *return_global_arr()
{
    strncpy(global_arr, "This string is a global arrray", SIZE);
    return global_arr;
}

/* (3) Static Array */
char *return_static_arr()
{
    static char static_arr[SIZE];

    strncpy(static_arr, "This string is in a static array", SIZE);
    return static_arr;
}

/* (4) Explicit allocate memory */
char *return_dynamic_string()
{
    char *buffer = malloc(SIZE);

    strncpy(buffer, "This string is in a malloc'ed buffer", SIZE);
    return buffer;
}

/* (5) Caller allocates/frees memory */
void fill_preallocated_buffer(char *result, int size)
{
    strncpy(result, "This string is in a preallocated buffer", size);
}

/* (6) Wrap fixed-size array in a struct */
struct Data {
    char buffer[SIZE];
};
struct Data return_struct_arr()
{
    struct Data d;

    strncpy(d.buffer, "This string is in a struct-wrapped array", SIZE);
    return d;
}
