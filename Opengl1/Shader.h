#pragma once


#include<glad/glad.h>
#include<glfw3.h>
#include<fstream>
#include<iostream>
#include <string>
#include <stdio.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


class Shader {

private:
	GLuint id;

	std::string loadShaderSource(char* fileName) 
	{

		std::string temp = "";
		std::string src = "";

		std::ifstream in_File;


		in_File.open(fileName);

		if (in_File.is_open()) {
			while (std::getline(in_File, temp)) {
				src += temp + "\n";
			}
		}
		else {
			std::cout << "CANNOT OPEN SHADER FILE";
		}

		in_File.close();
		
		return src;
	
	}

	GLuint loadShader(GLenum type,char* fileName)
	{
	
		char infoLog[512];
		GLint success;

		GLuint shader = glCreateShader(type);
		std::string str_src = this->loadShaderSource(fileName);
		const GLchar* src = str_src.c_str();
		glShaderSource(shader, 1, &src, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "CANNOT Compile SHADER FILE"<<fileName<<"\n";
			std::cout << infoLog;
		}
		
		return shader;
	}

	void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader) 
	{

		char infoLog[512];
		GLint success;


		this->id = glCreateProgram();
		glUseProgram(this->id);

		glAttachShader(this->id, vertexShader);
		if(geometryShader) glAttachShader(this->id, geometryShader);
		glAttachShader(this->id, fragmentShader);

		glLinkProgram(this->id);


		glGetProgramiv(this->id, GL_LINK_STATUS, &success);

		if (!success) {
			std::cout << "CANNOT link shaders";
		}

		this->use();

	}


public:

	Shader(char* vertexFile, char* fragmentFile, char* geometryFile = "")
	{
		GLuint vertexShader = 0;
		GLuint fragmentShader = 0;
		GLuint geometryShader = 0; 

		
		vertexShader = loadShader(GL_VERTEX_SHADER,vertexFile);
		if (geometryFile!="") geometryShader = loadShader(GL_GEOMETRY_SHADER, geometryFile);
		fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentFile);

		this->linkProgram(vertexShader,geometryShader, fragmentShader);

		
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);
		glDeleteShader(geometryShader);

		


	}

	~Shader()
	{
		glDeleteProgram(this->id);
	
	
	}

	void use()
	{
		glUseProgram(this->id);
	}

	int getId() {
		return this->id;
	}

	void unuse()
	{
		glUseProgram(0);
	}

	void setMat4fv(glm::mat4 value, const GLchar* name) {
		

		
		glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, GL_FALSE, glm::value_ptr(value));


	
	}

	void set3fv(glm::vec3 value, const GLchar* name) {
		

		glUniform3fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));

		
	}
};