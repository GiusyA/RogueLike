#include "BaseMenu.h"
#include "../../UI/UI_Element.h"

#pragma region constructor/destructor
BaseMenu::BaseMenu(Window* _owner)
{
	owner = _owner;
}

BaseMenu::~BaseMenu()
{
	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
		delete elements[i];

	elements.clear();
}
#pragma endregion constructor/destructor

#pragma region methods
void BaseMenu::SetActive(const bool _status)
{
	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
		elements[i]->SetActive(_status);
}

void BaseMenu::Close()
{
	isOpen = false;
	SetActive(false);
}

void BaseMenu::Open()
{
	isOpen = true;
	SetActive(true);
}

void BaseMenu::Draw()
{
	if (!isOpen)
		return;

	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
		elements[i]->Draw(owner);
}
#pragma endregion methods