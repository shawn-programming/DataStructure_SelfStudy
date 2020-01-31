//
//  main.cpp
//  Stack_LinkedListCPP
//
//  Created by Shawn on 12/22/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=NULL;}
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL){cout<<"Stack is FULL";}
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    int x=-1;
    if(top==NULL){cout<<"Stack is Empty\n";}
    else{
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    Stack stk;
    
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    stk.Display();
    cout<<stk.pop();
    return 0;
}
