/**
 * Program #   : Sudoku
 * File Name   : SudokuFactory.cpp
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Facilitates the creation of new Sudokus
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "SudokuFactory.h"
Puzzle* SudokuFactory::createPuzzle(Puzzle& inputPuzzle)
{
	//Dynamic cast then call the deep copy constructor
	Sudoku* copy = dynamic_cast<Sudoku*>(&inputPuzzle);
	return new Sudoku(*copy);
}
SudokuFactory::~SudokuFactory()
{
}