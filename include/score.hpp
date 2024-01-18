#ifndef SCORE_H
#define SCORE_H

#include <iostream>

struct Score
{
    Score(std::string& name, unsigned int steps);
    std::string _name;
    unsigned int _steps;
};

void show_score(std::string& file, Score new_score);
Score get_score(unsigned int steps);

#endif // SCORE_H