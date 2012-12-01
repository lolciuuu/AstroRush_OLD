#include "../include/Menu.hpp"
#include "App.hpp"
#include "Game.hpp"

/** Tutaj odbywa sie tworzenie wszystckich elementow glownego menu
 * pCurrentItem : domyslnie 1, bo 0 to resume game i przy starcie jest nie aktywne
 */
Menu::Menu() : pIsDone ( false ),pMenuState ( Gamespace::MAIN ), pCurrentItem ( 1 ) 
{
  gInfo("Constructor class: MENU");
   
    /// @TODO dokonczyc
    /// @TODO zrobic porzadek w tym syfie
  
    ushort pos_y = 250;
    ushort pos_x = ( App::getScreenWidth() / 2 ) + 100;
    ushort item_space = Property::getSetting ( "ITEM_SPACE" );

    // 
    SDL_Rect whereSpriteRect;
    whereSpriteRect.x = ( App::getScreenWidth()/2 ) - Property::getSetting("MENU_SPRITE_SIZE");
    whereSpriteRect.y = ( App::getScreenHeight()/2 ) - Property::getSetting("MENU_SPRITE_SIZE");
    
    // Wymiary textu w menu
    const ushort MENU_ITEM_TEXT_W( 300 );
    const ushort MENU_ITEM_TEXT_H( 100 );
    
    /** Wpis w menu:  -- Return -- */
    MenuItem resumeGameItem ( Sprite(SpriteManager::getInstance().getSprite("NEW_GAME") )
    		, Property::get( "RESUME_GAME" ),whereSpriteRect );
    {
         resumeGameItem.setActive ( false );
         resumeGameItem.setDescription ( Property::get ( "RESUME_GAME_DESC" ) );

         SDL_Rect rectName;
         rectName.x = pos_x;
         rectName.y = pos_y;
         rectName.w = MENU_ITEM_TEXT_W;
         rectName.h = MENU_ITEM_TEXT_H;


         resumeGameItem.setRectName ( rectName );
	pos_y += item_space;
    }

    /** Wpis w menu:  -- New Game -- */
    MenuItem playGameItem ( Sprite(SpriteManager::getInstance().getSprite("NEW_GAME") ) ,
			  Property::get ("NEW_GAME"), whereSpriteRect );  
    {
        playGameItem.setDescription ( Property::get ( "NEW_GAME_DESC" ) );
        playGameItem.setSelected ( true );
        SDL_Rect rectName;
              rectName.x = pos_x;
              rectName.y = pos_y;
              rectName.w = MENU_ITEM_TEXT_W;
              rectName.h = MENU_ITEM_TEXT_H;
        playGameItem.setRectName ( rectName );
        pos_y += item_space;
    }
   

    /** Wpis w menu:  -- HighScore -- */
    MenuItem highGameItem ( Sprite(SpriteManager::getInstance().getSprite("NEW_GAME") )
    		, Property::get ( "HIGH_GAME" ),whereSpriteRect );
    {
        highGameItem.setDescription ( Property::get ( "HIGH_GAME" ) );
        SDL_Rect rectName;
              rectName.x = pos_x;
              rectName.y = pos_y;
              rectName.w = MENU_ITEM_TEXT_W;
              rectName.h = MENU_ITEM_TEXT_H;
        highGameItem.setRectName ( rectName );
        pos_y += item_space;
    }
  
  
    /** Wpis w menu:  -- About -- */
    MenuItem AboutGameItem ( Sprite(SpriteManager::getInstance().getSprite("NEW_GAME") )
    		, Property::get ( "ABOUT_GAME" ),whereSpriteRect );
    {
       AboutGameItem.setDescription ( Property::get ( "ABOUT_GAME_DESC" ) );
       SDL_Rect rectName;
             rectName.x = pos_x;
             rectName.y = pos_y;
             rectName.w = MENU_ITEM_TEXT_W;
             rectName.h = MENU_ITEM_TEXT_H;
       AboutGameItem.setRectName ( rectName );
       pos_y += item_space;
    }
      
      
    /** Wpis w menu:  -- Exit -- */
    MenuItem exitItem ( Sprite(SpriteManager::getInstance().getSprite("NEW_GAME") )
    		, Property::get ( "EXIT_GAME" ),whereSpriteRect );
    {
        exitItem.setDescription ( Property::get ( "EXIT_GAME_DESC" ) );
        SDL_Rect rectName;
              rectName.x = pos_x;
              rectName.y = pos_y;
              rectName.w = MENU_ITEM_TEXT_W;
              rectName.h = MENU_ITEM_TEXT_H;
        exitItem.setRectName ( rectName );
    }

    
    /** Dodanie wszystckich wpisow w okreslonej kolejnosci */
    pMainMenuItem.push_back ( resumeGameItem );
    pMainMenuItem.push_back ( playGameItem );
    pMainMenuItem.push_back ( highGameItem );
    pMainMenuItem.push_back ( AboutGameItem );
    pMainMenuItem.push_back ( exitItem );
    
}


