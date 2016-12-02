//
//  Queue.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-02.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

Queue::Queue(){
    front = -1;
}

PuzzleNode Queue::getFront(){
    
    if(front < 0)
        throw EmptyQueue();
    
    return array[front];
}

void Queue::pop(){
    front--;
}

void Queue::push(PuzzleNode node){
 
    front++;
    for(int i = front; i > 0; i++)
        array[i] = array[i-1];
    
    array[0] = node;
}
