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

class OutOfBounds{};                        //an empty class for throwing errors

const static int PUZZLE_SIZE = 3;               //the puzzle is of size 3X3

class PuzzleNode{               //the puzzle node class
    
public:
    PuzzleNode();                   //a constructor function
    
    int getH();
    int getSeq();
    int getTotdist();
    
    void calcH();
    void calcSeq();
    void calcTotdist();
    
    void calcTilesOutOfPlace();
    void calcMinMovesToGoal();
    
    int getTilesOutOfPlace();
    int getMinMovesToGoal();
    
    int calcTileSeq(int i, int j);
    int getDisFromHome(int i, int j);

    int getClockNext(int i, int j);
    int getHomeX(int num);
    int getHomeY(int num);
    
    void setSquare(int i, int j, int value);
    int getSquare(int i, int j);
    
    void printPuzzle();
    
    void swap(int i1, int j1, int i2, int j2);               //function that swaps the values in two squares of the puzzle
    bool isSolved();
    
    void moveHoleUp();
    void moveHoleDown();
    void moveHoleLeft();
    void moveHoleRight();
    
    bool canMoveHoleUp();
    bool canMoveHoleDown();
    bool canMoveHoleLeft();
    bool canMoveHoleRight();
    
    int findHoleI();
    int findHoleJ();
    void setHole();            //a setter for the hole variable that calculates where they are
    void setHole(int i, int j);            //a setter for the hole variable
    
    void setDepth(int newDepth);            //a setter for the depth variable
    int getDepth();            //a getter for the depth variable
    void setLastMove(int move);            //a setter for the last move variable
    int getLastMove();            //a getter for the last move variable

    void setParent(int newParent);            //a setter for the parent variable
    int getParent();            //a getter for the parent variable
    
    void setLeftChild(int newLeftChild);            //a setter for the left child variable
    int getLeftChild();            //a getter for the left child variable
    
    void setRightChild(int newRightChild);            //a setter for the right child variable
    int getRightChild();            //a getter for the right child variable
  
    void setDownChild(int newDownChild);            //a setter for the Down child variable
    int getDownChild();            //a getter for the down child variable
    
    void setUpChild(int newUpChild);            //a setter for the Up child variable
    int getUpChild();            //a getter for the Up child variable
    
    void incrementChildCount();       //increments the child count for that puzzle node
    
private:
    int puzzle [PUZZLE_SIZE][PUZZLE_SIZE];          //the puzzle array
    int H, seq, totdist;                    //variables for functionality
    int holeI, holeJ;
    int lastMove;                       //the variable to show what the last move was
    int depth;
    int parent, childCount;                 //variables for the parent node and the children's locations
    int leftChild, rightChild, upChild, downChild;
    int tilesOutOfPlace;                        //the tiles out of place variable and min moves to the goal
    int minMovesToGoal;
};

#endif /* PuzzleNode_h */
