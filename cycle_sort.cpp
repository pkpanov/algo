/*
    cycle sort
*/

#include "common.h"

void print_arr( vector< int > & arr, int n ) {

    int i;

    for ( i = 0; i < n; i++ ) printf( "%d ", arr[ i ] );
    printf("\n");
}

void cycle_sort( vector< int > & arr, int n ) {

    int writes = 0;

    for ( int cycle_start = 0; cycle_start < n - 1; cycle_start++ ) {

        int & item = arr[ cycle_start ];
        int pos = cycle_start;

        for ( int i = cycle_start + 1; i < n; i++ )
            if ( arr[ i ] < item ) pos++;

        if ( pos == cycle_start ) continue;

        while ( item == arr[ pos ] ) pos++;

        if ( pos != cycle_start ) {

            swap( item, arr[ pos ] );
            writes++;
        }

        while ( pos != cycle_start ) {

            pos = cycle_start;

            for ( int i = cycle_start + 1; i < n; i++ )
               if ( arr[ i ] < item ) pos++;

            if ( pos == cycle_start ) continue;

            while ( item == arr[ pos ] ) pos++;

            if ( pos != cycle_start ) {

                swap( item, arr[ pos ] );
                writes++;
            }
        }
    }

    printf( "writes = %d\n", writes );
}

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );

    printf( "original array: " );
    print_arr( arr );

    cycle_sort( arr, n );

    printf( "sorted array: " );
    print_arr( arr );
}
