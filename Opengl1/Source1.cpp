//#include<glad/glad.h>
//#include<glfw3.h>
//#include<fstream>
//#include<iostream>
//#include <string>
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//
//#define STB_IMAGE_IMPLEMENTATION
//
//#include "stb_image.h"
//
//float posX = 0.0f, posY = 0.0f, posZ = 4.0f;
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window) {
//
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//		posZ -= 0.01f;
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//		posX -= 0.01f;
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//		posZ += 0.01f;
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//		posX += 0.01f;
//	}
//
//
//	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//
//	}
//
//}
//
//bool loadShaders(GLuint &program){
//
//	bool loadSuccess = true;
//
//
//		char infoLog[512];
//		GLint success;
//
//
//		std::string temp = "";
//		std::string src = "";
//
//		std::ifstream in_File;
//
//		//Vertex-------->
//
//
//		in_File.open("vertex.glsl");
//
//		if (in_File.is_open()) {
//			while(std::getline(in_File,temp)) {
//				src += temp + "\n";
//			}
//		}
//		else {
//			std::cout << "CANNOT OPEN VERTEX SHADER FILE";
//		}
//
//		in_File.close();
//
//		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//		const GLchar* vertSrc = src.c_str();
//		glShaderSource(vertexShader,1,&vertSrc,NULL);
//		glCompileShader(vertexShader);
//
//		glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
//		if (!success) {
//			std::cout << "CANNOT Compile VERTEX SHADER FILE";
//		}	
//
//
//		temp = "";
//		src = "";
//
//		glDeleteShader(vertexShader);
//
//
//		//Fragment-------->
//
//
//		
//
//
//		in_File.open("fragment.glsl");
//
//		if (in_File.is_open()) {
//			while (std::getline(in_File, temp)) {
//				src += temp + "\n";
//			}
//		}
//		else {
//			std::cout << "CANNOT OPEN Fragment SHADER FILE";
//		}
//
//		in_File.close();
//
//		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//		const GLchar* fragSrc = src.c_str();
//		glShaderSource(fragmentShader, 1, &fragSrc, NULL);
//		glCompileShader(fragmentShader);
//
//		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//		if (!success) {
//			std::cout << "CANNOT Compile Fragment SHADER FILE";
//		}
//
//
//		temp = "";
//		src = "";
//
//
//		program = glCreateProgram();
//
//		glAttachShader(program,vertexShader);
//		glAttachShader(program,fragmentShader);
//		glLinkProgram(program);
//
//
//		glGetProgramiv(program,GL_LINK_STATUS,&success);
//		if (!success) {
//			std::cout << "CANNOT link shaders";
//		}
//
//		glUseProgram(0);
//		glDeleteShader(fragmentShader);
//		glDeleteShader(vertexShader);
//
//
//
//		return loadSuccess;
//
//}
//
//
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//		return -1;
//
//	}
//
//
//
//	glViewport(0, 0, 800, 600);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	// set texture filtering parameters
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int width, height, nrChannels;
//
//
// //  
//
//	//const char* vertexShaderSource = "#version 330 core\n"
//	//	"layout (location = 0) in vec3 aPos;\n"
//	//	"layout (location = 1) in vec3 aColor;\n"
//	//	"layout (location = 2) in vec3 aNormal;\n"
//	//	"out vec3 outColor;\n"
//	//	"out vec3 outNormal;\n"
//	//	"uniform mat4 model;\n"
//	//	"uniform mat4 view;\n"
//	//	"uniform mat4 projection;\n"
//	//	"void main()\n"
//	//	"{\n"
//	//	"   gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//	//	"   outColor = aColor;\n"
//	//	"   outNormal = mat3(ModelMatrix) * aNormal;\n"
//	//	"}\0";
//
//	//unsigned int vertexShader;
//	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//
//	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	//glCompileShader(vertexShader);
//
//	//const char* fragmentShaderSource1 = "#version 330 core\n"
//	//	"out vec4 FragColor;\n"
//	//	"in vec3 outNormal;\n"
//	//	"uniform vec3 lightColor;\n"
//	//	"void main()\n"
//	//	"{\n"
//	//	"FragColor = vec4(lightColor,1.0);\n"
//	//	"}\0";
//
//	//unsigned int fragmentShader1;
//	//fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
//	//glCompileShader(fragmentShader1);
//
//	////For Ambient lightning just multiply light color with alpha value
//
//	//const char* fragmentShaderSource2 = "#version 330 core\n"
//	//	"out vec4 FragColor;\n"
//	//	"uniform vec3 objectColor;\n"
//	//	"in vec3 outNormal;\n"
//	//	"uniform vec3 lightColor;\n"
//	//	"void main()\n"
//	//	"{\n"
//	//	"FragColor = vec4(0.2f * lightColor * objectColor,1.0);\n"
//	//	"}\0";
//
//
//
//	//unsigned int fragmentShader2;
//	//fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//	//glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
//	//glCompileShader(fragmentShader2);
//
//
//
//
//	//unsigned int shaderProgram1;
//	//shaderProgram1 = glCreateProgram();
//
//
//	//glAttachShader(shaderProgram1, vertexShader);
//	//glAttachShader(shaderProgram1, fragmentShader1);
//	//glLinkProgram(shaderProgram1);
//
//
//
//	//unsigned int shaderProgram2;
//	//shaderProgram2 = glCreateProgram();
//
//
//	//glAttachShader(shaderProgram2, vertexShader);
//	//glAttachShader(shaderProgram2, fragmentShader2);
//	//glLinkProgram(shaderProgram2);
//
//
//
//	//////glUseProgram(shaderProgram1);
//	////glUseProgram(shaderProgram2);
//
//	//glDeleteShader(vertexShader);
//	//glDeleteShader(fragmentShader2);
//	//glDeleteShader(fragmentShader1);
//
//
//	GLuint coreProgram;
//
//	if (!loadShaders(coreProgram)) {
//	
//		glfwTerminate();
//
//	}
//
//	//float vertices[] = {
//
//	//	-0.5f, -0.5f, 0.0f,
//	//	0.5f, -0.5f, 0.0f, 
//	//	0.5f,  0.5f, 0.0f,
//	//	-0.5f,  0.5f, 0.0f
//
//	//};
//
//
//	float vertices[] = {
//		0.0f,0.0f,0.0f,
//		0.5f, 0.5f, 0.0f,
//		0.7f, 0.0f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		0.0f,  -0.7f, 0.0f,
//		-0.5f,  -0.5f, 0.0f,
//		
//		
//		-0.7f,  0.0f, 0.0f,
//
//
//		-0.5f,  0.5f, 0.0f,
//
//
//		0.0f,  0.7f, 0.0f,
//
//
//		
//
//
//	};
//
//
//	unsigned int indices[] = {
//		0,1,2,
//		0,2,3,
//		0,4,3,
//		0,4,5,
//		0,5,6,
//		0,6,7,
//		0,7,8,
//		0,8,1
//		
//
//
//	};
//
//	//unsigned nrOf = sizeof(indices) / sizeof(GLuint);
//
//
//
//
//
//
//	//float vertices[] = {
//	//	-0.5f, -0.5f, -0.5f, 0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//
//	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//
//	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//
//	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f, -0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//
//	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	 0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f,  0.5f,0.5f,  0.5f,  0.5f,
//	//	-0.5f,  0.5f, -0.5f,0.5f,  0.5f,  0.5f,
//	//};
//
//
//	//glm::vec3 cubePositions[] = {
//	//		   glm::vec3(0.0f,  0.0f,  0.0f),
//	//		   glm::vec3(2.0f,  5.0f, -15.0f),
//	//};
//
//
//	unsigned int VAO, VBO,EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1,&EBO);
//
//	float count = 0.0f;
//	float count1 = 0.0f;
//	float count2 = 0.0f;
//	
//	bool flag = true;
//
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(1);
//
//	glBindVertexArray(0);
//
//
//
//	//unsigned int VAO1;
//	//glGenVertexArrays(1, &VAO1);
//	//glBindVertexArray(VAO1);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//glEnableVertexAttribArray(0);
//
//	
//
//	while (!glfwWindowShouldClose(window)) {
//
//		processInput(window);
//
//		glClearColor(0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f, 1);
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//glm::mat4 model = glm::mat4(1.0f);
//		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.3f));
//
//		//unsigned int modelLoc = glGetUniformLocation(shaderProgram2, "model");
//		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//
//
//		//glm::mat4 view = glm::mat4(1.0f);
//		//float radius = 10.0f;
//
//		//view = glm::lookAt(glm::vec3(posX, posY, posZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		//unsigned int viewLoc = glGetUniformLocation(shaderProgram2, "view");
//		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//
//
//		//glm::mat4 projection = glm::mat4(1.0f);
//		//projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//
//		//unsigned int projectionLoc = glGetUniformLocation(shaderProgram2, "projection");
//		//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		//glBindVertexArray(VAO);
//		///*glDrawArrays(GL_TRIANGLES, 0, 36);*/
//		//glUseProgram(shaderProgram2);
//
//
//		////for (int i = 0; i < 2;i++) {
//		////	
//		////				
//		////	if (i == 0) {
//
//
//		//glUseProgram(shaderProgram2);
//
//		//glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
//		//unsigned int colorLoc = glGetUniformLocation(shaderProgram2, "lightColor");
//		//glUniform3fv(colorLoc, 1, glm::value_ptr(color));
//
//
//		//glm::vec3 color2 = glm::vec3(1.0f, 0.0f, 0.f);
//		//unsigned int colorLoc2 = glGetUniformLocation(shaderProgram2, "objectColor");
//		//glUniform3fv(colorLoc2, 1, glm::value_ptr(color2));
//
//
//
//		////    //}
//
//		//   //else if (i == 1) {
//
//		//   //	glUseProgram(shaderProgram2);
//
//		//   //	glm::vec3 color1 = glm::vec3(0.0f, 1.f, 1.f);
//		//   //	unsigned int colorLoc1 = glGetUniformLocation(shaderProgram2, "lightColor");
//		//   //	glUniform3fv(colorLoc1, 1, glm::value_ptr(color1));
//
//		//   //	glm::vec3 color2 = glm::vec3(1.0f, 1.0f, 1.f);
//		//   //	unsigned int colorLoc2 = glGetUniformLocation(shaderProgram2, "objectColor");
//		//   //	glUniform3fv(colorLoc2, 1, glm::value_ptr(color2));
//		//   //	
//
//		//   //
//		//   //}
//		//   //
//		//glm::mat4 model = glm::mat4(1.0f);
//
//		///*	model = glm::translate(model, cubePositions[i]);*/
//
//		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.3f));
//
//
//		//unsigned int modelLoc = glGetUniformLocation(shaderProgram2, "model");
//
//		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//		//for (int i = 0; i < 100; i++) {
//			
//		/*	float r = static_cast<float>(rand()) / RAND_MAX;
//			float g = static_cast<float>(rand()) / RAND_MAX;
//			float b = static_cast<float>(rand()) / RAND_MAX;*/
//
//		if (count>255.0f ) {
//			flag = false;
//		}
//
//		if (count<0.0f) {
//			flag = true;
//		}
//
//		if (count1 > 255.0f) {
//			count1 = 0.0f;
//		}
//
//		if (count2 > 255.0f ) {
//			count2 = 0.0f;
//		}
//
//
//			float r = count / 255.0f;
//			float g = count1 / 255.0f;
//			float b = count2 / 255.0f;
//
//
//			/*float g = static_cast<float>(rand()) / RAND_MAX;
//			float b = static_cast<float>(rand()) / RAND_MAX;*/
//
//
//
//
//			
//			GLint colorUniform = glGetUniformLocation(coreProgram, "FragColor1");
//			glUniform4f(colorUniform, r,g, b,1.0f); 
//
//			
//
//
//			glUseProgram(coreProgram);
//			glBindVertexArray(VAO);
//			 glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//
//
//			glDrawElements(GL_TRIANGLES,24,GL_UNSIGNED_INT,0);
//		//}
//
//			if (flag) count += 0.4;
//			else count -= 0.4;
//
//
//			/*count1 *= 0.01;
//			count2 += 1;*/
//
//		
//		
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//
//	}
//
//
//
//
//
//
//
//
//
//
//
//
//
//	glfwTerminate();
//
//
//	return 0;
//
//}
//
