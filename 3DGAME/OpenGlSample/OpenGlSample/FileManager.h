#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <string>
#include <vector>

#include "glm/glm.hpp"

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
	void loadObJ(
		RenderableObject* target_obj,
		std::string obj_path,
		std::string texture_path,
		std::string vs_shader_path,
		std::string fs_shader_path
	);
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