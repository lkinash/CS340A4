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

class Stack{
  
public:
    Stack();
    
    PuzzleNode getTop();
    void pop();
    void push(PuzzleNode node);
    int getTopIndex();
    
private:
    PuzzleNode array[1000];
    int top;
};

#endif /* Stack_h */
