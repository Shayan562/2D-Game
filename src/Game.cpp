#include "Game.h"

void Game::init(){
    //initializing videoMode
    windowDimensions.width=WIDTH;
    windowDimensions.height=HEIGHT;
    //initializing the window
    Window=new sf::RenderWindow(windowDimensions,"Game");
    Window->setFramerateLimit(60);

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

bool Game::isOpen(){
    return Window->isOpen();
}

void Game::checkEvents(){
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