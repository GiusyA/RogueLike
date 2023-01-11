#include "TextureManager.h"
#include <format>

#pragma region methods
sf::Texture* TextureManager::Get(const char* _path)
{
    if (!textures.contains(_path))
    {
        sf::Texture* _texture = new sf::Texture();

        if (!_texture->loadFromFile(_path))
            throw std::exception(std::format("[TextureManager] => Can't load texture at path: {}", _path).c_str());

        textures.insert(std::pair(_path, _texture));
        return _texture;
    }

    return textures[_path];
}
#pragma endregion methods

#pragma region override
void TextureManager::OnDestroy()
{
    for (std::pair<const char*, sf::Texture*> _pair : textures)
        delete _pair.second;

    textures.clear();
}
#pragma endregion override