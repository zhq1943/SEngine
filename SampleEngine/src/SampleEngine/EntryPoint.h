#pragma once

#ifdef SE_PLATEFORM_WINDOWS


extern SEngine::CApplication* SEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("SEngne Run!\n");
	auto app = SEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif