/**
 * Program #   : Sudoku
 * File Name   : Puzzle.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how the Sudoku class is interacted with as an interface
 *
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::ostream;
using std::istream;
class Puzzle {
public:
	/**
 * Function         :makeSavedVector()
 * Parameters       :none
 * Purpose          :sets the current arrangement as the master arrangement whos numbers cannot be altered
 * Pre-Condition    :the fullVector has data in it
 * Post-Condition   :savedVector is updated to reflect the fullVector
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :none
 */
	virtual void makeSavedVector() = 0;

	/**
 * Function         :updateFullVectorInts()
 * Parameters       :none
 * Purpose          :updates fullVectorInts to reflect the eightyOneCharString
 * Pre-Condition    :eightyOneCharString is non null
 * Post-Condition   :fullVectorInts is updated
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :none
 */
	virtual void updateFullVectorInts() = 0;
};