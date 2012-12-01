#include "LiveBar.hpp"
#include "App.hpp"

ulong LiveBar::pDistNum;
float LiveBar::pLiveAmount(1);
bool LiveBar::isLive(true);

/** */
LiveBar::LiveBar() : pRendererPtr( Renderer::getInstance() ), 
pWriterPtr( Writer::getInstance() ),pDistStr( Property::get("HIGH_GAME_DIST") )
{
  pDistanceRect.y = Property::getSetting( "HIGH_OFFSET_Y" );
  pDistanceRect.x = (App::getScreenWidth() / 2) -100;
  
  pDistanceRect.w = 300;
  pDistanceRect.h = 100;
  
}


/** */
void LiveBar::draw() {

    pWriterPtr->setFont("bold_big");
    SDL_Rect where({20,10,200,200});
    
/*
 
    //where = SDL_Rect({ 100,50,200,50});
    
    //pRendererPtr->fillRect( where,   pRendererPtr->getRGB(12,24,23) );
    
    where = SDL_Rect({ 110, 53, Uint16( 185*pLiveAmount ), 16 });
    
    pRendererPtr->fillRect( where,   pRendererPtr->getRGB(255,255,1) );

    pWriterPtr->draw( pDistanceRect, pDistStr + gToString<ulong>( pDistNum ) + " m" );
    
    pWriterPtr->setFont("bold_small"); 
   where = SDL_Rect({20,10,200,200});
        pRendererPtr->drawImg("LIVEBAR", where);*/
}


/** */
void LiveBar::update(const float& dt ) {
  float nextLiveAmount = pLiveAmount - (dt*0.002);
  
  if( nextLiveAmount > 0 )
  pLiveAmount = nextLiveAmount;
  
    if( nextLiveAmount < 0 )
    isLive = false;
  
}

/** */
void LiveBar::colision( ColisionType type ) {

  if( pLiveAmount >= 0.05 )  
    pLiveAmount -= 0.05;
  
  if( pLiveAmount < 0.05 ){
    isLive = false;
  
  #ifdef DEBUG  
    gInfo("LiveBar:: End game");
  #endif
  }
  
}

/** */
void LiveBar::increaseLive() {
    if( pLiveAmount <= 0.9 )  
    pLiveAmount += 0.1;
}

/** */
void LiveBar::reset() {
  pLiveAmount = 1.0f;
  isLive = true;
}
