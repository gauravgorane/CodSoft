#include <iostream>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void base(){

    cout << "\n\tPlayer 1 [X] \tPlayer 2 [O]" << endl;

    cout << "\n\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t\t     |     |     \n";

}

void player(){
    
    // if (turn == 'X'){
    //     cout << "\n\tPlayer - 1 [X] turn: ";
    // }
    // else if (turn == 'O'){
    //     cout << "\n\tPlayer - 1 [O] turn: ";
    // }

    // cin >> choice;

    // switch(choice){
    // case 1: row=0; column=0; break;
    // case 2: row=0; column=1; break;
    // case 3: row=0; column=2; break;
    // case 4: row=1; column=0; break;
    // case 5: row=1; column=1; break;
    // case 6: row=1; column=2; break;
    // case 7: row=2; column=0; break;
    // case 8: row=2; column=1; break;
    // case 9: row=2; column=2; break;
    // default:
    //     cout << "Invalid Move. Please choose a number between 1 and 9.\n";
    // }

    // if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
    //     board[row][column] = 'X';
    //     turn = 'O';
    // }
    // else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
    //     board[row][column] = 'O';
    //     turn = 'X';
    // }
    // else{
    //     cout << "Box already filled! \nPlease choose another!!\n\n";
    //     player();
    // }
    // base();

    bool validmove = false;

    while (!validmove)
    {
        if (turn == 'X'){
            cout << "\n\tPlayer - 1 [X] turn: ";
        }
        else if (turn == 'O'){
            cout << "\n\tPlayer - 2 [O] turn: ";
        }

        cin >> choice;

        switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout << "Invalid Move. Please choose a number between 1 and 9.\n";
            continue;
        }

        if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O' || turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
            board[row][column] = turn;
            validmove = true;
        }
        else{
            cout << "\tBox already filled! \nPlease choose another!!\n\n";
            player();
        }
    }
    
    turn = (turn == 'X') ? 'O' : 'X';

    base();
}

bool gameover(){

    // checking the winner for straight rows/columns

    for(int i=0;i<3;i++){
        if( board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i]){
            return false;
        }
    }

    // checking the winner for diagonals

    if( board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]){
        return false;
    }

    // checking the game is in continue mode or not

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return true;
            }
        }
    }

    // checking for game is draw or not

    draw = true;
    return false;

}

void resetBoard() {
    char cellValue = '1';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = cellValue++;
        }
    }
}

int main(){

    cout << "\n\t______TIC-TAC-TOE GAME______" << endl;

    bool playAgain = true;

    while (playAgain)
    {
        resetBoard();

        while (gameover())
        {
            base();
            player();
            gameover();
        }
        
        if (turn == 'X' && draw == false){
            cout << "\n\tCongratulations! Player 2 win the game." << endl;
        }
        else if (turn == 'O' && draw == false){
            cout << "\n\tCongratulations! Player 1 win the game." << endl;
        }
        else{
            cout << "\tGame Draw!"<< endl;
        }

        cout << "\nDo you want to play again? (1 for yes, 0 for no): ";
        cin >> playAgain;
    }
    

    
    return 0;
}