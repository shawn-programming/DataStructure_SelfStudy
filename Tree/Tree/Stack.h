//
//  Stack.h
//  Tree
//
//  Created by Shawn on 12/27/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void Strackcreate(struct Stack *st, int size){
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x){
    if(st->top==st->size-1) printf("Stack overflow\n");
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st){
    struct Node *x=NULL;
    if(st->top==-1) printf("stack Underflow");
    else{
        x=st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st){
    if(st.top==-1) return 1;
    return 0;
}

int isFullStack(struct Stack st){
    return st.top==st.size-1;
}

void Display(struct Stack st){
    int i;
    for(i = st.top; i>=0; i--) printf("%d ", st.S[i]);
    printf(" ");
}
#endif /* Stack_h */
