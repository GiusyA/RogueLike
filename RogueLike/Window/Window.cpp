#include "Window.h"
#include "../Event/Event.h"
#include "../Time/Time.h"
#include "Menu/BaseMenu.h"
#include "../UI/Manager/UI_ElementManager.h"
#include <format>

#pragma region constructor/destructor
Window::Window(const float _width, const float _height, const char* _title)
{
	width = _width;
	height = _height;
	title = _title;
}

Window::~Window()
{
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		delete _pair.second;

	menus.clear();
	Close();
	delete window;
}
#pragma endregion constructor/destructor

#pragma region methods
void Window::Update()
{
	sf::Event _event = sf::Event();
	sf::Clock _clock = sf::Clock();

	while (window->isOpen())
	{
		Time::deltaTime = _clock.restart().asSeconds();

		while (window->pollEvent(_event))
		{
			if (!window->hasFocus() && !eventIfNotFocus)
				continue;

			Event::currentEvent = &_event;
			OnReceiveEvent(_event);
			break;
		}

		UI_ElementManager::Instance()->Update();
		OnUpdate();
		window->clear();
		OnDraw();
		window->display();
	}
}

void Window::CloseAllMenus()
{
	for (std::pair<const char*, BaseMenu*> _pair : menus)
		_pair.second->Close();
}

void Window::OpenMenu(const char* _name)
{
	CloseAllMenus();

	if (!menus.contains(_name))
		throw std::exception(std::format("[Window] => Menu {} doesn't exist.", _name).c_str());

	menus[_name]->Open();
}

void Window::RegisterMenu(const char* _name, BaseMenu* _menu)
{
	menus.insert(std::pair(_name, _menu));
}

void Window::InitMenus() {}

void Window::OnDraw() {}

void Window::OnReceiveEvent(const sf::Event& _event)
{
	if (_event.type == sf::Event::Closed)
		Close();
}

void Window::OnUpdate() {}

void Window::Close()
{
	if (!window->isOpen())
		return;

	window->close();
}

void Window::Draw(sf::Drawable* _drawable)
{
	window->draw(*_drawable);
}

void Window::Open()
{
	InitMenus();
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	Update();
}

void Window::SetFrameLimit(const int _frame)
{
	window->setFramerateLimit(_frame);
}

bool Window::HasFocus() const
{
	return window->hasFocus();
}

bool Window::IsOpen() const
{
	return window->isOpen();
}

float Window::Width() const
{
	return width;
}

float Window::Height() const
{
	return height;
}

sf::RenderWindow* Window::Renderer() const
{
	return window;
}
#pragma endregion methods