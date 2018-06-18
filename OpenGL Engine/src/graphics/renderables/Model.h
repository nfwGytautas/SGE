#pragma once

#include "..\mesh\Mesh.h"
#include "..\material\Material.h"

class Model
{
public:
	Model(Mesh mesh, Material material);
	~Model();

	Mesh& GetMesh()
	{
		return m_mesh;
	}
	Material& GetMaterial()
	{
		return m_material;
	}

	size_t GetHash() const;
	bool operator==(const Model& mod) const;
private:
	Mesh m_mesh;
	Material m_material;
};