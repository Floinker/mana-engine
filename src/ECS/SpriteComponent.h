#pragma once
#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

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
	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}
	void init() override {
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
		destRect.w = srcRect.w * Game::PIXEL_SCALE * transform->scale;
		destRect.h = srcRect.h * Game::PIXEL_SCALE * transform->scale;

		transform->width = destRect.w;
		transform->height = destRect.h;
	}
	void update() override {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
	}
	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

};
