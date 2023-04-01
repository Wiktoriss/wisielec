#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <locale.h>
#include "gra.h"
#include "hangman.h"


int main()
{

    srand(time(0));

    sf::Sprite spr;
    sf::Texture tekstury;

    std::string link = "C:/Users/Wikto/CLionProjects/untitled1/textures/";
    std::string hasla[] = {"WISIELEC", "SAMOLOT", "SZALIK", "UCZELNIA", "PARADA", "SZKLANKA", "KORALE", "KIELICH"};

    std::string bledy_png[] = { "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png"}; //nazwy png

    hangman wisielec;

    int c = (rand() % 5);

    wisielec.setDobryString(hasla[c]);
    wisielec.setzgadywanyString();

    bool playing = false;

    int positions[20][2];
    bool wybor[40];

    for (int i = 0; i < 40; i++)
    {
        wybor[i] = false;
    }

    sf::RenderWindow window(sf::VideoMode(900, 900), "WISIELEC!");

    sf::Font font;
    font.loadFromFile("C:/Users/Wikto/CLionProjects/untitled1/Anonymous.ttf");

    sf::Text tekst("Wisielec", font);
    tekst.setCharacterSize(120);
    tekst.setFillColor(sf::Color::Green);
    tekst.setPosition(200, 0);

    sf::Text tekst1("Graj", font);
    tekst1.setCharacterSize(60);
    tekst1.setFillColor(sf::Color::Green);
    sf::IntRect r1(370, 500, 120, 60);
    tekst1.setPosition(370, 500);

    sf::Text tekst3("Wychodze", font);
    tekst3.setCharacterSize(60);
    tekst3.setFillColor(sf::Color::Green);

    //sf::IntRect r3(370, 700, 120, 60);
    tekst3.setPosition(320, 600);

    sf::Text tekst4(wisielec.getzgadywanyString(), font);
    tekst4.setCharacterSize(80);
    tekst4.setFillColor(sf::Color::Green);
    tekst4.setPosition(1000, 00);

    sf::Text tekst5("Zgaduj slowo", font);
    tekst5.setCharacterSize(60);
    tekst5.setFillColor(sf::Color::Green);
    tekst5.setPosition(1000, 00);


    sf::Text tekst7;
    tekst7.setFont(font);
    tekst7.setCharacterSize(30);
    tekst7.setStyle(sf::Text::Underlined);
    tekst7.setStyle(sf::Text::Bold);
    tekst7.setFillColor(sf::Color::Green);
    tekst7.setPosition(1000, 00);

    sf::Text tekst9("wygrane: " + std::to_string(wisielec.wygrane) + "\nprzegrane: " + std::to_string(wisielec.przegrane), font);
    tekst9.setCharacterSize(40);
    tekst9.setStyle(sf::Text::Underlined);
    tekst9.setStyle(sf::Text::Bold);
    tekst9.setFillColor(sf::Color::Green);
    tekst9.setPosition(1000, 00);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (r1.contains(event.mouseButton.x, event.mouseButton.y))
                {
                    std::cout << "Graj Button pressed\n";
                    c = (rand() % 5);
                    wisielec.setDobryString(hasla[c]);
                    wisielec.setzgadywanyString();
                    wisielec.ustawProby(0);
                    tekst4.setString(wisielec.getzgadywanyString());

                    for (int i = 0; i < 40; i++)
                    {
                        wybor[i] = false;
                    }
                    tekst1.setPosition(1000, 0);
                    /* r1.left = 1000;*/
                    tekst3.setPosition(1000, 0);
                    //r3.left = 1000;
                    tekst9.setPosition(1000, 0);
                    tekst4.setCharacterSize(80);
                    tekst5.setString("Zgaduj slowo!");
                    tekst7.setPosition(1000, 0);
                    tekst4.setPosition(220, 700);
                    tekst5.setPosition(150, 600);
                    playing = true;
                }
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (playing)
                {
                    if (event.text.unicode < 128)
                        if (isalnum(static_cast<char>(event.text.unicode)))
                        {

                            std::cout << "Litera jako liczba: " << static_cast<char>(event.text.unicode) << std::endl;
                            std::cout << "Litera jako liczba: " << event.text.unicode << std::endl;
                            if (wybor[toupper(event.text.unicode) - 65] == true)
                            {
                                std::cout << "Zgadniete \n";
                            }
                            else
                            {
                                wybor[toupper(event.text.unicode) - 65] = true;
                                if (wisielec.guessWord(toupper(static_cast<char>(event.text.unicode))))
                                {
                                    std::cout << "Dobry wybor.\n";
                                    tekst4.setString(wisielec.getzgadywanyString());
                                    if (wisielec.wygrana())
                                    {
                                        tekst5.setString("Wygrales!!!");
                                        tekst4.setCharacterSize(50);
                                        tekst4.setPosition(120, 700);
                                        tekst4.setString("Zgadles\"" + wisielec.getDobryString() + "\"");
                                        playing = false;
                                        tekst1.setString("Jeszcze raz!");
                                        tekst1.setPosition(250, 800);
                                        r1.top = 800;
                                        r1.left = 300;
                                        wisielec.wygrane++;
                                        std::cout << "Przegrane=" << wisielec.przegrane << std::endl;
                                        std::cout << "Wygrane=" << wisielec.wygrane << std::endl;
                                        tekst9.setString("Wygrane: " + std::to_string(wisielec.wygrane) + "\nPrzegrane: " + std::to_string(wisielec.przegrane));
                                        tekst9.setPosition(500, 200);
                                    }
                                }
                                else
                                {
                                    std::cout << "Zly wybor\n";
                                    wisielec.zwiekszProby();
                                    std::string s = link+std::string(bledy_png[wisielec.returnProby()]);
                                    if (tekstury.loadFromFile(s))
                                    {
                                        spr.setTexture(tekstury);
                                    }
                                    if (wisielec.przegrana())
                                    {
                                        tekst5.setString("Przegrales");
                                        tekst4.setCharacterSize(50);
                                        tekst4.setPosition(120, 700);
                                        tekst4.setString("Nie zgadles \"" + wisielec.getDobryString() + "\"");
                                        playing = false;
                                        tekst1.setString("Jeszcze raz!");
                                        tekst1.setPosition(250, 800);
                                        r1.top = 800;
                                        r1.left = 300;
                                        wisielec.przegrane++;
                                        std::cout << "Przegrane=" << wisielec.przegrane << std::endl;
                                        std::cout << "Wygrane=" << wisielec.wygrane << std::endl;
                                        tekst9.setString("Wygrane: " + std::to_string(wisielec.wygrane) + "\nPrzegrane: " + std::to_string(wisielec.przegrane));
                                        tekst9.setPosition(550, 200);
                                    }
                                }
                            }
                        }
                }
            }
        }

        window.clear();

        window.draw(tekst);
        window.draw(tekst1);
        window.draw(tekst3);
        window.draw(tekst4);
        window.draw(tekst5);
        window.draw(tekst7);
        window.draw(tekst9);
        window.draw(spr);


        window.display();
    }

    return 0;
}


