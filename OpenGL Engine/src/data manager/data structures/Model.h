#pragma once
#include <string>
#include <vector>
#include <array>

class Mesh;
class Model;
class RenderSystem;

struct VAO
{
	VAO();
	VAO(unsigned int ID, unsigned int elementCount);

	unsigned int ID;
	unsigned int elementCount;

	//Compares vertex arrays
	inline bool operator==(const VAO& rhs) const;
	inline bool operator!=(const VAO& rhs) const
	{
		return !(*this == rhs);
	}
};

enum class ShadingMapType
{
	Diffuse = 0,
	Specular = 1,


	UNSPECIFIED = 10,
	SIZE = 11
};
struct ShadingMap
{
	ShadingMap();
	ShadingMap(unsigned int textureID, ShadingMapType type);

	unsigned int textureID;
	ShadingMapType type;

	//Compares shading maps
	inline bool operator==(const ShadingMap& rhs);
	inline bool operator!=(const ShadingMap& rhs)
	{
		return !(*this == rhs);
	}
};

class Material
{
public:
	Material();

	void addShadingMap(ShadingMap map);
	void changeSpecularShininess(float value);

	//Compares materials
	inline bool operator==(const Material& rhs);
	inline bool operator!=(const Material& rhs)
	{
		return !(*this == rhs);
	}
private:
	//Material shading maps
	std::array<ShadingMap, (size_t)(ShadingMapType::SIZE)> m_shaderMaps;
	float m_shininess;

	friend Mesh;
	friend RenderSystem;
};

class Mesh
{
public:
	Mesh();
	Mesh(VAO& vao, Material& material);

	void setVAO(VAO vao);
	void setMaterial(Material material);
	void setWidth(float width);
	void setHeight(float height);

	VAO& getVAO();
	Material& getMaterial();
	float getWidth();
	float getHeight();

	//Compares meshes
	inline bool operator==(const Mesh& rhs);
	inline bool operator!=(const Mesh& rhs)
	{
		return !(*this == rhs);
	}
private:
	//Mesh vao
	VAO m_vertexArray;
	//Mesh material
	Material m_material;

	//Individual width and height of a mesh
	float m_width;
	float m_height;

	friend Model;
};

class Model
{
public:
	Model();
	void addMesh(Mesh mesh);

	float getWidth() const;
	float getHeight() const;

	std::vector<Mesh>& getMeshes();
	Mesh getMeshByVAO(VAO vao);
private:
	//Model meshes
	std::vector<Mesh> m_meshes;

	float m_width;
	float m_height;
};