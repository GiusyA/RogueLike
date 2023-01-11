#pragma once
#include "../../Singleton/Singleton.h"
#include <vector>

class UI_ElementManager : public Singleton<UI_ElementManager>
{
#pragma region f/p
private:
	std::vector<class UI_Element*> elements = std::vector<UI_Element*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	UI_ElementManager() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Register(UI_Element* _element);
	void UnRegister(UI_Element* _element);
	void Update();
#pragma endregion methods
#pragma region override
public:
	virtual void OnDestroy() override;
#pragma endregion override
};