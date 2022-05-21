#pragma once
#include "Level.h"
#include "StoneTiles.h"

// window height=720
// window width=1280
class Level1: public Levels{
    private:
        StoneTiles floorBrick;
        sf::Vector2f tileArea;

        void init();
    public:
        Level1();
        // virtual ~Level1();

        void drawTiles(sf::RenderTarget &);



};
Level1::Level1(){
    init();
}
void Level1::init(){
    tileArea=floorBrick.getDimensions();
}
void Level1::drawTiles(sf::RenderTarget &window){
    int height=90,level =1;;
    for(int i=0;i<10;i++){//bottom layer
        floorBrick.update(sf::Vector2f(i*tileArea.x,windowDimensions.y-tileArea.y));
        floorBrick.render(window);
    }
    for(int j=0;j<4;j++){
        for(int i=1;i<=9;i++){
            floorBrick.update(sf::Vector2f(i*tileArea.x,windowDimensions.y-tileArea.y-height*level));
            floorBrick.render(window);
        }
        level++;
        for(int i=0;i<9;i++){
            floorBrick.update(sf::Vector2f(i*tileArea.x,windowDimensions.y-tileArea.y-height*level));
            floorBrick.render(window);
    }
    level++;
    }


}
