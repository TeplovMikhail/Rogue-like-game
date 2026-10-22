
#pragma once

#include "enemy.hpp"

class Room
{
private:
    Enemy* m_enemy;

public:
    Room();
    ~Room();

    void SetEnemy(Enemy* enemy);
    void Describe() const;
    void AttackEnemy(int damage);
};
