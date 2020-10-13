#pragma once

#include "SampleEngine/Core.h"

namespace SEngine {
	class SE_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return m_InputInstance->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return m_InputInstance->IsMouseButtonPressedImpl(button); }
		static std::pair<float,float> GetMousePosition() { return m_InputInstance->GetMousePositionImpl(); }
		static float GetMouseXPos() { return m_InputInstance->GetMouseXPosImpl(); }
		static float GetMouseYPos() { return m_InputInstance->GetMouseYPosImpl(); }


	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXPosImpl() = 0;
		virtual float GetMouseYPosImpl() = 0;

	private:
		static Input* m_InputInstance;
	};
}