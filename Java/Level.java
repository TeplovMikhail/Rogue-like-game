public class Level {
    private String name;
    private final Room room;

    public Level(String name) {
        if (name == null || name.isBlank()) {
            System.out.println("[Ошибка] Название уровня не может быть пустым. Установлено 'Безымянный уровень'");
            this.name = "Безымянный уровень";
        } else {
            this.name = name;
        }
        this.room = new Room();
        System.out.println("Создан уровень: " + this.name);
    }

    public void placeEnemyInLevel(Enemy enemy) {
        this.room.setEnemy(enemy);
    }

    public void describe() {
        System.out.println("Уровень [" + name + "]");
        room.describe();
    }

    public void explore() {
        System.out.println("Игрок исследует уровень " + name + "...");
        room.attackEnemy(15);
    }

    @Override
    public String toString() {
        return "Уровень [" + name + "] -> " + room;
    }
}