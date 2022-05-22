#pragma once
#include "Level.h"
#include "StoneTiles.h"
// #include "Player.h"

// window height=720
// window width=1280
class Level1: public Levels{
    private:
        StoneTiles floorBrick;
        sf::Vector2f tileArea;

        void init();
        void initRowsX(); 
    public:
        Level1();
        // virtual ~Level1();

        void drawTiles(sf::RenderTarget &);
        // friend char Player::collision();
        // friend char Player::collision(char);

        Area rows[8];



};
Level1::Level1(){
    init();
    initRowsX();
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
    rows[0].top=windowDimensions.y-tileArea.y;
    rows[0].left=0;
    rows[0].bottom=windowDimensions.y;
    rows[0].right=1280;
    for(int j=1;j<=7;j+=2){
        for(int i=1;i<=9;i++){
            floorBrick.update(sf::Vector2f(i*tileArea.x,windowDimensions.y-tileArea.y-height*j));
            floorBrick.render(window);
        }
        //adding the cordinatoes(top layer and bottom layer) of the whole floor to array
        rows[j].top=windowDimensions.y-tileArea.y-height*j;//720-30(tile height)-90(extra space)*j(current floor)
        rows[j].bottom=windowDimensions.y-height*j;
    }
    for(int j=2;j<=6;j+=2){
        for(int i=0;i<9;i++){
            floorBrick.update(sf::Vector2f(i*tileArea.x,windowDimensions.y-tileArea.y-height*j));
            floorBrick.render(window);
        }
        // adding the coordinates(top layer and bottom layer) of the whole floor to array
        rows[j].top=windowDimensions.y-tileArea.y-height*j;
        rows[j].bottom=windowDimensions.y-height*j;
    }


}
void Level1::initRowsX(){
    int height=90;
    rows[0].left=0;
    rows[0].right=1280;

    for(int i=1;i<=7;i+=2){
        rows[i].left=128;
        rows[i].right=1280;
        rows[i].top=windowDimensions.y-tileArea.y-height*i;//720-30(tile height)-90(extra space)*j(current floor)
        rows[i].bottom=windowDimensions.y-height*i;

    }
    for(int i=2;i<=6;i+=2){
        rows[i].left=0;
        rows[i].right=1152;
        rows[i].top=windowDimensions.y-tileArea.y-height*i;
        rows[i].bottom=windowDimensions.y-height*i;

    }
    rows[0].top=windowDimensions.y-tileArea.y;
    rows[0].bottom=windowDimensions.y;
    // for(int j=1;j<=7;j+=2){
    //     //adding the cordinatoes(top layer and bottom layer) of the whole floor to array
    //     rows[j].top=windowDimensions.y-tileArea.y-height*j;//720-30(tile height)-90(extra space)*j(current floor)
    //     rows[j].bottom=windowDimensions.y-height*j;
    // }
    // for(int j=2;j<=6;j+=2){
    //     // adding the coordinates(top layer and bottom layer) of the whole floor to array
    //     rows[j].top=windowDimensions.y-tileArea.y-height*j;
    //     rows[j].bottom=windowDimensions.y-height*j;
    // }


}
