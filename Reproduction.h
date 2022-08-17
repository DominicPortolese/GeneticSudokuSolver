/**
 * Program #   : Sudoku
 * File Name   : Reproduction.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how the reproduction class is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Puzzle.h"
class Reproduction {
	/**
 * Function         :  mutate()
 * Parameters       :Puzzle& original
 * Purpose          :mutates the cells in the sudoku sheet at random
 * Pre-Condition    :non-null sudoku sheet
 * Post-Condition   :some of the cells may have changed
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :rand(), to_string(), size()
 */
	virtual void mutate(Puzzle& original) = 0;

	/**
 * Function         :makeOffspring()
 * Parameters       :Puzzle& original
 * Purpose          :makes offspring based on the input puzzle
 * Pre-Condition    :input puzzle is not null
 * Post-Condition   :more sudokus are made in the image of the input puzzle
 *                  :
 *                  :
 * Return Value     :Puzzle*
 * Functions Called :mutate()
 */
	virtual Puzzle* makeOffspring(Puzzle& original) = 0;
};