#include<iostream>
using namespace std;

struct Point {
    double x, y;
};

struct Rectangle {
    Point corner;
    double width, height;
};


Point lowerRight(Rectangle rect){
    return {rect.corner.x + rect.width, rect.corner.y + rect.height};

}

int main(){
    Point corner = {0.0, 0.0};
    Rectangle box = {corner, 100.0, 200.0};

    cout << lowerRight(box).x << ", " << lowerRight(box).y << endl;
    return 0;
}
