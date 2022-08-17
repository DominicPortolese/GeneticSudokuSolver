/**
 * Program #   : Sudoku
 * File Name   : SudokuFitness.cpp
 * Author(s)   : Spoorthi Gowda, Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Facilitates the creation and assignment of fitness values to sudoku sheets
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "SudokuFitness.h"
void SudokuFitness::duplicateTally(int& count, int duplicateArray[]) {
    //Start from 1, up to 9, counting the duplicates in each element so long as it is a duplicate. A value of 1 is not a duplicate.
    for (int i = 1; i < 10; i++) {
        if (duplicateArray[i] > 1) {
            int tempInt = duplicateArray[i];
            count += tempInt;
        }
    }
}
int SudokuFitness::howFit(Puzzle& p)
{

    // dynamic casting to handle Sudoku object
    Sudoku* sudoku = dynamic_cast<Sudoku*>(&p);
    int total = 0;


    //Loop through each column to check (if duplicate then conflicts++)
    //Reset the counter for each column
    for (int i = 0; i < 9; i++) {
        duplicates[0] = 0;
        duplicates[1] = 0;
        duplicates[2] = 0;
        duplicates[3] = 0;
        duplicates[4] = 0;
        duplicates[5] = 0;
        duplicates[6] = 0;
        duplicates[7] = 0;
        duplicates[8] = 0;
        duplicates[9] = 0;


        for (int j = 0; j < 9; j++) {
            ++duplicates[sudoku->fullVectorInts[j][i]];
        }
        duplicateTally(total, duplicates);
    }

    //Loop through each row to check (if duplicate not already found in same spot, then conflicts++)
    //Reset the counter for each row
    for (int i = 0; i < 9; i++) {
        duplicates[0] = 0;
        duplicates[1] = 0;
        duplicates[2] = 0;
        duplicates[3] = 0;
        duplicates[4] = 0;
        duplicates[5] = 0;
        duplicates[6] = 0;
        duplicates[7] = 0;
        duplicates[8] = 0;
        duplicates[9] = 0;

        for (int j = 0; j < 9; j++) {
            ++duplicates[sudoku->fullVectorInts[i][j]];
        }
        duplicateTally(total, duplicates);
    }

    //Loop through each 3x3 square to check (if duplicate not already found in same spot, then conflicts++)
    //Reset the counter for each square
    for (int k = 0; k < 9; k++) {
        int x = (k / 3) * 3;
        int y = (k % 3) * 3;
        duplicates[0] = 0;
        duplicates[1] = 0;
        duplicates[2] = 0;
        duplicates[3] = 0;
        duplicates[4] = 0;
        duplicates[5] = 0;
        duplicates[6] = 0;
        duplicates[7] = 0;
        duplicates[8] = 0;
        duplicates[9] = 0;

        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                ++duplicates[sudoku->fullVectorInts[i][j]];
            }
        }
        duplicateTally(total, duplicates);
    }
    return total;
}

