#include <iostream>
#include <fstream>
#include <exception>

#include "show.hpp"

void clearscr()
{
    std::cout << "\033[2J\033[1;1H";
}

char kb_input()
{
    system("stty raw");
    char c = getchar();
    system("stty cooked");
    std::cout << "\33[2K\r";
    return c;
}

void intro()
{
    clearscr();
    std::cout << "Welcome to Socoban game!\n"
              << "Your goal is to help the Brewer (&) with placing all barrels (o) in proper places (x).\n"
              << "Because the Brewer is not a gost, he can\'t get through the walls (#).\n"
              << "You can move the Brewer with wasd keys.\n"
              << "The Brewer can move up-(w), down-(s), right-(d) and left-(a).\n"
              << "You can undo your move by pressing (b).\n"
              << "You can quit level by pressing (.).\n"
              << "Good luck!\n";
}
std::ifstream choose_level(std::string &level)
{
    std::cout << "Choose level (type a number from 0 to 3):"
              << "\n";
    bool existing_file_name = false;
    std::ifstream myfile;
    while (!existing_file_name)
    {
        std::cin >> level;
        try
        {
            myfile.open("levels/"+level);
            if (myfile.fail())
                throw std::runtime_error(level);
            existing_file_name = true;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Level " << e.what() << " doesn\'t exist." << '\n';
        }
    }
    return myfile;
}

bool again()
{
    std::cout << "Wanna play again? (y/n)" << '\n';
    char c;
    std::cin >> c;
    if (c == 'n')
    {
        return false;
    }
    else
    {
        return true;
    }
}