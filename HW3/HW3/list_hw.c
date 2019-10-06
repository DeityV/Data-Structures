#include <stdio.h>
#include <stdlib.h>

#include "list_hw.h"

// ------------- Node functions

/* Creates a new link, that contains the value specified in the argument,
 * and that points to next_in.
 */
struct node * new_node(int value_in,  struct node * next_in) {
    struct node * result = (struct node *) malloc(sizeof (struct node));
    result->data = value_in;
    result->next = next_in;
    return result;
}

/*    --------  LIST functions    */
// List implementation uses a DUMMY NODE

/* Creates and returns an empty list with a dummy node. */
struct node * new_list() {
    struct node * dummy = new_node(0,NULL);
    return dummy;
}

/* Deallocates memory for all nodes in the list and the list object itself. */
void destroy_list(struct node * Ld) {
    struct node * next;
    struct node * current = Ld;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Inserts new_node after the node called "previous".
void insert_node(struct node * previous, struct node * new_node) {
    if (previous == NULL) {
        printf("\n Cannot insert after a NULL node. No action taken.");
    } else {
        new_node->next = previous->next;
        previous->next = new_node;
    }
}

// Returns 0 for empty lists (that have just one dummy node) and NULL lists
int compute_length(struct node * Ld) {
    if (Ld == NULL) {
        return 0;
    }
    
    int counter = 0;
    struct node * curr;
    for (curr = Ld->next; curr != NULL; curr = curr->next) {
        counter++;
    }
    return counter;
}


void print_list_vert(struct node * my_list) {
    if (my_list == NULL) {
        printf("\n<print_list> : list is NULL\n");
        return;
    }
    int i = 0;
    struct node * curr;
    printf("\n List items:\n");
    for (i = 0, curr = my_list->next; (curr != NULL); curr = curr->next) {
        printf("item %d: %d\n", i, curr->data);
        i++;
    }
    printf(" Length of above list = %d\n", i);
}

void print_list_horiz(struct node * my_list) {
    if (my_list == NULL) {
        printf("\n<print_list_horiz> : List is NULL\n");
        return;
    }
    int i = 0;
    struct node * curr;
    
    printf("\n List items: ");
    for (i = 0, curr = my_list->next; (curr != NULL); curr = curr->next) {
        printf("%5d    ", curr->data);
        i++;
    }
    printf("\n Length of above list = %d\n", i);
}

void print_list_pointer(struct node * my_list) {
    if (my_list == NULL) {
        printf("\n<print_list_pointer> : List is NULL\n");
        return;
    }
    
    int i = 0;
    struct node * curr;
    printf("\n List items:    ");
    for (i = 0, curr = my_list->next; (curr != NULL); curr = curr->next) {
        printf("%-11d ", curr->data);
        i++;
    }
    printf("\n List pointers: ");
    for (i = 0, curr = my_list->next; (curr != NULL); curr = curr->next) {
        printf("%p ", curr);
        i++;
    }
    printf("\n Length of above list = %d\n", i);
}


/*----------------------------------------------------------------
 New functions.
 * Finish their implementation below.
 * If you need to use helper functions you can define them and use them in this file.
 *** You should not change the behavior of any of the functions defined above.***
 *** You should only write code in this file. DO not modify the client file in any way. You will NOT submit the client file.
 
 NOTE: that the functions:
 link array_2_list(int arr[], int sz)
 link build_list_of_ints()
 are implemented and used in the instructor_client.c file,
 BUT YOU CAN ALSO CALL THEM AND USE THEM IN YOUR student_test_sublist function.
 */

/*
 This function returns a list that contains the values that appear in list A at positions given in pos_list
 Requirement 1: the values should appear in the result in the order given by pos_list. For example if
 A: 15 -> 100 -> 7 -> 5 -> 100 -> 7 -> 30 and
 pos_list : 3 -> 0 -> 6 -> 4
 The resulting list will be A[3] -> A[0] -> A[6] -> A[4] , which gives values: 5 -> 15 -> 30 -> 100.
 Requirement 2: the result should be a deep copy, so that any future changes in list A cannot possibly affect the result, and any future changes in the result cannot possibly affect list A. (List A should remain as it was after building the sublist.)
 Requirement 3: DO not copy the nodes in an array and then build a list from an array. When found the node in A, make a new node with the same value and insert it in the result list.
 Requirement 4: DO not make a copy of a list and change the data there. Build the result list by starting with an empty list and then creating new nodes and inserting them at the end of it.
 The list pos_list CAN have repetitions. E.g.:
 list A: 10 -> 5
 pos_list: 0->0->1->-0->1->1->0.
 produces list: 10->10->5->10->5->5->10
 (This example also shows that the size of A is unrelated to the size of pos_list.)*/
struct node * sublist(struct node * A, struct node * pos_list) {
    
    //print_list_vert(A);
    //print_list_vert(pos_list);
    
    int i = 1, j=0, pos_size;
    struct node * curr;
    struct node* temp = A;
    struct node* next = temp->next;
    temp = next;
    
    struct node* pos_temp = pos_list;
    struct node* pos_next = pos_temp->next;
    pos_temp = pos_next;
    
    struct node* result = new_list();
    struct node* result_next = result->next;
    //result = result_next;

    int flag;
    
    while(pos_temp != NULL)
    {
        struct node* pos_next = pos_temp->next;
        //result_next = result->next;
        
        //printf(" %d \n", pos_temp->data);
        
        flag = pos_temp->data;
        
        while(flag > 0)
        {
            struct node* next = temp->next;
            //printf(" %d \n", temp->data);
            temp = next;
            flag--;
        }
        //result_next = next;  WRROONNNGGGG
        result = temp;
        //printf("temp->data: %d\n", temp->data);
        printf("result->data: %d\n", result->data);
        
        pos_temp = pos_next;
        
        
        temp = A;
        next = temp->next;
        temp = next;
    }
    return result;
}

/*
 while(pos_list != NULL)
 {
 printf(" %d \n", pos_temp->data);
 
 pos_temp->next;
 pos_temp = pos_next;
 
 }
 */

void swap_first_third(struct node * A) {
    return;
}


/*
// Tests the sublist function.
int student_test_sublist() {
    printf("\n Running function student_test_sublist.\n ");
    return;
}
*/

void printList(struct node* n)
{
    while(n != NULL){
        printf(" %d ", n->data);
        n = n->next;
    }
}

int main(int argc, const char * argv[]) {
    struct node* dummy = NULL;
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* fourth = NULL;
    struct node* fifth = NULL;
    struct node* sixth = NULL;
    struct node* seventh = NULL;
    
    //Array A
    dummy = new_list();
    head = new_node(15, NULL);
    second = new_node(100, NULL);
    third = new_node(7, NULL);
    fourth = new_node(5, NULL);
    fifth = new_node(100, NULL);
    sixth = new_node(7, NULL);
    seventh = new_node(30, NULL);
   
    insert_node(dummy, head);
    insert_node(head, second);
    insert_node(second, third);
    insert_node(third, fourth);
    insert_node(fourth, fifth);
    insert_node(fifth, sixth);
    insert_node(sixth, seventh);
    
    //Pos_List
    struct node* pos_dummy = NULL;
    struct node* pos_head = NULL;
    struct node* pos_second = NULL;
    struct node* pos_third = NULL;
    struct node* pos_fourth = NULL;
    
    pos_dummy = new_list();
    pos_head = new_node(3, NULL);
    pos_second = new_node(0, NULL);
    pos_third = new_node(6, NULL);
    pos_fourth = new_node(4, NULL);
    
    
    insert_node(pos_dummy, pos_head);
    insert_node(pos_head, pos_second);
    insert_node(pos_second, pos_third);
    insert_node(pos_third, pos_fourth);
    
    
    struct node* result = sublist(dummy, pos_dummy);
    
    printf("__Vertical Print__:\n");
    
    
    print_list_vert(result);
    //print_list_vert(pos_dummy);
    
    
    //printList(result);
  
    
    
    return 0;
}
