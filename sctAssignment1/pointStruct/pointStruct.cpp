#include <iostream>
#include <cmath>
#include <string>

struct point{
    float x;
    float y;
    float z;
};

typedef struct point Point;

float zero_distance(const Point& my_point){
    return sqrt(my_point.x * my_point.x + my_point.y * my_point.y + my_point.z * my_point.z);
}

float distance(const Point& point1, const Point& point2){
    return sqrt(pow(point1.x - point2.x,2) + pow(point1.y - point2.y,2)+ pow(point1.z - point2.z,2));
}

Point compare(const Point& point1, const Point& point2){
    if(zero_distance(point1) > zero_distance(point2)) return point1;
    else return point2;
}

int region(const Point& my_point){
    int region = 0;
    if(my_point.x > 0){
        if(my_point.y > 0) region = 1;
        if(my_point.y < 0) region = 4; 
    }
    if(my_point.x < 0){
        if(my_point.y > 0) region = 2;
        if(my_point.y < 0) region = 3; 
    }
    if(my_point.z == 0) return 0;
    if(my_point.z < 0) return region + 4;
    return region;
}

bool is_in_same_region(const Point& point1, const Point& point2){
    if(point1.x * point2.x <= 0) return false;
    else if(point1.y * point2.y <= 0) return false;
    else if(point1.z * point2.z <= 0) return false;
    else return true;
}


int main(){
    // Test cases
    Point p1 = {2.0, 3.0, 4.0};
    Point p2 = {-2.0, -3.0, -4.0};
    Point p3 = {1.0, 1.0, 1.0};
    
    // Test zero_distance()
    std::cout << "Distance to origin for p1: " << zero_distance(p1) << std::endl;  // Should be 5.38516
    std::cout << "Distance to origin for p2: " << zero_distance(p2) << std::endl;  // Should be 5.38516
    std::cout << "Distance to origin for p3: " << zero_distance(p3) << std::endl;  // Should be 1.73205

    // Test distance()
    std::cout << "Distance between p1 and p2: " << distance(p1, p2) << std::endl;  // Should be 10.77032

    // Test compare()
    Point farthest = compare(p1, p2);
    std::cout << "The point farthest from the origin is: (" << farthest.x << ", " << farthest.y << ", " << farthest.z << ")" << std::endl;  // Should be p2

    // Test region()
    std::cout << "Region of p1: " << region(p1) << std::endl;  // Should be 1
    std::cout << "Region of p2: " << region(p2) << std::endl;  // Should be 7
    std::cout << "Region of p3: " << region(p3) << std::endl;  // Should be 1

    // Test is_in_same_region()
    std::string result = is_in_same_region(p1, p2) ? "True" : "False";
    std::cout << "Are p1 and p2 in the same region? " <<  result << std::endl;  // Should be false
    result = is_in_same_region(p1, p3) ? "True" : "False";
    std::cout << "Are p1 and p3 in the same region? " << result << std::endl;  // Should be true
    result = is_in_same_region(p2, p3) ? "True" : "False";
    std::cout << "Are p2 and p3 in the same region? " << result << std::endl;  // Should be false

    return 0;
}