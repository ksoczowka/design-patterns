#pragma once

#include <memory>
#include <string>
#include <vector>

class Product {
 public:
    virtual std::string info() = 0;
    std::string to_string() {
        std::string result = "";
        for (auto part : parts) {
            result += part;
        }
        return result;
    }
    std::vector<char> parts;
};

class ProductA : public Product {
 public:
    std::string info() override {
        return "Upper case letters";
    }
};

class ProductB : public Product {
 public:
    std::string info() override {
        return "Lower case letters";
    }
};


class Builder {
 public:
    virtual void reset() = 0;
    virtual void addA() = 0;
    virtual void addB() = 0;
    virtual void addC() = 0;

    virtual std::shared_ptr<Product> getProduct() = 0;
};

class NewBuilderA : public Builder {
 public:
    NewBuilderA() {}
    void addA() override {
        product_.parts.push_back('A');
    }
    void addB() override {
        product_.parts.push_back('B');
    }
    void addC() override {
        product_.parts.push_back('C');
    }

    std::shared_ptr<Product> getProduct() override { return std::make_shared<ProductA>(product_); }

    void reset() override {
        product_ = ProductA();
    }
 private:
    ProductA product_{};
};

class NewBuilderB : public Builder {
 public:
    NewBuilderB() {}
    void addA() override {
        product_.parts.push_back('a');
    }
    void addB() override {
        product_.parts.push_back('b');
    }
    void addC() override {
        product_.parts.push_back('c');
    }

    std::shared_ptr<Product> getProduct() override { return std::make_shared<ProductB>(product_); }

    void reset() override {
        product_ = ProductB();
    }
 private:
    ProductB product_{};
};

class Director {
 public:
    Director(){
        builder_ = nullptr;
    }

    void changeBuilder(const char& version) {
        if (version == 'A') {
            builder_ = std::make_shared<NewBuilderA>(NewBuilderA());
        } else if (version == 'B') {
            builder_ = std::make_shared<NewBuilderB>(NewBuilderB());
        } else {
            builder_ = nullptr;
        }
    }
    std::shared_ptr<Product> make() {
        if(builder_ != nullptr) {
            builder_->reset();
            builder_->addA();
            builder_->addB();
            builder_->addC();
            return builder_->getProduct();
        }
        return nullptr;
    }
 private:
    std::shared_ptr<Builder> builder_;
};