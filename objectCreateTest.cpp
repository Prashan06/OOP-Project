class MyClass {
public:
    MyClass(int value) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    for (int i = 0; i < 3; ++i) {
        MyClass obj(i);  // Object is created for each iteration
    }
    return 0;
}