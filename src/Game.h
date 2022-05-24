#pragma once
#include "Player.h"//contains iostream and sfml/graphics
#include "Level1.h"
#include <time.h>
#include <cstdlib>
#include "Player2.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//global variables for window width and height
const int HEIGHT=720;
const int WIDTH=1280;

class Game{
    private:
        sf::RenderWindow* Window;//window object pointer
        sf::VideoMode windowDimensions;//videoMode decleration(for window sizing)
        sf::Event event;//for polling

        //need to make it proper
        sf::Sprite background;
        sf::Texture texBg;


        Player* player;
        Player2* obj2;
        Level1 level;
        //initializers
        void init();//innitializer
        void initPlayer();//for innitializing plyaer
        void initPlayer2();
    //  //  sf::VertexArray ver;
    //    sf::Texture texture;
    //    sf::VertexArray triangle;
    public:
        //constructors
        Game();
        ~Game();

        //functions
        bool isOpen();//window.isOpen() check
        void checkEvents();//check for polling events
        void update();
        void render();//to clear, render and then draw
        void updatePlayer();
        void renderPlayer();
        void splashScreen();

        void updateobj2();
        void renderobj2();

        bool bulletCollision(sf::FloatRect, sf::FloatRect);

};

bool Game::bulletCollision(sf::FloatRect objectOfPlayer, sf::FloatRect objectOfBullet){
    if(objectOfPlayer.intersects(objectOfBullet)){
        return true;
    }
    else{
        return false;
    }
}

void Game::init(){
    //initializing videoMode
    windowDimensions.width=WIDTH;
    windowDimensions.height=HEIGHT;
    //initializing the window
    Window=new sf::RenderWindow(windowDimensions,"The Climber");
    Window->setFramerateLimit(60);

   // triangle.setPrimitiveType(sf::PrimitiveType::Triangles);
   // triangle[0].position=sf::Vector2f(10,10);
    // triangle[1].position=sf::Vector2f(100,10);
    // triangle[2].position=sf::Vector2f(100,100);

 //   triangle[0].color=sf::Color::Red;


    //vertex
    // ver[0].position = sf::Vector2f(10,20);
    // ver[0].color=sf::Color::Red;
    // ver[0].texCoords=sf::Vector2f(100,100);
    // ver.setPrimitiveType(sf::Quads);
    // ver.resize(32*32*4);

    // texture.loadFromFile("res/ground textures/Bricks1_Dark.png");

}
void Game::initPlayer(){//initializing the player object
    player= new Player();
    // player->setMapCollisions(level.rows);
}
void Game::initPlayer2(){
    obj2 = new Player2();
}

Game::Game(){
    splashScreen();
    //initializing
    init();
    initPlayer();
    initPlayer2();

    //move backgroung code into init function
    texBg.loadFromFile("res/rsz_1sky69.png");
  //       sf::Texture texture;
    //need to do exception handling for this
   // if(!texture.loadFromFile("res/rsz_1sky69.png"))
     //   {
       //    std::cout<<"404 Error Not Found";

        //}
//    sf::Sprite background;
    background.setTexture(texBg);
    background.setPosition(sf::Vector2f(0,0));

}
Game::~Game(){
    //both are pointer so they have to be deleted manually
    delete player;
    delete obj2;
    delete Window;
}

bool Game::isOpen(){//calling window.isOpen to check if window is open or not
    return Window->isOpen();
}

void Game::checkEvents(){//check for keyboard presses/close button press
    while(Window->pollEvent(event)){
        if(event.type==sf::Event::Closed)
            Window->close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            Window->close();

        if(sf::Event::KeyReleased){
            player->stopJump();
            obj2->stopJump();

        }

    }
}

void Game::update(){
    checkEvents();
    if(bulletCollision(player->getPlayerGlobal(),obj2->getObjectGlobal())){
        cout<<"Player 1 dead\n";
        Window->close();
    }
    if(bulletCollision(obj2->getPlayerGlobal(),player->getObjectGlobal())){
        cout<<"Player 2 dead\n";
    }
    player->update();
    obj2->update();
    //std::cout<<"Pos: "<<sf::Mouse::getPosition(*Window).x<<'\n';
    // level.drawTiles(*Window);
    // updatePlayer();
}

void Game::render(){
    Window->clear();

    Window->draw(background);
    //clear, render and then draw to the screen

//    Window->draw(triangle);
    // Window->clear(sf::Color(135,206,235));//to clear the window
    // renderPlayer();
    level.drawTiles(*Window);

    renderPlayer();

    renderobj2();


//    sf::RectangleShape shape(sf::Vector2f(10,5));
//     shape.setPosition(10,10);



//     sf::Sprite forTrieal;
//     sf::Texture testTex;
//     sf::IntRect curr(sf::IntRect(0,0,38,36));
//     testTex.loadFromFile("res/john3part2.png");
//     forTrieal.setTextureRect(curr);
//     forTrieal.setPosition(10,10);


 



    // Window->draw(shape);
    // Window->draw(forTrieal);

    //draw game here
    Window->display();//to draw to the screen

}
void Game::updatePlayer(){
    player->update();
}
void Game::updateobj2(){
    obj2->update();
}
void Game::renderPlayer(){
    player->render(*Window);
}
void Game::renderobj2(){
    obj2->render(*Window);
}
void Game::splashScreen(){
    sf::RenderWindow window(sf::VideoMode(1280,720),"3BROS ENTERTAINMENT - SKY CLIMBER");

    sf::Texture texture;
    //need to do exception handling for this
    try{
        texture.loadFromFile("res/SKYTOPIA11.png");
    }
    catch(exception e){
        cout<<"Error loading background";
    }

    sf::Sprite splashscreen;
    splashscreen.setTexture(texture);
    splashscreen.setPosition(sf::Vector2f(0,0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
                if(event.type==sf::Event::Closed)
                {
                    window.close();
                }
                window.clear();
                window.draw(splashscreen);
                window.display();
                for(int i=0;i<7;i++)
                {
                    sleep(1);
                }
                window.close();

        }

}
}
