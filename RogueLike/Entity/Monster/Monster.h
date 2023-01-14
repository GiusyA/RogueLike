#pragma once
#include "../Entity.h"

class Monster : public Entity
{
#pragma region f/p
private:

#pragma endregion f/p
#pragma region constructor/destructor
public:
	Monster();
	virtual ~Monster() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	
#pragma endregion methods
#pragma region override
public:
	virtual sf::Drawable* GetDrawable() override;
	virtual void Die() override;
	virtual void Restart() override;
	void OnUpdate() override;
	virtual void Init() override;
	virtual sf::FloatRect GetGlobalBounds()const override;
	virtual sf::Vector2f Position()const override;
#pragma endregion override
};

