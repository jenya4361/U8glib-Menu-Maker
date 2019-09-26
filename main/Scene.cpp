#include "Scene.h"

Scene::Scene()
  : m_name( "" )
  , m_nextY( 15 )
  , m_isActive( false )
  , m_currentCursorIndex( 0 )
{

}

Scene::Scene( const char* name )
  : m_name( name )
  , m_nextY( 15 )
  , m_isActive( false )
  , m_currentCursorIndex( 0 )
{

}

Scene::Scene( const Scene& scene )
  : m_name( scene.m_name )
  , m_nextY( scene.m_nextY )
  , m_isActive( scene.m_isActive )
  , m_currentCursorIndex( 0 )
{

}

void Scene::addFrame( int w, int h )
{
  m_frame.x = 0;
  m_frame.y = 0;
  m_frame.width = w;
  m_frame.height = h;
}

void Scene::addButton( const char* name, void (*callback)() )
{
  Button newButton;
  newButton.setCoords( Rect( 1, m_nextY, 121, 15 ) );
  newButton.setText( name );
  bool isFirst = !m_buttons.size();
  
  m_buttons.push_back( ButtonData( newButton, callback ) );
  if( isFirst )
    setCursorButtonIndex( 0 );

  m_nextY += 15;
}

void Scene::setCursorButtonIndex( int buttonIndex )
{
  m_currentCursorIndex = buttonIndex;
  
  for( int i = 0; i < m_buttons.size(); i++ )
  {
    ButtonData& button = m_buttons[i];
    button.first.setAdditionalText( i == buttonIndex ? " <-" : "" );
  }
}

void Scene::cursorUp()
{
  if( !m_buttons.size() )
    return;

  int newCursorIndex 
    = m_currentCursorIndex - 1 < 0
    ? (m_buttons.size() - 1)
    : m_currentCursorIndex - 1;

  setCursorButtonIndex( newCursorIndex );
}

void Scene::cursorDown()
{
  if( !m_buttons.size() )
    return;

  int newCursorIndex 
    = m_currentCursorIndex + 1 > (m_buttons.size() - 1)
    ? 0
    : m_currentCursorIndex + 1;

  setCursorButtonIndex( newCursorIndex );
}

void Scene::pressCurrentButton()
{
  if( !m_buttons.size() )
    return;

  m_buttons[m_currentCursorIndex].second();
}
