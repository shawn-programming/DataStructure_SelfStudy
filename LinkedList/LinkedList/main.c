 //
//  main.c
//  LinkedList
//
//  Created by Shawn on 12/3/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create(int A[], int n){
    struct Node* head;
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=NULL;
    last=head;
    
    for(i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next = t;
        last=t;
    }
    
    return head;
}

int count(struct Node *head){
    int n=0;
    struct Node *curr = head;
    while(curr){
        n++;
        curr = curr->next;
    }
    return n;
}

int sum(struct Node *head){
    int n=0;
    struct Node *curr = head;
    while(curr){
        n += curr->data;
        curr = curr->next;
    }
    return n;
}

int max(struct Node *head){
    int n = head->data;
    struct Node *curr = head->next;

    while(curr){
        if(curr->data > n) n = curr->data;
        curr = curr->next;
    }
    return n;
}

struct Node* search(struct Node *head, int key){
    struct Node* curr = head;
    if(key == head->data) return head;
    while(curr){
        if(curr){
            if(key == curr->data) return curr;
            curr = curr->next;
        }
    }
    return NULL;
}

void insert(struct Node** head, int pos, int data){
    struct Node* curr = *head;
    int A[1] = {data};
    int n=1;
    int size = count(*head);
    
    struct Node* newNode = create(A, 1);
    if(pos==0){
        newNode->next = *head;
        *head = newNode;
    }

    else{
        while(n!=pos){
            curr=curr->next;
            n++;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void insertSorted(struct Node** head, int data){
    struct Node* curr = *head;
    int A[1] = {data};
    struct Node* newNode = create(A,1);
                                  
    if((*head)->data >= data){
        newNode->next = (*head);
        *head = newNode;
        return;
    }
    
    while(curr->next){
        if(curr->data < data && curr->next->data > data){
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
    
    curr->next = newNode;
}

void delete(struct Node** head, int data){
    // checking if the head node has the data
    if((*head)->data == data){
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    // checing if curr->next has the data
    // if so, delete it
    struct Node* curr = *head;
    while(curr->next){
        if(curr->next->data == data){
            struct Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
        curr=curr->next;
    }
    printf("No such data is found\n");
}

bool isSorted(struct Node* head){
    int num = head->data;
    struct Node* curr = head;
    
    while(curr->next){
        if(curr->next->data < num) return false;
        num = curr->next->data;
        curr = curr->next;
    }
    
    return true;
}
// delete the duplicated values in a sorted linked list
void deleteDuplicate(struct Node** head){
    struct Node* front = *head;
    struct Node* end = (*head)->next;
    
    while(end){
        if(front->data == end->data){
            delete(head, front->data);
        }
        front = end;
        end = end->next;
    }
    
}

void display(struct Node *head){
    if(!head) printf("No data saved");
    while(head){
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}

void reverse(struct Node **head){
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = (*head)->next;
    
    while(next){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    *head = curr;
}

void reverseRecursive(struct Node **head, struct Node *curr, struct Node *prev);
//reverse using recursion
void reverseR(struct Node **head){
    reverseRecursive(head, (*head), NULL);
}

//recursion used in the reverse function

void reverseRecursive(struct Node **head, struct Node *curr, struct Node *prev){
    if(curr->next == NULL){
        (*head) = curr;
        curr->next = prev;
        return;
    }
    reverseRecursive(head, curr->next, curr);
    curr->next = prev;
}

//concatenate the second head to the tail of the head1
void concat(struct Node* head1, struct Node** head2){
    struct Node* curr = head1;
    while(curr->next) curr=curr->next;
    curr->next = *head2;
    *head2 = NULL;
}

//merge the first head and the second head in a sorted way
struct Node* merge(struct Node** firstHead, struct Node** secondHead){
    struct Node* firstCurr = *firstHead;
    struct Node* secondCurr = *secondHead;
    
    struct Node* newHead;
    if((*firstHead)->data < (*secondHead)->data){
        newHead = firstCurr;
        firstCurr = firstCurr->next;
    }
    else{
        newHead = secondCurr;
        secondCurr = secondCurr->next;
    }
    struct Node* newCurr = newHead;

    *firstHead = NULL;
    *secondHead = NULL;
    
    while(firstCurr && secondCurr){
        if(firstCurr->data <= secondCurr->data){
            newCurr->next = firstCurr;
            firstCurr = firstCurr->next;
            newCurr = newCurr->next;
        }
        else{
            newCurr->next = secondCurr;
            secondCurr = secondCurr->next;
            newCurr = newCurr->next;
        }
    }
    
    if(!firstCurr){
        newCurr->next = secondCurr;
    }
    else{
        newCurr->next = secondCurr;
    }
    return newHead;
}

//first pointer loops the list by one step
//while the second pointer loops the list by two steps
//if the second pointer ever reaches a null, it is not a loop
//else if they ever meet, it is a loop
bool isLoop(struct Node* head){
    struct Node* first = head;
    struct Node* second = head->next;
    
    while(true){
        if(second == first){
            return true;
        }
        else if(second == NULL || second->next == NULL){
            return false;
        }
        else
        {
            first = first->next;
            second = second->next->next;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int A[]={3,3,7,7,7,13,13};
    int B[]={11,12,13};
    
    struct Node* newNode;
    struct Node* firstNode = create(A,7);
    struct Node* secondNode = create(B,3);
    display(firstNode);
    deleteDuplicate(&firstNode);
    display(firstNode);
    newNode = merge(&firstNode, &secondNode);
    display(newNode);
    if(isLoop(newNode)){
        printf("this is a loop\n");
    }
    else{
        printf("this is not a loop\n");
    }

    
    
    return 0;
}
