import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        System.out.println("1. ССЫЛКИ И КОПИИ В ПАМЯТИ");
        Enemy originalGoblin = new Enemy("Гоблин", 30, 5);
        Enemy aliasGoblin = originalGoblin; 

        System.out.println("Наносим урон через aliasGoblin");
        aliasGoblin.takeDamage(10);

        System.out.println("originalGoblin изменился: " + originalGoblin);
        System.out.println("aliasGoblin: " + aliasGoblin);
        System.out.println("Указывают на один объект (==): " + (originalGoblin == aliasGoblin));

        System.out.println("2. СЦЕНАРИЙ: КОМПОЗИЦИЯ, АГРЕГАЦИЯ И ПРАВИЛО");
        Level level = new Level("Темница");
        level.placeEnemyInLevel(originalGoblin);
        level.describe();

        System.out.println("\n[Тест правила] Попытка атаковать нулевым уроном:");
        originalGoblin.takeDamage(0);
        level.explore();

        System.out.println("\nСостояние уровня после исследования:");
        System.out.println(level);

        System.out.println("3. ОСВОБОЖДЕНИЕ РЕСУРСА");
        try (DungeonLog log = new DungeonLog("Рейд-1")) {
            log.write("Игрок переступил порог темницы");
            log.write("Сработала ловушка, лог фиксирует событие");
        }

        System.out.println("4. РАБОТА СБОРЩИКА МУСОРА");
        WeakReference<Enemy> watcher = createGarbageEnemy();

        System.out.println("Объект в памяти до вызова сборщика: " + (watcher.get() != null));
        
        System.out.println("Запрос сборки мусора");
        System.gc();

        System.out.println("Объект в памяти после сборки мусора: " + (watcher.get() != null));

        System.out.println("5. ЗАВЕРШЕНИЕ РАБОТЫ");
    }

    private static WeakReference<Enemy> createGarbageEnemy() {
        Enemy tempEnemy = new Enemy("Временный фантом", 10, 1);
        return new WeakReference<>(tempEnemy);
    }
}