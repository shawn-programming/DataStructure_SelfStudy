//
//  Chains.h
//  Hash
//
//  Created by Shawn on 1/1/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#ifndef Chains_h
#define Chains_h

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

void SortedInsert(struct Node **H, int x){
    struct Node *t, *q=NULL, *p=*H;
    
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    
    if(*H==NULL)
        *H=t;
    else{
        while(p && p->data < x){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=*H;
            *H=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

struct Node *Search(struct Node *p, int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    
    return NULL;
}
#endif /* Chains_h */
