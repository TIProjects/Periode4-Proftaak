#pragma once
#include <GL\freeglut.h>

void idle();
int  getDeltaTime(const int* delta);

static int deltaTime;
static int lastTime;