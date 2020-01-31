//
//  main.c
//  permutation
//
//  Created by Shawn on 12/1/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <stdio.h>

void perm(char s[], int k);

int main(int argc, const char * argv[]) {
    // insert code here...

    char s[] = "abcdefg";
    perm(s, 0);
    return 0;
}



void perm(char s[], int k){
    static char A[10] = {0};
    static char res[10] = {0};
    
    
    if(s[k]=='\0'){
        res[k] = '\n';
        printf(" %s", res);
    }
    else{
        for(int i=0; s[i]!='\0'; i++){
            if(A[i]==0){
                res[k] = s[i];
                A[i] = 1;
                perm(s, k+1);
                A[i] = 0;
            }
        }
    }
    
}
