#include "MenuMaker.h"

MenuMaker* Menu;

void setup(void) {

  pinMode(13, OUTPUT);    
  
  Serial.begin(9600);
  
  //pinMode(4, INPUT);
  //pinMode(5, INPUT);
  //pinMode(6, INPUT);
  //pinMode(7, INPUT);

  Menu = new MenuMaker();
  Serial.print( "Hello!" );
  
  Menu->init(123, 63);
  Menu->createScene("Some");
  Menu->getScene( "Some" ).addButton( "Button 0", 
    []()
    {
        Serial.print( "Button 0 pressed" );
    } );
    
  Menu->showScene( "Some" );
  Menu->setUpdateTimeMS( 2000 );

  Serial.print( "Hello" );
  digitalWrite(13, HIGH);
}

void loop(void) {
  Menu->update(millis());
}
