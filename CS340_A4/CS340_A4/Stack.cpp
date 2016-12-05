//
//  Stack.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-02.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>

#include "Stack.h"

Stack::Stack(){
    top = -1;
}

PuzzleNode Stack::getTop(){
 
    if(top < 0)
        throw EmptyStack();
    
    return array[top];
}

int Stack::getTopIndex(){             //returns the index of the top of the stack
    return top;
}

void Stack::pop(){
    top--;
}

void Stack::push(PuzzleNode node){
    top++;
    array[top] = node;
}
    

