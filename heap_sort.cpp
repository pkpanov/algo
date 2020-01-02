/*
    heap sort
*/

#include "common.h"

void heapify( vector< int > & arr, int n, int i ) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ( ( l < n ) && ( arr[ l ] > arr[ largest ] ) ) largest = l;
    if ( ( r < n ) && ( arr[ r ] > arr[ largest ] ) ) largest = r;

    if ( largest != i ) {

        swap( arr[ i ], arr[ largest ] );
        heapify( arr, n, largest );
    }
}

void heap_sort( vector< int > & arr, int n ) {

    int i;

    for ( i = n / 2 - 1; i >= 0; i-- ) {

        heapify( arr, n, i );
    }
 
    for ( i = n - 1; i >= 0; i-- ) {

        swap( arr[ 0 ], arr[ i ] );
        heapify( arr, i, 0 );
    }
}

void doit() {

    vector< int > arr;
    int n = 20;

    gen_random_arr( arr, 20 );
  
    printf( "original array: " );
    print_arr( arr );
  
    heap_sort( arr, n );
 
    printf( "sorted array: " );
    print_arr( arr );
}
