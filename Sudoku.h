/**
 * Program #   : Sudoku
 * File Name   : Compare.h
 * Author(s)   : Dominic Portoles, Syrus Nelson
 * Date Due    : 6/5
 * Purpose     : Governs how the sudoku class is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#ifndef SUDOKU_H
#define SUDOKU_H
class SudokuFitness;
#include "Puzzle.h"
#include "SudokuFitness.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Sudoku : public Puzzle {

public:
	//fullVectorInts is responsible for holding all the Sudoku values, not just the original data.
	vector<vector<int>> fullVectorInts;


	//savedVectorInts is responsible for keeping track of which numbers are not allowed to be changed, the ones that come with the original sudoku problem
	vector<vector<int>> savedVectorInts;

	//eightyOneCharStringMaster holds the data as one simple string
	string eightyOneCharStringMaster = "";

	/**
	 * Constructor      : Sudoku();
	 * Purpose          : to create an empty Sudoku object
	 * Pre-Condition    : constructor is called
	 * Post-Condition   : Sudoku object is created
	 * Return Value     : none
	 * Functions Called : none
	 */
	Sudoku();

	/**
	 * Constructor      : Sudoku(Sudoku& toCopy);
	 * Purpose          : to create a Sudoku deep copy
	 * Pre-Condition    : constructor is called
	 * Post-Condition   : Sudoku object is created as a deep copy
	 * Return Value     : none
	 * Functions Called : none
	 */
	Sudoku(Sudoku& toCopy);

	/**
	 * Destructor       : ~Sudoku();
	 * Purpose          : to free up the memory when deleting Sudoku
	 * Pre-Condition    : destructor is called
	 * Post-Condition   : Sudoku object is deleted
	 * Return Value     : None
	 * Functions Called : None
	 */
	~Sudoku();

	/**
 * Function         : fillSudoku()
 * Parameters       :none
 * Purpose          :fills out the string with the vector data
 * Pre-Condition    :sudoku has data
 * Post-Condition   :sudokus string is filled out correctly
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :none
 */
	void fillSudoku();

	/**
 * Function         :makeSavedVector()
 * Parameters       :none
 * Purpose          :fills the savedVector with data from the string
 * Pre-Condition    :string is non null
 * Post-Condition   :savedVector is filled
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :none
 */
	void makeSavedVector();

	/**
 * Function         :operator<<()
 * Parameters       :ostream& output, Sudoku& puzzle
 * Purpose          :outputs a legible version of the sudoku
 * Pre-Condition    :sudoku is non null
 * Post-Condition   :legible output
 *                  :
 *                  :
 * Return Value     :ostream&
 * Functions Called : none
 */
	friend ostream& operator<<(ostream& output, Sudoku& puzzle);

	/**
	* Function         :operator>>()
	* Parameters       :istream& input, Sudoku& puzzle
	* Purpose          :inputs info to create a sudoku object
	* Pre-Condition    :info is valid
	* Post-Condition   :objects exists w/ info
	*                  :
	*                  :
	* Return Value     :istream&
	* Functions Called : none
	*/
	friend istream& operator>>(istream& input, Sudoku& puzzle);

	/**
	* Function         :updateFullVectorInts()
	* Parameters       :none
	* Purpose          :updates the fullvector with the data in the string
	* Pre-Condition    :eightyOneCharString is not null
	* Post-Condition   :fullVectorInts is filled out
	*                  :
	*                  :
	* Return Value     :void
	* Functions Called :none
	*/
	void updateFullVectorInts();
};
#endif