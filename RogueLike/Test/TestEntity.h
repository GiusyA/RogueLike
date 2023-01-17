#pragma once
#include "../Window/Window.h"
#include "../Entity/Player/Player.h"
#include "../Entity/Monster/Monster.h"
#include "../Time/Time.h"

class TestEntity : public Window
{
private:
	Time time = Time();
	Player player = Player();
	Monster monster = Monster();	
public:
	TestEntity();
	~TestEntity() override;
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

