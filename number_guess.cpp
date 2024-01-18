#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

    srand(time(0));

    int number = (rand() % 100) + 1;
    int guess = 0;

    cout << "_____NUMBER GUESSING GAME_____" << endl;

    do
    {
        cout << endl << "Enter Guess (1-100): ";
        cin >> guess;

        if (guess > number)
        {
            cout << "Guess lower" << endl;
        }
        else if (guess < number){
            cout << "Guess higher" << endl;
        }
        else{
            cout << endl << "_____Congratulations! You've won!_____" << endl;
        }
        
    } while (guess != number);

    return 0;
}