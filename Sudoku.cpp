/**
 * Program #   : Sudoku
 * File Name   : Sudoku.cpp
 * Author(s)   : Dominic Portolese, Syrus Nelson
 * Date Due    : 6/5
 * Purpose     : Sudoku is the container for each sudoku sheet, as well as provides functions to interact with it
 * User Input  : String representing an unsolved Sudoku puzzle
 *             :
 *             :
 *             :
 *             :
 * Output      : Close to solved Sudoku puzzle in legible ASCII format
 */
#include "Sudoku.h"

 // deep copy contructor
Sudoku::Sudoku(Sudoku& toCopy)
{
    eightyOneCharStringMaster = toCopy.eightyOneCharStringMaster;
    //filling out fullVectorInts
    vector<int> temp;
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            temp.push_back(toCopy.fullVectorInts[a][b]);
        }
        fullVectorInts.push_back(temp);
        temp.clear();
    }

    //filling out savedVectorInts
    for (int c = 0; c < 9; c++) {
        for (int d = 0; d < 9; d++) {
            temp.push_back(toCopy.savedVectorInts[c][d]);
        }
        savedVectorInts.push_back(temp);
        temp.clear();
    }
}

Sudoku::Sudoku()
{
    eightyOneCharStringMaster = "";
}

Sudoku::~Sudoku()
{ // Destructor
}

void Sudoku::fillSudoku()
{
    int size = savedVectorInts.size();

    //running for each cell
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            if (savedVectorInts[row][column] != 0) {
                continue;
            }
            fullVectorInts[row][column] = (rand() % 9) + 1;
        }
    }

    eightyOneCharStringMaster = "";

    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            //the tp_ is to adjust the char value to numerical format.
            eightyOneCharStringMaster += to_string(fullVectorInts[row][column]);
        }
    }
}


void Sudoku::updateFullVectorInts()
{
    int counter = 0;
    string temp = "";
    //running through each cell of fullVectorInts to update it with the string
    for (int a = 0; a < 9; a++) {
        vector<int> tempVec;

        for (int b = 0; b < 9; b++) {
            tempVec.push_back(stoi(eightyOneCharStringMaster.substr(counter, 1)));
            counter++;
        }
        fullVectorInts.push_back(tempVec);
    }
}

void Sudoku::makeSavedVector()
{
    int counter = 0;
    string temp = "";

    //running through each cell in savedVector to update it with the string
    for (int a = 0; a < 9; a++) {
        vector<int> tempVec;

        for (int b = 0; b < 9; b++) {
            tempVec.push_back(stoi(eightyOneCharStringMaster.substr(counter, 1)));
            counter++;
        }
        savedVectorInts.push_back(tempVec);
    }
}

ostream& operator<<(ostream& output, Sudoku& puzzle)
{
    //outputting the string in a legible format
    string input = puzzle.eightyOneCharStringMaster;
    int counter = 0;
    string toReturn = "";

    for (int a = 1; a <= 3; a++) {
        output << "+-------+-------+-------+\n";
        for (int b = 1; b <= 3; b++) {
            for (int c = 1; c <= 3; c++) {
                output << "|";
                output << " " + input.substr(counter, 1);
                counter++;
                output << " " + input.substr(counter, 1);
                counter++;
                output << " " + input.substr(counter, 1) + " ";
                counter++;
            }
            output << "|";
            output << "\n";
        }
    }

    output << "+-------+-------+-------+" << '\n' << endl;
    return output;
}

istream& operator>>(istream& input, Sudoku& puzzle)
{
    cout << "Please enter the Sudoku Puzzle in a text digit format with numbers from 0 to 9."
        << "\nWhere 0 is an empty space and the digits from 1 to 9 are fixed numbers: ";
    string inputString;
    input >> inputString;
    //checking for validity
    if (inputString.size() > 81 || inputString.size() < 81) {
        return input;
    }

    for (int character = 0; character < inputString.size(); character++) {
        if (!isdigit(inputString[character])) {
            return input;
        }
    }

    puzzle.eightyOneCharStringMaster = inputString;
    puzzle.updateFullVectorInts();
    puzzle.makeSavedVector();
    return input;
}
