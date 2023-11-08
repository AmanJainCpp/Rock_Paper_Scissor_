                          /* Rock , Paper , Scissor Game */
#include <iostream>
#include <cstring>
// for generating Random output
#include <random>
// Include the <chrono> header for time-based seed
#include <chrono> 
using namespace std;

int main()
{
    int iRound = 1;
    int iCcount = 0;
    int iUcount = 0;

    cout << endl;
    cout << endl;

    cout << "--------------------------------* Rock , Paper , Scissor Game *-----------------------------";
   
    cout << endl;
    cout << endl;

    cout << "welcome to the Game...." << endl;
    cout << endl;

    cout << "Press 1 for start the Game" << endl;
    cout << "Press 2 for Exit" << endl;

    int iOption;
    cout << "Player Choice: ";
    cin >> iOption;
    cout << endl;

    if (iOption == 1)
    {

        cout << "Winning Rules of Game: " << endl;
        cout << "Rock  vs  Paper   --> Paper wins" << endl;
        cout << "Rock  vs  Scissor --> Rock wins" << endl;
        cout << "Paper vs  Scissor --> Scissor wins" << endl;
    }

    else if (iOption == 2)
    {
        return 0;
    }

    else
    {
        cout << "Error" << endl;
        cout << "Type Either 1 or 2 to play the Game" << endl;
        return 1;
    }

    cin.ignore(); // Ignore the newline character left in the input buffer.

    string sName;
    cout << "Enter Your Name: ";
    getline(cin, sName);
    cout << endl;
    cout << "Your Game Name is " << sName << endl;
    cout << endl;

    int iNumberOfRounds;
    cout << "Enter Number of Rounds You Want to Play: ";
    cin >> iNumberOfRounds;
    int iUserInput;

    string sUserChoice;

    string sGame[3] = {"Rock", "Paper", "Scissor"};

    // Seed the generator with a time-based value
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    mt19937 gen(seed);

    uniform_int_distribution<int> distribution(0, 2);

    string sComputerChoice;

    int iUserCount = 1;
    int iComputerCount = 1;

    for (int i = 1; i <= iNumberOfRounds; i++)
    {
        cout << endl;
        cout << endl;
        cout << "Round:" << iRound++ << endl;
        cout << "Press" << endl;

        cout << " 1 for Rock " << endl;
        cout << " 2 for Paper" << endl;
        cout << " 3 for Scissor" << endl;
        cout << "Enter Your Choice: ";
        cin >> iUserInput;
        
        if (iUserInput >= 1 && iUserInput <= 3)
        {
            sUserChoice = sGame[iUserInput - 1];
        }

        int iRandomIndex = distribution(gen);
        sComputerChoice = sGame[iRandomIndex];

        cout << endl;
        cout << "Your Choice is " << sUserChoice << endl;
        cout << "Computer Choice is " << sComputerChoice << endl;
        cout << endl;

        if (sUserChoice == sComputerChoice)
        {
            cout << "Game result is Draw" << endl;
            cout << "User Score:" << (++iUcount) << endl;
            cout << "Computer Score:" << (++iCcount) << endl;
        }

        else if ((sUserChoice == "Rock" && sComputerChoice == "Scissor") ||
                 (sUserChoice == "Paper" && sComputerChoice == "Rock") ||
                 (sUserChoice == "Scissor" && sComputerChoice == "Paper"))
        {
            cout << "User Score:" << (++iUcount) << endl;
            cout << "Computer Score:" << iCcount << endl;
            cout << "You Win this Round" << endl;
            iUserCount++;
        }

        else
        {
            cout << "User Score:" << iUcount << endl;
            cout << "Computer Score:" << (++iCcount) << endl;
            cout << "Computer Win this Round" << endl;

            iComputerCount++;
        }
    }

    cout << endl;
    cout << endl;

    cout << "Final Result:" << endl;
    cout << endl;

    if (iUserCount == iComputerCount)
    {
        cout << "Draw Game" << endl;
    }

    else if (iUserCount > iComputerCount)
    {
        cout << "YOU WIN... Congratulations!" << endl;
    }
    else
    {
        cout << "Computer WINS... Better luck Next Time" << endl;
    }
    
    cout << endl;
    cout << "User Score: " << iUcount << endl;
    cout << "Computer Score: " << iCcount << endl;

    return 0;
}


       
