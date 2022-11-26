#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class ColliderComponent;

class Game
{
public:
	static const int PIXEL_SCALE = 2;
	static const int TILE_SIZE = 16;

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	static void AddTile(int id, int x, int y);

	bool running() { return isRunning;  };

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
};

