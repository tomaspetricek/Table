//
// Created by Tomáš Petříček on 07.08.2021.
//

#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#include <vector>
#include <tuple>
#include <iostream>
#include <any>

template<class ...T_s>
class Table final {
    // friend std::ostream &operator<<(std::ostream& os, const Table& table){ }
public:
    typedef std::tuple<T_s...> Row;

private:
    std::tuple<std::vector<T_s>...> cols;
    int n_cols = std::tuple_size<decltype(cols)>();

    template<int i = 0>
    void fill_row(const Row &row) {
        auto &col = std::get<i>(cols);
        col.push_back(std::get<i>(row));

        if constexpr(i + 1 != sizeof...(T_s))
            fill_row<i + 1>(row);
    }

public:
    Table() = default;

    explicit Table(std::vector<Row> rows) {
        for (int r{0}; r < rows.size(); r++)
            add_row(rows[r]);
    }

    Table(int n_rows, const Row &init_row) { // T_s... init_values
        for (int r{0}; r < n_rows; r++)
            add_row(init_row);
    }

    void add_row(const Row &row) {
        fill_row(row);
    }

    template<int i = 0>
    auto& get_col() {
        return std::get<i>(cols);
    }
};

#endif //TABLE_TABLE_H
