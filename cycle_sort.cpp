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

void cycle_sort( int arr[], int n ) {

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

int main( ) {

    int arr[] = { 12, 7, 11, 12, 12, 13, 5, 6, 5, 11, 11, 11, 5, 7 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    cycle_sort( arr, n );
 
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
