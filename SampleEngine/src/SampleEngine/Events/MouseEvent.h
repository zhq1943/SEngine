#pragma once

#include"Event.h"

namespace SEngine {
	class SE_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			:m_MouseX(x),m_MouseY(y)
		{}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent:" << m_MouseX << "," << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		float m_MouseX, m_MouseY;
	};

	class SE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset)
		{}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent:" << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	private:
		float m_XOffset, m_YOffset;
	};

	class SE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

		int m_Button;
	};

	class SE_API MosueButtonPressedEvent : public MouseButtonEvent
	{
	public :
		MosueButtonPressedEvent(int button)
			:MouseButtonEvent(button) {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	 };

	class SE_API MosueButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MosueButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}