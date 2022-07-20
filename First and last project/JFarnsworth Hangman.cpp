/*************************************************************************************
James Farnsworth
Programming 1
Jan 14, 2018
Hangman Project
*************************************************************************************/


//liberies
#include <iostream> //for input and output

#include <math.h> //can do things like rooting or pow

#include <iomanip> //move the header with setw

#include <ctime> //time

#include <cstdlib> // random srand and rand

#include <fstream> //header file for files

#include <string> //header file for strings

using namespace std; //here to stop needing to type std:: before every cout and cin statement

//CREATE DASHES FUNCTION
string create_Dashes(string copy_puzzle)
{
    string dash_string = copy_puzzle;
            for (int i = 0; i < copy_puzzle.length(); i++)
                dash_string[i] = '_';

            return dash_string;
}

/*this function has 2 parameters the string with the current letters
that have been inputed and the current letter guessed
it check the string to see if there are more than one in the string (meaning a duplicate has found
) it returns true if there is a duplicate and false if not*/

//CHECK LETTER FUNCTION
bool checkLetter(string guessed, char letter)
{
     bool found = false;
     int total = 0;

     //loops through each character of the string totaling how many times it finds the current letter

     for (int i = 0; i < guessed.length(); i++){
         if (guessed[i] == letter )
            total++;
     }
     //if the current letter is found more than once then it is a duplicate and found
     //is set to true
     if (total > 1)
        found = true;

     return found;
}

    /*function printPuzzle
    Loads and track winning puzzle
    This function takes 2 parameters the completed puzzle and the solution puzzle
    it loads the correct letters into the solution puzzle replacing Underlines
    with the correct letters.
    If the puzzle underlines have all been replaced with the correct letters
    the puzzle is solved and a message is printed.*/

    //REPLACES UNDERLINES WITH CORRECT LETTERS
    void printPuzzle(string passed)
    {
        //assumes all letters are correct
        int winner = 1;

        //check the letters to make sure they are input and not underlines
        //if it finds an underline it knows the puzzle is not solved and sets
        //"winner" to 0 indicating so
        for (int g = 0; g < passed.length(); g++)
        {
            if(passed[g] == '_')
                winner = 0;
        }

        //reprints the puzzle
        for (int i = 0; i < passed.length(); i++)
        {
            cout << passed[i] << " ";
        }
        cout << endl;

        //if all letters are input prints message
        if (winner == 1)
            cout << "You won, great job" << endl;
    }

    /*
    Function printHangman
    prints and tracks incorrect guesses
    This function takes 2 parameters, the solution puzzle and the number of incorrect guesses
    If the guess was incorrect it prints the current unsolved puzzle then
    the associated gallows based on how many incorrect guesses
    */

    void printHangman(int count)
    {
        //cout << "guess = " << count << endl;
        //cout << endl;
        //prints current solution with letters and underlines
        //for (int i = 0; i < passed.length(); i++)
        //{
        //  cout << passed[i] << " ";
        //}
        //cout << endl;

        //prints gallows based on how many incorrect guess they have
        switch (count)
        {
        case 1:
            cout << "                              ------" << endl
                    << "                              o      |" << endl;
            break;

        case 2:
            cout << "                              ------" << endl
                    << "                              o      |" << endl
                    << "                              |      |" << endl;
            break;

        case 3:
            cout << "                              ------" << endl
                    << "                              o      |" << endl
                    << "                             -|      |" << endl;
            break;

        case 4:
            cout << "                              ------" << endl
                    << "                              o      |" << endl
                    << "                             -|-     |" << endl;
            break;

        case 5:
            cout << "                              ------" << endl
                    << "                              o      |" << endl
                    << "                             -|-     |" << endl
                    << "                             /       |" << endl;
            break;

        case 6:
            cout << "                              ------" << endl
                    << "                              o      |" << endl
                    << "                             -|-     |" << endl
                    << "                             / \\     |" << endl;

            cout << "\nSorry you lost, better luck next time\n";
            break;

        default:
            //never get here
            cout << "How did you get here?";
            break;
        }
    }


//MAIN
int main(){

    //must be reset for new puzzle
    string puzzle = "jazz";//makes a string of dashes the same size as the puzzle string
    string solution = create_Dashes(puzzle);
    string hold = "";//used as a string to hold all guessed letters
    string current_letter = ""; //a string that will be loaded with the current letter guessed

    bool keepgoing = true, finished = false; //loop while not finished
    int guess = 0; //tracks amount of guesses
    char letter; //letter to guess

    cout << "Welcome to my Hangman game! Here is your puzzle\n\n";

    //This prints the puzzle with spaces and underlines
    for (int i = 0; i < puzzle.length(); i++)
        cout << solution[i] << " ";

    while(keepgoing && guess < 6)//keeps looping until end
    {
        bool dupe = true;//assumes there is a dupe as a default
        bool finished = true;//assumes the puzzle is finished
        bool found_letter = false;//assumes they did not find a letter
        //cout << "finished" << finished;
        //cout << solution;

        cout << endl << endl <<"Please enter one letter a - z to guess" << endl;
        cin >> letter;
        cout << endl;

        current_letter = letter;//sets the string current_letter to the character entered by user

        hold.append(current_letter);//adds the string with the current letter to the end of the hold string

        // the function duplicate is called. This function is passed the string with all the current guessed letters
        //and the letter they just guessed
        //It will return true if there is a duplicate letter and false if not.
        dupe = checkLetter(hold, letter);

        //if the letter is a duplicate it will stay in this loop until a non duplicate letter is entered
        while (dupe){
            cout << "Sorry, that letter has already been tried, please try another ";
            cout << "\n\nenter one letter to guess\n";
            cin >> letter;
            cout << endl;

            current_letter = letter;

            dupe = false;//resets the duplicate to false allowing the function to test it
            hold.append(current_letter);//resets the string adding the current letter to the end
            dupe = checkLetter(hold, letter);//checks again to see if the letter has already been tried
         }
         //loops through the puzzle to see if their letter matches
         for (int j = 0; j < puzzle.length(); j++){
                //if here is a match identifies there was a match and enters the letter ion the solution string
         if (letter == puzzle[j]){
            found_letter = true;
            solution[j] = letter;
            //cout << "found letter = " << found_letter;
        }
         }
         //cout << "found letter =" << found_letter;

         //if there was a letter, sends the solution string to printPuzzle function
         if (found_letter){
            cout << "You found a letter" << endl;
            printPuzzle(solution);
         }
         //if there was not a letter sends the solution string and the number of incorrect guess to printHangman function
         else{

            guess++;
            cout << "You did not find a letter" << endl;
            printPuzzle(solution);
            printHangman(guess);
            //printHangman(solution, guess);

         }
            //checks to see if they entered all the letters so it can end
            //if there is still an underline then it is not finished
            for (int k = 0; k < solution.length(); k++){
                if (solution[k] == '_'){
                    //cout << "here" << solution[k];
                    finished = false;

                }

            }

    }
    if (finished == true){//if it is finished it stops looping and goes to the end
        keepgoing = false;
    }
    //end message
    cout << "Thanks for Playing!\n";


    return 0;
}


