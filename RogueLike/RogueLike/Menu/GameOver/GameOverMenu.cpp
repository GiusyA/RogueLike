#include "GameOverMenu.h"
#include "../../../Window/Window.h"
#include "../../../Object/GameObject/Manager/GameObjectManager.h"
GameOverMenu::GameOverMenu(Window* _owner) : BaseMenu(_owner)
{	
	InitBackground();
	InitGameOverImage();
	InitButtons();
}

void GameOverMenu::InitBackground()
{
	background = new UI_Image(owner, "../assets/layers/game_over_background.png");
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetOrigin(sf::Vector2f(0, 0));

	elements.push_back(background);
}

void GameOverMenu::InitGameOverImage()
{
	gameOverImage = new UI_Image(owner, "../assets/layers/game_over.png");
	gameOverImage->SetPosition(sf::Vector2f((owner->Width() / 2) - (gameOverImage->GetGlobalBounds().width / 2), 20));

	elements.push_back(gameOverImage);
}

void GameOverMenu::InitButtons()
{
	restartButton = new UI_Button(owner, "../assets/button/restart.png");
	restartButton->SetPosition(sf::Vector2f(
		(owner->Width() / 2) - (restartButton->GetGlobalBounds().width / 2),
		owner->Height() / 2));

	elements.push_back(restartButton);

	quitButton = new UI_Button(owner, "../assets/button/quit.png");
	quitButton->SetPosition(sf::Vector2f(
		(owner->Width() / 2) - (quitButton->GetGlobalBounds().width / 2),
		(owner->Height() / 2) + restartButton->GetGlobalBounds().height + 50));

	elements.push_back(quitButton);
}

GameOverMenu::~GameOverMenu()
{

}

UI_Button* GameOverMenu::RestartButton() const
{
	return restartButton;
}

UI_Button* GameOverMenu::QuitButton() const
{
	return quitButton;
}
