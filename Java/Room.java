public class Room {
    private Enemy enemy;

    public Room() {
        this.enemy = null;
        System.out.println("Создана комната");
    }

    public void setEnemy(Enemy enemy) {
        this.enemy = enemy;
        if (this.enemy != null) {
            System.out.println("Противник помещён в комнату");
        }
    }

    public void describe() {
        System.out.print("Осмотр комнаты: ");
        if (enemy == null) {
            System.out.println("Комната пуста");
            return;
        }
        System.out.println("В комнате находится враг");
        System.out.println(enemy);
    }

    public void attackEnemy(int damage) {
        if (damage <= 0) {
            System.out.println("[Ошибка] Невозможно атаковать уроном <= 0");
            return;
        }

        if (enemy == null) {
            System.out.println("В комнате нет противника");
            return;
        }

        if (!enemy.isAlive()) {
            System.out.println("Нельзя атаковать мертвого врага");
            return;
        }

        enemy.takeDamage(damage);
    }

    @Override
    public String toString() {
        return "Комната {содержит: " + (enemy != null ? enemy.toString() : "пусто") + "}";
    }
}