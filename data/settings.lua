--[[ cxx_addProperty(string klucz,string wartosc) -> w grze: string Property::get(string klucz);
     cxx_addSetting(string klucz,double wartosc) -> w grze: double Property::getSetting(string klucz); --]]

-- Sciezki do plikow
print("[ LUA ] Load files path");
cxx_addProperty("ATLAS_PATH" , "data/atlas.png");
cxx_addProperty("FONT_BOLD_PATH" , "data/ubuntu_bold.ttf");
cxx_addProperty("FONT_REGULAR_PATH" , "data/ubuntu_regular.ttf");
cxx_addProperty("FONT_MEDIUM_PATH" , "data/ubuntu_medium.ttf");

-- Czcionki
print( "[ LUA ] Loads font name" );
cxx_addSetting("SMALL_FONT", 14 );
cxx_addSetting("NORMAL_FONT", 18 );
cxx_addSetting("BIG_FONT", 22 );

-- Ustawienia aplikacji
print( "[ LUA ] Loading application settings" );
cxx_addSetting("TIME_STEP", 500/60 );
cxx_addSetting("ITEM_SPACE", 40 );

--Ustawienia playera
print( "[ LUA ] Loading player settings" );
cxx_addSetting("PLAYER_OFFSET_X", 100 );
cxx_addSetting("PLAYER_OFFSET_Y", 150 );
cxx_addSetting("PLAYER_SLEEP_TIME", 6  );
cxx_addSetting("PLAYER_SPEED", 10 );
cxx_addSetting("PLAYER_Y_ACCELERATION", -200.0 );
cxx_addSetting("PLAYER_Y_VELOCITY", 100 );
cxx_addSetting("PLAYER_MAX_Y_POS", 120 );
cxx_addSetting("PLAYER_SIZE", 100 );

--Ustawienia mapy
print( "[ LUA ] Loading map settings" );
cxx_addSetting("MAP_LEVEL_1_SIZE", 50 );
cxx_addSetting("MAP_LEVEL_1_SPEED", 160 );
cxx_addSetting("LEVEL_VARIANTS", 38 );

-- Ustawienia HighScore
cxx_addSetting("HIGH_OFFSET_Y", 20 );

-- Ustawienia Menu
cxx_addSetting("MENU_SPRITE_SIZE", 220 );

