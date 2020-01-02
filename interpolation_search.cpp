/*
    iterpolation search: binary search with variable pivot
*/

#include "common.h"

int interpolation_search( vector< int > & arr, int n, int x ) {

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

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );

    int x = arr[ 0 ];

    sort( arr.begin(), arr.end() );
    print_arr( arr );

    int result = interpolation_search( arr, n, x );

    if ( result == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result );
}

