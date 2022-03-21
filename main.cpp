//#include <sctdlib>


#include "src/Game.h"
#include "src/Game.cpp"
#include "src/Player.h"
#include "src/Player.cpp"


int main(){
    Game game;

    //game loop
    while(game.isOpen()){//is window open
        //update
        game.update();

        //render
        game.render();
    }

}
