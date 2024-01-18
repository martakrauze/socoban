#ifndef MAN_H
#define MAN_H

#include <vector>
#include <memory>

#include "fields.hpp"
#include "board.hpp"

using FieldMatrix=std::vector<std::vector<std::unique_ptr<Field>>>;

class Step
{   
    public:
    Step(char dir, bool barrel);
    char dir() const;
    bool push_barrel() const;
    private:
    char _dir;
    bool _push_barrel;
};

class Man
{
public:
    Man()=default;
    Man(int x, int y);
    void move(FieldMatrix &board, char c);
    void move_back(FieldMatrix &board);
    void put(int x, int y);
    unsigned int steps();
    
private:
    int _x;
    int _y;
    unsigned int _steps;
    std::vector<Step> history;
};

#endif // MAN_H