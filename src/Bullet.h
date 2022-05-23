#pragma once
#include "Projectile.h"

class Bullet:public Projectile{
private:
    sf::CircleShape bullet;
    void init(sf::Vector2f pos);
public:
    Bullet(char, sf::Vector2f);
    ~Bullet();
    void ProjectileMovement();
    bool collision();
    sf::FloatRect getGlobalBound();
    void update();
    void render(sf::RenderTarget &target);

};
void Bullet::Bullet(char dir, sf::Vector2f pos):Projectile(dir,5.1){
    init(pos);
}
void Bullet::~Bullet(){
}
void Bullet::init(sf::Vector2f pos){
    bullet.setFillColor(sf::Color::Black);
    bullet.setRadius(2.f);
    bullet.setPosition(pos);
}
bool Bullet::update(){
    collision();
    ProjectileMovement();
}

void Bullet::render(sf::RenderTarget &target){
    target.draw(bullet);
}
sf::FloatRect Bullet::getGlobalBound(){
    return bullet.getGlobalBound();
}

