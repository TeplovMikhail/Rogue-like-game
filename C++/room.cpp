#include "room.hpp"
#include <iostream>

Room::Room() : m_enemy(nullptr)
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
    if (m_enemy != nullptr) {
        std::cout << "Противник помещён в комнату.\n";
    }
}

void Room::Describe() const
{
    std::cout << "Осмотр комнаты: ";
    if (m_enemy == nullptr) {
        std::cout << "Комната пуста.\n";
        return;
    }
    std::cout << "В комнате находится враг.\n";
    m_enemy->Describe();
}

void Room::AttackEnemy(int damage)
{

    if (damage <= 0) {
        std::cout << "[Ошибка] Невозможно атаковать уроном <= 0!\n";
        return;
    }

    if (m_enemy == nullptr) {
        std::cout << "В комнате нет противника.\n";
        return;
    }
    
    if (!m_enemy->IsAlive()) {
        std::cout << "Нельзя атаковать мертвого врага.\n";
        return;
    }

    m_enemy->TakeDamage(damage);
}