/**
 * Program #   : Sudoku
 * File Name   : Population.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs how the Population class is interacted with
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Puzzle.h"
class Population {
	/**
 * Function         :newGeneration();
 * Parameters       :none
 * Purpose          :creates new generation
 * Pre-Condition    :none
 * Post-Condition   :new generation is established
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :makeOffspring()
 */
	virtual void newGeneration() = 0;

	/**
 * Function         :cullPopulation
 * Parameters       :none
 * Purpose          :kill off 90% of the population
 * Pre-Condition    :none
 * Post-Condition   :90% of the population is deleted and priority queue adjusts
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called :empty(), pop(), top()
 */
	virtual void cullPopulation() = 0;

	/**
 * Function         :bestFitness()
 * Parameters       :none
 * Purpose          :find the most fit sudoku
 * Pre-Condition    :population is not empty
 * Post-Condition   :the sudoku with the best fitness is revealed
 *                  :
 *                  :
 * Return Value     :Puzzle*
 * Functions Called :push(), pop(), empty()
 */
	virtual Puzzle* bestFitness() = 0;

	/**
	 * Function         :bestFitness()
	 * Parameters       :none
	 * Purpose          :find the most fit sudoku
	 * Pre-Condition    :population is not empty
	 * Post-Condition   :the sudoku with the best fitness is revealed
	 *                  :
	 *                  :
	 * Return Value     :Puzzle*
	 * Functions Called :push(), pop(), empty()
	 */
	virtual Puzzle* bestIndividual() = 0;
};
