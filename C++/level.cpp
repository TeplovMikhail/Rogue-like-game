
#include "level.hpp"

#include <iostream>

Level::Level(const std::string& name)
    : m_name(name)
{
    std::cout << "Создан уровень: " << m_name << '\n';
}

Level::~Level()
{
    std::cout << "Уничтожен уровень: " << m_name << '\n';
}

void Level::Describe() const
{
    std::cout << "Уровень: " << m_name << '\n';
    m_room.Describe();
}

Room& Level::GetRoom()
{
    return m_room;
}
