//
//  PuzzleNode.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "PuzzleNode.h"

PuzzleNode::PuzzleNode(){           //the constructor for the puzzle node class
    
    puzzle[0][0] = 1; puzzle[0][1] = 3; puzzle[0][2] = 4;        //the puzzle as an test puzzle is set
    
    puzzle[1][0] = 8; puzzle[1][1] = 0; puzzle[1][2] = 2;       //with a zero where the hole is
    
    puzzle[2][0] = 7; puzzle[2][1] = 6; puzzle[2][2] = 5;       //and all the other values set
    
    H = 0; totdist = 0; seq = 0;            //the H, total distance and seq are set at 0
    lastMove = -1; depth = 0;           //the last move is set at -1
    parent = -1;
    leftChild = -1; rightChild = -1; upChild = -1; downChild = -1;          //the parent and all of the children are set to -1
    childCount = 0;             //child count is set to 0
    tilesOutOfPlace = -1;
    minMovesToGoal = -1;            //the tiles out of place and min moves to goal are set to -1
    
}

void PuzzleNode::calcH(){                            //a calculator function for the H value
    
    H = totdist + ( 3 * seq );          //the H value is calculated and set
}

void PuzzleNode::calcSeq(){                     //a calculator function for the Seq value
 
    int total = 0;                          //a temporary variable is set
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] != 0)
                total += calcTileSeq(i, j);     //the value for each tile's seq are added together
        }
    }
    seq = total;                   //sets the value calcuated to the variable
}

int PuzzleNode::calcTileSeq(int i, int j){                     //a calculator function for the tile sequence value
 
    if(i == 1 && j == 1)                    //if it is the middle it returns a 1
        return 1;

    int next = getClockNext(i, j);          //the value of what should be next is gotten
    int puzzleNumber = puzzle[i][j];            //the value of the tile is set

    if(puzzleNumber < 8 && ((puzzleNumber + 1) == next))        //if the next is right or for that tile then 1 is returned
        return 0;
    if(puzzleNumber == 8 && next == 1)          //if the value that comes after 8 is 1 that is correct too
        return 0;
    else
        return 2;                       //if the clockwise next is not right then 2 is returned
}

int PuzzleNode::getClockNext(int i, int j){         //gets the
    
    if(i == 1 && j == 1)
        throw OutOfBounds();                //if the value is not a valid value it throws an error
    
    if(i == 0 && j < 2)
        return puzzle[i][j + 1];      //if the next is just to the left, return the node to the left
    if(i == 2 && j > 0)
        return puzzle[i][j - 1];    //if the next is just to the right, return the node to the right
    if(i < 2 && j == 2)
        return puzzle[i + 1][j];    //if the next is just to the below, return the node to the below
    if(i > 0 && j == 0)
        return puzzle[i - 1][j];    //if the next is just to the above, return the node to the above
    else
        throw OutOfBounds();
}

void PuzzleNode::calcTotdist(){                      //a calculator function for the total distance value
    
    int total = 0;                          //a temporary value is set
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] != 0)
                total += getDisFromHome(i, j);      //the distance from home is added to the total each time
        }
    }
    totdist = total;                   //sets the value calcuated to the variable
}

int PuzzleNode::getDisFromHome(int i, int j){           //this function finds and returns the distance from home for a single tile
    
    int puzzleNumber = puzzle[i][j];                //the number at that square is found
    
    if(getHomeX(puzzleNumber) == j && getHomeY(puzzleNumber) == i)          //if the node is home then 0 is returned
        return 0;
    else
        return (abs(getHomeX(puzzleNumber) - j) + abs(getHomeY(puzzleNumber) - i));     //returns the distance from home by the x plus the y distance
}

bool PuzzleNode::isSolved(){        //function that tests if the puzzle is completely solved
 
    calcSeq();
    calcTotdist();              //calls the functions to calculate the seq, total distance and H value
    calcH();
    
    if((H + totdist + seq) == 0 )           //tests if it is solved
        return true;
    else
        return false;           //return false if not and true if it is
}

bool PuzzleNode::canMoveHoleUp(){           //tests if the hole can be moved up or not
    
    if(holeI <= 0)                      //if the hole value is in a position that is at the edge it can not be moved and false is returned
        return false;
    else
        return true;                //otherwise it is in a position where it could be moved and true is returned
}

bool PuzzleNode::canMoveHoleDown(){          //tests if the hole can be moved down or not

    if(holeI >= 2)
        return false;                     //if the hole value is in a position that is at the edge it can not be moved and false is returned
    else
        return true;                //otherwise it is in a position where it could be moved and true is returned
}

