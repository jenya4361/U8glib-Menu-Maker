#include "MenuMaker.h"

void setup(void) {

  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);
  
  Serial.begin(9600);

  
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Menu.init();
  Menu.setUpdateTimeMS( 1000 );
}

void loop(void) {

  Menu.update(millis());
}
