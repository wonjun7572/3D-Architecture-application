#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <string>
#include <vector>

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

class RenderableObject;

class FileManager
{
public:
	static FileManager* instance()
	{
		static FileManager instance;

		return &instance;
	}

public:

	//void loadObj(RenderableObject* obj, const char* vertex_data, const char* texturename, const char* vs_shader, const char* fs_shader);
	void loadObj(
		RenderableObject* target_obj,
		std::string obj_path,
		std::string texture_path,
		std::string vs_shader_path,
		std::string fs_shader_path);

	bool loadOBJ(
		const char* path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals
	);
	GLuint loadBMP(const char* imagepath);
	GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
};

#endif // !__FILEMANAGER_H__