#include <iostream>
#include "Table.h"

int main() {
    //Table<std::string, int> table{2, {"Hello", 20}}; // 10};

    Table<int, std::string> table{
            {
                    {2, "Hello"},
                    {3, "Good Bye"}
            }
    };

    table.add_row({4, "Oi"});

    auto &col = table.get_col<0>();

    for (int i{0}; i < col.size(); i++) {
        std::cout << col[i] << std::endl;
    }

    return 0;
}
