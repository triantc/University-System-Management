#include "person.h"
#include <iomanip>

Person::Person() : name(""), age(0), id(0) {
    count++;
}

Person::Person(const string& name): name(name), age(0), id(0) {
    count++;
}

Person::Person(const string& name, int age): name(name), age(age), id(0) {
    count++;
}

Person::Person(const string& name, int age, int id): name(name), age(age), id(id) {
    count++;
}

Person::~Person() {
    count--;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setId(int id) {
    this->id = id;
}

string Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}

int Person::getId() const{
    return id;
}

int Person::getCount() const{
    return count;
}

istream& operator>>(istream& is, Person& person) {
    string name;
    int age;
    int id;
    cout << "Enter name: ";
    getline(is, name); // Can also read names with space inbetween
    person.setName(name);
    cout << "Enter age: ";
    is >> age;
    person.setAge(age);
    cout << "Enter id: ";
    is >> id;
    person.setId(id);
    return is;
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << setw(20) << left << person.getName()
       << " Age: " << setw(5) << left << person.getAge()
       << " Id: " << person.getId() << endl;
    return os;
}
