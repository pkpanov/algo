/*
*/

#include <cstdio>

using namespace std;

struct node {

    int data;
    node *next;
};

void print_list( node *list ) {

    while ( list != NULL ) {

        printf( "%d ", list->data );
        list = list->next;
    }
    printf( "\n" );
}

void add_to_head( node **head_ptr, int data ) {

    node *new_node = new node();

    new_node->data = data;
    new_node->next = *head_ptr;
    *head_ptr= new_node;
}

struct node * get_tail( struct node *list ) {

    while ( ( list != NULL ) &&
            ( list->next != NULL ) ) {

        list = list->next;
    }

    return list;
}

struct node * partition( struct node **head_ptr, struct node **tail_ptr ) {

    struct node *pivot = *tail_ptr;
    struct node *prev = NULL;
    struct node *cur = *head_ptr;
    struct node *last = pivot;

    *head_ptr = NULL;

    while ( cur != pivot ) {

        node *next = cur->next;

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

struct node * quick_sort( struct node *head, struct node *tail ) {

    if ( ( head == NULL ) ||
         ( head == tail ) ) return head;

    struct node *pivot = partition( &head, &tail );

    if ( head != pivot ) {

        struct node *tmp = head;
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

int main() {

    node *list = NULL;

    add_to_head( &list, 15 );
    add_to_head( &list, 10 );
    add_to_head( &list, 5 );
    add_to_head( &list, 20 );
    add_to_head( &list, 3 );
    add_to_head( &list, 2 );

    printf( "original list: " );
    print_list( list );

    list = quick_sort( list, get_tail( list ) );

    printf( "sorted list: " );
    print_list( list );

    return 0;
}
