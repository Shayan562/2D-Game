#pragma once
#include <SFML/Graphics.hpp>

class Projectile{
    protected:
        const float speed;
        const char direction;
    public:
        Projectile(char dir);
        virtual ~Projectile();
        virtual void ProjectileMovement()=0;
        virtual bool collision()=0;
        virtual sf::FloatRect getGlobalBound()=0;
        virtual void update();//update the position/sprite(animation) of player
        virtual void render(sf::RenderTarget &target);
};
Projectile::Projectile(char dir):direction(dir),speed(0){}

Projectile::~Projectile(){}
