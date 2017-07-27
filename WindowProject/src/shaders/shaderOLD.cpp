//#include "shader.h"
//SHADER_H
//
//Shader::Shader(const GLchar *vertPath, const GLchar *fragPath)
//{
//	// vertex and fragment shader source code from file path
//	std::string vertSource;
//	std::string fragSource;
//	std::ifstream vertFile;
//	std::ifstream fragFile;
//
//	// ensure ifstream objects can throw exceptions:
//	vertFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
//	fragFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
//	try
//	{
//		// open shader shouce files
//		vertFile.open(vertPath, 1, 64);
//		fragFile.open(fragPath, 1, 64);
//		std::stringstream vertStream, fragStream;
//		// read file's buffer contents into streams
//		vertStream << vertFile.rdbuf();
//		fragStream << fragFile.rdbuf();
//		// close file handlers
//		vertFile.close;
//		fragFile.close;
//		// convert stream into string
//		vertSource = vertStream.str;
//		fragSource = fragStream.str;
//	} 
//	catch (std::ifstream::failure e)
//	{
//		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
//	}
//
//	// create/compile vertex shader
//	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertID, 1, &vertSource.c_str, NULL);
//	glCompileShader(vertID);
//	int vSuccess;
//	GLchar vInfoLog[512];
//	glGetShaderiv(vertID, GL_COMPILE_STATUS, &vSuccess);
//	if (!vSuccess)
//	{
//		glGetShaderInfoLog(vertID, 512, NULL, vInfoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vInfoLog << std::endl;
//	}
//
//	// create/compile fragment shader
//	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragID, 1, &fragSource.c_str, NULL);
//	glCompileShader(fragID);
//	int fSuccess;
//	GLchar fInfoLog[512];
//	glGetShaderiv(fragID, GL_COMPILE_STATUS, &fSuccess);
//	if (!fSuccess)
//	{
//		glGetShaderInfoLog(fragID, 512, NULL, fInfoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fInfoLog << std::endl;
//	}
//
//	// creat/link shader program
//	ID = glCreateProgram();
//	glAttachShader(ID, vertID);
//	glAttachShader(ID, fragID);
//	glLinkProgram(ID);
//	int pSuccess;
//	GLchar pInfoLog[512];
//	glGetProgramiv(ID, GL_LINK_STATUS, &pSuccess);
//	if (!pSuccess)
//	{
//		glGetProgramInfoLog(ID, 512, NULL, pInfoLog);
//		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << pInfoLog << std::endl;
//	}
//	glDeleteShader(vertID);
//	glDeleteShader(fragID);
//}