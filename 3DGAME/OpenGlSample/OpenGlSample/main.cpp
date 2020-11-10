#define _CRT_SECURE_NO_WARINGS
//midterm test
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"
#include "Time.h"
#include "Sun.h"

int main()
{
	FileManager* filemgr = FileManager::instance();

	Time* time = Time::instance();
	Renderer* renderer = Renderer::instance();

	RenderableObject* render_obj = new RenderableObject();
	NonRenderableObject* non_render_obj = new NonRenderableObject();

	Sun* sun = new Sun();

	renderer->init();

	while (true)
	{
		renderer->Clear();

		if (time->IsFixedRendering())
		{
			renderer->update();
		}

		renderer->render();

		renderer->Out();
	}


	renderer->shutDown();
	sun->shutDown();

	delete sun;
	delete non_render_obj;

	return 0;
}