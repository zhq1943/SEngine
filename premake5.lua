workspace "SampleEngine"
	architecture "x64"

	configurations
	{
	   "Debug",
	   "Release",
	   "Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "SampleEngine/vendor/GLFW/include"
IncludeDir["GLAD"] = "SampleEngine/vendor/GLAD/include"
IncludeDir["ImGui"] = "SampleEngine/vendor/ImGui" 

include "SampleEngine/vendor/GLFW/"
include "SampleEngine/vendor/GLAD/"
include "SampleEngine/vendor/ImGui/"


project "SampleEngine"
	location "SampleEngine"
	kind "SharedLib"
	language "C++"
    staticruntime "off"

	targetdir ("Output/bin/"..outputdir.."/%{prj.name}")
	objdir ("Output/bin_int/"..outputdir.."/%{prj.name}")

	pchheader "sepch.h"
	pchsource "SampleEngine/src/sepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}"
	}
    
    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"SE_PLATEFORM_WINDOWS",
			"SE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath}  ../Output/bin/"..outputdir.."/Sandbox")
		}

		filter "configurations:Debug"
			defines "SE_DEBUG"
            runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "SE_RELEASE"
            runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "SE_DIST"
            runtime "Release"
			optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
    staticruntime "off"

	targetdir ("Output/bin/"..outputdir.."/%{prj.name}")
	objdir ("Output/bin_int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SampleEngine/vendor/spdlog/include",
        "SampleEngine/vendor/GLAD/include",
        "SampleEngine/vendor/ImGui",
		"SampleEngine/src"
	}

	links
	{
		"SampleEngine"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"SE_PLATEFORM_WINDOWS",
		}

		filter "configurations:Debug"
			defines "SE_DEBUG"
            runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "SE_RELEASE"
            runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "SE_DIST"
            runtime  "Release"
			optimize "On"