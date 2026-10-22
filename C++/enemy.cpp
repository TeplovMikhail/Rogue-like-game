
#include "enemy.hpp"

#include <iostream>
#include <windows.h>

Enemy::Enemy(const std::string& name, int health, int damage)
    : m_name(name),
      m_health(health > 0 ? health : 1),
      m_damage(damage > 0 ? damage : 1)
{
    std::cout << "Создан противник: " << m_name << '\n';
}

Enemy::~Enemy()
{
    std::cout << "Уничтожен противник: " << m_name << '\n';
}

void Enemy::TakeDamage(int damage)
{
    if (damage <= 0)
    {
        std::cout << "Ошибка: урон должен быть положительным.\n";
        return;
    }

    if (!IsAlive())
    {
        std::cout << m_name << " уже побеждён!\n";
        return;
    }

    m_health -= damage;

    if (m_health < 0)
    {
        m_health = 0;
    }

    std::cout << m_name
              << " получил " << damage
              << " урона. Здоровье: " << m_health << '\n';
}

void Enemy::Describe() const
{
    std::cout << "Противник: " << m_name
              << " | Здоровье: " << m_health
              << " | Урон: " << m_damage << '\n';
}

bool Enemy::IsAlive() const
{
    return m_health > 0;
}
