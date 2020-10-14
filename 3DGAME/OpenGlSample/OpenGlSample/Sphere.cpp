#include "Sphere.h"

Sphere::Sphere() {

     VertexArrayID = Sphere_VertexArrayID;
     programID = Sphere_programID;
     MatrixID = Sphere_MatrixID;
     ViewMatrixID= Sphere_ViewMatrixID;
     ModelMatrixID= Sphere_ModelMatrixID;
     Texture= Sphere_Texture;
     TextureID= Sphere_TextureID;

    vertices= Sphere_vertices;
    uvs= Sphere_uvs;
    normals= Sphere_normals;

    vertexbuffer= Sphere_vertexbuffer;
    uvbuffer= Sphere_uvbuffer;
    normalbuffer= Sphere_normalbuffer;
    LightID= Sphere_LightID;

    Filemgr->loadOBJ(this, "orb.obj",
        "uvtemplate.DDS",
        "20161676_vs.shader",
        "20161676_fs.shader");
}

void Sphere::shutDown()
{
    // Cleanup VBO and shader
    glDeleteBuffers(1, &Sphere_vertexbuffer);
    glDeleteBuffers(1, &Sphere_uvbuffer);
    glDeleteBuffers(1, &Sphere_normalbuffer);
    glDeleteProgram(Sphere_programID);
    glDeleteTextures(1, &Sphere_Texture);
    glDeleteVertexArrays(1, &Sphere_VertexArrayID);
}