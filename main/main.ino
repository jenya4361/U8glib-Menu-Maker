#include "MenuMaker.h"

void setup(void) {
  Serial.begin(9600);

  // Init display size
  MenuMaker::Instance()->init( 123, 62 );
  
  Scene* createdScene = MenuMaker::Instance()->createScene( "Garage" );
  createdScene->addButton( "Open door", 
    [](){ Serial.print( "Door opened" ); } );
    
  createdScene->addButton( "Close door", 
    [](){ Serial.print( "Door closed" ); } );
    
  createdScene->addButton( "<<< Back", 
    [](){ Serial.print( "To Previous menu" ); } );

  MenuMaker::Instance()->showScene( "Garage" );
  MenuMaker::Instance()->setUpdateTimeMS( 2000 );
  
  createdScene->cursorDown();
  createdScene->pressCurrentButton();
}

void loop(void) {
  MenuMaker::Instance()->update(millis());
}
