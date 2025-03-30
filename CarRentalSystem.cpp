#include <iostream>//CarRentalSystem
#include <string>
using namespace std;
class Car{ //a class is a user defined data type which works as a blue print for an object
	private:
	string brand;
    string model;
	double pricePerDay;
    string	status;
    int days;
    double totalPrice;	
	double discountPercentage;
	
	public:
	
	Car(){
		brand = "Toyota";
		model = "A123";
		pricePerDay = 2500.0;
		status = "available";
		totalPrice = 0.0;
	}
	Car(const Car &car){
		brand = car.brand;
		model = car.model;
		pricePerDay = car.pricePerDay;
		status = car.status;
		totalPrice = car.totalPrice;
	}
	void BookCar(int numberOfDays){
		days = numberOfDays;
		totalPrice = pricePerDay*numberOfDays;
	}
	void BookCar(double discount){
		discountPercentage = discount;
		totalPrice = pricePerDay*(1-(discount/100));
	}
	void BookCar(){
		double insurance = 2500.0;
		totalPrice = pricePerDay+insurance;
	}
	double totalprice(){
		return totalPrice;
	}
	int operator +(const Car &other){
		return totalPrice+other.totalPrice;
	}
	bool operator >(const Car &other){
		return totalPrice>other.totalPrice;
	}
	void displaycarinfo(){
		cout<<"\nCar Model: "<<model;
		cout<<"\nCar Brand: "<<brand;
		cout<<"\nPrice per day: "<<pricePerDay;
		cout<<"\nCar status: "<<status;
		cout<<"\nTotal price: "<<totalPrice;
	}
};

int main(){// demonstrating how the object can used of this class
	Car c1;
	c1.BookCar();
	c1.displaycarinfo();
	Car c2(c1);
	c2.BookCar();
	c2.BookCar(2);
	c2.displaycarinfo();
	double result = c1+c2;
	cout<<"\nTotal rental price of 2 cars: "<<result;
	if(c1 > c2){
		cout<<"\ncar 1 is more expensive than car 2";
	}
	else{
		cout<<"\ncar 2 is more expensive than car 1";
	}
}