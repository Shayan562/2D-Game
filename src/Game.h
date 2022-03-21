#pragma once
#include "Player.h"//contains iostream and sfml/graphics

//global variables for window width and height
const int HEIGHT=600;
const int WIDTH=800;

class Game{
    private:
        sf::RenderWindow* Window;//window object pointer
        sf::VideoMode windowDimensions;//videoMode decleration(for window sizing)
        sf::Event event;//for polling

        Player* player;
        //initializers
        void init();//innitializer
        void initPlayer();//for innitializing plyaer
    
    public:
        //constructors
        Game();
        ~Game();

        //functions
        bool isOpen();//window.isOpen() check
        void checkEvents();//check for polling events
        void update();
        void render();//to clear, render and then draw
        void updatePlayer();
        void renderPlayer();
};