#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int row, col;
    int maxRow, maxCol, minRow, minCol;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up

    maxRow = maxCol = N - 1;
    minRow = minCol = 0;
    row = col = 0;

    while (M != 1) {
        if (direction == 0) {
            if (col < maxCol) {
                col++;
            } else {
                direction = 1;
                minRow++;
                row++;
            }
        } else if (direction == 1) {
            if (row < maxRow) {
                row++;
            } else {
                direction = 2;
                maxCol--;
                col--;
            }
        } else if (direction == 2) {
            if (col > minCol) {
                col--;
            } else {
                direction = 3;
                maxRow--;
                row--;
            }
        } else if (direction == 3) {
            if (row > minRow) {
                row--;
            } else {
                direction = 0;
                minCol++;
                col++;
            }
        }
        M--;
    }

    cout << row + 1 << " " << col + 1 << endl;
    return 0;
}
