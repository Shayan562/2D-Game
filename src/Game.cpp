#include "Game.h"

void Game::init(){
    //initializing videoMode
    windowDimensions.width=WIDTH;
    windowDimensions.height=HEIGHT;
    //initializing the window
    Window=new sf::RenderWindow(windowDimensions,"Game");
    Window->setFramerateLimit(60);

    triangle.setPrimitiveType(sf::PrimitiveType::Triangles);
    triangle[0].position=sf::Vector2f(10,10);
    // triangle[1].position=sf::Vector2f(100,10);
    // triangle[2].position=sf::Vector2f(100,100);

    triangle[0].color=sf::Color::Red;


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
    //std::cout<<"Pos: "<<sf::Mouse::getPosition(*Window).x<<'\n';
    updatePlayer();
}   

void Game::render(){
    //clear, render and then draw to the screen

    Window->draw(triangle);
    Window->clear(sf::Color::White);//to clear the window
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