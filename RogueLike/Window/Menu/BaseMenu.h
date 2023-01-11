#pragma once
#include "../../Object/Object.h"
#include <vector>

class UI_Element;

class BaseMenu : public Object
{
#pragma region f/p
protected:
	bool isOpen = false;
	class Window* owner = nullptr;
	std::vector<UI_Element*> elements = std::vector<UI_Element*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	BaseMenu() = default;
	BaseMenu(Window* _owner);
	virtual ~BaseMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void SetActive(const bool _status);
public:
	void Close();
	void Open();
	virtual void Draw();
#pragma endregion methods
};