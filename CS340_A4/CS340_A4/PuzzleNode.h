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
class Invalid{};                        //an empty class for throwing errors

const static int PUZZLE_SIZE = 3;               //the puzzle is of size 3X3

class PuzzleNode{               //the puzzle node class
    
public:
    PuzzleNode();                   //a constructor function
    
    int getH();                     //a getter for the H variable
    int getSeq();            //a getter for the seq variable
    int getTotdist();            //a getter for the total distance variable
    
    void calcH();                          //a calculator function for the H value
    void calcSeq();                    //a calculator function for the seq value
    void calcTotdist();                    //a calculator function for the total distance value
    
    void calcTilesOutOfPlace();                   //a calculator function for the tiles out of place value
    void calcMinMovesToGoal();                 //a calculator function for the min moves to goal value
    
    int getTilesOutOfPlace();                           //a getter for the tiles out of place variable
    int getMinMovesToGoal();                            //a getter for the min moves to goal variable
    
    int calcTileSeq(int i, int j);          //a calculator function for the tile sequence value
    int getDisFromHome(int i, int j);                     //a getter for the distance from home

    int getClockNext(int i, int j);                   //a getter for the next clockwise value
    int getHomeX(int num);                        //this function finds the home square in the X direction for the value passed in
    int getHomeY(int num);                    //this function finds the home square in the Y direction for the value passed in
    
    void setSquare(int i, int j, int value);            //function that sets the value in a square
    int getSquare(int i, int j);                    //function that gets the value in a square
    
    void printPuzzle();                             //function that prints the puzzle
    
    void swap(int i1, int j1, int i2, int j2);               //function that swaps the values in two squares of the puzzle
    bool isSolved();
    
    void moveHoleUp();                  //moves the hole up one square in the puzzle
    void moveHoleDown();                 //moves the hole down one square in the puzzle
    void moveHoleLeft();                 //moves the hole left one square in the puzzle
    void moveHoleRight();                 //moves the hole right one square in the puzzle
    
    bool canMoveHoleUp();             //tests if the hole can be moved up or not
    bool canMoveHoleDown();          //tests if the hole can be moved down or not
    bool canMoveHoleLeft();          //tests if the hole can be moved left or not
    bool canMoveHoleRight();          //tests if the hole can be moved right or not
    
    int findHoleI();        //finds where it whole is an returns the I value                     //a calculator function for the H value
    int findHoleJ();           //finds where it whole is an returns the J value 
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
    
    void setIndex(int newIndex);            //a setter for the index variable
    int getIndex();            //a getter for the index variable
    
    void setTestValue(char newTestValue);            //a setter for the test value variable
    int getTestValue();            //a getter for the test value variable
    
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
    char testValue;
    int index;
};

#endif /* PuzzleNode_h */
