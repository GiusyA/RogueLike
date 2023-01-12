#pragma once
#include <string>
class Entity
{
#pragma region f/p
private:
	std::string name = "";
	float life = 100.0f;
#pragma endregion f/p
public:
	Entity(std::string _name, const float _life);
#pragma region methods
public:
	std::string GetName() const;
	int GetLife();
	void AddLife(float _value);
#pragma endregion methods
};

