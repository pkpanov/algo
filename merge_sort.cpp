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

void merge( int arr[], int l, int m, int r ) {

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector< int > L( n1, 0 );
    vector< int > R( n2, 0 );

    for ( i = 0; i < n1; i++ )
        L[ i ] = arr[ l + i ];

    for ( i = 0; i < n2; i++ )
        R[ i ] = arr[ m + 1 + i ];

    i = 0;
    j = 0;
    k = l;

    while ( ( i < n1 ) && ( j < n2 ) ) {

        if ( L[ i ] <= R[ j ] ) {

            arr[ k ] = L[ i ];
            i++;
        } else {

            arr[ k ] = R[ j ];
            j++;
        }

        k++;
    }

    while ( i < n1 ) {

        arr[ k ] = L[ i ];
        i++;
        k++;
    }

    while ( j < n2 ) {

        arr[ k ] = R[ j ];
        j++;
        k++;
    }
}

void merge_sort( int arr[], int l, int r ) {

    if ( l < r ) {

        int m = l + ( r - l ) / 2;

        merge_sort( arr, l, m );
        merge_sort( arr, m + 1, r );
        merge( arr, l, m, r );
    }
}

int main( ) {

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    merge_sort( arr, 0, n - 1 );
  
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
