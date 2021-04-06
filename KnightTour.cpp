#include <iostream>

bool IsAll(int** board, int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (board[i][j] == -1)
                return false;
    return true;
}

bool IsSave(int** board, int size, int row, int col) {
    return (row < size && row >= 0 && col < size && col >= 0 && board[row][col] == -1);
}

void PrintOut(int** board, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << board[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Solve(int** board, int size, int start_row, int start_col, int row_knight, int col_knight, int row_moves[], int col_moves[], int step) {
    if (step == size * size) {
        if (row_knight == start_row && col_knight == start_col) {
            PrintOut(board, size);
            return true;
        }
        return false;
    }
    
    if (IsSave(board, size, row_knight, col_knight)) {
        board[row_knight][col_knight] = step;
        
        for (int i = 0; i < 8; ++i)
            if (Solve(board, size, start_row, start_col, row_knight + row_moves[i], col_knight + col_moves[i], row_moves, col_moves, step + 1))
                return true;
        
        board[row_knight][col_knight] = -1;
    }
    
    return false;
}

int main() {
    int row_moves[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int col_moves[] = {1, -1, -2, -2, -1, 1, 2, 2};
    
    int size;
    std::cout << "Input size: ";
    std::cin >> size;
    int** board = new int* [size];
    for (int i = 0; i < size; ++i)
        board[i] = new int [size];
    
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            board[i][j] = -1;
    
    int start_row, start_col;
    std::cout << "Input starting row and col: ";
    std::cin >> start_row >> start_col;
    
    if (!Solve(board, size, start_row, start_col, start_row, start_col, row_moves, col_moves, 0))
        std::cout << "No solution\n";
    
    for (int i = 0; i < size; ++i)
        delete [] board[i];
    delete [] board;
}
