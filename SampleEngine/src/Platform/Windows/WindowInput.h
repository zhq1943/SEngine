#pragma once

#include"SampleEngine/Input.h"

namespace SEngine
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float,float> GetMousePositionImpl() override;
		virtual float GetMouseXPosImpl() override;
		virtual float GetMouseYPosImpl()override;


	};
}
