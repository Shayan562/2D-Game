#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player{
    private:
        sf::Sprite sprite;
        sf::Texture textureSheet;

        //animation
        sf::IntRect current;

        //initializers
        void initTexture();
        void initSprite();


    public:
        Player();
        ~Player();

        void movement();//check for key inputs and move the player
        void update();//update the position/sprite(animation) of player
        void render(sf::RenderTarget &target);//draw it to the screen
};