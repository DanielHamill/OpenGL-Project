#pragma once

#include <glad\glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;
	Shader(const GLchar *vertPath, const GLchar *fragPath);
	// activate shader
	void use();
	// utility uniform functions
	void setBool(const std::string &name, const bool value) const;
	void setInt(const std::string &name, const int value) const;
	void setFloat(const std::string &name, const float value) const;
};

