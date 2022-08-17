/**
 * Program #   : Sudoku
 * File Name   : Fitness.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs the interactions for the Fitness class
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Puzzle.h"
class Fitness {
	/**
 * Function         :howfit()
 * Parameters       :Puzzle& p
 * Purpose          :determines how "fit" a sudoku sheet is by analyzing how many of its cells do not follow sudoku rules
 * Pre-Condition    :p is a non-null puzzle
 * Post-Condition   :the fitness number of the sheet is revealed
 *                  :
 *                  :
 * Return Value     :int
 * Functions Called :dynamic_cast(), duplicateTally
 */
	virtual int howFit(Puzzle& p) = 0;
};