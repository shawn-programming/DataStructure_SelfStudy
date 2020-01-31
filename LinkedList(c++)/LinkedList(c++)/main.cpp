//
//  main.cpp
//  LinkedList(c++)
//
//  Created by Shawn on 12/4/19.
//  Copyright © 2019 Shawn. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

using namespace std;


int main() {
    
    int A[5] = {1,2,3,4,5};
    LinkedList first(A,5);
    first.insert(5, 100);
    first.display();
    first.deleteI(5);
    first.display();
    cout<<first.length()<<endl;
    first.makeCircular();
    cout<<first.isCircular()<<endl;
    first.display();
    first.insert(0,123);
    first.display();
    return 0;
}
