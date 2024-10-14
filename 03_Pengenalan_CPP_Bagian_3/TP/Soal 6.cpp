#include <iostream>
#include <cmath> 
using namespace std;

class Kerucut {
private:
    
    double radius;   
    double tinggi;   

public:
    Kerucut(double r, double t) {
        radius = r;
        tinggi = t;
    }

    double hitungVolume() {
        return (1.0 / 3.0) * M_PI * radius * radius * tinggi;
    }

    double hitungLuasPermukaan() {
        double s = sqrt((radius * radius) + (tinggi * tinggi)); 
        return M_PI * radius * (radius + s);
    }

    double getRadius() {
        return radius;
    }

    double getTinggi() {
        return tinggi;
    }

    void setRadius(double r) {
        radius = r;
    }

    void setTinggi(double t) {
        tinggi = t;
    }
};

int main() {
    Kerucut kerucut1(5, 9);

    cout << "Volume kerucut: " << kerucut1.hitungVolume() << endl;
    cout << "Luas permukaan kerucut: " << kerucut1.hitungLuasPermukaan() << endl;

    return 0;
}