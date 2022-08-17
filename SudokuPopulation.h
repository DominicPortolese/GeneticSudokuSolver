/**
 * Program #   : Sudoku
 * File Name   : SudokuPopulation.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how SudokuPopulation is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
class Sudoku;
class SudokuOffspring;
#include "Population.h"
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include "Compare.h"
#include <stack>
#include <queue>
using std::priority_queue;
class SudokuPopulation : public Population {

	/**
	 * Function         : compare()
	 * Parameters       :Sudoku& first, Sudoku& second
	 * Purpose          : compares the two sudoku's fitness scores to determine which is larger
	 * Pre-Condition    : both sudokus are non null
	 * Post-Condition   : the lower sudoku fitness value is revealed
	 *                  :
	 *                  :
	 * Return Value     : bool
	 * Functions Called : howFit()
	 */
	auto compare(Sudoku& first, Sudoku& second);

	priority_queue<Sudoku*, vector<Sudoku*>, Compare> offspring;
	priority_queue<Sudoku*, vector<Sudoku*>, Compare> currPopulation;
	int populationSize; //create comparable priority_queue object
	int size;
	bool isFirst = true;
	SudokuOffspring reproduce;

public:

	/**
	 * Constructor      : SudokuPopulation(Sudoku& original, int populationSizeInput);
	 * Purpose          : to create a SudokuPopulation object
	 * Pre-Condition    : constructor is called
	 * Post-Condition   : object is created
	 * Return Value     : none
	 * Functions Called : none
	 */
	SudokuPopulation(Sudoku& original, int populationSizeInput);

	/**
	 * Destructor       : ~SudokuPopulation();
	 * Purpose          : to free up memory
	 * Pre-Condition    : destructor is called
	 * Post-Condition   : SudokuPopulation object is deleted
	 * Return Value     : none
	 * Functions Called : none
	 */
	~SudokuPopulation();

	/**
	 * Function         :newGeneration()
	 * Parameters       :none
	 * Purpose          : fills offspring with the new generation of sudokus
	 * Pre-Condition    : old generation is non null
	 * Post-Condition   : the new generation is filled
	 *                  :
	 *                  :
	 * Return Value     : void
	 * Functions Called : makeOffspring(), push(), top(), pop()
	 */
	void newGeneration();

	/**
	 * Function         :	priority_queue<Sudoku*, vector<Sudoku*>, Compare> getOffspring();
	 * Parameters       : none
	 * Purpose          : to return the offspring priority queue
	 * Pre-Condition    : function is called
	 * Post-Condition   : returns the offspring priority queue
	 * Return Value     : priority_queue<Sudoku*, vector<Sudoku*>, Compare>
	 * Functions Called : none
	 */
	priority_queue<Sudoku*, vector<Sudoku*>, Compare> getOffspring();

	/**
	 * Function         :cullPopulation()
	 * Parameters       :none
	 * Purpose          : deletes the worst 90% of the population
	 * Pre-Condition    : none
	 * Post-Condition   : the population is reduced to its best 10%
	 *                  :
	 *                  :
	 * Return Value     : void
	 * Functions Called : top(), pop()
	 */
	void cullPopulation();

	/**
	 * Function         :bestFitness()
	 * Parameters       :none
	 * Purpose          : returns the bestFit sudoku
	 * Pre-Condition    : the population is not null
	 * Post-Condition   : the best fit sudoku is returned
	 *                  :
	 *                  :
	 * Return Value     : Puzzle*
	 * Functions Called : empty(), push(), top(), pop()
	 */
	Puzzle* bestFitness();

	/**
	 * Function         :bestIndividual()
	 * Parameters       :none
	 * Purpose          : returns the bestFit sudoku
	 * Pre-Condition    : the population is not null
	 * Post-Condition   : the best fit sudoku is returned
	 *                  :
	 *                  :
	 * Return Value     : Puzzle*
	 * Functions Called : empty(), push(), top(), pop()
	 */
	Puzzle* bestIndividual();
};