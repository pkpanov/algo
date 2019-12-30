/*
*/

#include <cstdio>

using namespace std;

struct node {

    int data;
    node *next;
};

void sorted_insert( node **head_ptr, node *new_node );

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

void insertion_sort( node **head_ptr ) {

    node * sorted = NULL;
    node * current = *head_ptr;

    while ( current != NULL ) {

        struct node * next = current->next;

        sorted_insert( &sorted, current );
        current = next;
    }

    *head_ptr = sorted;
}

void sorted_insert( node **head_ptr, node *new_node ) {

    if ( ( *head_ptr == NULL ) || ( new_node->data <= ( *head_ptr )->data ) ) {

        new_node->next = *head_ptr;
        *head_ptr = new_node;
    } else {

        node * current = *head_ptr;

        while ( ( current->next != NULL ) && ( new_node->data > current->next->data ) ) {

            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
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

    insertion_sort( &list );

    printf( "sorted list: " );
    print_list( list );

    return 0;
}
