/*
*/

#include <cstdio>
#include <vector>

using namespace std;

void print_array( int arr[], int n ) {

    int i;

    for ( i = 0; i < n; i++ ) printf( "%d ", arr[ i ] );
    printf("\n");
}

void heapify( int arr[], int n, int i ) {

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

void heap_sort( int arr[], int n ) {

    int i;

    for ( i = n / 2 - 1; i >= 0; i-- ) {

        heapify( arr, n, i );
    }
 
    for ( i = n - 1; i >= 0; i-- ) {

        swap( arr[ 0 ], arr[ i ] );
        heapify( arr, i, 0 );
    }
}

int main( ) {

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    heap_sort( arr, n );
 
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
