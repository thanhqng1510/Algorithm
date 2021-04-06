#include <iostream>

struct book {
    int price;
    int stock;
    int weight_per_customer = 0;
};

void PrintOut(book* arr_book, int n, int money_left) {
    for (int i = 0; i < n; ++i) {
        if (arr_book[i].weight_per_customer == 0)
            continue;
        std::cout << arr_book[i].weight_per_customer << " copies of book " << i + 1 << std::endl;
    }
    std::cout << "You have " << money_left << " dollars left\n";
}

void Weight(book* arr_book, int n, int& money_left, int& temp_money_left, int level, int* temp_weight, bool& stop) {
    if (stop)
        return;
    
    if (level == n) {
        if (temp_money_left < money_left) {
            money_left = temp_money_left;
            
            for (int j = 0; j < n; ++j)
                arr_book[j].weight_per_customer = temp_weight[j];
            
            if (money_left == 0)
                stop = true;
        }
        return;
    }
    
    int cur_level_money_left = temp_money_left;
    for (int num_book = 0; num_book <= arr_book[level].stock; ++num_book) {
        temp_weight[level] = num_book;
        cur_level_money_left -= arr_book[level].price * (num_book != 0);
        Weight(arr_book, n, money_left, cur_level_money_left, level + 1, temp_weight, stop);
        
        if (cur_level_money_left < arr_book[level].price)
            break;
    }
}

int main() {
    int n;
    std::cout << "Input num of books: ";
    std::cin >> n;
    book* arr_book = new book[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Input price and stock for book " << i + 1 << ": ";
        std::cin >> arr_book[i].price;
        std::cin >> arr_book[i].stock;
    }
    int money_left;
    std::cout << "Input money: ";
    std::cin >> money_left;
    int temp_money_left = money_left;
    
    int* temp_weight = new int[n];
    for (int i = 0; i < n; ++i)
        temp_weight[i] = 0;
    
    bool stop = false;
    Weight(arr_book, n, money_left, temp_money_left, 0, temp_weight, stop);
    PrintOut(arr_book, n, money_left);
    
    delete[] temp_weight;
    delete[] arr_book;
}
