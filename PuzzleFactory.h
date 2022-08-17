/**
 * Program #   : Sudoku
 * File Name   : PuzzleFactory.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how PuzzleFactory is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Puzzle.h"
class PuzzleFactory {
public:
	/**
 * Function         :createPuzzle()
 * Parameters       :Puzzle& inputPuzzle
 * Purpose          :creates the first puzzle
 * Pre-Condition    :none
 * Post-Condition   :the first puzzle is created
 *                  :
 *                  :
 * Return Value     :Puzzle*
 * Functions Called :dynamic_cast()
 */
	virtual Puzzle* createPuzzle(Puzzle& inputPuzzle) = 0;
};