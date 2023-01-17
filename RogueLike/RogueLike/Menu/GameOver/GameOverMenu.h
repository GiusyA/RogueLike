#pragma once
#include "../../../Window/Menu/BaseMenu.h"
#include "../../../UI/Button/UI_Button.h"
#include "../../../UI/Image/UI_Image.h"

#include <vector>	
#include <SFML/Graphics.hpp>

class GameOverMenu : public BaseMenu
{

private:
	UI_Button* restartButton = nullptr;
	UI_Button* quitButton = nullptr;
	UI_Image* gameOverImage = nullptr;
	UI_Image* background = nullptr;

public:
	GameOverMenu() = default;
	GameOverMenu(Window* _owner);
	void InitBackground();
	void InitGameOverImage();
	void InitButtons();
	virtual ~GameOverMenu() override;

public:
	UI_Button* RestartButton() const;
	UI_Button* QuitButton() const;
};

