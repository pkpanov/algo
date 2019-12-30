/*
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x7FFFFFFF

void print_array( int arr[], int n ) {

    int i;

    for ( i = 0; i < n; i++ ) printf( "%d ", arr[ i ] );
    printf("\n");
}

int partition( int arr[], int low, int high ) {

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

int random_partition( int arr[], int low, int high ) {

    int n = high - low + 1;
    int r = rand() % n;

    swap( arr[ low + r ], arr[ high ] );

    return partition( arr, low, high );
}

int kth_element( int arr[], int low, int high, int k ) {

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

int main( ) {

    int arr[] = { 1, 10, 11, 3, 12, 8, 13, 14, 9, 22 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int k = 8;

    srand( 0 );
  
    printf( "%d-th element: %d\n", k, kth_element( arr, 0, n - 1, k ) );

    return 0;
}
