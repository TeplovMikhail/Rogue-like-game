public class Enemy {
    private String name;
    private int health;
    private int damage;

    public Enemy(String name, int health, int damage) {
        this.name = (name == null || name.isBlank()) ? "Безымянный" : name;
        
        if (health <= 0) {
            System.out.println("[Ошибка] Здоровье не может быть <= 0");
            this.health = 1;
        } 
        else {
            this.health = health;
        }

        if (damage < 0) {
            System.out.println("[Ошибка] Урон не может быть отрицательным");
            this.damage = 0;
        } 
        else {
            this.damage = damage;
        }

        System.out.println("Создан враг: " + this.name + " (HP: " + this.health + ")");
    }

    public Enemy() {
        this("Безымянный", 1, 0);
    }

    public void takeDamage(int damage) {
        if (damage < 0) {
            return;
        }
        this.health -= damage;
        System.out.println(this.name + " получил " + damage + " урона. Осталось HP: " + this.health);
        if (this.health <= 0) {
            System.out.println(this.name + " повержен");
        }
    }

    public boolean isAlive() {
        return this.health > 0;
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public int getDamage() {
        return damage;
    }

    @Override
    public String toString() {
        return "Враг [" + name + "]: HP=" + health + ", Урон=" + damage;
    }
}