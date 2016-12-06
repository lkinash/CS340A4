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
    /*
    userPuzzle.setSquare(0, 0, 1);
    userPuzzle.setSquare(0, 1, 3);
    userPuzzle.setSquare(0, 2, 4);
    
    userPuzzle.setSquare(1, 0, 8);
    userPuzzle.setSquare(1, 1, 0);
    userPuzzle.setSquare(1, 2, 2);
    
    userPuzzle.setSquare(2, 0, 7);
    userPuzzle.setSquare(2, 1, 6);
    userPuzzle.setSquare(2, 2, 5);
    
    */
    userPuzzle.setSquare(0, 0, 2);
    userPuzzle.setSquare(0, 1, 8);
    userPuzzle.setSquare(0, 2, 3);
    
    userPuzzle.setSquare(1, 0, 1);
    userPuzzle.setSquare(1, 1, 6);
    userPuzzle.setSquare(1, 2, 4);
    
    userPuzzle.setSquare(2, 0, 7);
    userPuzzle.setSquare(2, 1, 0);
    userPuzzle.setSquare(2, 2, 5);
   /*
    
    userPuzzle.setSquare(0, 0, 2);
    userPuzzle.setSquare(0, 1, 1);
    userPuzzle.setSquare(0, 2, 6);
    
    userPuzzle.setSquare(1, 0, 4);
    userPuzzle.setSquare(1, 1, 0);
    userPuzzle.setSquare(1, 2, 8);
    
    userPuzzle.setSquare(2, 0, 7);
    userPuzzle.setSquare(2, 1, 5);
    userPuzzle.setSquare(2, 2, 3);
    */
    puzzle = userPuzzle;
    puzzle.setHole();
    
    currentPuzzleIndex = 0;
    
    array[currentPuzzleIndex] = puzzle;
    
    array[currentPuzzleIndex].setHole();
    
    tempIndex = 0;
}

void Solver::printSolvedPathLoop(int index){
    
    if(index == -1)
        return;
    
    printSolvedPathLoop(array[index].getParent());
    array[index].printPuzzle();
    stepCounter++;
    
}

void Solver::printSolvedPath(){
    
    stepCounter = 0;
    
    printSolvedPathLoop(solved.getParent());
    printSolved();
    
    cout << "Puzzle solved in " << stepCounter << " steps" << endl;
}

void Solver::depthFirstSearch(){
    
    stack.push(array[currentPuzzleIndex]);
    
    while(stack.getTopIndex() >= 0){
        
        if(stack.getTop().isSolved()){
            solved = stack.getTop();
            return;
        }
 
        stack.pop();
        
        stackAllChildren();
    
        currentPuzzleIndex++;
    }
}

void Solver::stackAllChildren(){
        
    
    if((array[currentPuzzleIndex].canMoveHoleUp()) && ((array[currentPuzzleIndex].getLastMove() != 270)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleUp();
        array[tempIndex].setParent(currentPuzzleIndex);
        
        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setUpChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            stack.push(array[tempIndex]);
        }
        else
            tempIndex--;
            
    }
    
    if((array[currentPuzzleIndex].canMoveHoleDown()) && ((array[currentPuzzleIndex].getLastMove() != 90)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleDown();
        array[tempIndex].setParent(currentPuzzleIndex);

        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setDownChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            stack.push(array[tempIndex]);
        }
        else
            tempIndex--;
    }
    
    if((array[currentPuzzleIndex].canMoveHoleLeft()) && ((array[currentPuzzleIndex].getLastMove() != 180)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleLeft();
        array[tempIndex].setParent(currentPuzzleIndex);

        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setLeftChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            stack.push(array[tempIndex]);
        }
        else
            tempIndex--;
    }
    
    if((array[currentPuzzleIndex].canMoveHoleRight()) && ((array[currentPuzzleIndex].getLastMove() != 0)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleRight();
        array[tempIndex].setParent(currentPuzzleIndex);

        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setRightChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            stack.push(array[tempIndex]);
        }
        else
            tempIndex--;
    }
    
    
}

