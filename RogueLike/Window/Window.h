#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include <map>

class BaseMenu;
//Affiche les menus et gère les events & updates
class Window : public Object
{
#pragma region f/p
private:
	const char* title = "Default window";
	sf::RenderWindow* window = nullptr;
protected:
	float width = 900;
	float height = 800;
	std::map<const char*, BaseMenu*> menus = std::map<const char*, BaseMenu*>();
protected:
	bool eventIfNotFocus = false;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Window() = default;
	Window(const float _width, const float _height, const char* _title);
	Window(const Window& _copy) = delete;
	virtual ~Window();
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Update();
protected:
	void CloseAllMenus();
	void OpenMenu(const char* _name);
	void RegisterMenu(const char* _name, BaseMenu* _menu);
	virtual void InitMenus();
	virtual void OnDraw() = 0;
	virtual void OnReceiveEvent(const sf::Event& _event);
	virtual void OnUpdate() = 0;
public:
	void Close();
	void Draw(sf::Drawable* _drawable);
	void Open();
	void SetFrameLimit(const int _frame);
	bool HasFocus() const;
	bool IsOpen() const;
	float Width() const;
	float Height() const;
	sf::RenderWindow* Renderer() const;
#pragma endregion methods
};