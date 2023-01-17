#include "RL_MapMenu.h"
#include "../../../Window/Window.h"
#include "../../Door/RL_Door.h"
#include "../../../UI/Image/UI_Image.h"
#include "../../../UI/Label/UI_Label.h"
#include "../../../Object/GameObject/GameObject.h"
#include "../../../Object/GameObject/Manager/GameObjectManager.h"

#pragma region constructor/destructor
RL_MapMenu::RL_MapMenu(Window* _owner) : BaseMenu(_owner)
{
    InitBackground();
    InitInventory();

    InitDungeonDoor();
    InitDungeonLabel();

    InitShopDoor();
    InitShopLabel();
}
#pragma endregion constructor/destructor

#pragma region methods
void RL_MapMenu::InitBackground()
{
    background = new UI_Image(owner, "../Assets/base_background.png");
    background->SetScale(sf::Vector2f(5.355f, 5.355f));
    background->SetPosition(sf::Vector2f(0, 0));

    elements.push_back(background);
}

void RL_MapMenu::InitDungeonDoor()
{
    dungeonDoor = new RL_Door(owner);
    sf::Vector2f _position((owner->Width() / 4) - (dungeonDoor->GetGlobalBounds().width / 2),
        (owner->Height() / 2) - dungeonDoor->GetGlobalBounds().height);
    dungeonDoor->GetDoorImage()->SetPosition(_position);
}

void RL_MapMenu::InitDungeonLabel()
{
    dungeonLabel = new UI_Label(owner, "DUNGEON");
    dungeonLabel->SetCharacterSize(20);
    dungeonLabel->SetColor(sf::Color::Black);

    sf::Vector2f _position((owner->Width() / 4) - (dungeonDoor->GetGlobalBounds().width / 2) - 5,
        (owner->Height() / 2) - dungeonDoor->GetGlobalBounds().height - dungeonLabel->GetGlobalBounds().height - 20);
    dungeonLabel->SetPosition(_position);

    elements.push_back(dungeonLabel);
}

void RL_MapMenu::InitInventory()
{
    inventory = new UI_Label(owner, "Inventory (I)");
    inventory->SetCharacterSize(20);
    inventory->SetColor(sf::Color::Black);

    sf::Vector2f _position(owner->Width() - inventory->GetGlobalBounds().width - 10,
        owner->Height() - inventory->GetGlobalBounds().height - 10);
    inventory->SetPosition(_position);

    elements.push_back(inventory);
}

void RL_MapMenu::InitShopDoor()
{
    shopDoor = new RL_Door(owner);
    sf::Vector2f _position(((owner->Width() / 4) * 3) - (dungeonDoor->GetGlobalBounds().width / 2),
        (owner->Height() / 2) - dungeonDoor->GetGlobalBounds().height);
    shopDoor->GetDoorImage()->SetPosition(_position);
}

void RL_MapMenu::InitShopLabel()
{
    shopLabel = new UI_Label(owner, "SHOP");
    shopLabel->SetCharacterSize(20);
    shopLabel->SetColor(sf::Color::Black);

    sf::Vector2f _position(((owner->Width() / 4) * 3) - (shopLabel->GetGlobalBounds().width / 2),
        (owner->Height() / 2) - shopDoor->GetGlobalBounds().height - shopLabel->GetGlobalBounds().height - 20);
    shopLabel->SetPosition(_position);

    elements.push_back(shopLabel);
}

RL_Door* RL_MapMenu::ShopDoor()
{
    return shopDoor;
}

RL_Door* RL_MapMenu::DungeonDoor()
{
    return dungeonDoor;
}
#pragma endregion methods

#pragma region override
void RL_MapMenu::Draw()
{
    BaseMenu::Draw();
}
#pragma endregion override