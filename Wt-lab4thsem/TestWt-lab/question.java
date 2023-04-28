

/*Define an abstract class Shape having abstract method displayShapeFeatures(). 
Further define two abstract classes TwoDShape and ThreeDShape, both extending the
abstract class Shape. TwoDShape has abstract methods perimeter() and area();
ThreeDShape has abstract methods surfaceArea() and volume(). Then, implement
four concrete classes Circle, Rectangle, Sphere and Box by extending suitable
abstract classes; define suitable parameterized constructors for each of the classes;
and implement suitable main() method that creates objects for each of the classes, finds
their perimeter and area or surfaceArea and volume, whichever is relevant. Finally, main() should display these values using a suitable method mentioned above through
the respective objects. (b) Write a java applet program */
abstract class Shape {
      abstract void displayShapeFeatures();
}

abstract class TwoDShape extends Shape{
    abstract void displayShapeFeatures();
    abstract void perimeter();
    abstract void area();
}

abstract class ThreeDShape extends Shape{
    abstract void displayShapeFeatures();
    abstract void surfaceArea();
    abstract void volume();
}

class Circle extends TwoDShape{

    int radius;
     Circle(int radius){
        this.radius = radius;
     }

    @Override
    void displayShapeFeatures() {
        // TODO Auto-generated method stub
        System.out.println("Radius of Circle: " + radius);
    }

    @Override
    void perimeter() {
        // TODO Auto-generated method stub
        System.out.println("Perimeter of circle: " + 2*3.14*radius);
    }

    @Override
    void area() {
        // TODO Auto-generated method stub
        System.out.println("Area of circle: " + 3.14*radius*radius);
    }
    
}

class Rectangle extends TwoDShape{

    int length;
    int breadth;

     Rectangle(int length, int breadth){
        this.length = length;
        this.breadth = breadth;
     }

    @Override
    void displayShapeFeatures() {
        // TODO Auto-generated method stub
        System.out.println("Length and breadth " + length + " "+ breadth);
    }

    @Override
    void perimeter() {
        // TODO Auto-generated method stub
        System.out.println("Perimeter of Rectangle: " + 2*(length + breadth));
    }

    @Override
    void area() {
        // TODO Auto-generated method stub
        System.out.println("Area of Rectangle: " + length*breadth);
    }
    
}
class Sphere extends ThreeDShape{

    int radius;
     Sphere(int radius){
        this.radius = radius;
     }

    @Override
    void displayShapeFeatures() {
        // TODO Auto-generated method stub
        System.out.println("Radius of Sphere: " + radius);
    }

    @Override
    void surfaceArea() {
        // TODO Auto-generated method stub
        System.out.println("Surface Area of Sphere: " + 4*3.14*radius*radius);
    }

    @Override
    void volume() {
        // TODO Auto-generated method stub
        System.out.println("Volume  of Sphere: " + (4/3)*radius*radius*radius);
    }
    
}

class Box extends ThreeDShape{

    int a;
     Box(int a){
        this.a = a;
     }

    @Override
    void displayShapeFeatures() {
        // TODO Auto-generated method stub
        System.out.println("Side of Box: " + a);
    }

    @Override
    void surfaceArea() {
        // TODO Auto-generated method stub
        System.out.println("Surface Area of Box: " + 6*a*a);
    }

    @Override
    void volume() {
        // TODO Auto-generated method stub
        System.out.println("Volume of Box: " + a*a*a);
    }
    
    public static void main(String[] args) {
        Circle c = new Circle(10);
        c.area();
        c.perimeter();
        c.displayShapeFeatures();

        Rectangle r = new Rectangle(15,14);
        r.area();
        r.perimeter();
        r.displayShapeFeatures();

        Sphere s = new Sphere(20);
        s.surfaceArea();
        s.volume();
        s.displayShapeFeatures();

        Box b = new Box(25);
        b.surfaceArea();
        b.volume();
        b.displayShapeFeatures();
    }
}