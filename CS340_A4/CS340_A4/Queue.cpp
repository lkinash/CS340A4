//
//  Queue.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-02.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

Queue::Queue(){         //a constructor for the queue
    front = -1;             //set the front at 0 when the queue is created
}

PuzzleNode Queue::getFront(){
    
    if(front < 0)
        throw EmptyQueue();         // if the queue is trying to be accessed but is empty throw an error 
    
    return array[front];            //returns the first node in the queue
}

void Queue::pop(){      //pops the front node off the queue
    front--;            //decrement number of nodes in the queue
}

void Queue::push(PuzzleNode node){      //pushes a node into the queue
 
    front++;                        //increments the number of nodes in the queue
    
    if(front > 0){
        for(int i = front; i > 0; i--)          //cycle through the queue moving each node forward one
            array[i] = array[i-1];
    }
    
    array[0] = node;            //adds the new node as the first node in the array
}

int Queue::getFrontIndex(){
    return front;                     //returns the index of the front of the queue
}
