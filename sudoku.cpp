#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 9 // Size of the Sudoku grid

using namespace std;

// function prototypes
void GameStarts(int board[N][N]);
void PrintBoard(int board[N][N]);
bool CheckValidMove(int board[N][N], int row, int col, int value);
void PlaceRandomNum(int board[N][N], int count);
bool AllSolved(int board[N][N]);

int main()
{
    int board[N][N] = {0};
    bool solved = false;
    srand(time(0));
    PlaceRandomNum(board, 75);
    while (AllSolved)
    {
        GameStarts(board);
    }
    cout << "Congratulations You have won the game!!";
    return 0;
}

void GameStarts(int board[N][N])
{
    int row, col, value;
    PrintBoard(board);
    cout << "Enter row(1-9),col(1-9) & value(1-9): ";
    cin >> row >> col >> value;
    row--;
    col--;
    if (row >= 0 && row <= 9 && col >= 0 && col <= 9)
    {
        if (CheckValidMove(board, row, col, value))
        {
            board[row][col] = value;
        }
        else
        {
            cout << "Invalid Move!!" << endl;
            cout << "first" << endl;
        }
    }
    else
    {
        cout << "Invalid Move!!" << endl;
        cout << "second";
    }
}

void PrintBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "______________________" << endl;
        }
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool CheckValidMove(int board[N][N], int row, int col, int value)
{
    if (board[row][col] != 0)
    {
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == value || board[i][col] == value)
        {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + startRow][j + startCol] == value)
            {
                return false;
            }
        }
    }
    return true;
}

void PlaceRandomNum(int board[N][N], int count)
{
    while (count > 0)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        int num = rand() % 9 + 1;
        if (CheckValidMove(board, row, col, num))
        {
            board[row][col] = num;
            count--;
        }
    }
}

bool AllSolved(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}
