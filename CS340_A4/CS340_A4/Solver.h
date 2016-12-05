//
//  Solver.h
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef Solver_h
#define Solver_h

#include "PuzzleNode.h"
#include "Stack.h"
#include "Queue.h"

class Solver{
    
public:
    Solver();
    
    void depthFirstSearch();
    void breathFirstSearch();
    
    void depthNumberTiles();
    void depthNumberTilesPusher();
    
    void depthMinimumMoves();
    void depthMinimumMovesPusher();
    
    void depthH();
    void depthHPusher();
    
    void takeUserInput();
    void buildUserPuzzle();
    void userPromptBestFirst();
    
    void printSolved();
    void queueAllChildren();
    
private:
    PuzzleNode array[1000];
    PuzzleNode next;
    PuzzleNode puzzle;
    PuzzleNode best;
    PuzzleNode userPuzzle;
    PuzzleNode solved;
    Stack stack;
    Queue queue;
    
    int currentPuzzleIndex;
    int tempIndex;
};

#endif /* Solver_h */
