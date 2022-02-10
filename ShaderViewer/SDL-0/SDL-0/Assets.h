#pragma once
#include"Shader.h"
#include<map>
#include<string>

using std::map;
using std::string;

class Assets
{
public:
	static std::map<std::string, Shader > shaders;

	//load and generate a shader progrm from file loading vertex, fragment(tessellation control , evaluation
	//geometry) shaders source code. If Tcshaderfile, teshaderfile,gshaderfile are not mullptr it also loads
	static Shader LoadShader(const std::string& vShaderFile, const std::string& fShaderFile,
		const std::string& tcShaderFile, const std::string& teChaderFile,
		const std::string& gShaderFile, const std::string& name);


	// retrieves a stored shader
	static Shader& GetShader(const std::string& name);

	//properly de'alloctae all loaded ressources
	static void Clear();

private:


	static Shader LoadShaderFromFile(const std::string& vShaderFile, const std::string& fShaderFile,
		const std::string& tcShaderFile = "", const std::string& teShaderFile = "",
		const std::string& gShaderFile = "");
};

