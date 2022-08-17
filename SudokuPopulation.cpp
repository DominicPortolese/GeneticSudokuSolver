/**
 * Program #   : Sudoku
 * File Name   : SudokuPopulation.cpp
 * Author(s)   : Syrus Nelson, Dominic Portolese
 * Date Due    : 6/5
 * Purpose     : Provides a container for the sudoku objects of a generation
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "SudokuPopulation.h"
SudokuPopulation::SudokuPopulation(Sudoku& original, int populationSizeInput)
{
    currPopulation.push(&original);
    populationSize = populationSizeInput;
}

SudokuPopulation::~SudokuPopulation()
{
    while (!offspring.empty()) {
        Sudoku* temp = offspring.top();
        offspring.pop();
        delete temp;
        temp = nullptr;
    }

    // Clear out the queue when finished with it
    while (!currPopulation.empty()) {
        Sudoku* temp = currPopulation.top();
        currPopulation.pop();
        delete temp;
    }
}

priority_queue<Sudoku*, vector<Sudoku*>, Compare> SudokuPopulation::getOffspring()
{
    return offspring;
}

/*
  Run for the 10% original puzzles/original puzzle in currPopulation
  Split the mutations among those 10% evenly to get to filling up to max population size.
*/
void SudokuPopulation::newGeneration()
{
    if (currPopulation.size() == 1 && isFirst) {
        //Create an offspring Sudoku for the populationSize
        for (int original = 0; original < populationSize; original++) {
            offspring.push(reproduce.makeOffspring(*currPopulation.top()));
        }

        //Once reproduced enough times, remove it
        Sudoku* temp = currPopulation.top();
        currPopulation.pop();
        delete temp;
        temp = nullptr;
        isFirst = false;
    }
    else {
        size = populationSize;
        //tempSize is to keep track of the size so that the loop iterates for that many times without shortening/adjusting as it loops
        int tempSize = currPopulation.size();
        //For each original, non-offspring puzzle
        for (int original = 0; original < tempSize; original++) {
            //size + 1 when checking to account for odd size because of int properties
            for (int puzzle = 0; puzzle < ((size + 1) / tempSize); puzzle++) {
                offspring.push(reproduce.makeOffspring(*currPopulation.top()));
            }
            //Once reproduced enough times, remove it
            Sudoku* temp = currPopulation.top();
            currPopulation.pop();
            delete temp;
            temp = nullptr;
        }

    }
}

void SudokuPopulation::cullPopulation()
{
    int nintyPercent = populationSize * 0.9;
    for (int sudoku = 0; sudoku < nintyPercent; sudoku++) {
        Sudoku* temp = offspring.top();
        offspring.pop();
        delete temp; // Free memory to avoid memory leaks
        temp = nullptr;
    }

    //Get rid of old generation to input new generation
    while (!currPopulation.empty()) {
        Sudoku* temp = currPopulation.top();
        currPopulation.pop();
        delete temp; // Free memory to avoid memory leaks
        temp = nullptr;
    }

    int tempSize = offspring.size();
    //offspring become new parent Sudokus
    for (int sudoku = 0; sudoku < tempSize; sudoku++) {
        currPopulation.push(offspring.top());
        offspring.pop();
    }
}

Puzzle* SudokuPopulation::bestFitness()
{
    stack<Sudoku*> temp;
    Sudoku* returnVal;
    //checking to make sure there is something to be returned
    while (!offspring.empty()) {
        temp.push(offspring.top());
        offspring.pop();
    }
    returnVal = temp.top();
    while (!temp.empty()) {
        offspring.push(temp.top());
        temp.pop();
    }
    return returnVal;
}

Puzzle* SudokuPopulation::bestIndividual()
{
    stack<Sudoku*> temp;
    Sudoku* returnVal;
    //checking to make sure there is something to be returned
    while (!offspring.empty()) {
        temp.push(offspring.top());
        offspring.pop();
    }
    returnVal = temp.top();
    while (!temp.empty()) {
        offspring.push(temp.top());
        temp.pop();
    }
    return returnVal;
}