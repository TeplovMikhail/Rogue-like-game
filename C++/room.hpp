#pragma once
#include "enemy.hpp"
#include <memory>

class Room
{
private:
    std::weak_ptr<Enemy> m_enemy;

public:
    Room();
    ~Room();

    void SetEnemy(const std::shared_ptr<Enemy>& enemy);
    void Describe() const;
    void AttackEnemy(int damage);
};