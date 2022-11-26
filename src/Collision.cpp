#include "Collision.h"
#include "SDL.h"
#include"ECS\ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {
	SDL_Rect* res = new SDL_Rect();
	return SDL_IntersectRect(&rectA, &rectB, res);
}

bool Collision::AABB(const ColliderComponent& colliderA, const ColliderComponent& colliderB) {
	SDL_Rect* res = new SDL_Rect();
	if (SDL_IntersectRect(&colliderA.collider, &colliderB.collider, res)) {
		std::cout << colliderA.tag << " hit " << colliderB.tag << std::endl;
		return true;
	}
	return false;

}