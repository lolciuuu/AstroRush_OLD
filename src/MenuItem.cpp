#include "../include/MenuItem.hpp"

MenuItem::MenuItem(Sprite sprite, string name, SDL_Rect Where ): pItemName( name ),
        pImage( sprite ), pDesciption(""), pIsActive( true ), pIsSelected( false ),pCurrentItem(0)
{
  /// @TODO przeniesc offset sprita do zasobow
  pImage.setX( Where.x );
  pImage.setY( Where.y );
  
  pColorActive = SDL_Color( { 0,166, 252 } );  //119, 184, 0 

  
}


/** Metoda rysuje pojedynczy element w menu. W zaleznosci do
 * statu w jakim sie znajduje moze miec kolor: szary - nie aktywny, pomaranczowy- aktualnie wybrany
 * badz bialy domyslny.
 */
void MenuItem::draw() {

    // Rysowanie pozycji w menu glownym
    {	
        if ( !pIsActive && !pIsSelected) { // Rysowanie wyszarzonego itema

            SDL_Color color( {120,120,120} );
            pWriterPtr->draw( pRectName ,pItemName, color);

        }        
        else if ( pIsSelected ) { // Rysowanie aktywnego itema

            /// @TODO rysowanie obrazka menu, opisu, strzalek itd...

            SDL_Color color( {243,112,34} );
            pWriterPtr->draw( pRectName ,pItemName, pColorActive);


            // Rysowanie opisu pozycji badz tez itemsa dla itema menu
            {
                if( pItems.size() > 0 ){
		  SDL_Rect rect( {300,300,100,100});
		  pWriterPtr->draw( rect ,pItems[pCurrentItem] );
		}
		else{ // pokazanie opisu zaraz pod obrazkiem 
		    SDL_Rect rect;
		    rect.x = pImage.getX();
		    rect.y = pImage.getY() + ( pImage.getRect() ).h + 50;
		    rect.w = 300;
		    rect.h = 100;
		    pWriterPtr->draw( rect ,pDesciption );
		}
		
            }
            //Rysowanie obrazka dla danego itema
            {
	      pImage.draw();

            }
        }
        // Rysowanie domyslnego itema
        else {

            pWriterPtr->draw( pRectName ,pItemName );

        }
    }
}


/**
 */
void MenuItem::next(){
 
   if( pCurrentItem < (ushort)pItems.size()-1 ){
      ++pCurrentItem;
      Property::resetLang( pItems[pCurrentItem] );      
    }
 
}


/** */
void MenuItem::prev(){

  if( pCurrentItem > 0 ){
      --pCurrentItem;
      Property::resetLang( pItems[pCurrentItem] );
  }
 
}

/** */
void MenuItem::update( float dt ){

  pImage.update( dt );
  
}

