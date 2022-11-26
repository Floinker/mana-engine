#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x , int y) {
	this->objTexture = TextureManager::LoadTexture(textureSheet);
	this->xpos = x;
	this->ypos = y;
}

void GameObject::Update() {

	xpos++;
	ypos++;

	srcRect.w = 21;
	srcRect.h = 38;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * Game::PIXEL_SCALE;
	destRect.h = srcRect.h * Game::PIXEL_SCALE;
}

void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}