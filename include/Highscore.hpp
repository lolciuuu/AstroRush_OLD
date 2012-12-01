#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include "Headers.hpp"
#include "ColisionType.hpp"
#include "StandardReferences.hpp"

class Highscore: StandardReferences
{
public:
  Highscore();
  
  void show();
  
  void colision( ColisionType type );
  
  static void load();
  
  static void save();
  
private:
  
private:
  
  struct HighscoreItem {
    string name;
    string distance;
    string points;
  };
  static vector<HighscoreItem> pList;
  

 
};

#endif // HIGHSCORE_HPP
