#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

void upgrade( struct student child );

int main() {
    struct student aboy;

    // Initialize data.
    aboy.sex = 'M';
    aboy.gpa = 3.00;

    upgrade( aboy );

    // Print result (GPA will remain 3.00 because the original was not modified).
    printf( "%.2f", aboy.gpa );
    
    return 0;
}

void upgrade( struct student child ) {
    // Check sex and apply multiplier locally.
    if ( child.sex == 'M' ) {
        child.gpa *= 1.10; 
        // Increase 10% for Male.
    } else {
        child.gpa *= 1.20; 
        // Increase 20% for Female.
    }
}