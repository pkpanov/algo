/*
    insertion sort for singly linked list
*/

#include "common.h"

static
void sorted_insert( list ** head_ptr, list * new_node );

void insertion_sort( list ** head_ptr ) {

    list * sorted = NULL;
    list * current = *head_ptr;

    while ( current != NULL ) {

        list *next = current->next;

        sorted_insert( &sorted, current );
        current = next;
    }

    *head_ptr = sorted;
}

static
void sorted_insert( list ** head_ptr, list * new_node ) {

    if ( ( *head_ptr == NULL ) || ( new_node->data <= ( *head_ptr )->data ) ) {

        new_node->next = *head_ptr;
        *head_ptr = new_node;
    } else {

        list * current = *head_ptr;

        while ( ( current->next != NULL ) && ( new_node->data > current->next->data ) ) {

            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

void doit() {

    list *list = NULL;

    gen_random_list( &list, 20 );

    printf( "original list: " );
    print_list( list );

    insertion_sort( &list );

    printf( "sorted list: " );
    print_list( list );
}
