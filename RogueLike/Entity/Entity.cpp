#include "Entity.h"
#include "../UI/Image/UI_Image.h"
#include "../Window/Window.h"

#pragma region constructor/destructor
Entity::Entity(class Window* _owner, const char* _path, const sf::Vector2f& _position, const std::string& _name)
	: GameObject()
{
	image = new UI_Image(_owner, _path);
	image->SetScale(sf::Vector2f(5.355f, 5.355f));
	sf::Vector2f _updatePos(_position.x - image->GetGlobalBounds().width, _position.y - image->GetGlobalBounds().height);
	image->SetPosition(_updatePos);

	drawable = image->GetSprite();

	owner = _owner;
	name = _name;
}

Entity::Entity(const Entity& _copy)
{
	image = _copy.image;
	owner = _copy.owner;
	life = _copy.life;
	attack = _copy.attack;
	name = _copy.name;
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
	const float _y = _sprite->getPosition().y;
	const float _maxX = owner->Width() - 15;

	if (_sprite->getPosition().x <= 15)
		image->SetPosition(sf::Vector2f(15, _y));

	if (_sprite->getPosition().x >= _maxX)
		image->SetPosition(sf::Vector2f(_maxX, _y));
}

void Entity::IsHit(const float _dammage)
{
	life -= _dammage;
	life = (life < 0) ? 0 : life;
}

void Entity::SetAttack(const float _attack)
{
	attack = _attack;
}

void Entity::SetIsFighting(const bool _value)
{
	isFighting = _value;
}

void Entity::SetLife(const float _life)
{
	life = _life;
}

void Entity::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position);
}

std::string Entity::GetName() const
{
	return name;
}

float Entity::GetAttack() const
{
	return attack;
}

float Entity::GetLife() const
{
	return life;
}

void Entity::Init()
{
	life = 100.0f;
	attack = 10.0f;
}
#pragma endregion methods

#pragma region override
void Entity::OnCollisionEnter(GameObject* _other) {}

void Entity::OnUpdate()
{
	if (life <= 0)
	{
		OnDie.Invoke();
		return;
	}

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