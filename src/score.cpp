#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "show.hpp"
#include "score.hpp"

Score::Score(std::string &name, unsigned int steps) : _name(name), _steps(steps) {}

void show_score(std::string &file, Score new_score)
{
    std::vector<Score> scores;
    std::fstream myfile("levels/" + file + "_s");
    std::string name;
    unsigned int steps;
    if (myfile.is_open())
    {
        for (int i = 0; i < 5; i++)
        {
            myfile >> steps >> name;
            scores.push_back(Score(name, steps));
        }
    }
    myfile.close();
    myfile.open("levels/" + file + "_s", std::ios_base::out);
    scores.push_back(new_score);
    std::sort(scores.begin(), scores.end(), [](Score a, Score b)
              { return a._steps < b._steps; });
    scores.pop_back();
    std::cout << "Five best scores for level " << file << ":\n";
    for (const auto &s : scores)
    {
        std::cout << s._steps << " " << s._name << "\n";
        myfile << s._steps << " " << s._name << "\n";
    }
    myfile.close();
}

Score get_score(unsigned int steps)
{
    std::cout << "Your score is " << steps << " steps.\n";
    std::cout << "What\'s your name?\n";
    std::string name;
    std::cin >> name;
    return Score(name, steps);
}