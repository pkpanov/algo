/*
*/

#include <stdio.h>

int binary_search_recursive( int arr[], int l, int r, int x ) {

    if ( r >= l ) {

        int m = l + ( r - l ) / 2;

        if ( arr[ m ] == x ) {

            return m;
        } else if ( arr[ m ] > x ) {

            return binary_search_recursive( arr, l, m - 1, x );
        } else { // if ( arr[ m ] < x ) {

            return binary_search_recursive( arr, m + 1, r, x );
        }
    }

    return -1;
}

int binary_search_iterative( int arr[], int l, int r, int x ) {

    while ( l <= r ) {

        int m = l + ( r - l ) / 2;

        if ( arr[ m ] == x ) {

            return m;
        } else if ( arr[ m ] > x ) {

            r = m - 1;
        } else { // if ( arr[ m ] < x ) {

            l = m + 1;
        }
    }

    return -1;
}

int binary_search_topcoder( int arr[], int l, int r, int x ) {

    while ( l + 1 < r ) {

        int m = ( l + r ) / 2;

        if ( arr[ m ] <= x ) {

            l = m;
        } else {

            r = m;
        }
    }

    return ( arr[ l ] == x ) ? l : -1;
}

int main() {

    int arr[] = { 2, 3, 4, 10, 40, 44, 55 };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int x = 44;

    int result1 = binary_search_iterative( arr, 0, n - 1, x );

    if ( result1 == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result1 );

    int result2 = binary_search_recursive( arr, 0, n - 1, x );

    if ( result2 == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result2 );

    int result3 = binary_search_topcoder( arr, 0, n, x );

    if ( result3 == -1 ) printf( "element %d is not present in the array\n", x );
    else printf( "element %d is present at index %d\n", x, result3 );

    return 0;
}
