/*
    kth smallest/largest element in array
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

int random_partition( vector< int > & arr, int low, int high ) {

    int n = high - low + 1;
    int r = rand() % n;

    swap( arr[ low + r ], arr[ high ] );

    return partition( arr, low, high );
}

int kth_element( vector< int > & arr, int low, int high, int k ) {

    if ( ( k > 0 ) && ( k <= high - low + 1 ) ) {

        int p = random_partition( arr, low, high );

        if ( p - low == k - 1 ) {

            return arr[ p ];
        } else if ( p - low > k - 1 ) {

            return kth_element( arr, low, p - 1, k );
        } else { // if ( p - low < k - 1 ) {

            return kth_element( arr, p + 1, high, k - 1 - ( p - low ) );
        }
    }

    return INF;
}

void doit( ) {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );
    print_arr( arr );

    int k = rand() % 20 + 1;

    printf( "%d-th element: %d\n", k, kth_element( arr, 0, n - 1, k ) );
}
