#include "CompositeObject.h"
#include <iostream>

CompositeObject::CompositeObject()
{
	children = new vector<CompositeObject*>();
	Parent = nullptr;
	//movePos = glm::mat4(1.0f);
}

CompositeObject::~CompositeObject()
{
	for (
		vector<CompositeObject*>::const_iterator it = children->begin();
		it != children->end();
		++it
		)
	{
		delete (*it);
	}

	children->clear();

	delete children;
}


void CompositeObject::AddChild(CompositeObject* addObj)
{
	children->push_back(addObj);

	addObj->Parent = this;
}

void CompositeObject::update()
{
	if (Parent)
	{
		WorldTransform = Parent->WorldTransform * Transform;
	}
	else
	{
		WorldTransform = Transform;
	}
}