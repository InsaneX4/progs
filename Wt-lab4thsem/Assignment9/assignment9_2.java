
abstract class Shape{
    
    abstract void rectangle( int length, int breadth);
    abstract void squareArea(int side);
    abstract void circleArea(int radius);
}

class Area extends Shape{

    public static void main(String[] args) {
        Area one = new Area();
        one.circleArea(5);
        one.rectangle(30, 20);
        one.squareArea(55);
        
    }

    @Override
    void rectangle(int length, int breadth) {
        // TODO Auto-generated method stub
        System.out.println("Area of the Rectangle: "+length*breadth);
        
    }

    @Override
    void squareArea(int side) {
        // TODO Auto-generated method stub
        System.out.println("Area of the Sqaure: "+side*side);
        
    }

    @Override
    void circleArea(int radius) {
        // TODO Auto-generated method stub
        System.out.println("Area of the CircleArea: "+Math.PI*radius*radius);
        
    }}