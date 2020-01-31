//
//  LinkedList.cpp
//  LinkedList(c++)
//
//  Created by Shawn on 12/4/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

using namespace std;


Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}
int Node::getData(){return data;}
Node* Node::getNext(){return next;}
void Node::setData(int data){this->data = data;}
void Node::setNext(Node* next){this->next = next;}


LinkedList::LinkedList(int A[], int n){
    first = new Node(A[0]);
    Node* curr = first;
    for(int i=1; i<n; i++){
        curr->setNext(new Node(A[i]));
        curr=(curr->getNext());
    }
}

LinkedList::~LinkedList(){
    int n = length();
    Node* curr = first;
    for(int i=0; i<n; i++){
    //while(curr){
        first = first->getNext();
        delete(curr);
        curr = first;
    }
}

void LinkedList::display(){
    Node* curr = first;
    do{
        cout<<curr->getData()<<" ";
        curr=curr->getNext();
    }
    while(curr && curr!=first);
    cout<<endl;
}

void LinkedList::insert(int index, int x){
    Node* newNode = new Node(x);
    if(index==0){
        if(isCircular()){index=length();}
        else{
            newNode->setNext(first);
            first = newNode;
            return;
        }
    }
    Node* curr = first;
    for(int i=1;i<index;i++){
        curr=curr->getNext();
    }
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
}
int LinkedList::deleteI(int index){
    int deleted;
    Node* curr = first;
    if(index==0){
        first = curr->getNext();
        deleted = curr->getData();
        delete curr;
        return deleted;
    }
    for(int i=1;i<index;i++){
        curr=curr->getNext();
    }
    Node* next = curr->getNext();
    curr->setNext(next->getNext());
    deleted = next->getData();
    delete next;
    return deleted;
}

int LinkedList::length(){
    int length = 0;
    Node* curr = first;
    if(isCircular()) {
        length++;
        while(curr->getNext()!=first){
            length++;
            curr=curr->getNext();
        }
    }
    else{
        while(curr){
            length++;
            curr=curr->getNext();
        }
    }
    return length;
}

void LinkedList::makeCircular(){
    if(!first){return;}
    Node* curr = first;
    while(curr->getNext()){curr=(curr->getNext());}
    curr->setNext(first);
}

bool LinkedList::isCircular(){
    if(!first){return false;}
    Node* a = first;
    Node* b = first->getNext();
    while(a && b){
        if(a==b){return true;}
        a=(a->getNext());
        b=(b->getNext()->getNext());
    }
    return false;
}
