#pragma once
#include "StoneTiles.h"
#include <SFML/Graphics.hpp>
#include "Area.h"

class Levels{
    protected:
        sf::Vector2f windowDimensions;
        virtual void init();
    public:
        Levels();

};

Levels::Levels(){
    init();
}
void Levels::init(){
    windowDimensions.x=1280;
    windowDimensions.y=720;
}