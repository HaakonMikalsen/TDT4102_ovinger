#include "MeetingWindow.h"
#include "Person.h"
#include "Car.h"
#include <iostream>
#include <string>
MeetingWindow::MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title):
	// BEGIN 4a
    AnimationWindow{position.x,position.y,width,height,title},
	// END 4a

	// BEGIN 4e
	quitBtn({400,400},btnW,btnH,"quit"),
	// END 4e
	
	// BEGIN 5a
	personName({100,100},fieldW,fieldH,""),
	personEmail({100,150},fieldW,fieldH,""),
	// END 5a
	
	// BEGIN 5b
	personSeats({100,200},fieldW,fieldH,""),
	personNewBtn({100,250},btnW,btnH,"add"),
	// END 5b

	dummyArgument{0}
{
	// Felles
	// BEGIN 4f
	add(quitBtn);
	// END 4f
	
	// BEGIN 4g
	quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
	// END 4g
	
	// BEGIN 5d
	personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));

	// END 5d

	// Ny person
	#ifndef FOUR_A
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	#endif

	#ifndef FOUR_B
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	#endif
}

// Callbackfunksjoner
// BEGIN 4d
void MeetingWindow::MeetingWindow::cb_quit(){
	this->close();
}
// END 4d

// BEGIN 5c
void MeetingWindow::MeetingWindow::newPerson(){
	std::cout<<"running"<<std::endl;
	const std::string name = this->personName.getText();
	const std::string email = this->personEmail.getText();
	const std::string seatsString = this->personSeats.getText();
	int seatsInt;
	try {
		seatsInt = std::stoi(seatsString);
		seatsInt--;
		if (seatsInt<0){
			throw std::runtime_error(
                "FOR lirte plass :(!");

		}
		if (name==""){
			throw std::runtime_error(
                "mangler tekts :(!");

		}
		if (email==""){
			throw std::runtime_error(
                "mangler tekts :(!");

		}
    }
    // catch block to catch the thrown exception
    catch (const std::exception& e) {
        // print the exception
        std::cout << "Exception " << e.what() << std::endl;
		return;
    }
	std::unique_ptr<Car> car = std::make_unique<Car>(seatsInt);
	people.emplace_back(new Person{name,email,std::move(car)});
	this->personName.setText("");
	this->personEmail.setText("");
	this->personSeats.setText("");
}
// END 5c

void MeetingWindow::attachPersonWidget(TDT4102::Widget& pw)
{
	add(pw);
	personWidgets.emplace_back(std::ref(pw));
}