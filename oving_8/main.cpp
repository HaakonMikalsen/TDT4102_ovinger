#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <iostream>
#include "Car.h"

using std::cout;
using std::endl;


int main()
{
	// Her kan du teste koden din
	// Car c{2};
	// cout<<c.hasFreeSeats()<<endl;
	// c.reserveFreeSeat();
	// cout<<c.hasFreeSeats()<<endl;
	// c.reserveFreeSeat();
	// cout<<c.hasFreeSeats()<<endl;
	testPerson();
	// testMeeting();
	TDT4102::Point point{100,100};
	MeetingWindow meetingWindow{point,500,500,"Dette er en test"};
	meetingWindow.wait_for_close();
	return 0;
}
