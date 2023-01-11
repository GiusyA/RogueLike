#include "UI_Element.h"
#include "Manager/UI_ElementManager.h"

#pragma region constructor
UI_Element::UI_Element(Window* _owner)
{
	owner = _owner;
	UI_ElementManager::Instance()->Register(this);
}

UI_Element::UI_Element(const UI_Element& _copy)
{
	isActive = _copy.isActive;
	owner = _copy.owner;
}

UI_Element::~UI_Element()
{
	UI_ElementManager::Instance()->UnRegister(this);
}
#pragma endregion constructor

#pragma region methods
void UI_Element::SetActive(const bool _status)
{
	isActive = _status;
}

void UI_Element::OnUpdate() {}
#pragma endregion methods