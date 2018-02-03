#include "Event.h"
Event::Event(){
	//This should never be called. This is here to applease the compiler.
}
Event::Event(std::string input_name, std::string input_date, std::string input_creator, int input_id_number){
	date = boost::gregorian::from_string(input_date);
	
	//We cannot schedule on these days
	if(date.month() == 12 && date.day() == 25){
		//Christmas
		throw "holiday";
	}else if(date.month() == 1 && date.day() == 1){
		//New Years
		throw "holiday";
	}else if(date.month() == 7 && date.day() == 4){
		//July
		throw "holiday";
	}
	
	name = input_name;
	creator = input_creator;
	id_number = input_id_number;
}
Event::~Event(){
	if(record != nullptr){
		delete record;
	}
}
std::string Event::get_date(){
	return date.to_simple_string();
}
std::string Event::get_name(){
	return name;
}
std::string Event::get_creator(){
	return creator;
}
int Event::get_id_number(){
	return id_number;
}
bool Event::create_time(std::string hhu){
}
bool Event::remove_time(std::string hhu){
}
bool Event::add_user_to_time(std::string hour_and_increment, User u){
}
bool Event::remove_user_from_time(std::string hour_and_increment, User u){
}
