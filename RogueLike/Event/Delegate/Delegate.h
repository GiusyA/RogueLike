#pragma once
#include "../../Object/Object.h"
#include <cstddef>

template<typename Res, typename... Params>
class Delegate : public Object
{
#pragma region f/p
private:
	typedef Res(Object::* Function)(Params...);
	Function function = nullptr;
	Object* instance = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Delegate(nullptr_t)
	{
		function = nullptr;
		instance = nullptr;
	}

	Delegate(const Delegate& _copy)
	{
		function = _copy.function;
		instance = _copy.instance;
	}

	template<typename Class>
	Delegate(Class* _instance, Res(Class::* _ptr)(Params...))
	{
		if constexpr (!std::is_base_of_v<Object, Class>)
			throw std::exception("[Delegate] => Class must be inherited of Object.");

		instance = _instance;
		function = reinterpret_cast<Function>(_ptr);
	}
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetDynamic(nullptr_t)
	{
		*this = Delegate(nullptr_t);
	}

	template<typename Class>
	void SetDynamic(Class* _instance, Res(Class::* _ptr)(Params...))
	{
		*this = Delegate(_instance, _ptr);
	}

	bool IsValid() const
	{
		return instance != nullptr && function != nullptr;
	}

	Res Invoke(Params... _params)
	{
		if (instance == nullptr)
			throw std::exception("[Delegate] => Instance is nullptr.");

		if (function == nullptr)
			throw std::exception("[Delegate] => Function is nullptr.");

		return (instance->*function)(_params...);
	}
#pragma endregion methods
#pragma region operator
public:
	void operator=(nullptr_t)
	{
		instance = nullptr;
		function = nullptr;
	}

	void operator=(const Delegate& _other)
	{
		instance = _other.instance;
		function = _other.function;
	}
#pragma endregion operator
};