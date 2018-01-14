#include <iostream>
#include <unistd.h>

using namespace std;


class Time{
   public:
   Time(int h, int m);
   int gethours() const;
   int getminutes() const;
   void addminute();
   void subtractminute();
   bool operator==(Time t);
   void operator++(); //prefix
   void operator++(int); //postfix
   void operator--(); //prefix
   void operator--(int); //postfix
   private:
   int hours;
   int minutes;
};
 
Time::Time(int h, int m){ 
	hours=h;
	minutes=m;
}

int Time::gethours() const{ 
	return hours;
}


int Time::getminutes() const{ 
	return minutes;
}

bool Time::operator==(Time t){
  if (this->gethours() != t.gethours()) 
  	return false;
  if (this->getminutes() != t.getminutes()) 
  	return false;
  return true;
}

void Time::operator++(){
  this -> addminute();
}

void Time::operator++(int){
	this -> addminute();
}
void Time::operator--(){
  this -> subtractminute();
}

void Time::operator--(int){
	this -> subtractminute();
}


void Time::addminute() { 
	minutes++;
	if (minutes == 60 )
	{
		minutes=0;
		hours++;
	}

	if (hours == 13)
		hours=1;
}

void Time::subtractminute(){ 
	if(minutes == 0){
		minutes = 59;
		if(hours == 1)
			hours = 12;
		else
			hours--;
	}
	else 
		minutes--;
		
}

void subtract_test(){ //tests decrement and subtract_minute functions for Time class
	Time a = Time(1, 0);
	Time b = Time(12, 59);
	Time c = Time(12, 58);
	Time d = Time(12, 57);
	--a;
	if(a == b){
		a--; 
		if(a == c){
			a.subtractminute();
			if(a == d)
				cout << "Subtract test passed." << endl;
		}
	}
}
int main()
{
	subtract_test();
	Time start=Time(12,0);
	Time end=Time(1,15);
	for (int i=0; i<75; i++){
	//	sleep(60); //sleep 60 seconds
		++start; //add a minute to start
}
	if (start == end) cout << "class dismissed";
}
