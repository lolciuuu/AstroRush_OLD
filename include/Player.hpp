#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Headers.hpp"
#include "Sprite.hpp"
#include "Logger.hpp"

class Player
{
public:
    Player();
    void draw();
    void update(const float& dt );
    void reset();
    void run();
    void jump();
    
    short getPosX() const { return( pX ); }
    short getPosY() const { return( pY ); }
    
    void SpaceUp() {   pIsFly = false; }
    void SpaceDown(){   pIsFly = true; }

private:
  Sprite pRunSprite;
  Sprite pStandSprite;
  Sprite pFlySprite;
  PlayerState pState;
  Sprite* pCurrentSprite;
  
  short pX;
  short pY;

  bool pJumpAllowed;

  float pSpeed;
  float pVY;
  float pAY;
  
  // stale wczytane z zasobow
  const float PLAYER_Y_ACCELERATION;
  const float PLAYER_Y_VELOCITY;
  const float PLAYER_MAX_Y_POS;
  const float PLAYER_Y_OFFSET;
  const float MAX_Y_PLAYER;
  
  bool pIsFly;

  Logger logger;

    
};

#endif // PLAYER_HPP
