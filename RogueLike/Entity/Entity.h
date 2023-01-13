#pragma once
#include "../Object/Object.h"
#include <string>
//Propriété et caractéristique des entités
class UI_Image;
class Window;

class Entity :public Object
{
#pragma region f/p
protected:
	std::string name = "name";
	float life = 100.0f;
	bool isDead = false;
	UI_Image* image = nullptr;
	float attack = 50.0f;
	int level = 1;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Entity() = default;
	Entity(const std::string _name, const float _life,  UI_Image* _image, const float _attack, const int _level);
	Entity(const Entity& _copy);
	virtual ~Entity() = default;
#pragma endregion constructor/destructor
#pragma region setter/Getter
public:
	float GetLife() const;
	float SetLife(const float _life);
	bool SetDead(const bool _isDead);
	UI_Image* GetImage() const;
	void SetImage (Window* _owner);
	float GetAttack() const;
	float SetAttack(const float _attack);
	int SetLevel(const int _level);
	int GetLevel() const;
	bool IsDead();
#pragma endregion setter/Getter
#pragma region methods
private:
	virtual void OnDestroy(const bool _isdead);
public:
	void IsHit(const float _dammage);
#pragma endregion methods
};

