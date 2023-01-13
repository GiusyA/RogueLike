#pragma once
#include "../Entity.h"

class Monster : public Entity
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Monster ()= default;
	Monster(const std::string _name, const float _life, UI_Image* _image, const float _attack, const int _level);
	 virtual ~Monster() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Init();
public:

#pragma endregion methods
#pragma region override
public:
	virtual void OnDestroy(const bool _isdead) override;
#pragma endregion override
};

