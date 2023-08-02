#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& f, T& s)
{
    T aux = f;
    f = s;
    s = aux;
}

template<typename T>
T min(T& f, T& s)
{
    if (f > s)
        return (s);
    return (f);
}

template<typename T>
T max(T& f, T& s)
{
    if (f > s)
        return (f);
    return (s);
}

#endif