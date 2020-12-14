#define _CRT_SECURE_NO_WARINGS
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")
#pragma comment(lib, "Winmm.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Time.h"
#include "CompositeObject.h"
#include "../include/Earth.h"
#include "../include/BackGround.h"
#include "../include/Meteor.h"
#include "../include/Reset.h"

bool CheckCollision(CompositeObject* one, CompositeObject* two)
{
	bool collisionX = one->position.x + 1.0 >= (two->position.x) / 2 && (two->position.x) / 2 + 1 >= one->position.x;
	bool collisionY = one->position.y + 1.0 >= (two->position.y) / 2 && (two->position.y) / 2 + 1 >= one->position.y;
	bool collisionZ = one->position.z + 1.0 >= (two->position.z) / 2 && (two->position.z) / 2 + 1 >= one->position.z;
	return collisionX && collisionY && collisionZ;
}

int main()
{
	PlaySound(TEXT("InLakeBGM.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	FileManager* filemgr = FileManager::instance();

	Time* time = Time::instance();
	Renderer* renderer = Renderer::instance();

	RenderableObject* render_obj = new RenderableObject();
	NonRenderableObject* non_render_obj = new NonRenderableObject();

	BackGround* background = new BackGround();
	Earth* earth = new Earth();
	Reset* reset = new Reset();

	vector<Meteor*>* meteor = new vector<Meteor*>();

	for (int i = 0; i < 30; i++)
	{
		meteor->push_back(new Meteor());
	}

	renderer->init();

	background->setScale(5.0f, 5.0f, 0.1f);
	earth->setScale(0.2f, 0.2f, 0.2f);

	for (
		vector<Meteor*>::const_iterator it = meteor->begin();
		it != meteor->end();
		++it
		)
	{
		(*it)->setScale(0.2f, 0.2f, 0.2f);
	}

	while (true)
	{
		renderer->Clear();

		if (time->IsFixedRendering())
		{
			renderer->update();
		}

		renderer->render();

		for (
			vector<Meteor*>::const_iterator it = meteor->begin();
			it != meteor->end();
			++it
			)
		{
			if (CheckCollision(earth, (*it)))
			{
				earth->setPosition(0.0f, 0.0f, 0.0f);
				earth->setIsLive(false);
				reset->setGameOver(false);
			}
		}

		if (reset->getGameOver() && earth->getIsLive() == false)
		{
			earth->init();

			for (
				vector<Meteor*>::const_iterator it = meteor->begin();
				it != meteor->end();
				++it
				)
			{
				(*it)->init();
			}
		}

		renderer->Out();
	}

	for (
		vector<Meteor*>::const_iterator it = meteor->begin();
		it != meteor->end();
		++it
		)
	{
		delete (*it);
	}

	renderer->shutDown();

	delete background;
	delete earth;
	delete reset;
	delete non_render_obj;

	return 0;
}