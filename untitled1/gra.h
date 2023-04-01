#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class gra
{
protected:
    int proby;
public:
    static int max_proby;
    static int przegrane;
    static int wygrane;
    int przegrana();
};

