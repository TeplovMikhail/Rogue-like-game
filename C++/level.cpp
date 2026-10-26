#include "level.hpp"
#include <iostream>

Level::Level(const std::string& name) : m_name(name), m_room()
{

    if (m_name.empty()) {
        std::cout << "[Ошибка] Название уровня не может быть пустым. Установлено 'Безымянный уровень'.\n";
        m_name = "Безымянный уровень";
    }
    std::cout << "Создан уровень: " << m_name << "\n";
}

Level::~Level()
{
    std::cout << "Уничтожен уровень: " << m_name << "\n";
}

void Level::Describe() const
{
    std::cout << "Уровень [" << m_name << "]\n";
    m_room.Describe();
}

void Level::Explore()
{
    std::cout << "Игрок исследует уровень " << m_name << "...\n";
    m_room.AttackEnemy(15);
}

Room& Level::GetRoom()
{
    return m_room;
}