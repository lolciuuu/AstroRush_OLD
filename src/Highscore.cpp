#include "../include/Highscore.hpp"
#include "App.hpp"

/** */
Highscore::Highscore()
{
  
}

/** */
void Highscore::show(){
    Property::get("HIGH_GAME_DIST");
    pWriterPtr->setFont("bold_big");
    SDL_Rect where({40,40,200,200});
    pWriterPtr->draw(where ,"HIGHSCORE" );
    
    pWriterPtr->setFont("bold_small");
  
}

/** */
void Highscore::colision( ColisionType type ) {
  #ifdef DEBUG  
    gInfo("Highscore colision");
  #endif
    LiveBar::increaseLive();
}
  

/** */
void Highscore::load() {
    
}

/** */
void Highscore::save() {
  
}

