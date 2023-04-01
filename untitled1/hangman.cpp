#include "hangman.h"

hangman::hangman()
{
    proby = 0;
}

int hangman::returnProby()
{
    return proby;
}

void hangman::ustawProby(int number)
{
    proby = number;

}

void hangman::zwiekszProby()
{
    ustawProby(returnProby() + 1);
}

std::string hangman::getDobryString()
{
    return dobryString;
}

void hangman::setDobryString(std::string word)
{
    dobryString = word;
}

std::string hangman::getzgadywanyString()
{
    return zgadywanyString;
}

void hangman::setzgadywanyString()
{
    zgadywanyString = "";
    for (int i = 0; i < dobryString.length(); i++)
    {
        zgadywanyString = zgadywanyString + "_";
    }
}

void hangman::setzgadywanyString(std::string word)
{
    zgadywanyString = word;
}

bool hangman::wygrana()
{
    if (zgadywanyString == dobryString)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hangman::guessWord(char letter)
{
    bool correctness = false;
    for (int i = 0; i < dobryString.length(); i++)
    {
        if (letter == dobryString[i])
        {
            int sizeOfString = dobryString.length();
            zgadywanyString = zgadywanyString.substr(0, i) + dobryString.substr(i, 1) + zgadywanyString.substr(i + 1, sizeOfString - (i + 1));
            correctness = true;
        }
    }
    return correctness;
}
