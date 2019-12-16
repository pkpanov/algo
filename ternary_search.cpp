/*
*/

#include <stdio.h>

int ternary_search( int arr[], int l, int r, int x ) {

    if ( r >= l ) {

        int m1 = l + ( r - l ) / 3;
        int m2 = r - ( r - l ) / 3;

        if ( arr[ m1 ] == x ) {

            return m1;
        } else if ( arr[ m2 ] == x ) {

            return m2;
        } else if ( x < arr[ m1 ] ) {

            return ternary_search( arr, l, m1 - 1, x );
        } else if ( x > arr[ m2 ] ) {

            return ternary_search( arr, m2 + 1, r, x );
        } else {

            return ternary_search( arr, m1 + 1, m2 - 1, x );
        }
    }

    return -1;
}

int main() {

    int arr[] = { 2, 3, 4, 10, 40, 44, 55 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int x = 55;

    int result1 = ternary_search( arr, 0, n - 1, x );

    if ( result1 == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result1 );

    return 0;
}

