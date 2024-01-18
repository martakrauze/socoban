#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "fields.hpp"
#include "board.hpp"
#include "show.hpp"

void Board::read(std::ifstream &myfile)
{
    char tile;
    Goal::remain = 0;
    std::vector<std::unique_ptr<Field>> line;

    myfile >> _rows >> _columns;
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            myfile >> tile;
            if (tile == '#')
            {
                line.push_back(std::make_unique<Wall>());
            }
            else if (tile == '.')
            {
                line.push_back(std::make_unique<Floor>(false));
            }
            else if (tile == 'o')
            {
                line.push_back(std::make_unique<Floor>(true));
            }
            else if (tile == 'x')
            {
                line.push_back(std::make_unique<Goal>());
                Goal::remain++;
            }
            else if (tile == '&')
            {
                line.push_back(std::make_unique<Floor>(false));
                _man.put(j, i);
                line.back()->go_in();
            }
            else
            {
                line.push_back(std::make_unique<Field>());
            }
        }
        std::vector<std::unique_ptr<Field>> new_line;
        // new_line.reserve(line.size());
        std::swap(line, new_line);
        _board.push_back(std::move(new_line));
    }
}
void Board::print() const
{
    for (const auto &line : _board)
    {
        for (const auto &tile : line)
        {
            tile->print();
            std::cout << " ";
        }
        std::cout << "\n";
    }
}
bool Board::play()
{
    clearscr();
    print();
    char a = '1';
    bool win = false;
    while (a != '.' && !win)
    {
        a = kb_input();
        if (a != 'b')
        {
            _man.move(_board, a);
        }
        else
        {
            _man.move_back(_board);
        }
        clearscr();
        print();
        if (Goal::remain == 0)
        {
            win = true;
            std::cout << "You won!"
                      << "\n";
        }
    }
    return win;
}

unsigned int Board::steps()
{
    return _man.steps();
}