/**
 */
bool Menu::update (const float& dt ) {

   //  pRendererPtr->fillScreen( pRendererPtr->getRGB( 0, 0, 0 ) ); // wypelnienie ekrany wybranym kolorem
  
    switch ( pMenuState ) {

    case ( MAIN ) : {
        pMainMenuItem[ pCurrentItem ].update ( dt );
        break;
    }
    case ( HIGHSCORE ) : {
        pHighScore.show();
        break;
    }
    default: {
        gWarring ( "Unknown value of MenuState [Method: Menu::update() ]" );
        break;
    }

    }


    return pIsDone;
}

/** */
void Menu::draw() {

    switch ( pMenuState ) {
    case ( MAIN ) : {
        drawMainMenu();
        break;
    }
    case ( HIGHSCORE ) : {
        pHighScore.show();
        break;
    }
    default: {
        gWarring ( "Unknown value of MenuState [Method: Menu::draw() ]" );
        break;
    }
    }

}


/**
 */
void Menu::drawMainMenu() {
 
    //pRendererPtr->drawImg( string("MENU_TITLE"), pMenuTitleRect );
  
    pWriterPtr->setFont ( "bold_big" );

    for ( register uint i = 0; i < pMainMenuItem.size(); ++i ) {
        pMainMenuItem[i].draw();

    }

}


/** Obsluga nacicniecia entera w menu glownym */
void Menu::pressedReturn() {


    string currentItem = pMainMenuItem[pCurrentItem].getItemName();


    if ( currentItem ==  Property::get ( "RESUME_GAME" ) ) {
      
        Game::setGameState ( Gamespace::PLAY );
	
    } else if ( currentItem == Property::get ( "NEW_GAME" ) ) {

        // stworzenie nowej gry
        Game::setGameState ( Gamespace::PLAY );
        pMainMenuItem[0].setActive ( true );
        pMainMenuItem[ pCurrentItem ].setSelected ( false );
        pMainMenuItem[0].setSelected ( true );
        pCurrentItem = 0;
        pMainMenuItem[0].setSelected ( true );
	  
	// zresetowanie gry
	Game::resetGame();

    } else if ( currentItem ==  Property::get ( "HIGH_GAME" ) ) {
      // przejscie z menu do highscore
        pMenuState = Gamespace::HIGHSCORE;

    } else if ( currentItem ==  Property::get ( "EXIT_GAME" ) ) {
        // normalne wyjscie z gry poprzez wybranie exit w menu
        pIsDone = true;
    }




}


/**
 *
 */
void Menu::pressedEsc() {

    switch ( pMenuState ) {

    case ( MAIN ) : {
        pIsDone = true;
        break;
    }
    case ( HIGHSCORE ) : {
        // Powrot z highscore do glownego menu
        pMenuState = Gamespace::MAIN;
        break;
    }
    default: {
        gWarring ( "Error in Menu::pressedEsc" ); 
        break;
    }

    }

}

/**
 */
void Menu::pressedRight() {

    switch ( pMenuState ) {

    case ( MAIN ) : {
        if ( pMainMenuItem[pCurrentItem].getItemsNo() ) {
            pMainMenuItem[pCurrentItem].next();
        }
        break;
    }
    case ( HIGHSCORE ) : {
        break;
    }
    default: {
        gWarring ( "Error in Menu::pressedRight" );
        break;
    }
    }

}


/**
 */
void Menu::pressedLeft() {

    switch ( pMenuState ) {

    case ( MAIN ) : {
        if ( pMainMenuItem[pCurrentItem].getItemsNo() ) {
            pMainMenuItem[pCurrentItem].prev();
        }
        break;
    }
    case ( HIGHSCORE ) : {
        break;
    }
    default: {
        gWarring ( "Error in Menu::pressedRight" );
        break;
    }

    }


}


/**
 */
void Menu::pressedDown() {
    ///@TODO ustawienie elelemntu menu ponizej

    if ( pCurrentItem < ushort ( pMainMenuItem.size() - 1 ) ) {
        pMainMenuItem[pCurrentItem].setSelected ( false );
        pMainMenuItem[ ++pCurrentItem ].setSelected ( true );

    }


}


/** Przechodzenie do elementu menu znajdujacego sie powyzej
 */
void Menu::pressedUp() {

    if ( pCurrentItem > 1 ) {
        pMainMenuItem[pCurrentItem].setSelected ( false );
        pMainMenuItem[ --pCurrentItem ].setSelected ( true );
    } else if ( pCurrentItem == 1 ) {
        if ( pMainMenuItem[0].isActive() ) {
            pMainMenuItem[pCurrentItem].setSelected ( false );
            pMainMenuItem[ --pCurrentItem ].setSelected ( true );
        }

    }

}







