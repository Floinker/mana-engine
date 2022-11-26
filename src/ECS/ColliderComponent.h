#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	ColliderComponent(std::string tag) {
		this->tag = tag;
	}

	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		Game::colliders.push_back(this);
	}

	void update() override {
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width;
		collider.h = transform->height;
	}

	void draw() override {
		SDL_Color color;
		SDL_GetRenderDrawColor(Game::renderer, &color.r, &color.g, &color.b, &color.a);
		SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(Game::renderer, &collider);
		SDL_SetRenderDrawColor(Game::renderer, color.r, color.g, color.b, color.a);
	}
};