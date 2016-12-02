//
//  PuzzleNode.h
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef PuzzleNode_h
#define PuzzleNode_h

#include <stdlib.h>     
#include <iostream>

using namespace std;

class OutOfBounds{};

const static int PUZZLE_SIZE = 3;

class PuzzleNode{
    
public:
    PuzzleNode();
    
    int getH();
    int getSeq();
    int getTotdist();
    
    void calcH();
    void calcSeq();
    void calcTotdist();
    
    int calcTileSeq(int i, int j);
    int getDisFromHome(int i, int j);

    int getClockNext(int i, int j);
    int getHomeX(int num);
    int getHomeY(int num);
    
    void setSquare(int i, int j, int value);
    int getSquare(int i, int j);
    
    void printPuzzle();
    
private:
    int puzzle [PUZZLE_SIZE][PUZZLE_SIZE];
    int H;
    int seq;
    int totdist;
    
};

#endif /* PuzzleNode_h */