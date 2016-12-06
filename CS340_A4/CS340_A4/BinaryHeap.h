//
//  BinaryHeap.h
//  CS340_A4
//
//  NOTE: THIS CODE IS NOT MY CODE, IT WAS TAKEN FROM ANOTHER SOURCE AND MODIFIED TO WORK WITH MY CODE
//  SOURCE: https://www.codeproject.com/tips/816934/min-binary-heap-implementation-in-cplusplus
//
//  THAT SOURCE IS WHERE THE CODE FOR THIS CLASS CAME FROM, IT IS NOT MY CODE
//

#ifndef BinaryHeap_h
#define BinaryHeap_h

#include "vector"
#include "PuzzleNode.h"

using namespace std;

class MinHeap
{
private:
    PuzzleNode heap[5000];
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
    int getLength();
};

#endif /* BinaryHeap_h */
