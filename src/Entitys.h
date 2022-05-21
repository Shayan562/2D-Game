#pragma once
#include <SFML/Graphics.hpp>
#include "Area.h"

class Entitys{
    // private:
    protected:
        sf::Texture texture;
        sf::Vector2f entityDimensions;

    public:
        virtual void render(sf::RenderTarget &)=0;
};