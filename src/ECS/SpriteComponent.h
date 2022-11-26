#pragma once
#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}

	void setTex(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}
	void init() override {
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
		destRect.w = srcRect.w * Game::PIXEL_SCALE;
		destRect.h = srcRect.h * Game::PIXEL_SCALE;
	}
	void update() override {
		destRect.x = transform->x();
		destRect.y = transform->y();
	}
	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

};
