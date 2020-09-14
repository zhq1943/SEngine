#pragma once

#ifdef SE_PLATEFORM_WINDOWS


extern SEngine::CApplication* SEngine::CreateApplication();

int main(int argc, char** argv)
{
	SEngine::CLog::Init();
	SE_CORE_WARM("Hello this is Core Log");
	SE_INFO("hello this is Cline");

	auto app = SEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif