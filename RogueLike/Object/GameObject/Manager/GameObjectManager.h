#pragma once
#include "../../../Singleton/Singleton.h"
#include <vector>

class GameObject;

class GameObjectManager : public Singleton<GameObjectManager>
{
#pragma region f/p
private:
	std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
	std::vector<GameObject*> objectsToDestroy = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region constructor
public:
	GameObjectManager() = default;
#pragma endregion constructor
#pragma region methods
public:
	void CheckCollision();
	void Destroy(GameObject* _gameObject);
	void DestroyAllObjects();
	void DestroyAllRequests();
	void Draw(class Window* _window);
	void Register(GameObject* _gameObject);
	void Update();
	void UnRegister(GameObject* _gameObject);
#pragma endregion methods
#pragma region override
protected:
	void OnDestroy() override;
#pragma endregion override
};