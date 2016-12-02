//
//  Queue.h
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-02.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "PuzzleNode.h"

class EmptyQueue{};

class Queue{
    
public:
    Queue();
    
    PuzzleNode getFront();
    void pop();
    void push(PuzzleNode node);
    
private:
    PuzzleNode array[1000];
    int front;
};


#endif /* Queue_h */
