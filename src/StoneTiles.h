#pragma once
#include <SFML/Graphics.hpp>
#include "Entitys.h"

class StoneTiles:public Entitys{
    private:
        sf::RectangleShape* tile;
        void init();
    public:
        StoneTiles();
        ~StoneTiles();

        float getWitdh();
        float getHeight();
        sf::Vector2f getDimensions();
        void setWidth(float);
        void setHeight(float);
        void setDimensions(sf::Vector2f);

        void update(sf::Vector2f );
        void render(sf::RenderTarget &);
        // bool collision


};
void StoneTiles::init(){
    entityDimensions.x=128;
    entityDimensions.y=30;
    tile =new sf::RectangleShape(entityDimensions);
    //incase texture doesnt load, we can use basic color
    try
    {
        if(!texture.loadFromFile("res/Rocks2_Dark.png")){
            throw 404;
        }
        else{
            tile->setTexture(&texture);
            tile->setOutlineThickness(2);

        }
    }
    catch(int a)
    {
        //log error data to file
        tile->setFillColor(sf::Color(128,128,128));
        tile->setOutlineThickness(2);

    }
    
   // texture.loadFromFile("Rocks2_Dark.png");
    //tile->setTexture(&texture);
    //tile->setOutlineThickness(2);
}

StoneTiles::StoneTiles(){
    init();
}
StoneTiles::~StoneTiles(){
    delete tile;
}
float StoneTiles::getWitdh(){
    return entityDimensions.x;
}
float StoneTiles::getHeight(){
    return entityDimensions.y;
}
sf::Vector2f StoneTiles::getDimensions(){
    return entityDimensions;
}
void StoneTiles::setWidth(float x){
    entityDimensions.x=x;
}
void StoneTiles::setHeight(float y){
    entityDimensions.y=y;
}
void StoneTiles::setDimensions(sf::Vector2f dimensions){
    entityDimensions=dimensions;
}
void StoneTiles::update(sf::Vector2f cords){
    tile->setPosition(cords);
}

void StoneTiles::render(sf::RenderTarget &window){
    window.draw(*tile);//to pass by value rather than the address
}