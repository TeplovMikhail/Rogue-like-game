#include "enemy.hpp"
#include "level.hpp"
#include <iostream>
#include <memory>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "1. ДЕМОНСТРАЦИЯ std::unique_ptr\n";
    {
        std::unique_ptr<Enemy> skeleton = std::make_unique<Enemy>("Скелет", 50, 10);
        skeleton->Describe();

        std::cout << "\nПередача владения через std::move:\n";
        std::unique_ptr<Enemy> movedSkeleton = std::move(skeleton);

        if (!skeleton) {
            std::cout << "Исходный указатель skeleton теперь пуст (nullptr)\n";
        }
        if (movedSkeleton) {
            std::cout << "Владение перешло к movedSkeleton: ";
            movedSkeleton->Describe();
        }

        std::cout << "\nВыход из блока unique_ptr:\n";
    }

    std::cout << "2. МАССИВЫ std::unique_ptr\n";
    {

        std::cout << "Динамический массив Enemy[]\n";
        auto slimes = std::make_unique<Enemy[]>(2);
        slimes[0] = Enemy("Зеленый слайм", 10, 2);
        slimes[1] = Enemy("Синий слайм", 15, 3);

        std::cout << "Массив умных указателей unique_ptr<Enemy>[2]\n";
        std::unique_ptr<Enemy> entity[2];
        entity[0] = std::make_unique<Enemy>("Дракон", 100, 20);
        entity[1] = std::make_unique<Enemy>("Подрывник", 80, 15);

        std::cout << "\nВыход из блока массивов:\n";
    }

    std::cout << "3. ДЕМОНСТРАЦИЯ std::shared_ptr и use_count()\n";
    std::shared_ptr<Enemy> goblin = std::make_shared<Enemy>("Гоблин", 30, 5);
    std::cout << "Владельцев goblin: " << goblin.use_count() << "\n";

    {
        std::cout << "Создаем второго владельца (копирование shared_ptr)\n";
        std::shared_ptr<Enemy> goblinCopy = goblin;
        std::cout << "Владельцев внутри блока: " << goblin.use_count() << "\n";
        std::cout << "Уничтожаем локальную копию (выход из блока)\n";
    }
    std::cout << "Владельцев после выхода из блока: " << goblin.use_count() << "\n";

    std::cout << "4. ДЕМОНСТРАЦИЯ std::weak_ptr и lock()\n";
    {
        Level level("Темница");
        Room& roomRef = level.GetRoom();

        roomRef.SetEnemy(goblin);
        std::cout << "Владельцев гоблина: " << goblin.use_count() << "\n";

        level.Describe();

        std::cout << "\nАтака врага через комнату:\n";
        roomRef.AttackEnemy(goblin->GetDamage());

        std::cout << "\n[Тест правила] Попытка атаковать нулевым уроном:\n";
        roomRef.AttackEnemy(0);

        level.Explore();

        std::cout << "\nУничтожение уровня и комнаты\n";
    }

    std::cout << "\nПроверка состояния гоблина после гибели комнаты:\n";
    goblin->Describe();

    std::cout << "\nПроверка weak_ptr при уничтоженном объекте\n";
    {
        Room localRoom;
        {
            auto tempBoss = std::make_shared<Enemy>("Временный Босс", 40, 15);
            localRoom.SetEnemy(tempBoss);
            std::cout << "Босс жив, проверяем комнату:\n";
            localRoom.Describe();
            std::cout << "Уничтожаем единственного владельца tempBoss\n";
        }

        std::cout << "Попытка осмотреть комнату и атаковать после уничтожения босса:\n";
        localRoom.Describe();
        localRoom.AttackEnemy(10);
    }

    std::cout << "5. ЗАВЕРШЕНИЕ РАБОТЫ ПРОГРАММЫ (Уничтожение goblin)\n";
    return 0;
}