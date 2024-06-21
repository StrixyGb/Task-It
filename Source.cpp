

#include <iostream>
#include <string>
#include <vector>
using  namespace  std;

class BancAccount {
protected:
	int balance = 0;
	string owner;
	int id;

public:
	void topup(int sum) {
		cout << "Succesfully top upped!\n";
		balance += sum;
	}
	void withdraw(int sum) {
		if (sum <= balance) {
			cout << "Succesfully withdrawed!\n";
			balance -= sum;
		}
		else {
			cerr << "Influenced funds!";
		}
	}
	int getbalance() {
		return balance;
	}

};
void printmenu() {
	cout << "\n  MENU  \n"
		"1)Top up   2)Withdraw\n\n";
}
 void main ( ) {
	BancAccount acc;
	int sum;
	int choice;
	do {
		cout << acc.getbalance() << "$" << "\n";
		printmenu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter ammount to top-up: ";
			cin >> sum;
			acc.topup(sum);
			break;
		case 2:
			cout << "Enter the ammount to withdraw: ";
			cin >> sum;
			acc.withdraw(sum);

			break;
		}
	} while (choice != 0);

}