void Solver::breathFirstSearch(){
 
    
    queue.push(array[currentPuzzleIndex]);
    
    while(queue.getFrontIndex() >= 0){
    
        if(queue.getFront().isSolved()){
            solved = queue.getFront();
            return;
        }
        
        queue.pop();
        
        queueAllChildren();
        
        currentPuzzleIndex++;
    }
}

void Solver::queueAllChildren(){
    
    if((array[currentPuzzleIndex].canMoveHoleUp()) && ((array[currentPuzzleIndex].getLastMove() != 270)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleUp();
        array[tempIndex].setParent(currentPuzzleIndex);
 
        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setUpChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            queue.push(array[tempIndex]);
        }
        else
            tempIndex--;
    }
    
    if((array[currentPuzzleIndex].canMoveHoleDown()) && ((array[currentPuzzleIndex].getLastMove() != 90)||(array[currentPuzzleIndex].getLastMove() == -1))){

        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleDown();
        array[tempIndex].setParent(currentPuzzleIndex);
        
        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setUpChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            queue.push(array[tempIndex]);
        }
        else
            tempIndex--;    }
    
    if((array[currentPuzzleIndex].canMoveHoleLeft()) && ((array[currentPuzzleIndex].getLastMove() != 180)||(array[currentPuzzleIndex].getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleLeft();
        array[tempIndex].setParent(currentPuzzleIndex);
        
        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setUpChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            queue.push(array[tempIndex]);
        }
        else
            tempIndex--;    }
    
    if((array[currentPuzzleIndex].canMoveHoleRight()) && ((array[currentPuzzleIndex].getLastMove() != 0)||(array[currentPuzzleIndex].getLastMove() == -1))){

        tempIndex++;
        array[tempIndex] = array[currentPuzzleIndex];
        array[tempIndex].moveHoleRight();
        array[tempIndex].setParent(currentPuzzleIndex);
        
        if(!alreadyExists(tempIndex)){
            array[currentPuzzleIndex].setUpChild(tempIndex);
            array[currentPuzzleIndex].incrementChildCount();
            queue.push(array[tempIndex]);
        }
        else
            tempIndex--;
    }
}

void Solver::depthNumberTiles(){
 
}

void Solver::depthNumberTilesPusher(){
    
  
    
}

void Solver::depthMinimumMoves(){
    
    
    
}

void depthMinimumMoves(){
    
}

void Solver::depthH(){
    
    array[currentPuzzleIndex].setTestValue('h');
    array[currentPuzzleIndex].setIndex(currentPuzzleIndex);
    
    heap.Insert(array[currentPuzzleIndex]);
    
    while(heap.getLength() >= 0){
        
        if(heap.GetMin().isSolved()){
            solved = heap.GetMin();
            return;
        }
        
        heap.DeleteMin();
        
        depthHPusher();
    
    }
    
}

