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
    userPuzzle[0][0] = 1;
    userPuzzle[0][1] = 3;
    userPuzzle[0][2] = 4;
    
    userPuzzle[1][0] = 6;
    userPuzzle[1][1] = 0;
    userPuzzle[1][2] = 2;
    
    userPuzzle[2][0] = 5;
    userPuzzle[2][1] = 8;
    userPuzzle[2][2] = 7;
}

void Solver::depthFirstSearch(){
    
}

void Solver::breathFirstSearch(){
    
}

void Solver::depthNumberTiles(){
    
}

void Solver::depthMinimumMoves(){
    
}

void Solver::depthH(){
    
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




