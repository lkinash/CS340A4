//
//  BinaryHeap.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-12-05.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "BinaryHeap.h"

MinHeap::MinHeap(PuzzleNode* array, int index)
{
    for(int i = 0; i < index; ++i)
    {
        heap[i] = array[i];
    }
    length = index;
    Heapify();
}

MinHeap::MinHeap()
{
    length = -1;
    Heapify();
}


void MinHeap::Heapify()
{
    for(int i=length-1; i>=0; --i)
    {
        BubbleDown(i);
    }
}

void MinHeap::BubbleDown(int index)
{
    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;
    
    if(leftChildIndex >= length)
        return; //index is a leaf
    
    int minIndex = index;
    
    if(heap[index].getTestValue() > heap[leftChildIndex].getTestValue())
    {
        minIndex = leftChildIndex;
    }
    
    if((rightChildIndex < length) && (heap[minIndex].getTestValue() > heap[rightChildIndex].getTestValue()))
    {
        minIndex = rightChildIndex;
    }
    
    if(minIndex != index)
    {
        //need to swap
        PuzzleNode temp = heap[index];
        heap[index] = heap[minIndex];
        heap[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

void MinHeap::BubbleUp(int index)
{
    if(index == 0)
        return;
    
    int parentIndex = (index-1)/2;
    
    if(heap[parentIndex].getTestValue() > heap[index].getTestValue())
    {
        PuzzleNode temp = heap[parentIndex];
        heap[parentIndex] = heap[index];
        heap[index] = temp;
        BubbleUp(parentIndex);
    }
}

void MinHeap::Insert(PuzzleNode newValue)
{
    length++;
    heap[length] = newValue;
    BubbleUp(length);
}

PuzzleNode MinHeap::GetMin()
{
    return heap[0];
}

void MinHeap::DeleteMin()
{
    if(length == 0)
    {
        return;
    }
    
    heap[0] = heap[length-1];
    length--;
    
    BubbleDown(0);
}
