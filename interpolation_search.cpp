/*
*/

#include <stdio.h>
#include <math.h>

int interpolation_search( int arr[], int n, int x ) {

    int lo = 0;
    int hi = n - 1;

    while ( ( lo <= hi ) &&
            ( arr[ lo ] <= x ) && ( x <= arr[ hi ] ) ) {

        int p = lo + ( int )( ( ( double ) ( hi - lo ) / ( arr[ hi ] - arr[ lo ] ) ) * ( x - arr[ lo ] ) );

        if ( arr[ p ] == x ) {

            return p;
        } else if ( arr[ p ] > x ) {

            hi = p - 1;
        } else { // if ( arr[ p ] < x ) {

            lo = p + 1;
        }
    }

    return -1;
}

int main() {

    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int x = 18;

    int result = interpolation_search( arr, n, x );

    if ( result == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result );

    return 0;
}
