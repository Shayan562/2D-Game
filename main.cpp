#include "src/Game.hpp"
#include "src/Game.cpp"


int main(){
    Game game;

    //game loop
    while(game.checkWindowIsOpen()){//is window open
        //update
        game.update();

        //render
        game.render();
    }

}
