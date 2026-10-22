#pragma once

#include "room.hpp"
#include <string>

class Level
{
private:
    std::string m_name;
    Room m_room; // Объект комнаты, который принадлежит уровню

public:
    Level(const std::string& name);
    ~Level();

    void Describe() const;
    Room& GetRoom();
};