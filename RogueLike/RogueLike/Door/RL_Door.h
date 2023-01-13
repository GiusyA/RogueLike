#pragma once
#include "../../Object/GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

class RL_Door : public GameObject
{
#pragma region f/p
private:
	bool isOpen = false;
	class UI_Image* door = nullptr;
	class Player* player = nullptr;
public:
	Delegate<void> OnEnter = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RL_Door() = default;
	RL_Door(class Window* _owner);
	virtual ~RL_Door() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Close();
	void Open();
public:
	void SetCurrentPlayer(Player* _player);
	UI_Image* GetDoorImage();
#pragma endregion methods
#pragma region override
public:
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};