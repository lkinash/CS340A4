//
//  Stack.h
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-02.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "PuzzleNode.h"

class EmptyStack{};         //class to throw exceptions of

class Stack{                //the stack class itself
  
public:
    Stack();                //the constructor for the class
    
    PuzzleNode getTop();            //returns the node on the top of the stack
    void pop();                     //pops the top node off the stack
    void push(PuzzleNode node);         //adds a node to the top of the stack
    int getTopIndex();              //gets the number of nodes in the stack
    
private:
    PuzzleNode array[3000];         //an array of nodes to make up the stack
    int top;                    //the value that knows how many there are
};

#endif /* Stack_h */
