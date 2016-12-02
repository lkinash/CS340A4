//
//  PuzzleNode.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "PuzzleNode.h"

PuzzleNode::PuzzleNode(){
    
    puzzle[0][0] = 1;
    puzzle[0][1] = 3;
    puzzle[0][2] = 4;
    
    puzzle[1][0] = 8;
    puzzle[1][1] = 0;
    puzzle[1][2] = 2;
    
    puzzle[2][0] = 7;
    puzzle[2][1] = 6;
    puzzle[2][2] = 5;
    
    H = 0;
    totdist = 0;
    seq = 0;
}

void PuzzleNode::calcH(){
    
    H = totdist + ( 3 * seq );
}

void PuzzleNode::calcSeq(){
 
    int total = 0;
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){
            if(puzzle[i][j] != 0)
                total += calcTileSeq(i, j);
        }
    }
    seq = total;
    
    cout << "Total Seq: " << total << endl;
    
}

int PuzzleNode::calcTileSeq(int i, int j){
 
    if(i == 1 && j == 1)
        return 1;

    int next = getClockNext(i, j);
    int puzzleNumber = puzzle[i][j];

    if(puzzleNumber < 8 && ((puzzleNumber + 1) == next))
        return 0;
    
    if(puzzleNumber == 8 && next == 1)
        return 0;
    
    else
        return 2;
}

int PuzzleNode::getClockNext(int i, int j){
    
    if(i == 1 && j == 1)
        throw OutOfBounds();
    
    if(i == 0 && j < 2)
        return puzzle[i][j + 1];
    if(i == 2 && j > 0)
        return puzzle[i][j - 1];
    if(i < 2 && j == 2)
        return puzzle[i + 1][j];
    if(i > 0 && j == 0)
        return puzzle[i - 1][j];
    else
        throw OutOfBounds();
}

void PuzzleNode::calcTotdist(){
    
    int total = 0;
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){
            if(puzzle[i][j] != 0)
                total += getDisFromHome(i, j);
        }
    }
    totdist = total;
    
    cout << "Total Distance: " << total << endl;
}

int PuzzleNode::getDisFromHome(int i, int j){
    
    int puzzleNumber = puzzle[i][j];
    
    if(getHomeX(puzzleNumber) == j && getHomeY(puzzleNumber) == i)
        return 0;
    else
        return (abs(getHomeX(puzzleNumber) - j) + abs(getHomeY(puzzleNumber) - i));
}

int PuzzleNode::getHomeX(int num){
    
    if(num > 8 || num < 1)
        throw OutOfBounds();
 
    switch(num) {
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
            throw OutOfBounds();
    }
    
}

int PuzzleNode::getHomeY(int num){
    
    if(num > 8 || num < 1)
        throw OutOfBounds();
    
    switch(num) {
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
            throw OutOfBounds();
    }
}

void PuzzleNode::printPuzzle(){
    
    cout << "|-----------|" << endl ;
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        cout << "| ";
        for(int j = 0; j < PUZZLE_SIZE; j++){
            if(puzzle[i][j] != 0)
                cout << puzzle[i][j] << " | ";
            else
                cout << "  | ";
        }
        
        cout << endl << "|-----------|" << endl ;
    }
    
}

void PuzzleNode::setSquare(int i, int j, int value){
    puzzle[i][j] = value;
}

int PuzzleNode::getSquare(int i, int j){
    return puzzle[i][j];
}

int PuzzleNode::getH(){
    return H;
}

int PuzzleNode::getSeq(){
    return seq;
}

int PuzzleNode::getTotdist(){
    return totdist;
}
