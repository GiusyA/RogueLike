#include "Entity.h"
#include "../UI/Image/UI_Image.h"

#pragma region constructor/destructor
Entity::Entity(const std::string _name, const float _life, UI_Image* _image, const float _attack, const int _level)
{
	name = _name;
	 life = _life;
	 image = _image;
	 attack = _attack;
	 level = _level;
}
Entity::Entity(const Entity& _copy)
{
	name = _copy.name;
	life = _copy.life;
	image = _copy.image;
	attack = _copy.attack;
	level = _copy.level;
}
#pragma endregion constructor/destructor
#pragma region setter/Getter
float Entity::GetLife() const
{
	return life;
}
float Entity::SetLife(const float _life)
{
	return life = _life;
}
bool Entity::SetDead(const bool _isDead)
{
	return isDead =_isDead;
}
float Entity::GetAttack() const
{
	return attack;
}
float Entity::SetAttack(const float _attack)
{
	return attack = _attack;
}
int Entity::SetLevel(const int _level)
{

	return level = _level;
}
int Entity::GetLevel() const
{
	return level;
}
bool Entity::IsDead()
{
	if(life <=0)
		return isDead = true;
	else
		return isDead = false;
}
UI_Image* Entity::GetImage() const
{
	if (image != nullptr)
		return image;
}
void Entity::SetImage(Window* _owner)
{
	if (image != nullptr)
		image->Draw(_owner);
}
#pragma endregion setter/Getter
#pragma region methods
void Entity::OnDestroy(const bool _isdead)
{
	if (_isdead)
	{
		delete image;
		image = nullptr;
	}
}
void Entity::IsHit(const float _dammage)
{
	life -=_dammage;
}
#pragma endregion methods

