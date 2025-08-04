#include <iostream>
#include <cmath>

class Sphere {
public:
    Sphere() { radius_ = 1; }
    Sphere(const int& radius) : radius_(radius) {}

    virtual int getRadius() const { return radius_; }
private:
    int radius_;
};

class Cube {
public:
    Cube() = delete;
    Cube(const int& sideLenght) : sideLenght_(sideLenght) {}

    int getSideLenght() const { return sideLenght_; }
private:
    int sideLenght_;
};

class RoundHole {
public:
    RoundHole() = delete;
    RoundHole(const int& radius) : radius_(radius) {}

    int getRadius() const { return radius_; }
    bool fits(Sphere* sphere) const {
        if (this->radius_ >= sphere->getRadius()) {
            return true;
        }
        return false;
    }
private:
    int radius_;
};

class CubeToSphereAdapter : public Sphere {
public:
    CubeToSphereAdapter() = delete;
    CubeToSphereAdapter(const Cube& cube) : cube_(cube) {}
    
    int getRadius() const override { return cube_.getSideLenght() * std::sqrt(2) / 2; }
private:
    Cube cube_;
};

int main() {
    RoundHole hole = RoundHole(10);
    std::clog << "Log: Made round hole with radius of 10.\n";

    Sphere* sphere = new Sphere(4);
    std::clog << "Log: Made pointer to sphere with radius 4.\n";

    std::cout << std::boolalpha;
    std::cout << "Sphere fit in the hole: " << hole.fits(sphere) << ".\n";
    
    Cube cube = Cube(5);
    std::clog << "Log: Made cube object with sides of lenght 5.\n";

    CubeToSphereAdapter* cts = new CubeToSphereAdapter(cube);
    std::clog << "Log: Made adapter to check if the cube fits in the hole.\n";

    std::cout << "Cube fit in the hole: " << hole.fits(cts) << ".\n";


    return 0;
}