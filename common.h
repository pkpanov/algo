#pragma once

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define INF 0x7FFFFFFF

void doit();

int main( ) {

    srand( ( unsigned int )time( NULL ) );
    doit();
}

struct list {

    int data;
    list * prev;
    list * next;
};

void print_list( list * list ) {

    while ( list != NULL ) {

        printf( "%d ", list->data );
        list = list->next;
    }
    printf( "\n" );
}

void add_to_head( list ** head_ptr, int data ) {

    list * new_node = new list();

    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    if ( *head_ptr != NULL ) {

        new_node->next = *head_ptr;
        ( *head_ptr )->prev = new_node;
    }

    *head_ptr = new_node;
}

struct list * get_tail( list * list ) {

    while ( ( list != NULL ) &&
            ( list->next != NULL ) ) {

        list = list->next;
    }

    return list;
}

void gen_random_list( list ** head_ptr, int n ) {

    for ( int i = 0; i < n; i++ )
        add_to_head( head_ptr, rand() % 0x1000 );
}

void print_arr( vector< int > & arr ) {

    for ( int i = 0; i < ( int )arr.size(); i++ )
        printf( "%d ", arr[ i ] );
    printf( "\n" );
}

void gen_random_arr( vector< int > & arr, int n ) {

    for ( int i = 0; i < n; i++ )
        arr.push_back( rand() % 0x1000 );
}