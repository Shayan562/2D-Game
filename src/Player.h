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


void Player::initTexture(){
    if(!textureSheet.loadFromFile("res/hell-beast-idle.png")){
        std::cout<<"Couldn't load player sheet\n";
    }

}
void Player::initSprite(){
    sprite.setTexture(textureSheet);
    current=sf::IntRect(0,0,55,67);//approx 55 per animal
    sprite.setTextureRect(current);
}
Player::Player(){
    initTexture();
    initSprite();
}

Player::~Player(){

}

void Player::movement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        sprite.move(-1.f,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.move(1.f,0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        sprite.move(0.f,-1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        sprite.move(0.f,1.f);
    }
}

void Player::update(){
    movement();

}
void Player::render(sf::RenderTarget &target){
    target.draw(sprite);
}
