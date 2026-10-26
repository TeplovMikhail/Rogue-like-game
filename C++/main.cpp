#include "enemy.hpp"
#include "level.hpp"
#include <iostream>
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    std::cout << "1. СТАТИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ\n";
    Enemy goblin("Гоблин", 30, 5); 

    std::cout << "\n2. ДИНАМИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ\n";
    Enemy* skeleton = new Enemy("Скелет", 50, 10);

    std::cout << "\n3. ДИНАМИЧЕСКИЙ МАССИВ ОБЪЕКТОВ\n";
    Enemy* slimes = new Enemy[2] { Enemy("Зеленый слайм", 10, 2), Enemy("Синий слайм", 15, 3) };

    std::cout << "\n4. МАССИВ ДИНАМИЧЕСКИХ ОБЪЕКТОВ\n";
    Enemy* entity[2];
    entity[0] = new Enemy("Дракон", 100, 20);
    entity[1] = new Enemy("Подрывник", 80, 15);

    std::cout << "\n5. РАБОТА СО ССЫЛКАМИ И УКАЗАТЕЛЯМИ\n";
    {
        Level level("Темница"); 
        
        Room& roomRef = level.GetRoom(); 
        roomRef.SetEnemy(&goblin); 
        level.Describe();
        
        Enemy* enemyPtr = &goblin; 
        std::cout << "Попытка атаки через указатель (урон " << enemyPtr->GetDamage() << "):\n";
        roomRef.AttackEnemy(enemyPtr->GetDamage());
        
        std::cout << "\n[Тест правила] Попытка атаковать нулевым уроном:\n";
        roomRef.AttackEnemy(0);

        level.Explore();

        std::cout << "\nОсвобождение динамической памяти\n";
        delete[] slimes;
        for (int i = 0; i < 2; ++i) delete entity[i];
        delete skeleton;

        std::cout << "\nВЫХОД ИЗ БЛОКА (Уничтожение Level и Room)\n";
    }

    std::cout << "\n6. ПРОВЕРКА ЖИЗНИ АГРЕГАЦИИ\n";
    std::cout << "Гоблин всё ещё жив после уничтожения уровня:\n";
    goblin.Describe();

    std::cout << "\n7. КОНЕЦ ПРОГРАММЫ.\n";
    return 0;
}