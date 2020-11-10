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

	void loadObj(RenderableObject* obj, const char* vertex_data, const char* texturename, const char* vs_shader, const char* fs_shader);

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