#pragma once
#include <SFML/Graphics.hpp>

//global variables for window width and height
const int HEIGHT=720;
const int WIDTH=1280;

class Game{
    private:
        sf::RenderWindow* Window;
        sf::VideoMode windowDimensions;
        sf::Event event;
        //initializers
        void init();
    
    public:
        //constructors
        Game();
        virtual ~Game();

        //functions
        bool checkWindowIsOpen();
        void checkEvents();
        void update();
        void render();
};