#include "Player.h"
#include "../../Input/Input.h"
#include "../../UI/Image/UI_Image.h"
#include "../../UI/Label/UI_Label.h"
#include "../../Inventory/Item/Item.h"
#include "../../Inventory/Inventory.h"
#include "../../Object/GameObject/Manager/GameObjectManager.h"
#include "../../Window/Window.h"

#include <iostream>
#include <format>

#pragma region constructor/destructor
Player::Player(class Window* _owner, const sf::Vector2f& _position) : Entity(_owner, "D:/Documents/GitHub/RogueLike/assets/player.png", _position) 
{
    inv = new Inventory(this);
    image->SetOrigin(sf::Vector2f(0, 0));
    image->SetPosition(sf::Vector2f(0, 0));
}
#pragma endregion constructor/destructor

#pragma region override

int Player::GetMaxMana() const
{
    return maxMana;
}
void Player::Restart()
{

}
void Player::OnCollisionEnter(GameObject* _other)
{
   //ici on devrait afficher le text si il entre dans la hitbox de l'item
    /* if (dynamic_cast<Item*>(_other))
    {
        Item* _item = dynamic_cast<Item*>(_other);
        UI_Label _labelBuy = UI_Label(owner, std::format("Press [Enter] to buy {}", _item->GetName()).c_str());
        _labelBuy.SetPosition(sf::Vector2f(100, owner->Height() - 50));
        _labelBuy.SetCharacterSize(25);
        _labelBuy.Draw(owner);
    }*/
}

void Player::OnUpdate()
{
    Entity::OnUpdate();

    if (Input::IsKeyDown(sf::Keyboard::Q))
        image->SetPosition(sf::Vector2f(Position().x - 5, Position().y));

    if (Input::IsKeyDown(sf::Keyboard::D))
        image->SetPosition(sf::Vector2f(Position().x + 5, Position().y));

    if (Input::IsKeyDown(sf::Keyboard::Enter))
    {
        std::vector<Item*> items = GameObjectManager::Instance()->GetItems();
        for (Item* _item : items)
        {
            if (GetGlobalBounds().intersects(_item->GetGlobalBounds()))
            {
                if (inv->GetMoney() >= _item->GetCost())
                {
                    inv->AddItem(_item);
                    inv->RemoveMoney(_item->GetCost());
                    //Draw label pour dire que l'item a bien été acheter
                    break;
                }
            }
        }
    }
    if (Input::IsKeyDown(sf::Keyboard::I))
    {
        //TODO open inventory
    }
        

}
#pragma endregion override