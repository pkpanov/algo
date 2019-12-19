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

void count_sort( int arr[], int n, int exp ) {

    vector< int > sorted( n );
    int i, count[ 10 ];

    memset( &count, 0, sizeof( count ) );

    for ( i = 0; i < n; i++ )
        count[ ( arr[ i ] / exp ) % 10 ]++;

    for ( i = 1; i < 10; i++ )
        count[ i ] += count[ i - 1 ];

    for ( i = n - 1; i >= 0; i-- ) {

        sorted[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ] = arr[ i ];
        count[ ( arr[ i ] / exp ) % 10 ] -= 1;
    }

    for ( i = 0; i < n; i++ )
        arr[ i ] = sorted[ i ];
}

void radix_sort( int arr[], int n ) {

    int me = arr[ 0 ];

    for ( int i = 1; i < n; i++ )
        me = max( me, arr[ i ] );

    for ( int exp = 1; me / exp > 0; exp *= 10 )
        count_sort( arr, n, exp );
}

int main( ) {

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
  
    printf( "original array: " );
    print_array( arr, n );
  
    radix_sort( arr, n );
 
    printf( "sorted array: " );
    print_array( arr, n );

    return 0;
}
