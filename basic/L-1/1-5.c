#include <stdio.h>

int main() {
    int number ;
    int evensum = 0 ;
    int oddsum = 0 ;

    if( scanf( "%d", &number ) != 1 ) {
        return 1 ;
    }
    //end if

    while( number != 0 ) {
        if( number % 2 == 0 ) {
            evensum = evensum + number ;
        }else {
            oddsum = oddsum + number ;
        }
        //end if

        if( scanf( "%d", &number ) != 1 ) {
            return 1 ;
        }
        //end if 
    }
    
    //end while

    printf( "Even Sum: %d\n", evensum ) ;
    printf( "Odd Sum: %d\n", oddsum ) ;

    return 0 ;
}
//end function