//
//  main.c
//  Hashing
//
//  Created by Shawn on 1/2/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}

int probe(int H[], int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}
void Insert(int H[], int key){
    int index=hash(key);
    
    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
}

int main(int argc, const char * argv[]) {
    int HT[10] = {0};
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    
    return 0;
}

int Search(int H[], int key){
    int index=hash(key);
    
    int i=0;
    
    while(H[(index+i)%SIZE])
        i++;
    return (index+i)%SIZE;
}
