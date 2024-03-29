#include "../include/Sprite.hpp"
#include <App.hpp>

Sprite::Sprite( SpriteConfig Config ): pData(Config), pCurentFrame(0), pCurentFrameDuration( 0.0f ),
pRenderer( Renderer::getInstance() )
{
  pSrc.w = pDes.w = pData.width;
  pSrc.h = pDes.h = pData.height;  
 }


/** Metoda rysuje sprita zgodnie z danymi przechowywanymi w pData  */
void Sprite::draw(){

 ///TODO  usunac ponizszego ifa, gdy beda wszystkie itemsy w menu glownym
 ///if ten zapobiega wywalaniu sie aplikacji gdy sprite zostal utworzony za pomoca konstruktora bez parametrow
 if(pRenderer == NULL ) return;

 pSrc.x = pData.atlas_x + (pData.width * pCurentFrame);
 pSrc.y = pData.atlas_y;

 pDes.x = pData.pos_x;
 pDes.y = pData.pos_y; 
 
 pRenderer->draw( pSrc, pDes );
   
}


/** Metoda rysuje sprita na podanej pozycji  */
void Sprite::draw( short pos_x, short pos_y ){

 /// @TODO usunac ponizszego ifa, gdy beda wszystkie itemsy w menu glownym
 ///if ten zapobiega wywalaniu sie aplikacji gdy sprite zostal utworzony za pomoca konstruktora bez parametrow
 if(pRenderer == NULL ) return;

 pSrc.x = pData.atlas_x + (pData.width * pCurentFrame);
 pSrc.y = pData.atlas_y;

 pDes.x = pos_x;
 pDes.y = pos_y;
 
 pRenderer->draw( pSrc, pDes );
  
}


/** Aktualizacja animacji sprite; przechodzenie pomiedzy kolejnymi 
 * klatkami animacji
 */
void Sprite::update( float dt ){
  
  pCurentFrameDuration += dt*1000; // 
    
  if( pCurentFrameDuration >= pData.frame_duration_time ){
    pCurentFrameDuration = 0.0f;
    
    // przejscie do nastepnej klatki animacji
    if( pCurentFrame < ( pData.frame_count - 1 ) ){
      ++pCurentFrame;

    }    
    // ostatnia klatka animacji
    else if( pCurentFrame  == ( pData.frame_count - 1) ){

      if( pData.loop ){
	pCurentFrame = 0;
      }
      else return;    
    }
    
  }  
  
}

/** Zwraca polozenie pierwszej klatki animacji na atlasie */
SDL_Rect Sprite::getRect() const {
	SDL_Rect result;
	result.x = pData.atlas_x;
	result.y = pData.atlas_y;
	result.w = pData.width;
	result.h = pData.height;
  return( result );
}

/** Ustawia polozenie sprita na srodek ekranu */
void Sprite::centered() {
    pData.pos_x = ( App::getScreenWidth()/2 ) - (pData.width/2);
    pData.pos_y = ( App::getScreenHeight()/2) - (pData.height/2);
}

