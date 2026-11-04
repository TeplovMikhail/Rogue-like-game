public class DungeonLog implements AutoCloseable {
    private final String sessionName;

    public DungeonLog(String sessionName) {
        this.sessionName = sessionName;
        System.out.println("[+] Журнал подземелья открыт: " + this.sessionName);
    }

    public void write(String entry) {
        System.out.println("    [Журнал] " + entry);
    }

    @Override
    public void close() {
        System.out.println("[-] Журнал подземелья закрыт: " + this.sessionName);
    }
}