//
//  main.c
//  HW3
//
//  Created by Diego Guerrero on 10/5/19.
//  Copyright © 2019 Diego Vester. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n)
{
    while(n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

int main(int argc, const char * argv[]) {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;
    
    printList(head);
    
    return 0;
}
