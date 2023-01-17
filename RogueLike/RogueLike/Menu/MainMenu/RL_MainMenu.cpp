#include "RL_MainMenu.h"
#include "../../../UI/Image/UI_Image.h"
#include "../../../UI/Label/UI_Label.h"
#include "../../../Window/Window.h"
#include "../../../UI/Button/Label/UI_ButtonLabel.h"

#pragma region constructor/destructor
RL_MainMenu::RL_MainMenu(Window* _owner) : BaseMenu(_owner)
{
    InitBackground();
    InitTitle();
    InitPlayButton();
    InitQuitButton();
}
#pragma endregion constructor/destructor

#pragma region methods
void RL_MainMenu::InitBackground()
{
    background = new UI_Image(owner, "../Assets/base_background.png");
    background->SetScale(sf::Vector2f(5.355f, 5.355f));
    background->SetPosition(sf::Vector2f(0, 0));

    elements.push_back(background);
}

void RL_MainMenu::InitPlayButton()
{
    playButton = new UI_ButtonLabel(owner, "PLAY");

    playButton->SetCharacterSize(20);
    playButton->SetColor(sf::Color(40, 40, 40));

    sf::Vector2f _position((owner->Width() / 2) - 20 - playButton->GetGlobalBounds().width, (owner->Height() / 2));
    playButton->SetPosition(_position);

    elements.push_back(playButton);
}

void RL_MainMenu::InitQuitButton()
{
    quitButton = new UI_ButtonLabel(owner, "QUIT");

    quitButton->SetCharacterSize(20);
    quitButton->SetColor(sf::Color(40, 40, 40));

    sf::Vector2f _position((owner->Width() / 2) + 60 - quitButton->GetGlobalBounds().width, (owner->Height() / 2));
    quitButton->SetPosition(_position);

    elements.push_back(quitButton);
}

void RL_MainMenu::InitTitle()
{
    title = new UI_Label(owner, "RogueLike", "../Fonts/Ancient.ttf");
    title->SetCharacterSize(50);
    title->SetColor(sf::Color::Black);
    sf::Vector2f _position((owner->Width() / 2) - 100, (owner->Height() / 2) - title->GetGlobalBounds().height - 50);
    title->SetPosition(_position);

    elements.push_back(title);
}

UI_ButtonLabel* RL_MainMenu::PlayButton()
{
    return playButton;
}

UI_ButtonLabel* RL_MainMenu::QuitButton()
{
    return quitButton;
}
#pragma endregion methods

#pragma region override
void RL_MainMenu::Draw()
{
    BaseMenu::Draw();
}
#pragma endregion override