#pragma once
#include "Player.h"//contains iostream and sfml/graphics
#include "Level1.h"

//global variables for window width and height
const int HEIGHT=720;
const int WIDTH=1280;

class Game{
    private:
        sf::RenderWindow* Window;//window object pointer
        sf::VideoMode windowDimensions;//videoMode decleration(for window sizing)
        sf::Event event;//for polling

        Player* player;
        Level1 level;
        //initializers
        void init();//innitializer
        void initPlayer();//for innitializing plyaer
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
};

void Game::init(){
    //initializing videoMode
    windowDimensions.width=WIDTH;
    windowDimensions.height=HEIGHT;
    //initializing the window
    Window=new sf::RenderWindow(windowDimensions,"New");
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
}

Game::Game(){
    //initializing
    init();
    initPlayer();

}
Game::~Game(){
    //both are pointer so they have to be deleted manually
    delete player;
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

    }
}

void Game::update(){
    checkEvents();
    player->update();
    //std::cout<<"Pos: "<<sf::Mouse::getPosition(*Window).x<<'\n';
    // level.drawTiles(*Window);
    // updatePlayer();
}

void Game::render(){
    //clear, render and then draw to the screen

//    Window->draw(triangle);
    Window->clear(sf::Color(135,206,235));//to clear the window
    // renderPlayer();
    level.drawTiles(*Window);
    renderPlayer();

    //draw game here
    Window->display();//to draw to the screen

}
void Game::updatePlayer(){
    player->update();
}
void Game::renderPlayer(){
    player->render(*Window);
}
