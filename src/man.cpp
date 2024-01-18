#include <vector>
#include <memory>

#include "fields.hpp"
#include "board.hpp"
#include "man.hpp"

Man::Man(int x, int y) : _x(x), _y(y) {}
void Man::move(FieldMatrix &board, char c)
{
    board[_y][_x]->go_out();
    if (c == 'w')
    {
        if (board[_y - 1][_x]->can_go())
        {
            _y--;
            history.push_back(Step('w', false));
            _steps++;
        }
        else if (board[_y - 1][_x]->is_barrel())
        {
            if (board[_y - 2][_x]->can_go())
            {
                board[_y - 2][_x]->set_is_barrel(true);
                board[_y - 1][_x]->set_is_barrel(false);
                _y--;
                history.push_back(Step('w', true));
                _steps++;
            }
        }
    }
    else if (c == 's')
    {
        if (board[_y + 1][_x]->can_go())
        {
            _y++;
            history.push_back(Step('s', false));
            _steps++;
        }
        else if (board[_y + 1][_x]->is_barrel())
        {
            if (board[_y + 2][_x]->can_go())
            {
                board[_y + 2][_x]->set_is_barrel(true);
                board[_y + 1][_x]->set_is_barrel(false);
                _y++;
                history.push_back(Step('s', true));
                _steps++;
            }
        }
    }
    else if (c == 'd')
    {
        if (board[_y][_x + 1]->can_go())
        {
            _x++;
            history.push_back(Step('d', false));
            _steps++;
        }
        else if (board[_y][_x + 1]->is_barrel())
        {
            if (board[_y][_x + 2]->can_go())
            {
                board[_y][_x + 2]->set_is_barrel(true);
                board[_y][_x + 1]->set_is_barrel(false);
                _x++;
                history.push_back(Step('d', true));
                _steps++;
            }
        }
    }
    else if (c == 'a')
    {
        if (board[_y][_x - 1]->can_go())
        {
            _x--;
            history.push_back(Step('a', false));
            _steps++;
        }
        else if (board[_y][_x - 1]->is_barrel())
        {
            if (board[_y][_x - 2]->can_go())
            {
                board[_y][_x - 2]->set_is_barrel(true);
                board[_y][_x - 1]->set_is_barrel(false);
                _x--;
                history.push_back(Step('a', true));
                _steps++;
            }
        }
    }
    board[_y][_x]->go_in();
}

void Man::move_back(FieldMatrix &board)
{
    if (!history.empty())
    {
        board[_y][_x]->go_out();
        Step last_step = history.back();
        history.pop_back();
        if (last_step.dir() == 'w')
        {
            _y++;
            if (last_step.push_barrel())
            {
                board[_y - 2][_x]->set_is_barrel(false);
                board[_y - 1][_x]->set_is_barrel(true);
            }
        }
        else if (last_step.dir() == 's')
        {
            _y--;
            if (last_step.push_barrel())
            {
                board[_y + 2][_x]->set_is_barrel(false);
                board[_y + 1][_x]->set_is_barrel(true);
            }
        }
        else if (last_step.dir() == 'd')
        {
            _x--;
            if (last_step.push_barrel())
            {
                board[_y][_x + 2]->set_is_barrel(false);
                board[_y][_x + 1]->set_is_barrel(true);
            }
        }
        else if (last_step.dir() == 'a')
        {
            _x++;
            if (last_step.push_barrel())
            {
                board[_y][_x - 2]->set_is_barrel(false);
                board[_y][_x - 1]->set_is_barrel(true);
            }
        }
        board[_y][_x]->go_in();
        _steps--;
    }
}

void Man::put(int x, int y)
{
    _x = x;
    _y = y;
    _steps = 0;
}

unsigned int Man::steps()
{
    return _steps;
}

Step::Step(char dir, bool barrel) : _dir(dir), _push_barrel(barrel){};

char Step::dir() const
{
    return _dir;
}
bool Step::push_barrel() const
{
    return _push_barrel;
}