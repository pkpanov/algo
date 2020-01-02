/*
    ternary search
*/

#include "common.h"

int ternary_search( vector< int > & arr, int l, int r, int x ) {

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

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );

    int x = arr[ 0 ];

    sort( arr.begin(), arr.end() );
    print_arr( arr );

    int result1 = ternary_search( arr, 0, n - 1, x );

    if ( result1 == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result1 );
}
