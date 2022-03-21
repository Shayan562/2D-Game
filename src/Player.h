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

        void movement();
        void update();
        void render(sf::RenderTarget &target);
};