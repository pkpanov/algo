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

void shell_sort( int arr[], int n ) {

    for ( int gap = n / 2; gap > 0; gap /= 2 ) {
    {

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

int main( ) {

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    shell_sort( arr, n );
 
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
