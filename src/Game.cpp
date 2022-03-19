#include "Game.hpp"

void Game::init(){
    windowDimensions.width=WIDTH;
    windowDimensions.height=HEIGHT;
    Window=new sf::RenderWindow(windowDimensions,"Game");

}

Game::Game(){
    init();//initializing

}
Game::~Game(){
    delete Window;
}

bool Game::checkWindowIsOpen(){
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

}

void Game::render(){
    //clear, render and then draw to the screen
    Window->clear(sf::Color::White);
    //draw game here
    Window->display();

}