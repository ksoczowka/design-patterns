#pragma once

#include <memory>
#include <string>

class Implementation {
 public:
    Implementation() {}

    std::string getVersion() const { 
        return "Implementation()"; 
    }
};

class NewImplementationA : public Implementation {
 public:
    std::string getVersion() const {
        return "NewImplementationA()";
    }
};

class NewImplementationB : public Implementation {
 public:
    std::string getVersion() const {
        return "NewImplementationB()";
    }
};

class Abstraction {
 public:
    Abstraction() {
        implementation_ = nullptr;
    }
    Abstraction(std::shared_ptr<Implementation> Implementation) : implementation_(Implementation) {}
    std::string info() const {
        return "Abstraction()";
    }
    void setImplementation(std::shared_ptr<Implementation> other) {
        implementation_ = other;
    }

 protected:
    std::shared_ptr<Implementation> implementation_;
};

class NewAbstractionA : public Abstraction {
 public:
    std::string info() const {
        return "NewAbstractionA()";
    }
    std::string getImplementationVersionn() {
        return implementation_->getVersion();
    }
};

class NewAbstractionB : public Abstraction {
 public:
    std::string info() const {
        return "NewAbstractionB()";
    }
    std::string getImplementationVersionn() {
        return implementation_->getVersion();
    }
};