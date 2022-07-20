/*************************************************************************************
James Farnsworth
Programming 1
Oct 24th, 2018
This program is for practice with functions
*************************************************************************************/


//liberies for input and output
#include <iostream> //here to stop needing to type std:: before every cout and cin statement
#include <math.h> //for the sqrt function.
#include <string>
#include <ctime>
#include <stdlib.h>  /* srand, rand */
#include <stdio.h>
#include <time.h>    /* time */
#include <fstream>

using namespace std;


void fileCreator()
{
    cout << "Please name your txt file\n";

    string fileName;
    cin >> fileName;

    fileName.append(".txt");

    ofstream file(fileName);

    cout << "Type whatever you want to type in here\n\n";

    string userContent = "", quit = "0";
    int times = 0;

    while(quit == "no" || quit == "No" || quit == "NO" || quit == "0" || quit == "n" || quit == "N" || quit == "nah" || quit == "Nah")
    {

        cin >> userContent;
        file << userContent.append(" ");

        times++;

        if(times == 20)
        {
            cout << "Hey want to stop typing stuff now?\n\n";
            cin >> quit;
            times = 0;

        }


    }

    file.close();

}

int main(){


fileCreator();


return 0;

}



