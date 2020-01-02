/*
    merge sort for doubly linked list
*/

#include "common.h"

list * merge( list *a, list *b );
void split_list( list *head, list **a, list **b );

void merge_sort( list **head_ptr ) {

    list *a, *b;

    if ( ( *head_ptr == NULL ) || ( ( *head_ptr )->next == NULL ) ) return;

    split_list( *head_ptr, &a, &b );

    merge_sort( &a );
    merge_sort( &b );

    *head_ptr = merge( a, b );
}

list * merge( list *a, list *b ) {

    list *result = NULL;

    if ( a == NULL ) {

        return b;
    } else if ( b == NULL ) {

        return a;
    } else if ( a->data <= b->data ) {

        result = a;
        result->next = merge( a->next, b );
        result->next->prev = result;
        result->prev = NULL;
    } else { // if ( a->data > b->data ) {

        result = b;
        result->next = merge( a, b->next );
        result->next->prev = result;
        result->prev = NULL;
    }

    return result;
}

void split_list( list *head, list **a, list **b ) {

    list *fast, *slow;

    slow = head;
    fast = head->next;

    while ( fast != NULL ) {

        fast = fast->next;
        if ( fast != NULL ) {

            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

void doit() {

    list *list = NULL;

    gen_random_list( &list, 20 );

    printf( "original list: " );
    print_list( list );

    merge_sort( &list );

    printf( "sorted list: " );
    print_list( list );
}