bool PuzzleNode::canMoveHoleLeft(){          //tests if the hole can be moved left or not
    
    if(holeJ <= 0)                     //if the hole value is in a position that is at the edge it can not be moved and false is returned
        return false;
    else
        return true;                //otherwise it is in a position where it could be moved and true is returned
}

bool PuzzleNode::canMoveHoleRight(){          //tests if the hole can be moved right or not
    
    if(holeJ >= 2)                     //if the hole value is in a position that is at the edge it can not be moved and false is returned
        return false;
    else
        return true;                //otherwise it is in a position where it could be moved and true is returned
}

void PuzzleNode::moveHoleUp(){                   //moves the hole up one square in the puzzle

    if(!canMoveHoleUp())
        throw OutOfBounds();                 //first tests if the hole can be moved that direction and throws an error if not
    
    swap(holeI, holeJ, (holeI - 1), holeJ);     //swaps the hole and the new spot for the hole and then sets the new hole values
    setHole(holeI - 1, holeJ);
    lastMove = 90;                                       //then sets the value for the last move
}

void PuzzleNode::moveHoleDown(){                 //moves the hole down one square in the puzzle
    
    if(!canMoveHoleDown())
        throw OutOfBounds();                 //first tests if the hole can be moved that direction and throws an error if not
    
    swap(holeI, holeJ, (holeI + 1), holeJ);    //swaps the hole and the new spot for the hole and then sets the new hole values
    setHole(holeI + 1, holeJ);
    lastMove = 270;                                  //then sets the value for the last move
}

void PuzzleNode::moveHoleLeft(){                 //moves the hole left one square in the puzzle
    
    if(!canMoveHoleLeft())
        throw OutOfBounds();                 //first tests if the hole can be moved that direction and throws an error if not
    
    swap(holeI, holeJ, holeI, (holeJ - 1));    //swaps the hole and the new spot for the hole and then sets the new hole values
    setHole(holeI , holeJ - 1);
    lastMove = 180;                              //then sets the value for the last move

}

void PuzzleNode::moveHoleRight(){                 //moves the hole right one square in the puzzle
    
    if(!canMoveHoleRight())
        throw OutOfBounds();                    //first tests if the hole can be moved that direction and throws an error if not
    
    swap(holeI, holeJ, holeI, (holeJ + 1));    //swaps the hole and the new spot for the hole and then sets the new hole values
    
    setHole(holeI , holeJ + 1);
    lastMove = 0;                   //then sets the value for the last move

}

int PuzzleNode::findHoleI(){                   //finds where it whole is an returns the I value
    
    for(int i = 0; i < PUZZLE_SIZE; i++)
        for(int j = 0; j < PUZZLE_SIZE; j++)          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] == 0)
                return i;                       //returns if the hole is found
    
    return 0;               //returns 0 if it is not found
}

int PuzzleNode::findHoleJ(){                           //finds where it whole is an returns the J value 
    
    for(int i = 0; i < PUZZLE_SIZE; i++)
        for(int j = 0; j < PUZZLE_SIZE; j++)          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] == 0)
                return j;                                   //returns if the hole is found
    
    return 0;              //returns 0 if it is not found
}

void PuzzleNode::setHole(){          //sets the hole variables
 
    holeI = findHoleI();            //calls the find functions and then sets the variables
    holeJ = findHoleJ();
}

void PuzzleNode::setHole(int i, int j){             //sets the hole variables
    
    holeI = i;              //sets the hole values based on the values passed in
    holeJ = j;
    
}

void PuzzleNode::printPuzzle(){                 //prints out the current puzzle
    
    cout << "|-----------|" << endl ;           //prints out some formatting for a nice look
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        cout << "| ";
        for(int j = 0; j < PUZZLE_SIZE; j++){          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] != 0)
                cout << puzzle[i][j] << " | ";      //prints out the puzzle square value
            else
                cout << "  | ";          //prints out some formatting for a nice look
        }
        
        cout << endl << "|-----------|" << endl ;          //prints out some formatting for a nice look
    }
    cout << endl;                       //prints out some formatting for a nice look    
}

void PuzzleNode::calcTilesOutOfPlace(){                          //a calculator function for the tiles out of place value
    
    int total = 0;                              //a temporary value is set
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){          //double nested for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] != 0){
                if(getDisFromHome(i, j) > 0)            //then tests if is not at home and increments the total if it is
                    total++;
            }
        }
    }
    tilesOutOfPlace = total;                   //sets the value calcuated to the variable
}

