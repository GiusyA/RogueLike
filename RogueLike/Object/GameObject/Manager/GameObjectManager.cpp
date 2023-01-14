#include "GameObjectManager.h"
#include "../GameObject.h"

#pragma region methods
void GameObjectManager::CheckCollision()
{
	for (GameObject* _a : gameObjects)
	{
		for (GameObject* _b : gameObjects)
		{
			if (_a == _b || !_a->GetGlobalBounds().contains(_b->Position()))
				continue;

			_b->OnCollisionEnter(_a);
		}
	}
}
void GameObjectManager::Destroy(GameObject* _gameObject)
{
	objectsToDestroy.push_back(_gameObject);
}
void GameObjectManager::DestroyAllObjects()
{
	for (GameObject* _object : gameObjects)
	{
		delete _object;
		_object = nullptr;
	}

	objectsToDestroy.clear();
	gameObjects.clear();
}
void GameObjectManager::DestroyAllRequests()
{
	for (GameObject* _object : objectsToDestroy)
		UnRegister(_object);

	objectsToDestroy.clear();
}
void GameObjectManager::Draw(Window* _window)
{
	const size_t _size = gameObjects.size();

	for (size_t i = 0; i < _size; i++)
		gameObjects[i]->OnDraw(_window);
}
void GameObjectManager::Register(GameObject* _gameObject)
{
	gameObjects.push_back(_gameObject);
}
void GameObjectManager::Update()
{
	const size_t _size = gameObjects.size();

	for (size_t i = 0; i < _size; i++)
		gameObjects[i]->OnUpdate();
}
void GameObjectManager::UnRegister(GameObject* _gameObject)
{
	const size_t _size = gameObjects.size();

	for (size_t i = 0; i < _size; i++)
	{
		if (gameObjects[i] == _gameObject)
		{
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
			break;
		}
	}
}
#pragma endregion methods
#pragma region override
void GameObjectManager::OnDestroy()
{
	const size_t _size = gameObjects.size();

	for (size_t i = 0; i < _size; i++)
		delete gameObjects[i];

	gameObjects.clear();
}
#pragma endregion override