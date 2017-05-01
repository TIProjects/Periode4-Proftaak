#pragma once
#include <GL\freeglut.h>

static int width = 1280;
static int height = 720;
static float camNear = 0.1f;
static float camFar = 50.0f;

void window();
void reshape(int w, int h);
void drawCube();