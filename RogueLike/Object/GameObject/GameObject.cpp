#include "GameObject.h"
#include "../../Window/Window.h"
#include "Manager/GameObjectManager.h"
#pragma region constructor/destructor
GameObject::GameObject()
{
	GameObjectManager::Instance()->Register(this);
}

GameObject::GameObject(const GameObject& _copy)
{
	drawable = _copy.drawable;
}

GameObject::~GameObject() {}
#pragma endregion constructor/destructor

#pragma region methods
void GameObject::OnCollisionEnter(GameObject* _other) {}

void GameObject::OnDraw(Window* _window)
{
	_window->Draw(drawable);
}

void GameObject::OnUpdate() {}
#pragma endregion methods