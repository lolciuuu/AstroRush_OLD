#ifndef SPRITE_HPP
#define SPRITE_HPP
#include "Spriteconfig.hpp"
#include "Renderer.hpp"

class Sprite
{

public:
    Sprite( SpriteConfig Config );
    
    void draw();
    void draw( short pos_x, short pos_y );
    void update( float dt );
    
    short getX() const { return pData.pos_x; }
    short getY() const { return pData.pos_y; }
    
    void setX( short X ) { pData.pos_x = X; }
    void setY( short Y ) { pData.pos_y = Y; }
    
    SDL_Rect getRect() const;
    
    void centered();
    
    void reset() { pCurentFrame = 0; pCurentFrameDuration = 0.0F; }
    
private:
  
  
private:
    SpriteConfig pData;
    ushort pCurentFrame;
    float pCurentFrameDuration;
    Renderer* pRenderer;
    
    SDL_Rect pSrc;
    SDL_Rect pDes; 
};

#endif // SPRITE_HPP
