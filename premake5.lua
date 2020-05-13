workspace "Pine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pine/vendor/GLFW/include"
IncludeDir["Glad"] = "Pine/vendor/Glad/include"
IncludeDir["ImGui"] = "Pine/vendor/imgui"
IncludeDir["glm"] = "Pine/vendor/glm"
IncludeDir["stb_image"] = "Pine/vendor/stb_image"

group "Dependencies"
	include "Pine/vendor/GLFW"
	include "Pine/vendor/Glad"
	include "Pine/vendor/imgui"

group ""

project "Pine"
	location "Pine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		"PN_PLATFORM_WINDOWS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "PN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pine/vendor/spdlog/include",
		"Pine/src",
		"Pine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Pine"
	}

	defines
	{
		"PN_PLATFORM_WINDOWS"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "PN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PN_DIST"
		runtime "Release"
		optimize "on"