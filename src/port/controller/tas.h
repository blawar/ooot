#pragma once
#include <stdio.h>
#include "controllers.h"


class Tas : public N64Controller, public InputDevice
{
public:
	static bool isTasPlaying();

	Tas();
	virtual ~Tas();
	void scan() override;
	void update();

private:
	FILE* fp;
};