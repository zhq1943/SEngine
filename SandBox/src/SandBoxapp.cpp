
#include<SEngine.h>
#include<iostream>
#include<memory>



class ExampleLayer :public SEngine::CLayer
{
public:
	ExampleLayer()
		:CLayer("Example")
	{
	};

	void OnUpdate() override
	{
		//SE_INFO("ExampleLayer::Update");
	};

	void OnEvent(SEngine::Event& event) override
	{
		//SE_TRACE("{0}", event);
		if (event.GetEventType() == SEngine::EventType::KeyPressed)
		{
			SEngine::KeyPressedEvent& keyEvent = (SEngine::KeyPressedEvent&)event;
			SE_TRACE("{0}",(char)keyEvent.GetKeyCode());
		}
	}
};

class Sandbox:public SEngine::CApplication
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	};
	~Sandbox()
	{};

private:

};


SEngine::CApplication* SEngine::CreateApplication()
{
	return new Sandbox();
}