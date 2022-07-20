/*************************************************************************************
James Farnsworth
Programming 1
Oct 24th, 2018
This program is for practice with functions
*************************************************************************************/


//liberies
#include <iostream> //here to stop needing to type std:: before every cout and cin statement
#include <math.h> //for the sqrt function.
#include <string>
#include <ctime>
#include <stdlib.h>  /* srand, rand */
#include <stdio.h>
#include <time.h>    /* time */
#include <algorithm> //transform and stuff
#include <cctype>
#include <functional>

using namespace std;

//all my prototypes below
//void myName();//ignore
void loopName();//first func
void square();//2nd func
void biggest();//3rd func
void guessingGame();//4th func
void hangMan();//5th func


//misc function protos
void picker();
bool againFunction();
string create_Dashes(string);
bool checkLetter(string, char);
void printPuzzle(string);
void printHangman(int);


int main(){
//my main vars
    string again;



    cout << "Hello! There are five things you can do in this program. Which will you pick?\n\n";//main text

    do{

        cout << " \n 1: Loop name/word \n 2: Root a number \n 3: Tells whats the biggest of 3 numbers \n 4: Guessing game\n " <<
        "5: Hangman game\n\n";

        picker();//calls picker function

        cout << "\nHey want to go back to the function menu of the program? y for yes n for no.\n\n";
        cin >> again; //repeats entire program if you want

    }
    while(again == "Y"||again == "y"||again == "Yes"|| again == "yes");
    cout << "Ok bye then";

    return 0;
}








//All main functions below


//lOOP NAME X AMOUNT OF TIMES
void loopName(){ //1st function
    string bump;//To bump txt or not to bump txt that is the variable
    int times;//how many times?
    string nameString;//string for holding name/word
    string again;//again var

    do{//loop for wanting to go again
    cout << "\nOk whats the name or word?\n";
    cin >> nameString;

    cout << "Ok how many times do you want to loop?\n";
    cin >> times;

    cout << "Last thing do you want the text to bump in to each other vertically? Y for yes N for no.\n";
    cin >> bump;

    if (bump == "y" || bump == "Y" || bump == "Yes" || bump == "yes")
    {
        for(int i = 0; i < times; i++){
            cout << endl << nameString;
        }
        cout << endl;
    }
    else
        for(int i = 0; i < times; i++){
            cout << endl << nameString << endl << endl;
        }
    cout << "Hey want to loop another word?\n";
    cin >> again;
        }
    while(again == "Y"||again == "y"||again == "Yes"|| again == "yes");
   }


//SQUARING
void square(){ //square the number
    int rNumber;
    cout << "\nPlease enter a number to square by\n";
    cin >> rNumber;
    cout << "\nYour root num is " << sqrt(rNumber);;

}

//KNOWS BIGGEST
void biggest(){ //which one is the biggest?
    int num1 = 0, num2 = 0, num3 = 0;

    cout << "\n Put three numbers and the computer will tell you which is the biggest!\n";
    cin >> num1;
    cin >> num2;
    cin >> num3;

if(num1 > num2 && num1 > num3)
    {cout << endl << num1 << " is the greatest\n";}
else if(num2 > num1 && num2 > num3)
    {cout << endl << num2 << " is the greatest\n";}
else if(num3 > num2 && num3 > num1)
    {cout << endl << num3 << " is the greatest\n";}
else cout << "They're all the same\n";
}

//GUESSINGGAME
void guessingGame(){

srand(time(NULL));

int guess = 0, answer = rand() % 100, guessCounter = 0;
string again = "";

do{

cout << "\nI'm thinking of a number between 1 and 100, will you get it in less then 10 tries?\n\n";

do{

cin >> guess;

if (guess < answer && guess > 0)
{
    cout << "\nToo low\n\n";
}
else if(guess > answer && guess < 101)
{
    cout << "\nToo high\n\n";

}
else if(guess == answer)
    cout << " ";
else
    cout << "\nHey I said between 1 and 100!\n\n";

guessCounter++;
}
while(guess != answer);




if(guessCounter < 10)
{
    cout << "\nNice job you got it in " << guessCounter << " tries! The answer was " << answer << "!" << endl << endl;
}
else if(guessCounter >= 10)
{
    cout << "\nWelp you got it in " << guessCounter << " tries, better luck next time. Answer was " << answer << endl << endl;
}
else
    printf("What have you done!");

}
while(againFunction() == 1);

}

