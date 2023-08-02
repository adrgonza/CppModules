#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename Function>
void iter(T* adress, int len, Function f)
{
    if (!adress || !f || !len)
        return ;
    for (int i = 0; i < len; i++)
        f(adress[i]);
}

#endif