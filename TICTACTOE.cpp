#include <iostream>
using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 9; i += 3)
    {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin()
{

    int winPatterns[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (auto &pattern : winPatterns)
    {

        if (board[pattern[0]] == currentPlayer && board[pattern[1]] == currentPlayer && board[pattern[2]] == currentPlayer)
            return true;
    }
    return false;
}

bool checkDraw()
{
    for (char cell : board)
    {

        if (cell != 'X' && cell != 'O')
            return false;
    }
    return true;
}

void playGame()
{
    int move;
    while (true)
    {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        move--;

        if (move < 0 || move >= 9 || board[move] == 'X' || board[move] == 'O')
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[move] = currentPlayer;

        if (checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{
    char playAgain;
    do
    {

        for (int i = 0; i < 9; i++)
            board[i] = '1' + i;
        currentPlayer = 'X';

        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
