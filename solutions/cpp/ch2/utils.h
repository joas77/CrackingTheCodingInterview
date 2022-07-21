#pragma once

#include <iostream>
#include <string>

void print(const std::string& msg, const std::string& end="\n")
{
    std::cout << msg << end;
}