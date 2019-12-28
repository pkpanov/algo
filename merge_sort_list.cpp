/*
*/

#include <cstdio>

using namespace std;

struct node {

    int data;
    node *next;
};

node * merge( node *a, node *b );
void split_list( node *list, node **a, node **b );

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

void merge_sort( node **head_ptr ) {

    node *a, *b;

    if ( ( *head_ptr == NULL ) || ( ( *head_ptr )->next == NULL ) ) return;

    split_list( *head_ptr, &a, &b );

    merge_sort( &a );
    merge_sort( &b );

    *head_ptr = merge( a, b );
}

node * merge( node *a, node *b ) {

    node *result = NULL;

    if ( a == NULL ) {

        return b;
    } else if ( b == NULL ) {

        return a;
    } else if ( a->data <= b->data ) {

        result = a;
        result->next = merge( a->next, b );
    } else { // if ( a->data > b->data ) {

        result = b;
        result->next = merge( a, b->next );
    }

    return result;
}

void split_list( node *list, node **a, node **b ) {

    node *fast, *slow;

    slow = list;
    fast = list->next;

    while ( fast != NULL ) {

        fast = fast->next;
        if ( fast != NULL ) {

            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = list;
    *b = slow->next;
    slow->next = NULL;
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

    merge_sort( &list );

    printf( "sorted list: " );
    print_list( list );

    return 0;
}
