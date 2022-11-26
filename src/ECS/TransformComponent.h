#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int width = 16;
	int height = 16;
	int scale = 1;

	int speed = 3;

	TransformComponent() {
		position.Zero();
	}
	TransformComponent(int s) {
		position.Zero();
		scale = s;
	}
	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}
	TransformComponent(float x, float y, int w, int h, int s) {
		position.x = x;
		position.y = y;
		width = w;
		height = h;
		scale = s;
	}

	void init() override {
		velocity.Zero();
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
