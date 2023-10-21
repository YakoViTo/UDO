#include <iostream>
#include <string>
using namespace std;

string addMore(const string question) {
	if (question == "meals" || question == "drinks" || question == "funds")
		return "Add more " + question + " (Y/N)?";
	return "Add more (Y/N)?";
}

void getFundsBalance(const float& funds, const string message) {
	cout << message;
	printf("%.2f", funds);
	cout << endl;
	cin.clear();
}

int main() {
	
	//User Funds
	float funds = 0.0;

	//Constant strings to avoid some hardcoding
	const string MAIN_TITLE = string("========================================\n") +
							  "====== Welcome to the Dining Hall ======\n" +
							  "========================================";

	const string VOUCHER_TITLE = "Please choose your Dining Voucher:";
	const string BILLS_TITLE = "Please choose your coins/bills:";
	const string SELECTION_TITLE = "Please make a selection:";
	const string SELECT_BEVERAGES = "Select your beverages:";
	const string VOUCHER_CHOICE = "(1)$10, (2)$20, (3)$50, (4)$100: ";
	const string FOOD_CHOICE = "(P)otato Chip $2.50, (H)am Burger $5.50, (C)hicken Rice $5.50, (B)rooklyn Pizza $4.50";
	const string BEVERAGE_CHOICE = "(A)quaVeena $1.50, (B)epsi $2.00, (C)ool Cola $2.00, (G)atorade $2.25, (N)o Beverage";
	const string END_MSG_CHANGE = "Take your changes and enjoy your meals";
	const string END_MSG_NO_CHANGE = "Enjoy your meals";

	//Constant prices to avoid some hardcoding
	const float POTATO_PRICE = 2.5;
	const float HAMBURGER_PRICE = 5.5;
	const float CHICKEN_PRICE = 5.5;
	const float PIZZA_PRICE = 4.5;
	const float AQUA_PRICE = 1.5;
	const float BEBPSI_PRICE = 2.0;
	const float COLA_PRICE = 2.0;
	const float GATORADE_PRICE = 2.25;

	//Constant vouchers to avoid some hardcoding
	const float FIRST_VOUCHER = 10;
	const float SECOND_VOUCHER = 20;
	const float THIRD_VOUCHER = 50;
	const float FOURTH_VOUCHER = 100;

	//Constant bills/coins to avoid some hardcoding
	const float FIRST_BILL = 10;
	const float SECOND_BILL = 20;
	const float THIRD_BILL = 50;
	const float FOURTH_BILL = 100;

	//Lowest priced product. This is to determine when the user has insufficient funds to buy any item.
	const float BEVERAGE_LOWEST_PRICE = 1.5;
	const float FOOD_LOWEST_PRICE = 2.5;

	//Main flow
	cout << MAIN_TITLE << endl;

	try {

		char option = 0;

		//Choose your voucher
		cout << VOUCHER_TITLE << endl;
		cout << VOUCHER_CHOICE;

		//Get input. Clear the input stream and break the loop if it's a valid option.
		while (cin >> option) {
			switch (option) {
			case '1':
				funds = FIRST_VOUCHER;
				break;
			case '2':
				funds = SECOND_VOUCHER;
				break;
			case '3':
				funds = THIRD_VOUCHER;
				break;
			case '4':
				funds = FOURTH_VOUCHER;
				break;
			default:
				break;
			}
			
			if (funds != 0) {
				getFundsBalance(funds, "You've inserted: $");
				break;
			}	
		}

		/*//Verify to add more funds
		bool addMoreFunds = false;

		//Add more funds question
		cout << addMore("funds") << endl;
		while (cin >> option) {
			if (tolower(option) == 'y') {
				cin.clear();
				addMoreFunds = true;
				break;
			}
			if (tolower(option) == 'n') {
				cin.clear();
				break;
			}
				
		}*/

		//Add more funds question
		cout << addMore("funds") << endl;
		while (cin >> option) {
			if (tolower(option) == 'y' || tolower(option) == 'n') {
				cin.clear();
				break;
			}
		}

		//Add more funds
		if (tolower(option) == 'y') {
			do {
				cout << BILLS_TITLE << endl;

				//Get input. Clear the input stream and break the loop if it's a valid option.
				while (cin >> option) {
					float oldFunds = funds;

					switch (option) {
					case '1':
						funds += FIRST_BILL;
						break;
					case '2':
						funds += SECOND_BILL;
						break;
					case '3':
						funds += THIRD_BILL;
						break;
					case '4':
						funds += FOURTH_BILL;
						break;
					default:
						break;
					}

					if (oldFunds != funds) {
						getFundsBalance(funds, "You've inserted: $");
						break;
					}
				}

				//Add more funds question
				cout << addMore("funds") << endl;
				while (cin >> option)
					if (tolower(option) == 'y' || tolower(option) == 'n') {
						cin.clear();
						break;
					}	

			} while (tolower(option) == 'y');
		}
		
		//Choose your meal
		do {
			cout << SELECTION_TITLE << endl;
			cout << FOOD_CHOICE << endl;

			while (cin >> option) {
				float oldFunds = funds;
				switch (tolower(option)) {
				case 'p':
					funds -= POTATO_PRICE;
					break;
				case 'h':
					funds -= HAMBURGER_PRICE;
					break;
				case 'c':
					funds -= CHICKEN_PRICE;
					break;
				case 'b':
					funds -= PIZZA_PRICE;
					break;
				default:
					break;
				}

				if (funds < 0) {
					cout << "Insufficient funds. Select another meal." << endl;
					funds = oldFunds;
				}
				else
					if (oldFunds != funds) {
						getFundsBalance(funds, "Coins/bills: $");
						break;
					}
			}

			//If funds are lower than the cheapest food item, break.
			if (funds < FOOD_LOWEST_PRICE)
				break;

			//Add more meals question
			cout << addMore("meals") << endl;
			while (cin >> option)
				if (tolower(option) == 'y' || tolower(option) == 'n') {
					cin.clear();
					break;
				}
		} while (tolower(option) == 'y');

		//Ask if the remaining funds are enough to buy the cheapest beverage
		if (funds >= BEVERAGE_LOWEST_PRICE) {
			//Choose your beverage
			do {
				cout << SELECT_BEVERAGES << endl;
				cout << BEVERAGE_CHOICE << endl;

				while (cin >> option) {
					
					//If no beverage is selected, then break the loop
					if (tolower(option) == 'n')
						break;

					float oldFunds = funds;

					switch (tolower(option)) {
					case 'a':
						funds -= AQUA_PRICE;
						break;
					case 'b':
						funds -= BEBPSI_PRICE;
						break;
					case 'c':
						funds -= COLA_PRICE;
						break;
					case 'g':
						funds -= GATORADE_PRICE;
						break;
					default:
						break;
					}

					if (funds < 0) {
						cout << "Insufficient funds. Select another meal." << endl;
						funds = oldFunds;
					}
					else
						if (oldFunds != funds) {
							getFundsBalance(funds, "Coins/bills: $");
							break;
						}
				}

				//If funds are lower than the cheapest beverage item or
				//the user doesn't want any beverage, break.
				if (funds < BEVERAGE_LOWEST_PRICE || tolower(option) == 'n')
					break;

				//Add more meals question
				cout << addMore("drinks") << endl;
				while (cin >> option)
					if (tolower(option) == 'y' || tolower(option) == 'n') {
						cin.clear();
						break;
					}
			} while (tolower(option) == 'y');
		}
			
		//End messages. If there are funds remaining, display total change.
		if (funds == 0)
			cout << END_MSG_NO_CHANGE << endl;
		else {
			getFundsBalance(funds, "Your change: $");
			cout << END_MSG_CHANGE << endl;
		}
		//Keep window open
		cin.clear();
		cin.ignore();
		cin.get();
		return 0;
	}
	//Exception handling
	catch (const exception& e) {
		cerr << e.what() << endl;
		//Keep window open
		cin.clear();
		cin.ignore();
		cin.get();
		return 1;
	}
	//Unknown exception. 
	catch (...) {
		cerr << "Unknown error" << endl;
		//Keep window open
		cin.clear();
		cin.ignore();
		cin.get();
		return 2;
	}
}