/**
 * Program #   : Sudoku
 * File Name   : Compare.cpp
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Compares sudoku fitnesses for the priority queue
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "Compare.h"
bool Compare::operator()(Sudoku* left, Sudoku* right) {
	return eval.howFit(*left) < eval.howFit(*right);
}