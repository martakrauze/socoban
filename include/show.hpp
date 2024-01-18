#ifndef SHOW_H
#define SHOW_H

#include <iostream>

void clearscr();

char kb_input();

void intro();

std::ifstream choose_level(std::string& level);

bool again();

#endif // SHOW_H