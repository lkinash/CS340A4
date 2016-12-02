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

class Solver{
    
public:
    Solver();
    
    void depthFirstSearch();
    void breathFirstSearch();
    void depthNumberTiles();
    void depthMinimumMoves();
    void depthH();
    
    void takeUserInput();
    void buildUserPuzzle();
    void userPromptBestFirst();
    
private:
    PuzzleNode puzzle;
    PuzzleNode next;
    PuzzleNode userPuzzle;
    PuzzleNode solved;
    
};

#endif /* Solver_h */
