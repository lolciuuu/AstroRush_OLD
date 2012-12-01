/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef WRITER_HPP
#define WRITER_HPP
#include "Headers.hpp"
#include "Renderer.hpp"

class Writer
{

public:
 
  void draw( SDL_Rect WhereRect, string Text );
  void draw( SDL_Rect WhereRect, string Text , SDL_Color Color );
  
  static Writer* getInstance(){
		if( pInstance == NULL ){
		    atexit( clean );
			pInstance = new Writer();
			return pInstance;
		}
		return pInstance;
	}
	
   ~Writer();
	
	void init();
	
	void setFont(string fontName, SDL_Color fontColor); 
	
	void setFont( string FontName );
	
	void setScreenPtr(SDL_Surface* Screen){ pScreen = Screen; };
	
private:
   Writer();
   
   static void clean(){ delete pInstance; }
   
private:  
  static Writer* pInstance;
  Renderer* pRendererPtr;
  
  SDL_Surface* pScreen;
  
  TTF_Font* pFont;
  
};

#endif // WRITER_HPP

