#include <iostream>
#include "Table.h"

int main() {
    Table<int, int> table{10, {10, 20}}; // 10};

    table.add_row({60, 70});
    return 0;
}
