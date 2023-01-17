#include "ShopMenu.h"
#include "../../../UI/Image/UI_Image.h"
#include "../../../UI/Label/UI_Label.h"
#include "../../../Inventory/Item/Database/ItemDatabase.h"
#include "../../../Object/GameObject/Manager/GameObjectManager.h"
#include "../../../Window/Window.h"
#include "../../../Inventory/Item/Database/ItemDatabase.h"
#include "../../../Inventory/Item/Item.h"

#define SCALE_ITEM 5.0f
ShopMenu::ShopMenu(Window* _owner) : BaseMenu(_owner)
{
    InitBackground();
    InitTables();
    InitItems();
    InitLabel();

}

void ShopMenu::InitLabel()
{
    labelBuy = new UI_Label(owner, "Press [Enter] to Buy");
    labelBuy->SetCharacterSize(15);
    labelBuy->SetPosition(sf::Vector2f(20, owner->Height() - 50));

    elements.push_back(labelBuy);

    inventory = new UI_Label(owner, "Press [I] to Inventory");
    inventory->SetCharacterSize(15);
    inventory->SetPosition(sf::Vector2f((owner->Width() - 50) - inventory->GetGlobalBounds().width, owner->Height() - 50));

    elements.push_back(inventory);
}


void ShopMenu::InitTables()
{
    table1 = new UI_Image(owner, "../assets/table.png");
    table2 = new UI_Image(owner, "../assets/table.png");
    table3 = new UI_Image(owner, "../assets/table.png");
    table1->SetScale(sf::Vector2f(SCALE_ITEM, SCALE_ITEM));
    table2->SetScale(sf::Vector2f(SCALE_ITEM, SCALE_ITEM));
    table3->SetScale(sf::Vector2f(SCALE_ITEM, SCALE_ITEM));
    table2->SetPosition(sf::Vector2f((owner->Width() / 2) - (table2->GetGlobalBounds().width / 2), (owner->Height() / 2) - table2->GetGlobalBounds().height / 2));
    table1->SetPosition(table2->GetSprite()->getPosition() - sf::Vector2f(table2->GetGlobalBounds().width + 100, 0));
    table3->SetPosition(table2->GetSprite()->getPosition() + sf::Vector2f(table2->GetGlobalBounds().width + 100, 0));

    elements.push_back(table1);
    elements.push_back(table2);
    elements.push_back(table3);
}

void ShopMenu::InitBackground()
{
    background = new UI_Image(owner, "../assets/base_background.png");
    background->SetScale(sf::Vector2f(5.355f, 5.355f));
    background->SetPosition(sf::Vector2f(0, 0));
    background->SetOrigin(sf::Vector2f(0, 0));

    elements.push_back(background);

}

void ShopMenu::InitItems()
{

    Item* _mana = GameObjectManager::Instance()->GetItem(MANA_POTION);

    Item* _spells = GameObjectManager::Instance()->GetItem(FIREBALL);

    Item* _heal = GameObjectManager::Instance()->GetItem(HEAL_POTION);

    float _scale = SCALE_ITEM - 1;
    sf::Vector2f _pos1 = table1->GetSprite()->getPosition();
    _mana->SetPosition(sf::Vector2f(_pos1.x + 5, _pos1.y - 5));
    _mana->SetScale(sf::Vector2f(_scale, _scale));
    sf::Vector2f _pos2 = table2->GetSprite()->getPosition();
    _spells->SetPosition(sf::Vector2f(_pos2.x + 5, _pos2.y - 5));
    _spells->SetScale(sf::Vector2f(_scale, _scale));
    sf::Vector2f _pos3 = table3->GetSprite()->getPosition();
    _heal->SetPosition(sf::Vector2f(_pos3.x + 5, _pos3.y - 5));
    _heal->SetScale(sf::Vector2f(_scale, _scale));

    elements.push_back(_mana);
    elements.push_back(_spells);
    elements.push_back(_heal);
}
ShopMenu::~ShopMenu()
{

}
