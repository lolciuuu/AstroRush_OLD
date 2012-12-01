#ifndef STANDARDREFERENCES_HPP
#define STANDARDREFERENCES_HPP

#include "Renderer.hpp"
#include "Writer.hpp"
#include "Resource.hpp"
#include "Property.hpp"


class StandardReferences {
public:  
  StandardReferences() :
      pRendererPtr( Renderer::getInstance() ),
      pWriterPtr( Writer::getInstance() )
      {
	// Ustawienie referencji do globalnych modulow
      }
  
protected:
  Renderer* pRendererPtr;
  Writer* pWriterPtr;  

};
#endif