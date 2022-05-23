#pragma once
#include <SFML/Graphics.hpp>

class Enemy{
    private:
        const float healthMax;
        float healthCurr;
        const float damage;
        bool isAlive;
        sf::Sprite enemy;
        sf::Texture texture;

    public:
        Enemy();
        virtual ~Enemy();
        virtual void movement()=0;
        virtual void attack()=0;
        virtual sf::FloatRect getGlobal()=0;
        virtual void damageIn()=0;
        virtual void kill()=0;

};
