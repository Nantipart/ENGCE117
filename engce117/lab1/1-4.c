#include <stdio.h>

int GetSet( int *Array[] ) ;

int main() {
    int *data[777], num = 0 ;
    num = GetSet( data ) ;
    return 0 ;
}//end function

int GetSet( int *Array[] ) {

    int num = 0 ;

    printf( "Enter the number of Elements: " ) ;
    scanf( "%d", &num ) ;

    printf( "Enter the Elements: " ) ;
    for ( int i = 0 ; i < num ; i++ ) {
        scanf( "%d" , &Array[i] ) ;
    }//end for

    printf( "Number of Elements: %d\n", num ) ;
    for ( int i = 0 ; i < num ; i++ ) {
        printf( "%d " , Array[i] ) ;
    }//end for

    return 0 ;
}//end function