//
//  LinkedList.hpp
//  LinkedList(c++)
//
//  Created by Shawn on 12/4/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

class Node{
private:
    int data;
    Node* next;
public:
    Node(int data, Node* next=NULL);
    int getData();
    Node* getNext();
    void setData(int data);
    void setNext(Node* next);
};

class LinkedList{
private:
    Node* first;
public:
    LinkedList(){first=NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();
    
    void display();
    
    
    void insert(int index, int x);
    int deleteI(int index);
    int length();
    void makeCircular();
    bool isCircular();
};

#endif /* LinkedList_hpp */
