/**
 * Program #   : Sudoku
 * File Name   : Compare.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs the comparing for the priority queue
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "Sudoku.h"
#include "SudokuFitness.h"
#pragma once
class Compare
{
public:
	SudokuFitness eval;
	/**
 * Function         : operator()
 * Parameters       :Sudoku* left, Sudoku* right
 * Purpose          :compares two sudoku objects' fitness values
 * Pre-Condition    :both are non-null
 * Post-Condition   :describes which fitness value is greater
 *                  :
 *                  :
 * Return Value     :bool
 * Functions Called :howfit()
 */
	bool operator()(Sudoku* left, Sudoku* right);
};