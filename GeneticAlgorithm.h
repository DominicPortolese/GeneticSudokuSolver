/**
 * Program #   : Sudoku
 * File Name   : GeneticAlgorithm.h
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Governs the interactions for the GeneticAlgorithm class
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#pragma once
#include "Sudoku.h"
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
class GeneticAlgorithm {
    string userInput;
    int populationSize = 50;
    int numberGenerations;
    SudokuFitness fitness;

public:
    Sudoku* original;

    /**
     * Constructor      : GeneticAlgorithm(int populationSizeInput, int numberGenerationsInput);
     * Purpose          : to create a Genetric Algorithm object from command line input of main()
     * Pre-Condition    : constructor is called
     * Post-Condition   : GeneticAlgorithm object is created
     * Return Value     : none
     * Functions Called : none
     */
    GeneticAlgorithm(int populationSizeInput, int numberGenerationsInput);

    /**
 * Function         :geneticAlgorithm()
 * Parameters       :none
 * Purpose          :Runs for numberGenerations in a for loop and inputs populationSize into the newGeneration Population method
 * Pre-Condition    :pop size and generations are >0
 * Post-Condition   :new generations established
 *                  :
 *                  :
 * Return Value     :void
 * Functions Called : cullPopulation(), reproduce()
 */
    void geneticAlgorithm();

};