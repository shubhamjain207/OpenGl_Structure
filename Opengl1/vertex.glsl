#version 330 core


layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout(location = 2) in vec3 aNormal;


out vec3 outPos;
out vec3 outColor;
out vec3 outNormal;
out vec3 FragPos;


uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

uniform vec3 ColorChange; 

void main()
{
  
   outPos = aPos;
   outColor = ColorChange;
  
   FragPos = vec3(ModelMatrix * vec4(aPos, 1.0));
   outNormal =  aNormal;
	
   gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(aPos,1.f);
 
  

   
}