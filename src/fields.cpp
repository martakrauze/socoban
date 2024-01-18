#include "fields.hpp"
#include <iostream>

void Field::print() const
{
    std::cout << ' ';
}
bool Field::can_go() const
{
    return _can_go;
}
void Field::can_go(bool a)
{
    _can_go = a;
}
void Field::go_out()
{
    _man = false;
}
void Field::go_in()
{
    _man = true;
}
void Field::set_is_barrel(bool is_barrel)
{
    _is_barrel = is_barrel;
    _can_go = !is_barrel;
}
bool Field::is_barrel() const
{
    return _is_barrel;
}

Wall::Wall()
{
    _can_go = false;
    _is_barrel = false;
    _man=false;
}
void Wall::print() const
{
    std::cout << '#';
}

Floor::Floor(bool is_barrel)
{
    _can_go = !is_barrel;
    _is_barrel = is_barrel;
    _man=false;
}

void Floor::print() const
{
    if (_man)
    {
        std::cout << '&';
    }
    else if(_is_barrel)
    {
        std::cout << 'o';
    }
    else
    {
        std::cout << ' ';
    }
}

unsigned int Goal::remain = 0;

Goal::Goal()
{
    _can_go = true;
    _is_barrel = false;
    _man=false;
}
void Goal::print() const
{   
    if (_man)
    {
        std::cout << '&';
    }
    else if(_is_barrel)
    {
        std::cout << "⨂";
    }
    else
    {
        std::cout << 'x';
    }
}
void Goal::set_is_barrel(bool is_barrel)
{
    if(!_is_barrel && is_barrel)
    {
        remain--;
    }
    else if(_is_barrel && !is_barrel)
    {
        remain++;
    }
    _is_barrel = is_barrel;
    _can_go = !is_barrel;
}