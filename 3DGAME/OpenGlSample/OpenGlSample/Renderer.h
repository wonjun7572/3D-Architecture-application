#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "ICleanUp.h"
#include "RenderableObject.h"

struct GLFWwindow;
class Object;

class Renderer: public ICleanUp 
{
private:
	GLFWwindow* window;
	
public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:

	void render(RenderableObject* src_obj);
	void init();
	void addObject(RenderableObject* src_obj);
	void update(Object* src_obj);


	virtual void shutDown() override;
};

#endif // !__RENDERER_H__