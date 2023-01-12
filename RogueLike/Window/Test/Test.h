#pragma once
#include "../Window.h"
#include <vector>
class Test :   public Window
{
private:
	class Player* player = nullptr;
	class UI_Image* background = nullptr;
public:
	Test(const int _w, const int _h, const char* _title, Player* _player);
	~Test();

	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

