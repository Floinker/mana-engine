#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map() {

}

Map::~Map() {

}

 void Map::LoadMap(std::string path, int sizeX, int sizeY) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			Game::AddTile(atoi(&tile), x * Game::TILE_SIZE * Game::PIXEL_SCALE, y * Game::TILE_SIZE * Game::PIXEL_SCALE);
			mapFile.ignore();
		}
	}

	mapFile.close();
}