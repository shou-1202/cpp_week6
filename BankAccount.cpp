#include <iostream>
#include <String>
using namespace std;
class BankAccount{// a class is a user defined data type which works as a blue print for an object
	private:
	double balance;
	double draw;
	string accountNumber, accountHolderName;
	
	public:
	BankAccount(string accnum, string name, double accbal){
		accountNumber = accnum;
		accountHolderName = name;
		balance = accbal;
	}
	void deposit(int deposit){
		balance+=deposit;
	}
	void deposit(double deposit){
        balance += deposit;
	}		
	void withdraw(double with1){
		draw = with1;
		if(draw<balance){
			balance -= draw;
		}
		else{
			cout<<"withdrawn amount is more than balance";
		}
	}
	void withdraw(int with1){
		draw = with1;
		if(draw<balance){
			balance -= draw;
		}
		else{
			cout<<"withdrawn amount is more than balance";
		}
	}
	void displayinfo(){
		cout<<"\nAccount Number: "<<accountNumber;
		cout<<"\nAccount Holder Name: "<<accountHolderName;
		cout<<"\nBalance: "<<balance;
	}
	bool operator >(const BankAccount &other){
		return balance>other.balance;
	}
	bool operator <(const BankAccount &other){
		return balance<other.balance;
	}
		
};
int main(){// demonstrating how the object can used of this class
	BankAccount customer1("CBIN1234","shourya",5000.0);
	customer1.deposit(500);
	customer1.deposit(1000.0);
	customer1.withdraw(1500);
	customer1.withdraw(500.0);
	customer1.displayinfo();
	BankAccount customer2("CBIN1235", "RIYA", 6000.0);
	customer2.withdraw(2000);
	customer2.displayinfo();
	if(customer1>customer2){
		cout<<"\nAccount 1 has higher balance than account 2";
	}
	else{
		cout<<"\nAccount 2 has higher balance than account 1";
	}
}