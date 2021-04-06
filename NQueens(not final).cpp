#include <iostream>

bool PutQueen(char**& chess_board, int size, int col);
bool IsSave(char** chess_board, int size, int row, int col);
void PrintOut(char** chess_board, int size);

bool IsSave(char** chess_board, int size, int row, int col) {
    int i, j;
    
    for (i = 0; i < col; ++i)
        if (chess_board[row][i] == 'X')
            return false;
    
    for (i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (chess_board[i][j] == 'X')
            return false;
    
    for (i = row, j = col; j >= 0 && i < size; ++i, --j)
        if (chess_board[i][j] == 'X')
            return false;
    
    return true;
}

void PrintOut(char** chess_board, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << " " << chess_board[i][j] << " ";
        std::cout << std::endl;
    }
}

bool PutQueen(char**& chess_board, int size, int col) {
    if (col >= size)
        return true;
    
    for (int row = 0; row < size; ++row)
        if (IsSave(chess_board, size, row, col)) {
            chess_board[row][col] = 'X';
            
            if (PutQueen(chess_board, size, col + 1))
                return true;
            
            chess_board[row][col] = '.';
        }
    
    return false;
}

int main() {
    int size;
    std::cout << "Input size: ";
    std::cin >> size;
    char** chess_board = new char* [size];
    
    for (int i = 0; i < size; ++i)
        chess_board[i] = new char [size];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            chess_board[i][j] = '.';
    
    PutQueen(chess_board, size, 0);
    PrintOut(chess_board, size);
    
    for (int i = 0; i < size; ++i)
        delete [] chess_board[i];
    delete [] chess_board;
}
