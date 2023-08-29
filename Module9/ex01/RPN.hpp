#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN & other);

        RPN& operator=(const RPN& other);

        ~RPN();

        bool isSign(char);
        bool parseInput(const std::string &input);
        bool exec(const std::string &input);
};

#endif