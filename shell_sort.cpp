/*
    shell sort
*/

#include "common.h"

void shell_sort( vector< int > & arr, int n ) {

    for ( int gap = n / 2; gap > 0; gap /= 2 ) {

        for ( int i = gap; i < n; i++ ) {

            int t = arr[ i ];

            int j = i;

            while ( ( j >= gap ) && ( arr[ j - gap ] > t ) ) {

                arr[ j ] = arr[ j - gap ];
                j -= gap;
            }

            arr[ j ] = t;
        }
    }
}

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );

    printf( "original array: " );
    print_arr( arr );

    shell_sort( arr, n );

    printf( "sorted array: " );
    print_arr( arr );
}
