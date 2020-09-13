
#include<SEngine.h>
#include<iostream>
#include<memory>

class Sandbox:public SEngine::CApplication
{
public:
	Sandbox()
	{};
	~Sandbox()
	{};

private:

};


SEngine::CApplication* SEngine::CreateApplication()
{
	return new Sandbox();
}