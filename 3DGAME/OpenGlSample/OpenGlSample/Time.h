#pragma once
#include <Windows.h>

class Time
{
private:
	int frame;
	int count;
	double _perFrame;
	LARGE_INTEGER _frameInfo;
	LARGE_INTEGER _prevFrameCounter;
	LARGE_INTEGER _nowFrameCounter;

	Time();

public:
	static Time* instance()
	{
		static Time instance;

		return &instance;
	}

	bool IsFixedRendering();
};