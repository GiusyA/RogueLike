#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class RL_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	class UI_Label* title = nullptr;
	class UI_Image* background = nullptr;
	class UI_ButtonLabel* playButton = nullptr;
	UI_ButtonLabel* quitButton = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	RL_MainMenu() = default;
	RL_MainMenu(class Window* _owner);
	RL_MainMenu(const RL_MainMenu& _copy) = delete;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitBackground();
	void InitPlayButton();
	void InitQuitButton();
	void InitTitle();
public:
	UI_ButtonLabel* PlayButton();
	UI_ButtonLabel* QuitButton();
#pragma endregion methods
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};