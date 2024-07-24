#include<iostream>
using namespace std;
int main()
{
    const int cols = 7;
    const int row = 6;
    char arr[row][cols];
    int curplayer = 1;

    //initialize in the table
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = ' ';
        }
    }
    // jitni dafa total turn chalni
    for (int turn = 0; turn < row * cols; turn++)
    {
        system("cls");
        //make the table
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "| " << arr[i][j] << " ";
            }
            cout << "|\n";
            for (int j = 0; j < 6; j++)
            {
                cout << "-----";
            }
            cout << "\n";
        }
        cout << "  1   2   3   4   5   6   7\n";
        //take column from user
        int column;
        cout << "Player " << curplayer << " your turn (Enter a Column 1-7): ";
        cin >> column;
        --column;
        //to start the input form bottom
        for (int turn1 = row - 1; turn1 >= 0; --turn1)
        {
            if (arr[turn1][column] == ' ')
            {
                if (curplayer == 1)
                {
                    arr[turn1][column] = 'X';
                }
                else
                {
                    arr[turn1][column] = 'O';
                }
                break;
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                char number;
                number = arr[i][j];
                if (number == ' ')
                    continue;
                // horizontally checked
                if (i + 3 < row && arr[i][j] == arr[i][j] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j])
                {
                    cout << endl << "Player " << curplayer << " is winner\n";
                    return 0;
                }
                //vertically checked 
                if (j + 3 < cols && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
                {
                    cout << endl << "Player " << curplayer << " is winner\n";
                    return 0;
                }
                //diagonally positively checked
                if (i + 3 < row && j + 3 < cols && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3])
                {
                    cout << endl << "Player " << curplayer << " is winner\n";
                    return 0;
                }
                //diagonally negatively checked
                if (i - 3 >= row && j + 3 < cols && arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == arr[i - 2][j + 2] && arr[i][j] == arr[i - 3][j + 3])
                {
                    cout << endl << "Player " << curplayer << " is winner\n";
                    return 0;
                }
            }
        }
        // for other player turn
        if (curplayer == 1)
        {
            curplayer = 2;
        }
        else
            curplayer = 1;
    }
    cout << "It's a draw!\n";
    cout << endl;
    system("pause");
    return 0;
}

