#version 330 core

in vec3 outPos;
in vec3 outColor;
in vec3 outNormal;
in vec3 FragPos;

uniform vec3 cameraPos;


out vec4 FragColor;

uniform mat4 ModelMatrix;

uniform vec3 LightPos;



void main()
{
	// AMBIENT_LIGHTNING
	//vec3 ambientLight = vec3(0.7f,0.7f,0.7f);

	// DIFFUSE_LIGHTNING
	
	vec3 norm = normalize(outNormal);
	//LightPosWorld = vec3(ModelMatrix * vec4(outPos, 1.0));
	vec3 lightDir = normalize(LightPos - FragPos);
	float diffuse = max(dot(lightDir, norm),0.0);
	vec3 diffuseFinal = diffuse * vec3(1.0f,1.0f,1.0f);


	// SPECULAR_LIGHTNING

	

	/*vec3 viewDir = normalize(LightPos - FragPos);
	vec3 reflectDir = normalize(reflect(viewDir, norm));
	vec3 cameraPos = normalize(FragPos - cameraPos);
	float spec = pow(max(dot(cameraPos, reflectDir), 0.0), 32);
	vec3 specular =  spec * vec3(1.f,1.f,1.f);*/





	//vec3 pointToLightDirVector = normalize(outPos - LightPosition);
	//vec3 diffuseColor = vec3(1.f,0.f,0.f);
	//float diffuse = clamp(dot(pointToLightDirVector,outNormal),0,1);
 //   vec3 diffuseFinal = diffuse * outColor ;




	 FragColor = vec4(outColor, 1.0f) * vec4(diffuseFinal,1.0f);

}