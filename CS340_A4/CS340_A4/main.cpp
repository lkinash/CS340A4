//
//  main.cpp
//  CS340_A4
//
//  Created by Lindsey Kinash on 2016-11-29.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <iostream>
#include "Solver.h"

using namespace std;

int main() {

    //PuzzleNode node = *new PuzzleNode();
    
    //node.setHole();
    
    //node.printPuzzle();
 
    
    
    Solver solver = *new Solver();
    
    //solver.buildUserPuzzle();
    
    //solver.breathFirstSearch();
    
    //solver.depthFirstSearch();
    
    //solver.depthNumberTiles();
    
    solver.depthH();
    
    solver.printSolved();
    
    return 0;
    
}
