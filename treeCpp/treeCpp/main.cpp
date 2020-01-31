//
//  main.cpp
//  treeCpp
//
//  Created by Shawn on 12/27/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Queue.hpp"

class Tree{
public:
    Node *root;
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::Preorder(Node* p){
    if(p){
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node* p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->lchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(Node *root){
    Queue q(100);
    
    printf("%d ", root->data);
    q.enqueue(root);
    
    while(!q.isEmpty()){
        root=q.dequeue();
        if(root->lchild){
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root){
    int x=0, y=0;
    if(root==0){return 0;}
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y){return x+1;}
    else{return y+1;}
}

    
void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    
    printf("Enter root value ");
    scanf("%d", &x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    
    while(!q.isEmpty()){
        p=q.dequeue();
        printf("enter left child ");
        scanf("%d", &x);
        if((x!=-1)){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("enter right child ");
        scanf("%d", &x);
        if((x!=-1)){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}



int main(int argc, const char * argv[]) {
    Tree t;
    t.CreateTree();
    t.Preorder(t.root);
    return 0;
}
