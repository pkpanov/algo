/*
*/

#include <stdio.h>
#include <math.h>

#define min( a, b ) ( a < b ? a : b )

int jump_search( int arr[], int n, int x ) {

    int step = ( int )sqrt( n );
    int prev = 0;

    while ( arr[ min( step, n ) - 1 ] < x ) {

        prev = step;
        step += ( int )sqrt( n );

        if ( prev >= n ) return -1;
    }

    while ( arr[ prev ] < x ) {

        prev++;

        if ( prev == min( step, n ) ) return -1;
    }

    if ( arr[ prev ] == x ) {

        return prev;
    } else {

        return -1;
    }
}

int main() {

    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int x = 55;

    int result = jump_search( arr, n, x );

    if ( result == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result );

    return 0;
}
