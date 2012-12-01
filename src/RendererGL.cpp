#include "../include/RendererGL.hpp"

/** */
RendererGL::RendererGL():
pScreen(NULL), pAtlas( Resource::getSurf("ATLAS") ),
pBackground( Resource::getSurf("BACKGROUND_MAP") ), isInit( false )
{
	pBackground_GL = 0;
	pAtlas_GL = 0;
}


/**  */
void RendererGL::draw( SDL_Rect& Src, float x, float y, float w, float h ){

 	   glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

	   const double texture_w = pAtlas->w;    // szerokość atlasu
	   const double texture_h = pAtlas->h;    // wysokość atlasu

	   const double left = Src.x / texture_w;
	   const double right =  left + (Src.w / texture_w );
	   const double bottom =  Src.y / texture_h;
	   const double top =  bottom + (Src.h  / texture_h);

	   glPushMatrix();  {
	     glTranslatef(0, 0, 0);
	     glBegin(GL_QUADS);
	     {
	         glTexCoord2f(right, top);//1
	         glVertex2f( x+w, y+h );

	         glTexCoord2f(left, top);//2
	         glVertex2f( x, y+h );

             glTexCoord2f(left, bottom);//3
	         glVertex2f( x, y );

	         glTexCoord2f(right, bottom);//4
	         glVertex2f( x+w, y );
	     }
	     glEnd();
	   }
	   glPopMatrix();
}

/**  */
void RendererGL::draw( SDL_Rect& Src, SDL_Rect& Dest ){

 	   glBindTexture(GL_TEXTURE_2D, pAtlas_GL);

	   const double texture_w = pAtlas->w;    // szerokość atlasu
	   const double texture_h = pAtlas->h;    // wysokość atlasu

	   const double left = Src.x / texture_w;
	   const double right =  left + (Src.w / texture_w );
	   const double bottom =  Src.y / texture_h;
	   const double top =  bottom + (Src.h  / texture_h);

	   glPushMatrix();  {
	     glTranslatef(0, 0, 0);
	     glBegin(GL_QUADS);
	     {
	         glTexCoord2f(right, top);//1
	         glVertex2f( Dest.x+Dest.w, Dest.y+Dest.h );

	         glTexCoord2f(left, top);//2
	         glVertex2f( Dest.x, Dest.y+Dest.h );

             glTexCoord2f(left, bottom);//3
	         glVertex2f( Dest.x, Dest.y );

	         glTexCoord2f(right, bottom);//4
	         glVertex2f( Dest.x+Dest.w, Dest.y );
	     }
	     glEnd();
	   }
	   glPopMatrix();
}

/** Wygenerowanie textur openGL-a */
void RendererGL::init() {
		create_gl( pBackground , &pBackground_GL );
		create_gl( pAtlas, &pAtlas_GL );
}

/** Zamienia SDL_Surface na format openGL-a */
void RendererGL::create_gl(SDL_Surface * surf, GLuint * tex )
{
	GLenum format;
	GLint  colors_amount = surf->format->BytesPerPixel;

    if (colors_amount == 4) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGBA;
            else
                    format = GL_BGRA;
    }
    else if (colors_amount == 3) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGB;
            else
                    format = GL_BGR;
    }
    else {
        gCritical("Image is not truecolor");
    }

    glGenTextures( 1, tex );

    glBindTexture( GL_TEXTURE_2D, *tex );

    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D( GL_TEXTURE_2D, 0, colors_amount, surf->w, surf->h, 0, format, GL_UNSIGNED_BYTE, surf->pixels );
}



/** Rysowanie tla gry za pomoca GL-a */
void RendererGL::drawBackground() {
 	glBindTexture(GL_TEXTURE_2D, pBackground_GL );

	  glBegin( GL_QUADS );
	  	glTexCoord2f( 0, 0 );
	  	glVertex2f( 0.f, 0.f  );

	  	glTexCoord2f( 1, 0 );
	  	glVertex2f( pScreen->w, 0.f );

	  	glTexCoord2f( 1, 1 );
	  	glVertex2f( pScreen->w, pScreen->h );

	  	glTexCoord2f( 0, 1 );
	  	glVertex2f( 0.f, pScreen->h);
	  glEnd();
}

/** */
GLuint RendererGL::get_gl(SDL_Surface * surf ) {

	GLenum format;
	GLint  colors_amount = surf->format->BytesPerPixel;
	GLuint tex( 0 );

    if (colors_amount == 4) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGBA;
            else
                    format = GL_BGRA;
    }
    else if (colors_amount == 3) {
            if (surf->format->Rmask == 0x000000ff)
                    format = GL_RGB;
            else
                    format = GL_BGR;
    }
    else {
        gCritical("Image is not truecolor");
    }

    glGenTextures( 1, &tex );

    glBindTexture( GL_TEXTURE_2D, tex );

    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D( GL_TEXTURE_2D, 0, colors_amount, surf->w, surf->h, 0, format, GL_UNSIGNED_BYTE, surf->pixels );
    return tex;
}

/** */
void RendererGL::draw( SDL_Surface* surf, SDL_Rect& Dest ) {
	  glBindTexture(GL_TEXTURE_2D, get_gl(surf) );

		     glBegin(GL_QUADS);
		     {
		         glTexCoord2f(0,0);//1
		         glVertex2f( Dest.x, Dest.y );

		         glTexCoord2f( 1, 0 );//2
		         glVertex2f( Dest.x + Dest.w, Dest.y );

	             glTexCoord2f(1, 1);//3
		         glVertex2f( Dest.x + Dest.w , Dest.y + Dest.h );

		         glTexCoord2f(0,1);//4
		         glVertex2f( Dest.x, Dest.y + Dest.h);
		     }
		     glEnd();
}



/** Wyslanie na ekran zawartosci buforu */
void RendererGL::flip() {
	 SDL_GL_SwapBuffers();

}

/** Czyszczenie ekranu za pomoca GL */
void RendererGL::cleanScreen() {
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
}

