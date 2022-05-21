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
    try{
        if(!textureSheet.loadFromFile("res/john_stand_shooting_ng.png")){
            throw 404;
        }
    }
    catch(int a){
        //write error to log file
        std::cout<<"Couldn't load player sheet\n";
    }
    // if(!textureSheet.loadFromFile("res/hell-beast-idle.png")){
    //     std::cout<<"Couldn't load player sheet\n";
    // }

}
void Player::initSprite(){
    sprite.setTexture(textureSheet);
    current=sf::IntRect(0,0,30,23);//approx 30 per image in the sheet
    sprite.setTextureRect(current);
    sprite.setScale(2.f,2.f);

    sprite.setPosition(1280-30,720-23);
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
        sprite.setScale(-2.f,2.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.move(1.f,0.f);
        sprite.setScale(2.f,2.f);
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
