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
    top = -1;                       //initilizes the stack as being empty
}

PuzzleNode Stack::getTop(){                   //returns the node on the top of the stack
 
    if(top < 0)
        throw EmptyStack();                 //tests if the stack is empty and throws an error
    
    return array[top];              //otherwise returns the top of the stack
}

int Stack::getTopIndex(){             //returns the index of the top of the stack
    return top;
}

void Stack::pop(){                                 //pops the top node off the stack
    top--;                  //decrements the size of the stack
}

void Stack::push(PuzzleNode node){              //adds a node to the top of the stack
    top++;                          //increments the number of nodes
    array[top] = node;          //adds the node passed in onto the stack
}
    

