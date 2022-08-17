/**
 * Program #   : Sudoku
 * File Name   : SudokuFitness.h
 * Author(s)   : Spoorthi Gowda, Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how SudokuFitness is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#ifndef SUDOKUFITNESS_H
#define SUDOKUFITNESS_H
 //class Sudoku;
#include "Fitness.h"
#include "Puzzle.h"
#include "Sudoku.h"
class SudokuFitness : public Fitness {
public:
	//To keep track of duplicates where each element number corresponds to the Sudoku square value. The 0th element is ignored.
	int duplicates[10] = { 0 };

	/**
 * Function         :howFit()
 * Parameters       :Puzzle& p
 * Purpose          :howFit determines a puzzle's fitness score, meaning how closely it follows the rules for sudoku
 * Pre-Condition    :the puzzle is populated with data
 * Post-Condition   :the score is revealed and returned
 *                  :
 *                  :
 * Return Value     :int
 * Functions Called :dynamic_cast(), duplicateTally()
 */
	int howFit(Puzzle& p);

	/**
	 * Function         : duplicateTally()
	 * Parameters       :int& count, int duplicateArray[]
	 * Purpose          : keeps track of the number of duplicant entries a number has in the sudoku
	 * Pre-Condition    : none
	 * Post-Condition   : updates the count with the number of duplicants
	 *                  :
	 *                  :
	 * Return Value     : void
	 * Functions Called : none
	 */
	void duplicateTally(int& count, int duplicateArray[]);
};
#endif