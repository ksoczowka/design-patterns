#pragma once

#include <string>

class Interface {
 public:
    Interface() {}
    std::string methodA(std::string data) {
        return data;
    }
};

class Service {
 public:
    Service() {}
    int methodB(int data) {
        return data;
    }
};

class InterfaceToServiceAdapter : public Interface, public Service {
 public:
    InterfaceToServiceAdapter() {}
    
    std::string adapter(int data) {
       return methodA(std::to_string(data)); 
    }
};