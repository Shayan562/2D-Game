
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<unistd.h>
#include<math.h>
// #include<conio.h>
// #include<Windows.h>
// #include<cstdlib>
#include<ctime>
#include<cerrno>
#include "src/Game.h"
#include "src/Player.h"
#include "src/Level1.h"
#include "src/Player2.h"
int main()
{
    // sf::RenderWindow window(sf::VideoMode(1280,720),"3BROS ENTERTAINMENT - SKY CLIMBER");

    // sf::Texture texture;
    // //need to do exception handling for this
    // if(!texture.loadFromFile("res/SKYTOPIA11.png"))
    //     {
    //        std::cout<<"404 Error Not Found";
    //         return 0;
    //     }
    // sf::Sprite splashscreen;
    // splashscreen.setTexture(texture);
    // splashscreen.setPosition(sf::Vector2f(0,0));
    // //splashscreen.scale(sf::Vector2f(2,2));
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //             if(event.type==sf::Event::Closed)
    //             {
    //                 window.close();
    //             }
    //             window.clear();
    //             window.draw(splashscreen);
    //             window.display();
    //             for(int i=0;i<15;i++)
    //             {
    //                 Sleep(550);
    //             }
    //             window.close();
// 
        // }
    // }

    Game game;

    //game loop
    while(game.isOpen()){//is window open
      //update
        game.update();

        //render
        game.render();
    }



}
