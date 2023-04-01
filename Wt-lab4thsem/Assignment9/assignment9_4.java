
interface Motor{
    int capacity = 200;
    void run();
    void consume();
}

class WashingMachine implements Motor{

    public static void main(String[] args) {
        WashingMachine m = new WashingMachine();
        m.run();
        m.consume();
    }
    @Override
    public void run() {
        System.out.println("Running.........");
    }

    @Override
    public void consume() {
        System.out.println("Cosuming: "+capacity+"Kg");
    }

}
