#include "gra.h"
int gra::max_proby = 5;

int gra::wygrane = 0;

int gra::przegrane = 0;

int gra::przegrana()
{
    if (proby > max_proby)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}