#include <iostream>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0, double z = 0) : x_(x), y_(y), z_(z) {}

    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

    Point operator-(const Point& other) const {
        return Point(x_ - other.x_, y_ - other.y_, z_ - other.z_);
    }

    bool operator==(const Point& other) const {
        return (x_ == other.x_ && y_ == other.y_ && z_ == other.z_);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other); 
    }

    Point& operator++() {
        x_ += 1.0;
        y_ += 1.0;
        z_ += 1.0;
        return *this;  
    }

    Point operator++(int) {
        Point temp = *this; 
        ++(*this);       
        return temp;      
    }

    void print() const {
        cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << endl;
    }

private:
    double x_;
    double y_;
    double z_; 
};

int main() {
    Point p1(1, 2, 3);
    Point p2(4, 5, 6);
    Point p3(1, 2, 3);

    cout << "p1: ";
    p1.print();
    cout << "p2: ";
    p2.print();

    Point diff = p2 - p1;
    cout << "p2 - p1: ";
    diff.print();

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 == p3: " << (p1 == p3) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;

    cout << "++p1: ";
    (++p1).print();

    cout << "p2++: ";
    (p2++).print();
    cout << "p2 после p2++: ";
    p2.print(); 

}