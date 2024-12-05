#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person {
    // count is how many 'persons' exist at the time
    static int count;
    string name;
    int age;
    int id; // id number / university number / a unique number
public:
    Person();
    Person(const string& name);
    Person(const string& name, int age);
    Person(const string& name, int age, int id);
    virtual ~Person();

    void setName(const string& name);
    void setAge(int age);
    void setId(int id);
    string getName() const;
    int getAge() const;
    int getId() const;
    int getCount() const;

    friend istream& operator>>(istream& is, Person& person);
    friend ostream& operator<<(ostream& os, const Person& person);
};

#endif