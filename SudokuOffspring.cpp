/**
 * Program #   : Sudoku
 * File Name   : SudokuOffspring.cpp
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Facilitates the creation of new offspring via mutation
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "SudokuOffspring.h"
Sudoku* SudokuOffspring::makeOffspring(Puzzle& original)
{
    Sudoku* returnPuzzle = dynamic_cast<Sudoku*>(factory.createPuzzle(original));
    mutate(*returnPuzzle);
    return returnPuzzle;
}
void SudokuOffspring::mutate(Puzzle& original)
{
    Sudoku* mutated = dynamic_cast<Sudoku*>(&original);

    //For each non-fixed square, attempt to mutate with a 2% chance.
    for (int row = 0; row < mutated->savedVectorInts.size(); row++) {

        for (int column = 0; column < mutated->savedVectorInts[row].size(); column++) {

            //running for each cell in savedVectorInts to verify whether or not it is allowed to be edited
            if (((rand() % 100) + 1) >= 98) {

                if (mutated->savedVectorInts[row][column] != 0) {
                    continue;
                }
                mutated->fullVectorInts[row][column] = ((rand() % 9) + 1);
            }
        }
    }

    mutated->eightyOneCharStringMaster = "";
    for (int row = 0; row < mutated->savedVectorInts.size(); row++) {
        for (int column = 0; column < mutated->savedVectorInts.size(); column++) {
            //the to_string is to adjust the char value to numerical format.
            mutated->eightyOneCharStringMaster += to_string(mutated->fullVectorInts[row][column]);
        }
    }
}