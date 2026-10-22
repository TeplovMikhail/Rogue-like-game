#include "enemy.hpp"
#include "level.hpp"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Enemy skeleton("Скелет", 30, 10);

    {
        Level level("Подземелье");
        level.GetRoom().SetEnemy(&skeleton);

        level.Describe();
        level.GetRoom().AttackEnemy(10);
    }

    skeleton.Describe();

    return 0;
}
