//#include <sctdlib>


#include "src/Game.h"
#include "src/Player.h"
#include "src/Level1.h"


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
