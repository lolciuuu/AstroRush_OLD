#include "../include/Writer.hpp"
#include "Resource.hpp"

/// Init zmiennych statycznych
  Writer* Writer::pInstance;
//END

/** */
Writer::Writer(): pRendererPtr( NULL ), pScreen( NULL )
{
  pFont = Resource::getFont("bold_small");
}

/** */
void Writer::setFont( string FontName ){
    pFont = Resource::getFont(FontName);
}

/** */
Writer::~Writer() {

}

/** */
void Writer::draw( SDL_Rect WhereRect, string Text, SDL_Color Color ){

  SDL_Surface* tmp_surf = TTF_RenderText_Blended( pFont, Text.c_str(), Color );
  pRendererPtr->draw(tmp_surf,WhereRect);
  SDL_FreeSurface( tmp_surf );
  
}

/** */
void Writer::draw( SDL_Rect WhereRect, string Text ){

  SDL_Color Color={ 250,250,250 };  		    
  SDL_Surface* tmp_surf = TTF_RenderText_Blended( pFont, Text.c_str(), Color );
  WhereRect.w = pScreen->w * (0.01 * Text.length() );
  WhereRect.h = pScreen->h * 0.1;


  pRendererPtr->draw(tmp_surf,WhereRect);
  SDL_FreeSurface( tmp_surf );
  
}


/** Pobranie referencji do Renderera */
void Writer::init() {
	string methodName = "Writer::init()";
	gStartMethod( methodName );

		pRendererPtr = Renderer::getInstance();

	gEndMethod( methodName );
}

