
#include<SEngine.h>
#include<iostream>
#include<memory>


class ExampleLayer :public SEngine::CLayer
{
public:
	ExampleLayer()
		:CLayer("Example")
	{};

	void OnUpdate() override
	{
		SE_INFO("ExampleLayer::Update");
	};

	void OnEvent(SEngine::Event& event) override
	{
		SE_TRACE("{0}", event);
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