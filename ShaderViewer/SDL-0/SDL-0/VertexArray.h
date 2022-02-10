#pragma once

constexpr float vertices[] = {
	-0.5f, 0.5f,0.f, // Top left
	0.5f,0.5f,0.f,// Top Right
	0.5f,-0.5f,0.f,// BottomRight
	-0.5f,-0.5f,0.f// Bottom Left
};
constexpr unsigned int indices[] = {
	0,1,2,
	2,3,0
};

class VertexArray
{
public:
	VertexArray(const float* verticesP, unsigned int nbVerticesP, const unsigned int* indicesP, unsigned int nbIndicesP);
	~VertexArray();

	void SetActive();

	unsigned int GetNbVertices()const { return nbVertices; }
	unsigned int GetNbIndices() const { return nbIndices; }

private:

	unsigned int nbVertices;
	unsigned int nbIndices;

	//OpenGl Id of the vertex array object
	unsigned int vertexArray;

	//OpenGL Id of the vertex Buffer$
	unsigned int vertexBuffer;

	//OpenGL ID of the index Buffer
	unsigned int indexBuffer;


};

