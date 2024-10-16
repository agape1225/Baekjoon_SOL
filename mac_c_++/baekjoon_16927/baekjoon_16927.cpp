#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R;
int arr[305][305] = {0};
int new_arr[305][305] = {0};

void move_arr(int start_row, int start_col, int end_row, int end_col, int R)
{

    // cout << "R : " << R << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            new_arr[i][j] = arr[i][j];
        }
    }

    for (int r = 0; r < R; r++)
    {
        for (int i = start_row; i < end_row; i++)
        {
            new_arr[i + 1][start_col] = arr[i][start_col];
        }

        for (int i = start_col; i < end_col; i++)
        {
            new_arr[end_row][i + 1] = arr[end_row][i];
        }

        for (int i = end_row; i > start_row; i--)
        {
            new_arr[i - 1][end_col] = arr[i][end_col];
        }

        for (int i = end_col; i > start_col; i--)
        {
            new_arr[start_row][i - 1] = arr[start_row][i];
        }

        for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = new_arr[i][j];
        }
    }
    }

    
}

int main(void)
{

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    int start_row = 0;
    int start_col = 0;

    int end_row = N - 1;
    int end_col = M - 1;

    while (start_row < end_row && start_col < end_col)
    {
        int row_size = end_row - start_row + 1;
        int col_size = end_col - start_col + 1;
        int total = row_size * 2 + (col_size - 2) * 2;

        // cout << "total: " << total << endl;

        move_arr(start_row, start_col, end_row, end_col, R % total);

        start_row++;
        start_col++;

        end_row--;
        end_col--;

        // cout << start_row << ' ' << start_col << ' ' << end_row << ' ' << end_col << ' ' << endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}