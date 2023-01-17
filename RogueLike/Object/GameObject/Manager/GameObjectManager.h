#pragma once
#include <vector>
#include <map>
#include <string>
#include "../../../Singleton/Singleton.h"

class GameObject;
class Item;

class GameObjectManager : public Singleton<GameObjectManager>
{
#pragma region f/p
private:
	std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
	std::vector<GameObject*> objectsToDestroy = std::vector<GameObject*>();
	std::map<std::string, Item*> gameItems = std::map<std::string, Item*>();
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

	Item* GetItem(const std::string& _name);
	void RegisterItem(Item* _item);
	void UnRegisterItem(const Item* _item);
	std::vector<Item*> GetItems() const;
#pragma endregion methods
#pragma region override
protected:
	void OnDestroy() override;
#pragma endregion override
};