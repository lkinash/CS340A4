//
//  Solver.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "Solver.h"
#include <iostream>

using namespace std;

Solver::Solver(){
    
    userPuzzle.setSquare(0, 0, 1);
    userPuzzle.setSquare(0, 1, 3);
    userPuzzle.setSquare(0, 2, 4);
    
    userPuzzle.setSquare(1, 0, 8);
    userPuzzle.setSquare(1, 1, 0);
    userPuzzle.setSquare(1, 2, 2);
    
    userPuzzle.setSquare(2, 0, 7);
    userPuzzle.setSquare(2, 1, 6);
    userPuzzle.setSquare(2, 2, 5);
    
    puzzle = userPuzzle;
    puzzle.setHole();
    
    currentPuzzleIndex = 0;
    
    array[currentPuzzleIndex] = puzzle;
    
    array[currentPuzzleIndex].setHole();
    
    tempIndex = 0;
}

void Solver::depthFirstSearch(){
    
    if(puzzle.isSolved()){
        solved = puzzle;
        return;
    }
    
    
    if(puzzle.canMoveHoleLeft() && ((puzzle.getLastMove() != 0) || (puzzle.getLastMove() == -1)))
    {
        stack.push(puzzle);
        puzzle.moveHoleLeft();
        puzzle.setDepth((puzzle.getDepth() + 1));
        puzzle.printPuzzle();
        depthFirstSearch();
        puzzle = stack.getTop();
        stack.pop();
    }
    
    
}

void Solver::breathFirstSearch(){
 
    
    queue.push(array[currentPuzzleIndex]);
    
    while(queue.getFrontIndex() >= 0){
    
        if(queue.getFront().isSolved()){
            solved = queue.getFront();
            return;
        }
      
        queue.getFront().printPuzzle();
        
        queue.pop();
        
        currentPuzzleIndex++;
        
        queueAllChildren();
    }
}

