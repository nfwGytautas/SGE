#pragma once
#include "Entity.h"

class BatchManager;
class EntityManager
{
public:
	void refresh();
	void update(float frameTime);
	void draw();
	Entity& addEntity();

	void addToGroup(Entity* mEntity, Group mGroup);
	std::vector<Entity*>& getEntitiesByGroup(Group mGroup);

	EntityManager(BatchManager* pManager);
	~EntityManager();
private:
	std::vector<std::unique_ptr<Entity>> m_entities;
	std::array<std::vector<Entity*>, maxGroups> m_groupedEntities;
	BatchManager* m_bManager;
};