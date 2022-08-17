/**
 * Program #   : Sudoku
 * File Name   : SudokuFactory.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how SudokuFactory is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Sudoku.h"
class SudokuFactory : public PuzzleFactory {
public:

	/**
 * Function         :createPuzzle()
 * Parameters       :Puzzle& inputPuzzle
 * Purpose          :creates a new sudoku object as a copy to the old one
 * Pre-Condition    :the old one is not null
 * Post-Condition   :a new sudoku is created
 *                  :
 *                  :
 * Return Value     :Puzzle*
 * Functions Called :sudoku() copy constructor
 */
	Puzzle* createPuzzle(Puzzle& inputPuzzle);

	/**
	 * Destructor       : ~SudokuFactory();
	 * Purpose          : to free up memory
	 * Pre-Condition    : destructor has been called
	 * Post-Condition   : SudokuFactory object is deleted
	 * Return Value     : none
	 * Functions Called : none
	 */
	~SudokuFactory();

};