//HANGMAN GAME
void hangMan(){

    string again = "";
    string hold = "";//used as a string to hold all guessed letters
    string current_letter = ""; //a string that will be loaded with the current letter guessed
    bool keepgoing = true, finished = false; //loop while not finished
    int guess = 0; //tracks amount of guesses
    char letter; //letter to guess

    cout << "\n\nWelcome to my Hangman game!\n";
    do{
    cout << "\nInput a word for the puzzle! btw don't use caps at all please\n";


    //must be reset for new puzzle
    string puzzle = "";//makes a string of dashes the same size as the puzzle string

    cin >> puzzle;

    string solution = create_Dashes(puzzle);


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
                //if here is a match identifies there was a match and enters the letter on the solution string
         if (letter == puzzle[j]){
            found_letter = true;
            solution[j] = letter;
            //cout << "found letter = " << found_letter;
        }
         }

         //cout << "found letter =" << found_letter;

         //if there was a letter, sends the solution string to printPuzzle function
         if (found_letter){
            cout << "You found a letter!" << endl;
            printPuzzle(solution);
         }

         //if there was not a letter sends the solution string and the number of incorrect guess to printHangman function
         else{

            guess++;
            cout << "You did not find a letter." << endl;
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

    if (finished == true){//if it is finished it stops looping and goes to the end
        keepgoing = false;
    }

    }

    //end message
    cout << "\nThanks for Playing!\n\n";


    }
    while(againFunction() == 1);

}

//HANGMAN FUNCTIONS

/*
This function just replaces the puzzle letters to underscores/blanks/dashes
what ever you want to call them.
*/
//CREATE DASHES FUNCTION
string create_Dashes(string copy_puzzle)
{
    string dash_string = copy_puzzle;
            for (int i = 0; i < copy_puzzle.length(); i++)
                dash_string[i] = '_';

            return dash_string;
}

/*
this function has 2 parameters the string with the current letters
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


/*
    function printPuzzle
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
            cout << "\nYou won! Nice job!\n" << endl;
    }



    /*
    Function printHangman
    prints and tracks incorrect guesses
    This function takes 2 parameters, the solution puzzle and the number of incorrect guesses
    If the guess was incorrect it prints the current unsolved puzzle then
    the associated gallows based on how many incorrect guesses
    */
    //PRINT HANGMAN FUNCTION
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




//MISC FUNCTIONS


//PICKER FUNCTION
void picker(){

    int pick;

    do{

        cin >> pick;

        switch(pick)//function picker
        {

            case 1:
                loopName();//1st function call
                break;
            case 2:
                square();//2nd function call
                break;
            case 3:
                biggest();//3rd function call
                break;
            case 4:
                guessingGame();//4th function call
                break;
            case 5:
                hangMan();//5th function call
                break;
            default:            //here incase you pick something that isn't the picks numbers.
                cout << "Uh you cant pick that sorry. Please pick a function\n\n" <<
                "1:loop name \n 2:root a number \n 3:tells whats the biggest of 3 numbers \n 4:guessing game\n 5:Hangman game\n";

        }
    }
    while(pick < 1 || pick > 5 || pick == ' ');//Basically repeats program until you actually pick a function
}



//AGAIN FUNCTION

bool againFunction()
{
    string again = "";

    cout << "\nHey want to go again?\n";
    cin >> again;
    cout << endl;

    if(again == "Yes" || again == "Y" || again == "y" || again == "yes" || again == "1")
        return 1;
    else
        cout << "\nOk bye then!\n";
        return 0;


}
