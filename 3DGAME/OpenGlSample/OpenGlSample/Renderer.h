#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "ICleanUp.h"
#include "IUpdate.h"
#include "IRender.h"

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

struct GLFWwindow;

class RenderableObject;
class Sphere;

class Renderer : public ICleanUp
{
private:
	GLFWwindow* window;
	std::vector<RenderableObject*> objList;

public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:

	void render();
	void renderObject(RenderableObject* src_obj);
	void init();
	virtual void shutDown() override;
	GLFWwindow* GetWindow() const { return window; }
	void update(IUpdate* src_obj);
	void addObject(RenderableObject* render_obj);

	void Clear();
	void Out();

public:
	glm::mat4 getPosition(glm::mat4, RenderableObject* src_obj);

};

#endif // !__RENDERER_H__