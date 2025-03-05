#include "Person.h"

// BEGIN 2b
Person::Person(std::string name,std::string email,std::unique_ptr<Car> car = nullptr){
    this->name = name;
    this->email = email;
    this->car = std::move(car);
}
std::string Person::getEmail() const{
    return this->email;
}
std::string Person::getName() const{
    return this->name;
}
Car* Person::getCar() const{
    return this->car.get();
}
void Person::setEmail(const std::string& email){
    this->email = email;
}
void Person::setName(const std::string& name){
    this->name = name;
}
void Person::setCar(std::unique_ptr<Car> & car){
    this->car = std::move(car);
}
// END 2b

// BEGIN 2c
bool Person::hasAvailableSeats() const{
    if (this->getCar()==nullptr){
        return false;
    }
    return this->getCar()->hasFreeSeats();
}
// END 2c

// BEGIN 2d
std::ostream& operator<<(std::ostream& os,const Person& p){
    os<<"Navn: "<<p.getName()<<std::endl;
    os<<"Email: "<<p.getEmail()<<std::endl;
    os<<"Has space: "<< (p.hasAvailableSeats() ? "true" :"false") <<std::endl;
    return os;
}
// END 2d


void testPerson(){
    Person p1{"håkon","hakmikalsen@yahoo.com"};
    std::cout<<p1<<std::endl;
    p1.setEmail("hakmikalsen@gmail.com");
    p1.setName("Håkon");
    std::cout<<p1<<std::endl;
    
    std::unique_ptr<Car> car = std::make_unique<Car>(2);
    p1.setCar(car);
    std::cout<<p1<<std::endl;
    p1.getCar()->reserveFreeSeat();
    p1.getCar()->reserveFreeSeat();
    std::cout<<p1<<std::endl;


}