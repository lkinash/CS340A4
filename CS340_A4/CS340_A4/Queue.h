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

class EmptyQueue{};         //class to throw exceptions of

class Queue{            //the queue clas
    
public:
    Queue();                //a constructor for the queue
    
    PuzzleNode getFront();          //gets the front node
    void pop();                     //pops the front node off the queue
    void push(PuzzleNode node);     //pushes a node into the queue
    
    int getFrontIndex();                //gets the number of nodes in the queue
    
private:
    PuzzleNode array[3000];         //the queue is an array of puzzle nodes
    int front;                  //front tracks the nodes in the queue
};


#endif /* Queue_h */
