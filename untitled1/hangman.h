#pragma once
#include <iostream>
#include <string>
#include "gra.h"

class hangman : public gra
{
private:
    std::string dobryString;
    std::string zgadywanyString;
public:
    hangman();
    int returnProby();
    void ustawProby(int number);
    void zwiekszProby();
    std::string getDobryString();
    void setDobryString(std::string word);
    std::string getzgadywanyString();
    void setzgadywanyString();
    void setzgadywanyString(std::string word);
    bool wygrana();
    bool guessWord(char letter);
};

