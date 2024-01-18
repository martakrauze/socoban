#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "fields.hpp"
#include "man.hpp"

using FieldMatrix=std::vector<std::vector<std::unique_ptr<Field>>>;

class Board
{
public:
    void read(std::ifstream &myfile);
    void print() const;
    bool play();
    unsigned int steps();

private:
    FieldMatrix _board;
    unsigned int _columns;
    unsigned int _rows;
    Man _man;
};

#endif // BOARD_H