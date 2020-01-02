/*
    jump search: search with sqrt(n) step
*/

#include "common.h"

//#define min( a, b ) ( a < b ? a : b )

int jump_search( vector< int > & arr, int n, int x ) {

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

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );

    int x = arr[ 0 ];

    sort( arr.begin(), arr.end() );
    print_arr( arr );

    int result = jump_search( arr, n, x );

    if ( result == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result );
}
