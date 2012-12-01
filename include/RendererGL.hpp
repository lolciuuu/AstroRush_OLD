#ifndef RENDERERGL_HPP
#define RENDERERGL_HPP
#include "Headers.hpp"
#include "Resource.hpp"

class RendererGL {
public:
	RendererGL();

	virtual ~RendererGL(){}

	virtual void draw( SDL_Rect& Src, SDL_Rect& Dest );

	virtual void draw( SDL_Surface* surf, SDL_Rect& where );

	void draw( SDL_Rect& Src, float x, float y, float w, float h );

	virtual void drawBackground();

	void flip();

	void cleanScreen();

	void init();
  
protected:
    SDL_Surface* pScreen;
    SDL_Surface* pAtlas;
    SDL_Surface* pBackground;

    SDL_Rect pScreenRect;

private:
	void create_gl(SDL_Surface * surface, GLuint * tex );
	GLuint get_gl(SDL_Surface * surface );

private:
	unsigned pAtlas_GL;
	unsigned pBackground_GL;
	bool isInit;
  
};

#endif
