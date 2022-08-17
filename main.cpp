/**
 * Program #   : Sudoku
 * File Name   : main.cpp
 * Author(s)   : Syrus Nelson
 * Date Due    : 6/5
 * Purpose     : To act as the driver for the program
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */

#pragma once
#include "GeneticAlgorithm.h"

 /**
  * Function         : int main(int argc, char* argv[]);
  * Parameters       : int argc, char* argv[]
  * Purpose          : To handle the command line input and facilitate solving the puzzle
  * Pre-Condition    : program is executed
  * Post-Condition   : Upon entering valid input, a Sudoku puzzle is returned in visual format, close to the solution.
  * Return Value     : int
  * Functions Called : isdigit(), stoi(), runAlgorithm
  */
int main(int argc, char* argv[])
{ //Arg 1 is population size, arg2 is number of generations
    /*
  //Check input size
    if (argc < 3 || argc > 3) {
        cout << "Entered incorrect number of arguments, please enter two integer values." << endl;
        cout << "Terminating program..." << endl;
        exit(0);
    }

    //Check if the input is a digit
    if (!isdigit(*argv[1]) || !isdigit(*argv[2])) {
        cout << "Entered incorrect value type, please enter two integer values." << endl;
        cout << "Terminating program..." << endl;
        exit(0);
    }
     */
   // int populationSize = std::stoi(argv[1]);
   // int generations = std::stoi(argv[2]);
    int populationSize = 2000;
    int generations = 18;
    //Check for input of 0
    if (populationSize <= 0 || generations <= 0) {
        cout << "Entered invalid parameters, please make sure you have entered values greater than zero." << endl;
        cout << "Terminating program..." << endl;
        exit(0);
    }
   
    //Create and run the algorithm
    GeneticAlgorithm runAlgorithm(populationSize, generations);
    runAlgorithm.geneticAlgorithm();
    return 0;
};