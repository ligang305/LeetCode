#include <iostream>
#include "vector"
#include "string"
#include "algorithm"

using namespace std;
class Person{
private:
    int age;
    string name;

public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    ~Person(){
//        cout << "object: " <<this->name << " is being deleted." <<endl;
    }
    void setAge(int age){
        this->age = age;
    }
    void setName(string name){
        this->name = name;
    }
    int getAge(){
        return this->age;
    }
    string getName(){
        return this->name;
    }

};

int main()
{
    Person p1("xiaowang", 18);
    Person p2("xiaohuang", 20);
    Person p3("xiaozhu", 2);
    Person p4("dingding", 50);

    vector<Person> people = {p1, p2, p3, p4};
    for (int i = 0; i < people.size(); ++i) {
        cout << people[i].getName() <<endl;
    }

    /*std::vector<std::string> strs = {"hello", "hell", "her"};
    std::vector<int> ints = {3, 6, 5, 8, 4};
    int s = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
    std::cout <<*iter <<std::endl;*/
    vector<Person>::iterator iterator = min_element(people.begin(), people.end(), [](Person& s, Person& t) {return s.getAge() > t.getAge();});
    cout <<iterator->getName() <<"------>" <<iterator->getAge();
    return 0;
}

