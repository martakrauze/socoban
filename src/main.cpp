#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "fields.hpp"
#include "board.hpp"
#include "man.hpp"
#include "show.hpp"
#include "score.hpp"

int main()
{
    intro();
    bool want_to_play = true;
    std::string level;
    while (want_to_play)
    {
        std::ifstream myfile = choose_level(level);
        Board new_board;
        if (myfile.is_open())
        {
            new_board.read(myfile);
        }
        myfile.close();
        if(new_board.play())
        {
            Score your_score=get_score(new_board.steps());
            show_score(level, your_score);
        }
        want_to_play=again();    
    }
    return 0;
}