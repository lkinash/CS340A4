//
//  BinaryHeap.h
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-05.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef BinaryHeap_h
#define BinaryHeap_h

#include "vector"
#include "PuzzleNode.h"

using namespace std;

class MinHeap
{
private:
    PuzzleNode heap[1000];
    int length;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();
    
public:
    MinHeap(PuzzleNode* array, int length);
    MinHeap();
    
    void Insert(PuzzleNode newValue);
    PuzzleNode GetMin();
    void DeleteMin();
};

#endif /* BinaryHeap_h */
