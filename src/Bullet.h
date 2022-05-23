#pragma once
#include "Projectile.h"

class Bullet:public Projectile{
private:
    sf::CircleShape bullet;
    void init();

public:
    Bullet();
    ~Bullet();
    void ProjectileMovement();
    bool collision();
    sf::FloatRect getGlobalBound();
    void update();
    void render(sf::RenderTarget &target);
    void setPosition(sf::Vector2f);
    void setDirection(char dir);

};
Bullet::Bullet():Projectile(5.1){
    init();
}
Bullet::~Bullet(){
}
void Bullet::init(){
    bullet.setFillColor(sf::Color::Black);
    bullet.setRadius(2.f);
}
void Bullet::update(){
    collision();
    ProjectileMovement();
}

void Bullet::render(sf::RenderTarget &target){
    target.draw(bullet);
}
sf::FloatRect Bullet::getGlobalBound(){
    return bullet.getGlobalBounds();
}
bool Bullet::collision(){
    if(bullet.getPosition().x>1280){
        return true;
    }
    else if(bullet.getPosition().x<0){
        return true;
    }
    else{
        return false;
    }
}
void Bullet::ProjectileMovement(){
    if(collision()==false){
        if(direction=='l'){
            bullet.move(-1*speed,0.f);
        }
        else{ 
            bullet.move(speed,0.f);
        }
    }
}
void Bullet::setPosition(sf::Vector2f pos){
    bullet.setPosition(pos);
}
void Bullet::setDirection(char dir){
    direction=dir;
}

