/*
    quick sort: recursive and iterative
*/

#include "common.h"

int partition( vector< int > & arr, int low, int high ) {

    int pivot = arr[ high ];
    int i = low;

    for ( int j = low; j < high; j++ ) {

        if ( arr[ j ] < pivot ) {

            swap( arr[ j ], arr[ i ] );
            i++;
        }
    }

    swap( arr[ high ], arr[ i ] );
    return i;
}

void quick_sort( vector< int > & arr, int low, int high ) {

    if ( low < high ) {

        int p = partition( arr, low, high );
        quick_sort( arr, low, p - 1 );
        quick_sort( arr, p + 1, high );
    }
}

void quick_sort_iterative( vector< int > & arr, int low, int high ) {

    vector< int > st( high - low + 1, 0 );
    int top = -1;

    st[ ++top ] = low;
    st[ ++top ] = high;

    while ( top >= 0 ) {

        high = st[ top-- ];
        low = st[ top-- ];

        int p = partition( arr, low, high );

        if ( p - 1 > low ) {

            st[ ++top ] = low;
            st[ ++top ] = p - 1;
        }

        if ( p + 1 < high ) {

            st[ ++top ] = p + 1;
            st[ ++top ] = high;
        }
    }
}

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );
  
    printf( "original array: " );
    print_arr( arr );
  
    //quick_sort( arr, 0, n - 1 );
    quick_sort_iterative( arr, 0, n - 1 );
 
    printf( "sorted array: " );
    print_arr( arr );
}
