#include "Monster.h"

#pragma region constructor/destructor
Monster::Monster(const std::string _name, const float _life, UI_Image* _image, const float _attack, const int _level) : Entity( _name,  _life, _image,  _attack,  _level)
{
}
Monster::~Monster()
{
	OnDestroy(isDead);
}
void Monster::Init()
{
}
#pragma endregion constructor/destructor
#pragma region methods

#pragma endregion methods
#pragma region override
void Monster::OnDestroy(const bool _isdead)
{
	if (_isdead)
	{

	}
}
#pragma endregion override
