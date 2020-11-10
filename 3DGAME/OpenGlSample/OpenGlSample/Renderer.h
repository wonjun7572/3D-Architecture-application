#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "FileManager.h"
#include "ICleanUp.h"
#include "IUpdate.h"
#include <vector>

class RenderableObject;
class NonRenderableObject;

class Renderer : public ICleanUp
{
private:
	glm::vec3 cameraPos;

	std::vector< RenderableObject*> renderObjList;
	std::vector< NonRenderableObject*> nonrenderObjList;

public:

	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:
	GLFWwindow* window;

	void addRenderObject(RenderableObject* obj);
	void addNonRenderObject(NonRenderableObject* obj);

	void render();
	int init();
	virtual void shutDown() override;

	void update();
	void Clear();
	void Out();
};

#endif // !__RENDERER_H__