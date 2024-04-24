
class Point {
    int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    Point () {
        this(0, 0);
    }

    Point (int y) {
        this(0, y);
    }

    public void print() {
        System.out.println("x: " + x + " y: " + y);
    }

    public static void main(String[] args) {
        Point p = new Point();
        p.print();
    }
}

