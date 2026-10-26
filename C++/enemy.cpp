#include "enemy.hpp"
#include <iostream>

Enemy::Enemy(const std::string& name, int health, int damage)
    : m_name(name), m_health(health), m_damage(damage)
{
    if (m_health <= 0) {
        std::cout << "[Ошибка] Здоровье не может быть <= 0.\n";
        m_health = 1;
    }
    if (m_damage < 0) {
        std::cout << "[Ошибка] Урон не может быть отрицательным.\n";
        m_damage = 0;
    }
    std::cout << "Создан враг: " << m_name << " (HP: " << m_health << ")\n";
}

Enemy::Enemy() : m_name("Безымянный"), m_health(1), m_damage(0)
{
    std::cout << "Создан враг (по умолчанию): " << m_name << "\n";
}

Enemy::~Enemy()
{
    std::cout << "Уничтожен враг: " << m_name << "\n";
}

void Enemy::TakeDamage(int damage)
{
    if (damage < 0) return;
    m_health -= damage;
    std::cout << m_name << " получил " << damage << " урона. Осталось HP: " << m_health << "\n";
    if (m_health <= 0) {
        std::cout << m_name << " повержен!\n";
    }
}

void Enemy::Describe() const
{
    std::cout << "Враг [" << m_name << "]: HP=" << m_health << ", Урон=" << m_damage << "\n";
}

bool Enemy::IsAlive() const
{
    return m_health > 0;
}