#pragma once
#include "../Window/Window.h"
#include "../Entity/Player/Player.h"
#include "../Entity/Monster/Monster.h"


class TestEntity : public Window
{
private:
	Player player = Player();
	Monster monster = Monster();	

public:
	TestEntity();
	~TestEntity() override;
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

