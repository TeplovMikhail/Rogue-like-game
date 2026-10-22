
#include "room.hpp"

#include <iostream>

Room::Room()
    : m_enemy(nullptr)
{
    std::cout << "Создана комната.\n";
}

Room::~Room()
{
    std::cout << "Уничтожена комната.\n";
}

void Room::SetEnemy(Enemy* enemy)
{
    m_enemy = enemy;

    if (m_enemy != nullptr)
    {
        std::cout << "Противник помещён в комнату.\n";
    }
}

void Room::Describe() const
{
    if (m_enemy == nullptr)
    {
        std::cout << "Комната пуста.\n";
        return;
    }

    m_enemy->Describe();
}

void Room::AttackEnemy(int damage)
{
    if (m_enemy == nullptr)
    {
        std::cout << "В комнате нет противника.\n";
        return;
    }

    m_enemy->TakeDamage(damage);
}
