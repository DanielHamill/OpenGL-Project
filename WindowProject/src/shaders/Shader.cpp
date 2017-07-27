#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	// retreave shader source code from file path
	std::string vertCode;
	std::string fragCode;
	std::ifstream vertFile;
	std::ifstream fragFile;
	// ensure ifstream objects can throw exeptions
	vertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		vertFile.open(vertexPath);
		fragFile.open(fragmentPath);
		std::stringstream vertStream, fragStream;
		// read file's buffer contents into streams
		vertStream << vertFile.rdbuf();
		fragStream << fragFile.rdbuf();
		// close file handlers
		vertFile.close();
		fragFile.close();
		// convert stream into string
		vertCode = vertStream.str();
		fragCode = fragStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* vertSource = vertCode.c_str();
	const char* fragSource = fragCode.c_str();

	// creating\compiling vertex shader
	GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertSource, NULL);
	glCompileShader(vertexID);
	GLint vSuccess;
	char vInfoLog[512];
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &vSuccess);
	if (!vSuccess)
	{
		glGetShaderInfoLog(vertexID, 512, NULL, vInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vInfoLog << std::endl;
	}

	// creating\compiling fragment shader
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragSource, NULL);
	glCompileShader(fragmentID);
	GLint fSuccess;
	char fInfoLog[512];
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &fSuccess);
	if (!fSuccess)
	{
		glGetShaderInfoLog(fragmentID, 512, NULL, fInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fInfoLog << std::endl;
	}

	// creating\linking shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertexID);
	glAttachShader(ID, fragmentID);
	glLinkProgram(ID);
	GLint pSuccess;
	char pInfoLog[512];
	glGetProgramiv(ID, GL_LINK_STATUS, &pSuccess);
	if (!pSuccess)
	{
		glGetProgramInfoLog(ID, 512, NULL, pInfoLog);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << pInfoLog << std::endl;
	}
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

}

// use/activate the shader
void Shader::use()
{
	glUseProgram(ID);
}

// utility uniform functions
void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}