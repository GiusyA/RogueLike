#pragma once
#include "../../../Singleton/Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

//Gère les textures 

class TextureManager : public Singleton<TextureManager>
{
#pragma region f/p
private:
	std::map<const char*, sf::Texture*> textures = std::map<const char*, sf::Texture*>();
#pragma endregion f/p
#pragma region constructor
public:
	TextureManager() = default;
#pragma endregion constructor
#pragma region methods
public:
	sf::Texture* Get(const char* _path);
#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};