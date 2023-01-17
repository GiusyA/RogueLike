#pragma once
#include "../Spells.h"


class Fireball : public Spells
{
#pragma region f/p

#pragma endregion f/p
#pragma region constructor
public:
	Fireball() = default;
	Fireball(const float _damage, const float _cost);
#pragma endregion constructor
#pragma endregion methode
	void SetOrigin(sf::Vector2f _vector);
	void SetPosition(sf::Vector2f _vector);
	sf::Drawable* GetDrawable();
	void Destruc();
#pragma endregion methode
#pragma region override
public:
	void virtual OnUse(class Entity* _entity) override;
	virtual sf::FloatRect GetGlobalBounds() const;
	virtual sf::Vector2f Position() const;
#pragma endregion override
};

