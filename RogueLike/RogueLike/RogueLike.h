#pragma once
#include "../Window/Window.h"

class RogueLike : public Window
{
#pragma region f/p
private:
	bool onMain = false;
	bool onMap = false;
	bool onShop = false;
	bool onDead = true;
protected:
	class Player* player = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RogueLike();
	void RegisterItems();
	~RogueLike() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Close();
	void Start();
	void Exit();
public:
	void GameOver();

#pragma endregion methods
#pragma region override
public:
	virtual void InitMenus() override;
	virtual void OnDraw() override;
	virtual void OnReceiveEvent(const sf::Event& _event) override;
	virtual void OnUpdate() override;
#pragma endregion override
};