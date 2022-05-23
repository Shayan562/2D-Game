#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class Splashscreen{
    private:
        sf::Texture texture;

sf::RenderWindow window(sf::VideoMode(1280,720),"3BROS ENTERTAINMENT - SKY CLIMBER");

    sf::Texture texture;
    //need to do exception handling for this
    if(!texture.loadFromFile("res/SKYTOPIA11.png"))
        {
           std::cout<<"404 Error Not Found";
            return 0;
        }
    sf::Sprite splashscreen;
    splashscreen.setTexture(texture);
    splashscreen.setPosition(sf::Vector2f(0,0));
    //splashscreen.scale(sf::Vector2f(2,2));
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
                for(int i=0;i<15;i++)
                {
                    Sleep(550);
                }
                window.close();

        }
};