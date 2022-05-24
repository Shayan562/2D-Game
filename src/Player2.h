#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Area.h"
#include "Level1.h"
#include "Bullet.h"
using namespace std;

class Player2{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        //animation
        sf::IntRect current;

        //initializers
        void initTexture();
        void initSprite();
        sf::Vector2f temp;
        // Area obj.rows[8];


        //need to set a constructor and destructor
        const float gravity=3;
        bool isJumping= false;
        const float speed=2.5;
        const float jumpHeight=-6.5;//up in sfml is lower

        char directionCurr;
        bool bullet;
        Bullet *pro;
        Level1 obj;

    public:
        Player2();
        ~Player2();

        void movement(char , char);//check for key inputs and move the player
        void update();//update the position/sprite(animation) of player
        void render(sf::RenderTarget &target);//draw it to the screen

        Area playerBounds;
        char collision();
        char collision(char a);
        bool collision(int);
        bool collisionDown(int );
        void stopJump();

        // void destructBullet(Bullet*);
        sf::FloatRect getPlayerGlobal();
        sf::FloatRect getObjectGlobal();
        // void setMapCollisions(Area arr[8]);
};


void Player2::initTexture(){
    try{
        if(!texture.loadFromFile("res/john3part2.png")){
            throw 404;
        }
    }
    catch(int a){
        //write error to log file
        std::cout<<"Couldn't load player sheet\n";
    }
    // texture.loadFromFile("res/john3.png");
    // if(!texture.loadFromFile("res/hell-beast-idle.png")){
    //     std::cout<<"Couldn't load player sheet\n";
    // }

}
void Player2::initSprite(){
    sprite.setTexture(texture);


    // current=sf::IntRect(4,5,32,21);//approx 30 per image in the sheet

    // current=sf::IntRect(5,4,19,18);//left,top,width,height

    current=sf::IntRect(0,0,38,36);//left,top,width,height new
    sprite.setTextureRect(current);
    // sprite.setSize(sf::Vector2f(38,36));

    sprite.setOrigin(19.f,18.f);
    sprite.setPosition(1280-19,0+18);
    playerBounds.top=18;
    playerBounds.left=1280-19;
    playerBounds.bottom=0+18;
    playerBounds.right=1280+19;


}
Player2::Player2(){
    initTexture();
    initSprite();
    pro=new Bullet;
    bullet=false;
}

Player2::~Player2(){

}

void Player2::movement(char tempColHor, char tempColVer){
 //   sf::Vector2f a=sprite.getPosition();
    // cout<<a.y+36<<" , ";
    // cout<<"bbb";
  //  if(sf::Keyboard::isKeyPressed)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && tempColHor!='l' ){
        directionCurr='l';
        //tempCOlHor!='l'
        // cout<<"a";
        sprite.move(-1*speed,0.f); //2.5
        sprite.setScale(-1.f,1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && tempColHor!='r'){
            directionCurr='r';
        sprite.move(speed,0.f);//2.5
        sprite.setScale(1.f,1.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (tempColVer=='n' || tempColVer=='b')){
        sprite.move(0.f,jumpHeight);//1
        isJumping=true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (tempColVer=='n' || tempColVer=='t')){
        //sprite.move(0.f,1.f);

        // if(a.y+36 > 690 && a.y+36 < 720){
            // cout<<"Not moving";
        // }
        // else{
            sprite.move(0.f,speed);//1
        // }
    }
    else if(tempColVer!='b' && isJumping==false){
        sprite.move(0,gravity);
    }

    // else{
        // cout<<"abc";
        // sprite.move(0.f,0.f);
    // }

    temp=sprite.getPosition();
    playerBounds.top=temp.y-18;
    playerBounds.left=temp.x-19;
    playerBounds.bottom=temp.y+18;
    playerBounds.right=temp.x+19;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && bullet==false){
        bullet=true;
        pro->setDirection(directionCurr);
        pro->setPosition(temp);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7) && bullet==true){
        bullet=false;
    }
}

void Player2::update(){
    char ColVer=collision();
    char ColHor=collision('a');
    if(bullet){
        if(pro->collision()){
            bullet=false;
        }
        else{
            pro->update();
        }
    }
    movement(ColHor,ColVer);

}
void Player2::render(sf::RenderTarget &target){
    target.draw(sprite);
    if(bullet){
    pro->render(target);
    }
}

char Player2::collision(){
    for(int i=0;i<8;i++){
        // bool a=playerBounds.bottom < obj.rows[i].top;
        // cout<<"map"<<a;
   //     sf::Vector2f a=sprite.getPosition();
        if (playerBounds.top<=0){
            if(!isJumping){
                sprite.move(0.f,gravity);
            }
            return 't';
        }
        else if(playerBounds.top < obj.rows[i].bottom && playerBounds.top > obj.rows[i].top && collision(i)){
           return 't';//collision at the top
        }
        else if (playerBounds.bottom > obj.rows[i].top && playerBounds.bottom < obj.rows[i].bottom && collision(i)){
            // if(obj.rows[i+1].)
//            cout<<"b\n";
            return 'b';//collision at the bottom
        }
        // else if(player)

    }
    return 'n';
}
char Player2::collision(char a){
    if(playerBounds.left < 0){
        return 'l';
    }
    else if(playerBounds.right >1280){
        return 'r';
    }
    return 'n';
}

bool Player2::collision(int i){
    // if(i==7){
        // return false;
    // }

    if(playerBounds.right<obj.rows[i].left && playerBounds.left>0){
        return false;
    }
    else if(playerBounds.left>obj.rows[i].right && playerBounds.right<1280){
        return false;
    }
    else{
        return true;
    }

}

void Player2::stopJump(){
    isJumping=false;
}

sf::FloatRect Player2::getPlayerGlobal(){
    return sprite.getGlobalBounds();
}
sf::FloatRect Player2::getObjectGlobal(){
    return pro->getGlobalBound();
}
