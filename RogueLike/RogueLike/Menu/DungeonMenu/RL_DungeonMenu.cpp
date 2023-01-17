#include "RL_DungeonMenu.h"
#include "../../../UI/Image/UI_Image.h"
#include "../../../UI/Label/UI_Label.h"
#include "../../../Window/Window.h"

#pragma region constructor/destructor
RL_DungeonMenu::RL_DungeonMenu(Window* _owner) : BaseMenu(_owner)
{
    InitBackground();

    InitLaunchFightText();

    InitLife();
    InitMana();
    InitMoney();

    InitPotions();

    InitSpells();
}
#pragma endregion constructor/destructor

#pragma region methods
void RL_DungeonMenu::InitBackground()
{
    background = new UI_Image(owner, "../Assets/base_background.png");
    background->SetScale(sf::Vector2f(5.355f, 5.355f));
    background->SetPosition(sf::Vector2f(0, 0));

    elements.push_back(background);
}

void RL_DungeonMenu::InitFireball()
{
    fireball = new UI_Image(owner, "../Assets/Spells/fireball.png");
    fireball->SetScale(sf::Vector2f(3, 3));
    sf::Vector2f _position((owner->Width() / 3) - fireball->GetGlobalBounds().width + 35, owner->Height() - 35 - fireball->GetGlobalBounds().height);
    fireball->SetPosition(_position);

    fireballBind = new UI_Label(owner, "A");
    fireballBind->SetColor(sf::Color::Black);
    fireballBind->SetCharacterSize(16);
    _position = sf::Vector2f(owner->Width() / 3 + fireballBind->GetGlobalBounds().width, owner->Height() - fireballBind->GetGlobalBounds().height - 15);
    fireballBind->SetPosition(_position);

    elements.push_back(fireball);
    elements.push_back(fireballBind);
}

void RL_DungeonMenu::InitGodheal()
{
    godHeal = new UI_Image(owner, "../Assets/Spells/godhealgrey.png");
    godHeal->SetScale(sf::Vector2f(3.5f, 3.5f));
    sf::Vector2f _position(((owner->Width() / 3) * 2) - godHeal->GetGlobalBounds().width + 35, owner->Height() - 35 - godHeal->GetGlobalBounds().height);
    godHeal->SetPosition(_position);

    godHealBind = new UI_Label(owner, "R");
    godHealBind->SetColor(sf::Color::Black);
    godHealBind->SetCharacterSize(16);
    _position = sf::Vector2f((owner->Width() / 3) * 2, owner->Height() - godHealBind->GetGlobalBounds().height - 15);
    godHealBind->SetPosition(_position);

    elements.push_back(godHeal);
    elements.push_back(godHealBind);
}

void RL_DungeonMenu::InitHealPotion()
{
    healPot = new UI_Image(owner, "../Assets/Potions/healgrey.png");
    healPot->SetScale(sf::Vector2f(1.5f, 1.5f));
    healPot->SetPosition(sf::Vector2f(75, 5));

    healPotBind = new UI_Label(owner, "F");
    healPotBind->SetColor(sf::Color::Black);
    healPotBind->SetCharacterSize(16);
    healPotBind->SetPosition(sf::Vector2f(healPot->GetGlobalBounds().width + 75, 8));

    elements.push_back(healPot);
    elements.push_back(healPotBind);
}

void RL_DungeonMenu::InitLaunchFightText()
{
    launchFight = new UI_Label(owner, LAUNCH_FIGHT_TEXT);
    launchFight->SetColor(sf::Color::Black);
    launchFight->SetCharacterSize(16);
    launchFight->SetPosition(sf::Vector2f((owner->Width() / 2) - 50, 10));

    elements.push_back(launchFight);
}

void RL_DungeonMenu::InitLife()
{
    lifeImage = new UI_Image(owner, "../Assets/life.png");

    life = new UI_Label(owner, "100");
    life->SetColor(sf::Color::Black);
    life->SetCharacterSize(20);
    life->SetPosition(sf::Vector2f(lifeImage->GetGlobalBounds().width + 5, 5));

    elements.push_back(lifeImage);
    elements.push_back(life);
}

void RL_DungeonMenu::InitMana()
{
    manaImage = new UI_Image(owner, "../Assets/mana.png");
    manaImage->SetPosition(sf::Vector2f(0, 35));

    mana = new UI_Label(owner, "100");
    mana->SetColor(sf::Color::Black);
    mana->SetCharacterSize(20);
    mana->SetPosition(sf::Vector2f(manaImage->GetGlobalBounds().width + 5, 40));

    elements.push_back(manaImage);
    elements.push_back(mana);
}

void RL_DungeonMenu::InitManaPotion()
{
    manaPot = new UI_Image(owner, "../Assets/Potions/managrey.png");
    manaPot->SetScale(sf::Vector2f(1.5f, 1.5f));
    manaPot->SetPosition(sf::Vector2f(75, 40));

    manaPotBind = new UI_Label(owner, "G");
    manaPotBind->SetColor(sf::Color::Black);
    manaPotBind->SetCharacterSize(16);
    manaPotBind->SetPosition(sf::Vector2f(manaPot->GetGlobalBounds().width + 75, 43));

    elements.push_back(manaPot);
    elements.push_back(manaPotBind);
}

void RL_DungeonMenu::InitMoney()
{
    moneyImage = new UI_Image(owner, "../Assets/money.png");
    moneyImage->SetPosition(sf::Vector2f(5, 75));

    money = new UI_Label(owner, "0");
    money->SetColor(sf::Color::Black);
    money->SetCharacterSize(20);
    money->SetPosition(sf::Vector2f(moneyImage->GetGlobalBounds().width + 12, 70));

    elements.push_back(moneyImage);
    elements.push_back(money);
}

void RL_DungeonMenu::InitPotions()
{
    InitHealPotion();
    InitManaPotion();
}

void RL_DungeonMenu::InitShield()
{
    shield = new UI_Image(owner, "../Assets/Spells/shieldgrey.png");
    shield->SetScale(sf::Vector2f(5.355f, 5.355f));
    sf::Vector2f _position((owner->Width() / 2) - shield->GetGlobalBounds().width + 55, owner->Height() - 15 - shield->GetGlobalBounds().height);
    shield->SetPosition(_position);

    shieldBind = new UI_Label(owner, "E");
    shieldBind->SetColor(sf::Color::Black);
    shieldBind->SetCharacterSize(16);
    _position = sf::Vector2f((owner->Width() / 2) + 10, owner->Height() - shieldBind->GetGlobalBounds().height - 15);
    shieldBind->SetPosition(_position);

    elements.push_back(shield);
    elements.push_back(shieldBind);
}

void RL_DungeonMenu::InitSpells()
{
    InitFireball();
    InitShield();
    InitGodheal();
}

UI_Label* RL_DungeonMenu::LaunchFight()
{
    return launchFight;
}

UI_Label* RL_DungeonMenu::Life()
{
    return life;
}

UI_Label* RL_DungeonMenu::Mana()
{
    return mana;
}

UI_Label* RL_DungeonMenu::Money()
{
    return money;
}

UI_Image* RL_DungeonMenu::HealPotion()
{
    return healPot;
}

UI_Image* RL_DungeonMenu::ManaPotion()
{
    return manaPot;
}

UI_Image* RL_DungeonMenu::Shield()
{
    return shield;
}

UI_Image* RL_DungeonMenu::GodHeal()
{
    return godHeal;
}
#pragma endregion methods

#pragma region override
void RL_DungeonMenu::Draw()
{
    BaseMenu::Draw();
}
#pragma endregion override