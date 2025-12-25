#include <stdio.h>

struct student {
    char name[ 20 ];
    int age;
    char sex;
    float gpa;
};

void upgrade( struct student *child );

int main() {
    struct student aboy;

    // Initialize data.
    aboy.sex = 'M';
    aboy.gpa = 3.00;

    // Call function: Pass the address of 'aboy' using '&'.
    upgrade( &aboy );

    // Print result (GPA will be updated to 3.30).
    printf( "%.2f", aboy.gpa );
    
    return 0;
}

void upgrade( struct student *child ) {
    if ( child->sex == 'M' ) {
        child->gpa *= 1.10; 
        // Increase 10%
    } else {
        child->gpa *= 1.20; 
        // Increase 20%
    }
}