void Solver::depthHPusher(){
    
    
    if((heap.GetMin().canMoveHoleUp()) && ((heap.GetMin().getLastMove() != 270)||(heap.GetMin().getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = heap.GetMin();
        array[tempIndex].moveHoleUp();
        array[tempIndex].setIndex(tempIndex);
        array[tempIndex].setTestValue('h');
        array[tempIndex].setParent(heap.GetMin().getIndex());
        
        if(!alreadyExists(tempIndex)){
            array[heap.GetMin().getIndex()].setUpChild(tempIndex);
            array[heap.GetMin().getIndex()].incrementChildCount();
            heap.Insert(array[tempIndex]);
            array[tempIndex].printPuzzle();
        }
        else
            tempIndex--;
        
    }
    
    if((heap.GetMin().canMoveHoleDown()) && ((heap.GetMin().getLastMove() != 90)||(heap.GetMin().getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[heap.GetMin().getIndex()];
        array[tempIndex].moveHoleDown();
        array[tempIndex].setIndex(tempIndex);
        array[tempIndex].setTestValue('h');
        array[tempIndex].setParent(heap.GetMin().getIndex());
        
        if(!alreadyExists(tempIndex)){
            array[heap.GetMin().getIndex()].setDownChild(tempIndex);
            array[heap.GetMin().getIndex()].incrementChildCount();
            heap.Insert(array[tempIndex]);
              array[tempIndex].printPuzzle();
        }
        else
            tempIndex--;
    }
    
    if((heap.GetMin().canMoveHoleLeft()) && ((heap.GetMin().getLastMove() != 180)||(heap.GetMin().getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[heap.GetMin().getIndex()];
        array[tempIndex].moveHoleLeft();
        array[tempIndex].setIndex(tempIndex);
        array[tempIndex].setTestValue('h');
        array[tempIndex].setParent(heap.GetMin().getIndex());
        
        if(!alreadyExists(tempIndex)){
            array[heap.GetMin().getIndex()].setLeftChild(tempIndex);
            array[heap.GetMin().getIndex()].incrementChildCount();
            heap.Insert(array[tempIndex]);
              array[tempIndex].printPuzzle();
        }
        else
            tempIndex--;
    }
    
    if((heap.GetMin().canMoveHoleRight()) && ((heap.GetMin().getLastMove() != 0)|| (heap.GetMin().getLastMove() == -1))){
        
        tempIndex++;
        array[tempIndex] = array[heap.GetMin().getIndex()];
        array[tempIndex].moveHoleRight();
        array[tempIndex].setIndex(tempIndex);
        array[tempIndex].setTestValue('h');
        array[tempIndex].setParent(heap.GetMin().getIndex());
        
        if(!alreadyExists(tempIndex)){
            array[heap.GetMin().getIndex()].setRightChild(tempIndex);
            array[heap.GetMin().getIndex()].incrementChildCount();
            heap.Insert(array[tempIndex]);
            array[tempIndex].printPuzzle();
        }
        else
            tempIndex--;
    }
    
    
}

bool Solver::alreadyExists(int index){
    
    int temp = array[index].getParent();
    
    while(1){
        
        temp = (array[temp].getParent());
        
        if(temp != -1){
            if(arePuzzleTheSame(index, temp))
                return true;
        }
        else if(temp == -1){
            return false;
        }
    }
    return false;
}

bool Solver::arePuzzleTheSame(int index1, int index2){
    
    for(int i = 0; i < PUZZLE_SIZE; i++){
        for(int j = 0; j < PUZZLE_SIZE; j++){          //double nested for loops are used to go through all the squares in the puzzle
            if(array[index1].getSquare(i, j) != array[index2].getSquare(i, j))
                return false;
        }
    }
    
    return true;
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
        
        if(num == 1){                   //if the selection is for depth first search
            depthFirstSearch();         //calls the depth first search
            break;
        }
        else if(num == 2){                  //if the selection was a 2
            breathFirstSearch();            //that is selecting a breath first search
            break;
        }
        else if(num == 3){                      //the user selected a best first search
            userPromptBestFirst();              //then the user prompt to pick which of the best first searches to do is called
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
        
        if(num < 9 && num >= 0)                         //checks that the number entered is a valid number
            userNode.setSquare(i, j, num);          //addes that number to the square if it is
        else
            while(1){
                cout << "That number is not valid, the number must be between 0 and 8." << endl;            //tells the user if they entered a value that is
                cout << "Enter a number to fill tile (" << i << ", " << j << ") here: " << endl;            //not a valiid number
        
                cin >> num;                                     //the users desired action is taken is as a number
                getline(cin, input);                    //a getline is done so there are no errors later if the user entered anythign extra
        
                if(num < 9 && num >= 0){                    //checks that the number entered is a valid number
                    userNode.setSquare(i, j, num);              //addes that number to the square if it is
                    break;
                }
            }
        }
    }
    cout << "The following is the puzzle you entered: " << endl;            //prints out the user puzzle for the user
    userNode.printPuzzle();

    takeUserInput();
}