void Solver::queueAllChildren(){
    
    if((array[currentPuzzleIndex].canMoveHoleUp()) && ((array[currentPuzzleIndex].getLastMove() != 270)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleUp();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setUpChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
        queue.push(array[tempIndex]);
    }
    
    if((array[currentPuzzleIndex].canMoveHoleDown()) && ((array[currentPuzzleIndex].getLastMove() != 90)||(array[currentPuzzleIndex].getLastMove() == -1))){

        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleDown();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setDownChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
        queue.push(array[tempIndex]);
    }
    
    if((array[currentPuzzleIndex].canMoveHoleLeft()) && ((array[currentPuzzleIndex].getLastMove() != 180)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleLeft();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setLeftChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
        queue.push(array[tempIndex]);
    }
    
    if((array[currentPuzzleIndex].canMoveHoleRight()) && ((array[currentPuzzleIndex].getLastMove() != 0)||(array[currentPuzzleIndex].getLastMove() == -1))){

        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleRight();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setRightChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
        queue.push(array[tempIndex]);
    }
}

void Solver::depthNumberTiles(){
 
    stack.push(array[currentPuzzleIndex]);
 
    while(stack.getTopIndex() >= 0){
    
        depthNumberTilesPusher();
    
        currentPuzzleIndex = tempIndex;
    
        stack.getTop().printPuzzle();
        
        if(stack.getTop().isSolved()){
            solved = stack.getTop();
        }
    }
}

void Solver::depthNumberTilesPusher(){
    
    if((array[currentPuzzleIndex].canMoveHoleUp()) && ((array[currentPuzzleIndex].getLastMove() != 270)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleUp();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setUpChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
    }
    
    if((array[currentPuzzleIndex].canMoveHoleDown()) && ((array[currentPuzzleIndex].getLastMove() != 90)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleDown();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setDownChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
    }
    
    if((array[currentPuzzleIndex].canMoveHoleLeft()) && ((array[currentPuzzleIndex].getLastMove() != 180)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleLeft();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setLeftChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
    }
    
    if((array[currentPuzzleIndex].canMoveHoleRight()) && ((array[currentPuzzleIndex].getLastMove() != 0)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleRight();
        array[tempIndex].setParent(currentPuzzleIndex);
        array[currentPuzzleIndex].setRightChild(tempIndex);
        array[currentPuzzleIndex].incrementChildCount();
    }
    
    stack.getTop().calcTilesOutOfPlace();
    
    int up = -1, down = -1, left = -1, right = -1, stackValue =  stack.getTop().getTilesOutOfPlace();
    
    if(array[currentPuzzleIndex].getUpChild() != -1){
        array[array[currentPuzzleIndex].getUpChild()].calcTilesOutOfPlace();
        up = array[array[currentPuzzleIndex].getUpChild()].getTilesOutOfPlace();
    }
    
    if(array[currentPuzzleIndex].getDownChild() != -1){
        array[array[currentPuzzleIndex].getDownChild()].calcTilesOutOfPlace();
        down = array[array[currentPuzzleIndex].getDownChild()].getTilesOutOfPlace();
    }
    
    if(array[currentPuzzleIndex].getRightChild() != -1){
        array[array[currentPuzzleIndex].getRightChild()].calcTilesOutOfPlace();
        right = array[array[currentPuzzleIndex].getRightChild()].getTilesOutOfPlace();
    }
    
    if(array[currentPuzzleIndex].getLeftChild() != -1){
        array[array[currentPuzzleIndex].getLeftChild()].calcTilesOutOfPlace();
        left = array[array[currentPuzzleIndex].getLeftChild()].getTilesOutOfPlace();
    }
    
    if(stackValue < up && stackValue < down && stackValue < left && stackValue < right)
        return;
    
    else if(up >= down && up >= left && up >= right){
        stack.push(array[array[currentPuzzleIndex].getUpChild()]);
        if(down >= left && down >= right){
            stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            if(left >= right)
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(left >= down && left >= right){
            stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            if(down >= right)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(right >= down && right >= left){
            stack.push(array[array[currentPuzzleIndex].getRightChild()]);
            if(down >= left)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
        }
    }
            
    else if(down >= up && down >= left && down >= right){
        stack.push(array[array[currentPuzzleIndex].getDownChild()]);
        if(up >= left && up >= right){
            stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            if(left >= right)
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(left >= up && left >= right){
            stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            if(up >= right)
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(right >= up && right >= left){
            stack.push(array[array[currentPuzzleIndex].getRightChild()]);
            if(up >= left)
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
        }
    }
    
    else if(right >= down && right >= left && right >= up){
        stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        if(down >= left && down >= up){
            stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            if(left >= up)
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
        }
        else if(left >= down && left >= up){
            stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
            if(down >= up)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
        }
        else if(up >= down && up >= left){
            stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            if(down >= left)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
        }
    }
    
    else if(left >= down && left >= up && left >= right){
        stack.push(array[array[currentPuzzleIndex].getLeftChild()]);
        if(down >= up && down >= right){
            stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            if(up >= right)
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(up >= down && up >= right){
            stack.push(array[array[currentPuzzleIndex].getUpChild()]);
            if(down >= right)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getRightChild()]);
        }
        else if(right >= down && right >= up){
            stack.push(array[array[currentPuzzleIndex].getRightChild()]);
            if(down >= up)
                stack.push(array[array[currentPuzzleIndex].getDownChild()]);
            else
                stack.push(array[array[currentPuzzleIndex].getUpChild()]);
        }
    }
    
    
    
    
}

void Solver::depthMinimumMoves(){
    
}

void depthMinimumMoves(){
    
}

void Solver::depthH(){
    
    stack.push(puzzle);
    
    while(1){
        
        depthHPusher();
        
        puzzle = stack.getTop();
        stack.pop();
        
        puzzle.printPuzzle();
        
        if(puzzle.isSolved()){
            solved = puzzle;
            return;
        }
    }
    
}

void Solver::depthHPusher(){
 
    int bestH = 10000;
    
    if((puzzle.canMoveHoleUp()) && ((puzzle.getLastMove() != 270)||(puzzle.getLastMove() == -1))){
    
        next = puzzle;
        next.moveHoleUp();
        next.calcH();
        
        if(next.getH() < bestH){
            best = next;
            bestH = next.getH();
        }
    }
    
    if((puzzle.canMoveHoleDown()) && ((puzzle.getLastMove() != 90)||(puzzle.getLastMove() == -1))){
        
        next = puzzle;
        next.moveHoleDown();
        next.calcH();
        
        if(next.getH() < bestH){
            best = next;
            bestH = next.getH();
        }
    }
    
    if((puzzle.canMoveHoleLeft()) && ((puzzle.getLastMove() != 180)||(puzzle.getLastMove() == -1))){
        
        next = puzzle;
        next.moveHoleLeft();
        next.calcH();
        
        if(next.getH() < bestH){
            best = next;
            bestH = next.getH();
        }
    }
    
    if((puzzle.canMoveHoleRight()) && ((puzzle.getLastMove() != 0)||(puzzle.getLastMove() == -1))){
        
        next = puzzle;
        next.moveHoleRight();
        next.calcH();
        
        if(next.getH() < bestH){
            best = next;
            bestH = next.getH();
        }
    }
   
    stack.push(best);
}

void Solver::printSolved(){         //prints the puzzle that is set as solved to test if it is solved
    
    solved.printPuzzle();           //calls the print function for the solved node
}

void Solver::takeUserInput(){
    
    string input;               //some variables used to take in the value from the user are created
    int num;
    
    while(1){                   //a loop is created so that the user can do more than one thing to the heap
        cout << "Enter a number to select the strategy for solving the puzzle: " << endl;         //prompts to tell the user which number entered calls which function are printed
        cout << "Enter 1 for depth first search, enter 2 for breath first search, enter 3 for best first search" <<endl;
        cout << "Enter 0 to exit these options" << endl;
        cout << "Enter the number here: " ;                 //the user is prompted to enter a number and a list of options is printed out with numbers for each
        
        cin >> num;                                     //the users desired action is taken is as a number
        getline(cin, input);                    //a getline is done so there are no errors later if the user entered anythign extra
        
        if(num == 0)                            //if the number is 0 then then the user wants to exit the program so this breaks out of the loop
            break;
        
        if(num == 1){
            depthFirstSearch();
            break;
        }
        else if(num == 2){
            breathFirstSearch();
            break;
        }
        else if(num == 3){
            userPromptBestFirst();
            break;
        }
    }
    return;
}

void Solver::userPromptBestFirst(){
    
    string input;               //some variables used to take in the value from the user are created
    int num;
    
    while(1){                   //a loop is created so that the user can do more than one thing to the heap
        cout << "Enter a number to select which of the best first strategies to use for solving the puzzle: " << endl;         //prompts to tell the user which number entered calls which function are printed
        cout << "Enter 1 for depth in the search space + number of tiles out of place, enter 2 for depth in the search space + minimum number of moves to reach the goal state., enter 3 for  depth in the search space + the heuristic H " <<endl;
        cout << "Enter 0 to exit these options" << endl;
        cout << "Enter the number here: " ;                 //the user is prompted to enter a number and a list of options is printed out with numbers for each
        
        cin >> num;                                     //the users desired action is taken is as a number
        getline(cin, input);                    //a getline is done so there are no errors later if the user entered anythign extra
        
        if(num == 0)                            //if the number is 0 then then the user wants to exit the program so this breaks out of the loop
            break;
        
        if(num == 1){
            depthNumberTiles();
            break;
        }
        else if(num == 2){
            depthMinimumMoves();
            break;
        }
        else if(num == 3){
            depthH();
            break;
        }
    }
}

void Solver::buildUserPuzzle(){
    
    string input;               //some variables used to take in the value from the user are created
    int num;
    PuzzleNode userNode = *new PuzzleNode();
    
    cout << "To fill the puzzle you will need to enter number starting at the top left corner. For the spot where there is no tile enter a 0. The program assumes you will not enter two tile of the same number." << endl;
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){
                       //a loop is created so that the user can do more than one thing to the heap
        cout << "Enter a number to fill tile (" << i << ", " << j << ") here: " << endl;
        
        cin >> num;                                     //the users desired action is taken is as a number
        getline(cin, input);                    //a getline is done so there are no errors later if the user entered anythign extra
        
        if(num < 9 && num >= 0)
            userNode.setSquare(i, j, num);
        else
            while(1){
                cout << "That number is not valid, the number must be between 0 and 8." << endl;
                cout << "Enter a number to fill tile (" << i << ", " << j << ") here: " << endl;
        
                cin >> num;                                     //the users desired action is taken is as a number
                getline(cin, input);                    //a getline is done so there are no errors later if the user entered anythign extra
        
                if(num < 9 && num >= 0){
                    userNode.setSquare(i, j, num);
                    break;
                }
            }
        }
    }
    cout << "The following is the puzzle you entered: " << endl;
    userNode.printPuzzle();

    //takeUserInput();
}


