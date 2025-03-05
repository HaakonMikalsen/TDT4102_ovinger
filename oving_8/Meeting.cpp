#include "Meeting.h"
#include "Person.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// BEGIN 3b
std::ostream& operator<<(std::ostream& os, Campus campus) {
    os << campusToString.at(campus) << std::endl;
    return os;
}
// END 3b

// BEGIN 3e
void Meeting::addParticipant(std::shared_ptr<Person> participant) {
    this->participants.push_back(participant);
}
// END 3e

// BEGIN 3f
Meeting::Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, const std::shared_ptr<Person> leader):leader(leader) {
    this->day=day;
    this->startTime=startTime;
    this->endTime=endTime;
    this->location=location;
    this->subject=subject;
    this->participants.push_back(leader);
}
// END 3f

// BEGIN 3h
std::vector<std::string> Meeting::getParticipantList() const {
    std::vector<std::string> partiList{};
    for (std::shared_ptr p : this->getParticipants()) {
        partiList.push_back(p.get()->getName());
    }
    return partiList;
}
// END 3h

// BEGIN 3i
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting& M) {
    std::vector<std::shared_ptr<Person>> matchList{};
    if (this->location != M.getLocation()) {
        return matchList;
    }
    if (this->day != M.getDay()) {
        return matchList;
    }
    if (abs(this->startTime - M.getStartTime()) > 1) {
        return matchList;
    }
    if (abs(this->endTime - M.getEndTime()) > 1) {
        return matchList;
    }

    for (std::shared_ptr p : M.getParticipants()) {
        if (p.get()->hasAvailableSeats()) {
            matchList.push_back(p);
        }
    }
    return matchList;
}
// END 3i

// BEGIN 3j

std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
    os << "Subject: " << meeting.getSubject() << std::endl;
    os << "StartTime: " << meeting.getStartTime() << std::endl;
    os << "EndTime: " << meeting.getEndTime() << std::endl;
    os << "Location: " << meeting.getLocation() << std::endl;
    os << "Leader: " << meeting.getLeader()->getName() << std::endl;
    os << "Participants: " << std::endl;

    for (const std::string& p : meeting.getParticipantList()) {
        os << "- " << p << std::endl;
    }

    return os;
}

// END 3j

void testMeeting() {
    Campus loc = Campus::trh;
    std::cout << loc;
    loc = Campus::aal;
    std::cout << loc;
    loc = Campus::gjo;
    std::cout << loc;
    std::cout << std::endl
              << "----------"
              << std::endl;
    //chat kode fordi denne er helt forferdelig å teste
    std::unique_ptr<Car> leaderCar = std::make_unique<Car>(2);
    std::shared_ptr<Person> leader = std::make_shared<Person>("Alice", "alice@example.com", std::move(leaderCar));

    // Create a meeting
    Meeting meeting1(1, 10, 12, Campus::trh, "C++ Lecture", leader);
    
    // Create participants
    std::shared_ptr<Person> participant1 = std::make_shared<Person>("Bob", "bob@example.com", nullptr);
    std::shared_ptr<Person> participant2 = std::make_shared<Person>("Charlie", "charlie@example.com", nullptr);

    
    meeting1.addParticipant(participant1);
    meeting1.addParticipant(participant2);

    // Print meeting details
    std::cout << "Meeting Details:" << std::endl;
    std::cout << meeting1 << std::endl;
    
    // Check participant list
    std::vector<std::string> participantList = meeting1.getParticipantList();
    std::cout << "Participants List:" << std::endl;
    for (const std::string& name : participantList) {
        std::cout << "- " << name << std::endl;
    }
    
    // Create another meeting at the same location and overlapping time
    std::shared_ptr<Person> leader2 = std::make_shared<Person>("Dave", "dave@example.com", std::make_unique<Car>(1));
    Meeting meeting2(1, 11, 13, Campus::trh, "Algorithms Workshop", leader2);
    
    std::shared_ptr<Person> participant3 = std::make_shared<Person>("Eve", "eve@example.com", std::make_unique<Car>(1));
    meeting2.addParticipant(participant3);
    
    // Check for potential co-driving partners
    std::vector<std::shared_ptr<Person>> potentialDrivers = meeting1.findPotentialCoDriving(meeting2);
    std::cout << "Potential Co-Driving Participants:" << std::endl;
    for (const auto& person : potentialDrivers) {
        std::cout << "- " << person->getName() << std::endl;
    }
}