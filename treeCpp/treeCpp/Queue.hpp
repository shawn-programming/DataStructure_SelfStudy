//
//  Queue.hpp
//  treeCpp
//
//  Created by Shawn on 12/27/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){front=rear=-1;size=10;Q=new Node*[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty(){return front==rear;}
    void Display();
};

void Queue::enqueue(Node* x){
    if(rear==size-1)
        printf("Qeueu Full\n");
    else{
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue(){
    Node* x=NULL;
    if(front==rear)
        printf("Queue is Empty\n");
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1; i<=rear; i++){
        printf("%d ", Q[i]->data);
    }
    printf("\n");
}

#endif /* Queue_hpp */
