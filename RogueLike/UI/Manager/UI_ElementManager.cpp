#include "UI_ElementManager.h"
#include "../UI_Element.h"

#pragma region methods
void UI_ElementManager::Register(UI_Element* _element)
{
	elements.push_back(_element);
}

void UI_ElementManager::UnRegister(UI_Element* _element)
{
	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
	{
		if (elements[i] == _element)
		{
			elements.erase(elements.begin() + i);
			break;
		}
	}
}

void UI_ElementManager::Update()
{
	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
		elements[i]->OnUpdate();
}
#pragma endregion methods

#pragma region override
void UI_ElementManager::OnDestroy()
{
	const size_t _size = elements.size();

	for (size_t i = 0; i < _size; i++)
		delete elements[i];

	elements.clear();
}
#pragma endregion override