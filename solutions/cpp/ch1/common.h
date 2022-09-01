#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[ ";

    for(const auto& e: v)
        out << e << " ";
    
    out << "]" << std::endl;

    return out;
}
