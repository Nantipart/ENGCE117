#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0 ;
    int i = 0 ;
    // Prompt user for number of times to print "Hello World"

    scanf( "insert number : %d",&n ) ;
    // insert the number of times to print "Hello World"

    for( i = 1 ; i <= n ; i++ ){
        printf( "[%d] Hello World\n",i ) ;
    }//end for

    return 0 ;
}//end function 