#include "Entity.h"
#include "../UI/Image/UI_Image.h"
#include "../Window/Window.h"

#pragma region constructor/destructor
Entity::Entity(class Window* _owner, const char* _path, const sf::Vector2f& _position)
{
	image = new UI_Image(_owner, _path);
	image->SetScale(sf::Vector2f(5.355f, 5.355f));
	sf::Vector2f _updatePos(_position.x - image->GetGlobalBounds().width, _position.y - image->GetGlobalBounds().height);
	image->SetPosition(_updatePos);

	drawable = image->GetSprite();

	owner = _owner;
}

Entity::Entity(const Entity& _copy)
{
	isDead = _copy.isDead;
	image = _copy.image;
	owner = _copy.owner;
}

Entity::~Entity()
{
	delete image;
	image = nullptr;

	delete owner;
	owner = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
void Entity::EntityMovementsLimits()
{
	sf::Sprite* _sprite = image->GetSprite();
	const float _x = _sprite->getPosition().x;
	const float _y = _sprite->getPosition().y;

	const float _maxX = owner->Width() - 15;
	const float _maxY = owner->Height() - 15;

	if (_sprite->getPosition().x <= 15)
		image->SetPosition(sf::Vector2f(15, _y));

	if (_sprite->getPosition().x >= _maxX)
		image->SetPosition(sf::Vector2f(_maxX, _y));

	if (_sprite->getPosition().y <= 15)
		image->SetPosition(sf::Vector2f(_x, 15));

	if (_sprite->getPosition().y >= _maxY)
		image->SetPosition(sf::Vector2f(_x, _maxY));
}

void Entity::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}
#pragma endregion methods

#pragma region override
void Entity::OnCollisionEnter(GameObject* _other) {}

void Entity::OnUpdate()
{
	if (isDead)
		return;

	EntityMovementsLimits();
}

sf::FloatRect Entity::GetGlobalBounds() const
{
	return image->GetGlobalBounds();
}

sf::Vector2f Entity::Position() const
{
	return image->GetSprite()->getPosition();
}
#pragma endregion override