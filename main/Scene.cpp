#include "Scene.h"

Scene::Scene()
  : m_name( String() )
  , m_nextY( 0 )
  , m_isActive( false )
{

}

Scene::Scene( const String& name )
  : m_name( name )
  , m_nextY( 0 )
  , m_isActive( false )
{

}

Scene::Scene( const Scene& scene )
  : m_name( scene.m_name )
  , m_nextY( scene.m_nextY )
  , m_isActive( scene.m_isActive )
{

}

void Scene::addButton( const String& name, void (*callback)() )
{
  Button newButton;
  newButton.setCoords( Int4Data( 1, m_nextY, 121,15 ) );
  newButton.setText( name );
  
  m_buttons.push_back( ButtonData( newButton, callback ) );

  m_nextY += 15;  
}

