#include "RenderableObject.h"
#include "Renderer.h"

RenderableObject::RenderableObject()
{
	_IsMoveCheck = false;
	Renderer* renderer = Renderer::instance();
	renderer->addRenderObject(this);
}
