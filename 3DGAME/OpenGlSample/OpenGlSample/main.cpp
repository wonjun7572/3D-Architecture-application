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
#include "Obj.h"

int main()
{
	FileManager* filemgr = FileManager::instance();

	Time* time = Time::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* ground = new RenderableObject();
	renderer->addObject(ground);

	filemgr->loadObJ(
		ground,
		"ground.obj",
		"skin.BMP",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	Sphere* sun = new Sphere(filemgr);
	renderer->addObject(sun);

	Obj* earth = new Obj();
	renderer->addObject(earth);

	filemgr->loadObJ(
		earth,
		"orb.obj",
		"8k_earth.BMP",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	Obj* moon = new Obj();
	renderer->addObject(moon);

	filemgr->loadObJ(
		moon,
		"orb.obj",
		"8k_moon.BMP",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	sun->setPosition(-2.0f, 5.0f, 0.0f);
	earth->setPosition(2.0f, 5.0f, 0.0f);
	moon->setPosition(0.0f, 3.0f, 0.0f);
	ground->setPosition(0.0f, -10.0f, 0.0f);
	
	sun->setMoving(true);
	earth->setMoving(true);
	moon->setMoving(true);
	ground->setMoving(false);

	NonRenderableObject* non_render_obj = new NonRenderableObject();

	renderer->setCameraPos(0, 5, 13);


	while (true)
	{
		renderer->Clear();

		if (time->IsFixedRendering())
		{
			renderer->update(earth);
			renderer->update(moon);
			renderer->update(non_render_obj);
		}

		renderer->render();

		renderer->Out();
	}

	sun->shutDown();
	renderer->shutDown();
	moon->shutDown();
	earth->shutDown();
	moon->shutDown();

	delete moon;
	delete earth;
	delete sun;
	delete non_render_obj;

	return 0;
}