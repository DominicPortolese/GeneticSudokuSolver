/**
 * Program #   : Sudoku
 * File Name   : GeneticAlgorithm.cpp
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Facilitates the mutation of the sudoku sheets
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "GeneticAlgorithm.h"

void GeneticAlgorithm::geneticAlgorithm()
{
    //0. Ask for user input of 81 char string of digits from 0-9
    //1. Ask Population for bestFitness
    //2. Ask Population to cullPopulation
    //3. Ask Population to reproduce
    //4. Repeat for numberGenerations
    //5. Ask Population for bestIndividual and output it

    original = new Sudoku();
    cin >> *original;

    //checking for invalid input
    if (original->eightyOneCharStringMaster.empty()) {
        cout << "You have entered an invalid puzzle format." << endl;
        cout << "Please re-run the program." << endl;
        delete original;
        original = nullptr;
        exit(0);
    }


    cout << "Starting Sudoku Puzzle:\n" << *original;
    original->fillSudoku();
    SudokuPopulation* currentPopulation = new SudokuPopulation(*original, populationSize);

    //running for each generation
    for (int generation = 0; generation < numberGenerations; generation++) { //4.

        if (currentPopulation->getOffspring().empty()) {
            //To avoid checking fitness when offspring is empty
        }
        //checking to see if the sudoku has been solved early
        else if (fitness.howFit(*currentPopulation->bestFitness()) == 0) { //1.
            cout << "Here is the Sudoku solution:\n" <<
                currentPopulation->bestFitness();
            break;
        }

        //We don't kill the only Sudoku in the zeroth generation
        if (generation > 0) {
            currentPopulation->cullPopulation(); //2.
        }
        currentPopulation->newGeneration(); //4.
    }

    Sudoku* sudoku = dynamic_cast<Sudoku*>(currentPopulation->bestIndividual());
    cout << "Here is the Sudoku puzzle with the best overall fitness:\n" << *sudoku; //5.
    delete currentPopulation;
    currentPopulation = nullptr;
    original = nullptr;
}
GeneticAlgorithm::GeneticAlgorithm(int populationSizeInput, int numberGenerationsInput)
{
    populationSize = populationSizeInput;
    numberGenerations = numberGenerationsInput;
}