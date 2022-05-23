#pragma once
#include <SFML/Graphics.hpp>

class Projectile{
    protected:
        const float speed;
        char direction;
    public:
        Projectile(float);
        virtual ~Projectile();
        virtual void ProjectileMovement()=0;
        virtual bool collision()=0;
        virtual sf::FloatRect getGlobalBound()=0;
        virtual void update()=0;//update the position/sprite(animation) of player
        virtual void render(sf::RenderTarget &target)=0;
};
Projectile::Projectile(float s):speed(s){}

Projectile::~Projectile(){}
