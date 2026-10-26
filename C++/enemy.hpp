#pragma once
#include <string>

class Enemy
{
private:
    std::string m_name;
    int m_health;
    int m_damage;

public:
    Enemy(const std::string& name, int health, int damage);
    Enemy();
    ~Enemy();

    void TakeDamage(int damage);
    void Describe() const;
    bool IsAlive() const;
    
    int GetHealth() const { return m_health; }
    int GetDamage() const { return m_damage; }
};