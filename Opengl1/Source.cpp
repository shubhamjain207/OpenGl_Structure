//#include<glad/glad.h>
//#include<glfw3.h>
//#include<iostream>
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
//	if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window,true);
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
//
//
//int main() {	
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//
//		
//	GLFWwindow* window = glfwCreateWindow(800,600,"Learn",NULL,NULL);
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
//	glViewport(0,0,800,600);
//
//	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
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
//	unsigned char* image = stbi_load("grass.png", &width, &height, &nrChannels, 0);
//
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//
//
//	
//
//	stbi_image_free(image);
//
//
//	const char* vertexShaderSource = "#version 330 core\n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"layout (location = 1) in vec3 aColor;\n"
//		"layout (location = 2) in vec2 aTexCoord;\n"
//		"out vec3 outColor;\n"
//		"out vec2 TexCoord;\n"
//		"uniform mat4 model;\n"
//		"uniform mat4 view;\n"
//		"uniform mat4 projection;\n"
//		"void main()\n"
//		"{\n"
//		"   gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//		"   outColor = aColor;\n"
//		"   TexCoord = aTexCoord;\n"
//		"}\0";
//
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	const char* fragmentShaderSource = "#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"in vec3 outColor;\n"
//		"in vec2 TexCoord;\n"
//		"uniform sampler2D ourTexture;\n"
//		"void main()\n"
//		"{\n"		
//		"FragColor = texture(ourTexture,TexCoord);\n"
//		"}\0";
//
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//
//
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	int count = 0.0f;
//
//	glUseProgram(shaderProgram);
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	//float vertices[] = {
//	//	// positions          // colors           // texture coords
//	//	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
//	//	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
//	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
//	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
//	//};
//
//
//
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//	   glm::vec3(0.0f,  0.0f,  0.0f),
//	   glm::vec3(2.0f,  5.0f, -15.0f),
//	   glm::vec3(-1.5f, -2.2f, -2.5f),
//	   glm::vec3(-3.8f, -2.0f, -12.3f),
//	   glm::vec3(2.4f, -0.4f, -3.5f),
//	   glm::vec3(-1.7f,  3.0f, -7.5f),
//	   glm::vec3(1.3f, -2.0f, -2.5f),
//	   glm::vec3(1.5f,  2.0f, -2.5f),
//	   glm::vec3(1.5f,  0.2f, -1.5f),
//	   glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//
//
//	unsigned int indeces[] = {
//
//		0,1,3,
//		1,2,3
//
//	};
//
//
//	
//	unsigned int EBO, VAO,VBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//
//	
//
//
//	
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
//
//
//	
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_DYNAMIC_DRAW);
//
//	
//	
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(205.f/255.f,240.f/255.f,255.f/255.f,1);
//		glEnable(GL_DEPTH_TEST);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//glm::mat4 model = glm::mat4(1.0f);
//		//model = glm::rotate(model, (float)glfwGetTime() * glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.3f));
//
//		//unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//		//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		
//
//
//		
//
//		glm::mat4 view = glm::mat4(1.0f);
//		float radius = 10.0f;
//
//		view = glm::lookAt(glm::vec3(posX, posY, posZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//
//		/*view = glm::translate(view, glm::vec3(0.0f, 1.0f, -10.0f));*/
//
//		unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//		
//
//		glm::mat4 projection = glm::mat4(1.0f);
//		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//
//		unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
//		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//
//
//
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		glUseProgram(shaderProgram);
//
//	
//
//		glBindVertexArray(VAO);
//
//		for (int i = 0; i < 10 ;i++) {
//
//			glm::mat4 model = glm::mat4(1.0f);
//
//			model = glm::translate(model, cubePositions[i]);
//
//			/*model = glm::rotate(model, (float)glfwGetTime() * glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.3f));*/
//
//
//			unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//			 
//			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		
//		
//		
//
//		
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//		
//	
//	
//	}
//
//
//
//	glfwTerminate();
//	
//
//	return 0;
//
//}