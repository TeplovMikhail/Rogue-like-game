#include "room.hpp"
#include <iostream>
#include <memory>

Room::Room()
{
    std::cout << "Создана комната.\n";
}

Room::~Room()
{
    std::cout << "Уничтожена комната.\n";
}

void Room::SetEnemy(const std::shared_ptr<Enemy>& enemy)
{
    m_enemy = enemy;
    if (!m_enemy.expired()) {
        std::cout << "Противник помещён в комнату.\n";
    }
}

void Room::Describe() const
{
    std::cout << "Осмотр комнаты: ";

    if (auto enemy = m_enemy.lock()) {
        std::cout << "В комнате находится враг.\n";
        enemy->Describe();
    } 
    else {
        std::cout << "Комната пуста (враг отсутствует или уничтожен).\n";
    }
}

void Room::AttackEnemy(int damage)
{
    if (damage <= 0) {
        std::cout << "[Ошибка] Невозможно атаковать уроном <= 0!\n";
        return;
    }

    auto enemy = m_enemy.lock();
    if (!enemy) {
        std::cout << "В комнате нет противника (или объект уже удален).\n";
        return;
    }

    if (!enemy->IsAlive()) {
        std::cout << "Нельзя атаковать мертвого врага.\n";
        return;
    }

    enemy->TakeDamage(damage);
}