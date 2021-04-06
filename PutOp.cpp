#include <iostream>
using namespace std;

bool Cal(int x1, int x2, int op, int& cal_res) {
    if (x2 == 0 && op == 3)
        return false;
    
    switch (op) {
        case 0:
            cal_res = x1 + x2;
            break;
        case 1:
            cal_res = x1 - x2;
            break;
        case 2:
            cal_res = x1 * x2;
            break;
        case 3:
            cal_res = x1 / x2;
            break;
    }
    return true;
}

bool CalExp(int* num, int n, int* op, int& cal_res) {
    if (n == 1)
        return (cal_res = num[0]);
    if (n == 2)
        return Cal(num[0], num[1], op[0], cal_res);
    
    int* temp = new int[n];     // this is the array we'll use to calculate
    for (int i = 0; i < n; ++i)
        temp[i] = num[i];
    
    int id_num0 = 0, id_num1 = 1, id_num2 = 2, id_op0 = 0, id_op1 = 1;
    for (int i = 0; i < n - 2; ++i) {
        if (op[id_op0] == 2 || op[id_op0] == 3 || op[id_op1] == 0 || op[id_op1] == 1) {
            if (!Cal(temp[id_num0], temp[id_num1], op[id_op0], temp[id_num1]))
                return false;
            id_num0 = id_num1; id_num1 = id_num2; ++id_num2;
            id_op0 = id_op1; ++id_op1;
        }
        else {
            if (!Cal(temp[id_num1], temp[id_num2], op[id_op1], temp[id_num2]))
                return false;
            id_num1 = id_num2; ++id_num2;
            ++id_op1;
        }
    }
    
    bool final_res = Cal(temp[id_num0], temp[id_num1], op[id_op0], cal_res);
    delete[] temp;
    return final_res;
}

void PrintOut(int* num, int n, int* op, int res) {
    char o[] = {'+', '-', '*', '/'};
    
    for (int i = 0; i < n - 1; ++i)
        std::cout << num[i] << " " << o[op[i]] << " ";
    std::cout << num[n - 1] << " = " << res << std::endl;
}

void PutOp(int* num, int n, int* op, int i, int& cal_res, int res) {
    if (i > n - 2) {
        if (CalExp(num, n, op, cal_res))
            if (cal_res == res)
                PrintOut(num, n, op, res);
        return;
    }
    
    for (int j = 0; j < 4; ++j) {
        op[i] = j;
        PutOp(num, n, op, i + 1, cal_res, res);
    }
}

int main() {
    int n;
    std::cout << "Input n: ";
    std::cin >> n;
    int* num = new int[n], * op = new int[n - 1], res;
    std::cout << "Input " << n << " numbers: ";
    for (int i = 0; i < n; ++i)
        std::cin >> num[i];
    std::cout << "Input result: ";
    std::cin >> res;
    
    int cal_res;
    PutOp(num, n, op, 0, cal_res, res);
    
    delete[] num;
    delete[] op;
}
