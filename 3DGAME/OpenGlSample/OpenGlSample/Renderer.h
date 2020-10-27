#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "ICleanUp.h"
#include "IUpdate.h"
#include "IRender.h"
#include "KeyInput.h"

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
//midterm test
struct GLFWwindow;

class RenderableObject;
class Sphere;

class Renderer : public ICleanUp
{
private:
	glm::vec3 cameraPos;

	std::vector<RenderableObject*> objList;

public:

	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:
	GLFWwindow* window;

	void render();
	void renderObject(RenderableObject* src_obj);
	void init();
	virtual void shutDown() override;
	GLFWwindow* GetWindow() { return window; }
	void update(IUpdate* src_obj);
	void addObject(RenderableObject* render_obj);
	void setCameraPos(float x, float y, float z);
	float initialFoV = 45.0f;
	void Clear();
	void Out();

public:
	glm::mat4 getPosition(glm::mat4, RenderableObject* src_obj);
};

#endif // !__RENDERER_H__