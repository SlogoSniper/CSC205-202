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

int findArea(Rectangle rect){

    int height = rect.height - rect.corner.y;
    int width = rect.width - rect.corner.x;

    return height * width;
}

int main(){
    Point corner = {0.0, 0.0};
    Rectangle box = {corner, 100.0, 200.0};

    Point lRight = lowerRight(box);

    cout << findArea(box) << endl;

    return 0;
}