void PuzzleNode::calcMinMovesToGoal(){                       //a calculator function for the move to goal value
 
    int total = 0;                              //sets a temporary value
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){           //double for loops are used to go through all the squares in the puzzle
            if(puzzle[i][j] != 0)
                total += getDisFromHome(i, j);
        }
    }
    minMovesToGoal = total;             //sets the value calcuated to the variable
}

void PuzzleNode::swap(int i1, int j1, int i2, int j2){          //function that swaps the values in two squares of the puzzle
    int temp = puzzle[i1][j1];
    puzzle[i1][j1] = puzzle[i2][j2];                    //a temporary value is used to switch the two tiles in the puzzle
    puzzle[i2][j2] = temp;
}

void PuzzleNode::setSquare(int i, int j, int value){                   //a setter for a square in the puzzle
    puzzle[i][j] = value;
}

int PuzzleNode::getSquare(int i, int j){                   //a getter for the value of a square
    return puzzle[i][j];
}

int PuzzleNode::getTilesOutOfPlace(){                   //a getter for the tiles out of place variable
    return tilesOutOfPlace;
}

int PuzzleNode::getMinMovesToGoal(){                   //a getter for the min moves to goal variable
    return minMovesToGoal;
}

int PuzzleNode::getH(){                   //a getter for the H variable
    return H;
}

int PuzzleNode::getSeq(){                   //a getter for the sequence variable
    return seq;
}

int PuzzleNode::getTotdist(){                   //a getter for the total distance variable
    return totdist;
}

void PuzzleNode::setDepth(int newDepth){                   //a setter for the depth variable
    depth = newDepth;
}

int PuzzleNode::getDepth(){                   //a getter for the depth variable
    return depth;
}

void PuzzleNode::setLastMove(int move){                   //a setter for the last move variable
    lastMove = move;
}

int PuzzleNode::getLastMove(){                   //a getter for the last move variable
    return lastMove;
}

void PuzzleNode::setParent(int newParent){                   //a setter for the parent variable
    parent = newParent;
}

int PuzzleNode::getParent(){                   //a getter for the parent variable
    return parent;
}

void PuzzleNode::setLeftChild(int newLeftChild){                   //a getter for the left child variable
    leftChild = newLeftChild;
}

int PuzzleNode::getLeftChild(){                   //a setter for the left child variable
    return leftChild;
}

void PuzzleNode::setRightChild(int newRightChild){                   //a setter for the right child variable
    rightChild = newRightChild;
}

int PuzzleNode::getRightChild(){                   //a getter for the right child variable
    return upChild;
}

void PuzzleNode::setDownChild(int newDownChild){                   //a setter for the down child variable
    downChild = newDownChild;
}

int PuzzleNode::getDownChild(){                   //a getter for the down child variable
    return downChild;
}

void PuzzleNode::setUpChild(int newUpChild){              //a setter for the Up child variable
    upChild = newUpChild;
}

int PuzzleNode::getUpChild(){                     //a getter for the Up child variable
    return upChild;
}

void PuzzleNode::incrementChildCount(){       //increments the child count for that puzzle node
    childCount++;
}

int PuzzleNode::getHomeX(int num){                 //this function finds the home square in the X direction for the value passed in
    
    if(num > 8 || num < 1)                         //checks that the number is within the limits of numbers
        throw OutOfBounds();
    
    switch(num) {                    //enter the switch statement and it will return the correct value for the value passed in
        case 1 :
            return 0;
            break;
        case 2 :
            return 1;
            break;
        case 3 :
            return 2;
            break;
        case 4 :
            return 2;
            break;
        case 5 :
            return 2;
            break;
        case 6 :
            return 1;
            break;
        case 7 :
            return 0;
            break;
        case 8 :
            return 0;
            break;
        default :
            throw OutOfBounds();                          //throws an error if it is not a valid value
    }
    
}

int PuzzleNode::getHomeY(int num){          //this function finds the home square in the Y direction for the value passed in
    
    if(num > 8 || num < 1)
        throw OutOfBounds();            //checks that the number is within the limits of numbers
    
    switch(num) {               //enter the switch statement and it will return the correct value for the value passed in
        case 1 :
            return 0;
            break;
        case 2 :
            return 0;
            break;
        case 3 :
            return 0;
            break;
        case 4 :
            return 1;
            break;
        case 5 :
            return 2;
            break;
        case 6 :
            return 2;
            break;
        case 7 :
            return 2;
            break;
        case 8 :
            return 1;
            break;
        default :
            throw OutOfBounds();                //throws an error if it is not a valid value
    }
}

