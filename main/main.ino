// Include main lib file
#include "MenuMaker.h"

void setup(void) {
  Serial.begin(9600);

  // Init display size
  MenuMaker::Instance()->init( 123, 62 );

  // Create your own scene
  Scene* createdScene = MenuMaker::Instance()->createScene( "Garage" );

  // Add buttons to this scene
  createdScene->addButton( "Open door", 
    [](){ Serial.print( "Door opened" ); } );
    
  createdScene->addButton( "Close door", 
    [](){ Serial.print( "Door closed" ); } );
    
  createdScene->addButton( "<<< Back", 
    [](){ Serial.print( "To Previous menu" ); } );

  // Display this or another scene
  MenuMaker::Instance()->showScene( "Garage" );

  // Refresh screen rate (MS)
  MenuMaker::Instance()->setUpdateTimeMS( 2000 );

  // Call cursorUp and cursorDown methoods to move cursor
  createdScene->cursorDown();

  // Current button callback
  createdScene->pressCurrentButton();
}

void loop(void) {
  // Menu maker update
  MenuMaker::Instance()->update(millis());
}
