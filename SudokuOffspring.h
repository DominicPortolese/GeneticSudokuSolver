/**
 * Program #   : Sudoku
 * File Name   : SudokuOffspring.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how SudokuOffspring is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Reproduction.h"
#include "Sudoku.h"
#include "SudokuFactory.h"
class SudokuOffspring : public Reproduction {
	SudokuFactory factory;

	/**
	 * Function         :mutate()
	 * Parameters       :Puzzle& original
	 * Purpose          : changes the values of the numbers in the cells of the sudoku
	 * Pre-Condition    : none
	 * Post-Condition   : some of the cells have changed values
	 *                  :
	 *                  :
	 * Return Value     : void
	 * Functions Called : rand()
	 */
	void mutate(Puzzle& original);

public:
	/**
	 * Function         :makeOffspring()
	 * Parameters       :Puzzle& original
	 * Purpose          : makes offspring in the image of the original passed into it
	 * Pre-Condition    : original needs to be non null
	 * Post-Condition   : an offspring is created and returned
	 *                  :
	 *                  :
	 * Return Value     : Sudoku*
	 * Functions Called : dynamic_cast(), mutate()
	 */
	Sudoku* makeOffspring(Puzzle& original);
};