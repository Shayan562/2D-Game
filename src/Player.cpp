#include "Player.h"

void Player::initTexture(){
    if(!textureSheet.loadFromFile("/home/shayan/Documents/new folder/Project/res/hell-beast-idle.png")){
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