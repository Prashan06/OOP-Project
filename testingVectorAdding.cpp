#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
    int index; // New attribute to store the index

    Person() : name("Unknown"), age(0), index(-1) {}
    Person(const string& n, int a, int i) : name(n), age(a), index(i) {}

    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Index: " << index << endl;
    }
};

class Group {
private:
    vector<Person> people;

public:
    void addPerson() {
        Person personWithIndex = newPerson;
        personWithIndex.index = people.size(); // Set the index
        people.push_back(personWithIndex);
    }

    void displayGroup() const {
        for (const auto& person : people) {
            person.display();
        }
    }
};

int main() {
    Group myGroup;

    // Add Person objects to the group
    myGroup.addPerson();
    myGroup.addPerson();

    // Display the group
    myGroup.displayGroup();

    return 0;
}


