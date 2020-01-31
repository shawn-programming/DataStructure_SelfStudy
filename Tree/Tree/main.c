//
//  main.c
//  Tree
//
//  Created by Shawn on 12/26/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void treeCreate(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    
    printf("Enter root value ");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("enter left child ");
        scanf("%d", &x);
        if((x!=-1)){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);
        }
        printf("enter right child ");
        scanf("%d", &x);
        if((x!=-1)){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node* p){
    if(p){
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Ineorder(struct Node* p){
    if(p){
        Ineorder(p->lchild);
        printf("%d ", p->data);
        Ineorder(p->rchild);
    } 
}
void Postorder(struct Node* p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->lchild);
        printf("%d ", p->data);
    }
}

void Ipreorder(struct Node *p){
    struct Stack stk;
    Strackcreate(&stk, 100);
    
    while(p || !isEmptyStack(stk)){
        if(p){
            printf("%d ", p->data);
            push(&stk, p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(struct Node *p){
    struct Stack stk;
    Strackcreate(&stk, 100);
    
    while(p || !isEmptyStack(stk)){
        if(p){
            push(&stk, p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

void LevelOrder(struct Node *root){
    struct Queue q;
    create(&q, 100);
    
    printf("%d ", root->data);
    enqueue(&q, root);
    
    while(!isEmpty(q)){
        root=dequeue(&q);
        if(root->lchild){
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild){
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node *root){
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
}

int height(struct Node *root){
    int x=0, y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int countLeaf(struct Node *root){
    if(!root)
        return 0;
    else if(!(root->lchild) && !(root->rchild))
        return 1;
    return countLeaf(root->lchild) + countLeaf(root->rchild);
}


int main(){
    treeCreate();
    printf("Count %d ", count(root));
    printf("Height %d ", height(root));
    printf("Leaf %d", countLeaf(root));
    
    
    return 0;
}
