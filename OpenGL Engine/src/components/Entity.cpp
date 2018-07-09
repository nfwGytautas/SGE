#include "Entity.h"
#include "EntityManager.h"

void Entity::init()
{
	for (auto& c : m_components)
	{
		c->init();
	}
}

void Entity::update(float frameTime)
{
	for (auto& c : m_components)
	{
		c->update(frameTime);
	}
}

void Entity::draw()
{
	for (auto& c : m_components)
	{
		c->draw();
	}
}

void Entity::handleMessage(const char * message)
{
	for (auto& c : m_components)
	{
		c->handleMessage(message);
	}
}

bool Entity::isAlive() const
{
	return m_alive;
}

void Entity::destroy()
{
	m_alive = false;
}

bool Entity::hasGroup(Group mGroup) const noexcept
{
	return m_groupBitset[mGroup];
}

void Entity::delGroup(Group mGroup) noexcept
{
	m_groupBitset[mGroup] = false;
}

void Entity::addGroup(Group mGroup) noexcept
{
	m_groupBitset[mGroup] = true;
	m_manager.addToGroup(this, mGroup);
}

Entity::Entity(EntityManager& mManager)
	: m_manager(mManager)
{}

Entity::~Entity()
{
	m_components.clear();
}