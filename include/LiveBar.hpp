#ifndef LIVEBAR_HPP
#define LIVEBAR_HPP
#include "Headers.hpp"
#include "Renderer.hpp"
#include "ColisionType.hpp"
#include "Writer.hpp"

class LiveBar {
public:
  LiveBar();  
  
  void reset();
  
  void draw();
  
  void update(const float& dt );
  
  static bool isALive() { return( isLive ); }
  
  static void colision( ColisionType type );
  static void increaseLive();
  
  static string getResult() { return( toString<ulong>(pDistNum) ); }
  
  
  static void nextMeter() { ++pDistNum; }
  static void resetMeter() { pDistNum = 0; } /// @TODO Zapisanie wyniku
  
private:
  Renderer* pRendererPtr;
  Writer* pWriterPtr;
  static bool isLive;
  static float pLiveAmount;
  
  
  SDL_Rect pDistanceRect;
  string pDistStr;
  static ulong pDistNum;
  
  
};
#endif
