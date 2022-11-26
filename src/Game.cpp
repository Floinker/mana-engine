#include "Game.h"
#include "Map.h"
#include "TextureManager.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders;

Map* map;
Manager manager;

auto& playerEntity(manager.addEntity());

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 63, 118, 255, 255);
			std::cout << "Renderer created!..." << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	map = new Map();

	Map::LoadMap("assets/map1.map", 16, 16);

	playerEntity.addComponent<TransformComponent>(100, 500);
	playerEntity.addComponent<SpriteComponent>("assets/player.png");
	playerEntity.addComponent<KeyboardController>();
	playerEntity.addComponent<ColliderComponent>("player");
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

int cnt = 0;
void Game::update()
{
	manager.refresh();
	manager.update();

	for (auto cc : colliders) {
		Collision::AABB(playerEntity.getComponent<ColliderComponent>(), *cc);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::AddTile(int id, int x, int y) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, Game::TILE_SIZE, Game::TILE_SIZE, id);
}