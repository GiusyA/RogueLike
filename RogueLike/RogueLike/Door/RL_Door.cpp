#include "RL_Door.h"
#include "../../UI/Image/UI_Image.h"
#include "../../UI/Image/TextureManager/TextureManager.h"
#include "../../Entity/Player/Player.h"
#include "../../Object/GameObject/Manager/GameObjectManager.h"

#pragma region constructor/destructor
RL_Door::RL_Door(class Window* _owner) : GameObject()
{
    door = new UI_Image(_owner, "../Assets/doorClosed.png");
    door->SetScale(sf::Vector2f(5.355f, 5.355f));

    drawable = door->GetSprite();
}

RL_Door::~RL_Door()
{
    delete door;
    door = nullptr;

    delete player;
    player = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
void RL_Door::Close()
{
    sf::Texture* _texture = TextureManager::Instance()->Get("../Assets/doorClosed.png");
    door->GetSprite()->setTexture(*_texture);
}

void RL_Door::Open()
{
    sf::Texture* _texture = TextureManager::Instance()->Get("../Assets/doorOpened.png");
    door->GetSprite()->setTexture(*_texture);
}

void RL_Door::SetCurrentPlayer(Player* _player)
{
    player = _player;
}

UI_Image* RL_Door::GetDoorImage()
{
    return door;
}
#pragma endregion methods

#pragma region override
void RL_Door::OnUpdate()
{
    if (player == nullptr)
        return;
    
    if (isOpen)
    {
        if (!door->GetGlobalBounds().contains(player->Position()))
        {
            isOpen = false;
            Close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            OnEnter.Invoke();
    }
    else
    {
        if (door->GetGlobalBounds().contains(player->Position()))
        {
            isOpen = true;
            Open();
        }
    }
}

sf::FloatRect RL_Door::GetGlobalBounds() const
{
    return door->GetGlobalBounds();
}

sf::Vector2f RL_Door::Position() const
{
    return door->GetSprite()->getPosition();
}
#pragma endregion override