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


struct node * sublist(struct node * A, struct node * pos_list) {
    
    //print_list_vert(A);
    //print_list_vert(pos_list);
    
    int i = 1, j=0, pos_size;
    struct node* temp = A;
    struct node* next = temp->next;
    temp = next;
    
    struct node* pos_temp = pos_list;
    struct node* pos_next = pos_temp->next;
    pos_temp = pos_next;
    
    struct node* dummy = new_list();
    struct node* result;
    struct node* result_next;
    dummy->next = result;
    result = new_node(0, result_next);
    result_next = new_node(0, NULL);
    //result = result_next;
    struct node* temp2 = new_list();

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
        
        result->data = temp->data;
        printf("result->data: %d\n", result->data);
        result->next = temp2;
        temp2->next = result_next;
        result = temp2;
        
        //printf("temp->data: %d\n", temp->data);
        
        //result->next= result_next;
        
        pos_temp = pos_next;
        
        
        temp = A;
        next = temp->next;
        temp = next;
    }
    return result;
}


void swap_first_third(struct node * A) {
    return;
}

void delete_occurrences(struct node * A, int V) {
    
    struct node* temp = A;
    
    int i = 0;
    
    while(A != NULL)
    {

        
        if(A->data == V && i == 0)
        {
            A = temp->next;
            free(temp);
            return;
            
        }
        temp = temp->next;
        if(A->data == V)
        {
            struct node* next = temp->next->next;
            free(temp->next);
            
            temp->next = next;
        }

    }
    
    return;
}



// Tests the sublist function.
int student_test_sublist() {
    printf("\n Running function student_test_sublist.\n ");
    return 0;
}


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
    
   
    
    
    print_list_vert(result);
    //print_list_vert(pos_dummy);
    
    
    
  
    
    
    return 0;
}
