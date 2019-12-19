/*
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void print_array( int arr[], int n ) {

    int i;

    for ( i = 0; i < n; i++ ) printf( "%d ", arr[ i ] );
    printf("\n");
}

int paritition( int arr[], int low, int high ) {

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

void quick_sort( int arr[], int low, int high ) {

    if ( low < high ) {

        int p = paritition( arr, low, high );
        quick_sort( arr, low, p - 1 );
        quick_sort( arr, p + 1, high );
    }
}

int main( ) {

    //int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr[] = { 10, 11, 12, 13, 14, 9 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    quick_sort( arr, 0, n - 1 );
 
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
