/*
    quick sort for singly linked list
*/

#include "common.h"

struct list * partition( struct list **head_ptr, struct list **tail_ptr ) {

    struct list *pivot = *tail_ptr;
    struct list *prev = NULL;
    struct list *cur = *head_ptr;
    struct list *last = pivot;

    *head_ptr = NULL;

    while ( cur != pivot ) {

        list *next = cur->next;

        if ( cur->data < pivot->data ) {

            if ( ( *head_ptr ) == NULL ) *head_ptr = cur;
            prev = cur;
        } else {

            if ( prev )
                prev->next = cur->next;

            cur->next = NULL;
            last->next = cur;
            last = cur;
        }

        cur = next;
    }

    if ( ( *head_ptr ) == NULL ) *head_ptr = pivot;
    *tail_ptr = last;

    return pivot;
}

struct list * quick_sort( struct list *head, struct list *tail ) {

    if ( ( head == NULL ) ||
         ( head == tail ) ) return head;

    struct list *pivot = partition( &head, &tail );

    if ( head != pivot ) {

        struct list *tmp = head;
        while ( tmp->next != pivot )
            tmp = tmp->next;
        tmp->next = NULL;

        head = quick_sort( head, tmp );

        tmp = get_tail( head );
        tmp->next = pivot;
    }

    pivot->next = quick_sort( pivot->next, tail );

    return head;
}

void doit() {

    list *list = NULL;

    gen_random_list( &list, 20 );

    printf( "original list: " );
    print_list( list );

    list = quick_sort( list, get_tail( list ) );

    printf( "sorted list: " );
    print_list( list );
}
