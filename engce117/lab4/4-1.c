#include <stdio.h>

// Function prototype declaration.
void go( int **p, int *z );

int main() {
    int *a, b = 10, c = 20;

    // Call function to make 'a' point to 'b' (passing address of 'a').
    go( &a, &b );
    printf( "%d %p %p\n", *a, a, &a );

    // Call function to make 'a' point to 'c'.
    go( &a, &c );
    printf( "%d %p %p\n", *a, a, &a );

    return 0;
}

// Function definition.
void go( int **p, int *z ) {
    // Update the original pointer 'a' to point to the address of 'z'.
    *p = z; 
}