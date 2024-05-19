#pragma once

#include <memory>

enum class CarSize {
    SMALL = 0,
    MEDIUM = 1,
    BIG = 2
};

class Car {
 public:
    virtual int getNumberOfWheels() const = 0;
    virtual float getEngine() const = 0;
    virtual CarSize getSize() const = 0;
};

class SportCar : public Car {
 public:
    SportCar() {}
    
    int getNumberOfWheels() const override;
    float getEngine() const override;
    CarSize getSize() const override;
};

class TruckCar : public Car {
    TruckCar() {}

    int getNumberOfWheels() const override;
    float getEngine() const override;
    CarSize getSize() const override;
};

class CityCar : public Car {
    CityCar() {}

    int getNumberOfWheels() const override;
    float getEngine() const override;
    CarSize getSize() const override;
};

class Factory {
 public:
    virtual std::shared_ptr<Car> makeCar() const = 0;
};