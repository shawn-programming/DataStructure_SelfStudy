//
//  main.c
//  Hash
//
//  Created by Shawn on 1/1/20.
//  Copyright © 2020 Shawn. All rights reserved.
//

#include <stdio.h>
#include "Chains.h"

int hash(int key){
    return key%10;
}

void Insert(struct Node *H[], int key){
    int index=hash(key);
    SortedInsert(&H[index], key);
}

int main(int argc, const char * argv[]) {
    struct Node *HT[10];
    int i;
    
    for(i=0;i<10;i++)
        HT[i]=NULL;
    
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    
    struct Node *temp = Search(HT[hash(22)], 22);
    printf("%d ", temp->data);
    return 0;
}
