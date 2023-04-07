

#include <iostream>
#include<cmath>

using namespace std;

class triangle {
private: 
    bool triang;

public:
     double a;
     double b;
     double c;
    triangle(double triangle_a, double triangle_b, double triangle_c) {
        setTriangle(triangle_a, triangle_b, triangle_c);
    }
    operator bool() const {
        return getTriangleTrue();
    }

   bool operator++ ()
    {
       if (getTriangleTrue()) {
           ++a;
           ++b;
           ++c;
           return true;
       }
       return false;
   }
   bool operator--() {
       if (a > 1 && b > 1 && c > 1) {
           --a;
           --b;
           --c;
           return true;
       }
       return false;
   }
   triangle operator*(int scalar) {
       return triangle(a * scalar, b * scalar, c * scalar);
   }

    void setTriangle(double triangle_a, double triangle_b, double triangle_c) {
        a = triangle_a;
        b = triangle_b;
        c = triangle_c;
    }
    void getTriangleSide() {
        cout << "A= " << a << " B= " << b << " C= " << c << endl;
    }
    void getTrianglePerimetr() {
        double perimetr = 0;
        perimetr = a + b + c;
        cout << "Периметр треугольника = " << perimetr << endl;
    }
    void getTriangleSquare() {
        double p, square;
        p = (a + b + c) / 2;
        square = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Площадь треугольника = " << square << endl;
    }
    bool getTriangleTrue() const {
        if ((a + b) - c > 0 || (b + c) - a > 0 || (a + c) - b > 0) {
            cout << "Треугольник с такими сторонами существует" << endl;
            return true;
        }
        else {
            cout << "Треугольник с такими сторонами не возможен" << endl;
            return false;
        }
    }
    void switchbyindex(int i) {
        switch (i) {
        case 0:
            cin >> a;
            break;
        case 1:
            cin >> b;
            break;
        case 2:
            cin >> c;
            break;
        default:
            cout << "Ошибочный запрос нет стороны с данным индексом";
        }
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
    triangle fo(12, 3, 11);
    fo.getTriangleSide();
    fo.getTrianglePerimetr();
    fo.getTriangleSquare();
    fo.getTriangleTrue();
    fo.switchbyindex(1);
    fo.getTriangleSide();
    ++fo;
    fo.getTriangleSide();
    if(--fo);
    fo.getTriangleSide();
    if (fo) {
        cout << "Треугольник ";
        fo.getTriangleSide();
        cout << endl << "существует";
    }
    else {
        cout << "Треугольник ";
        fo.getTriangleSide();
        cout << endl << "не существует";
    }
    triangle so = fo * 4;
    cout << "Треугольник до умножения";
    fo.getTriangleSide();
    cout << " Треугольник после усножения";
    so.getTriangleSide();

}

