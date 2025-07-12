#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int number);
void display_prime_in_range (int range_start,int range_end);

int main() {
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check if a number is prime\n";
        cout << "2. Display prime numbers in a range\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            int num;
			while(true){
				cout << "Enter a number: ";
				cin >> num;
	
				if (cin.fail()) {
					cout << "Invalid input! Please enter a number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
	
				if (isprime(num))
					cout << num << " is a prime number.\n";
				else
					cout << num << " is not a prime number.\n";
				break;
			}

        } else if (choice == 2) {
			while(true){
				int a, b;
				cout << "Enter the start of the range: ";
				cin >> a;
				cout << "Enter the end of the range: ";
				cin >> b;
	
				if (cin.fail()) {
					cout << "Invalid input! Please enter numbers.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
	
				display_prime_in_range(a, b);
				break;
			}

        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}

bool isprime(int number){
	
	int limit = sqrt(number);
	
	if(number<2)
		return false;
	
	for(int i=2;i<=limit;i++){
		if (number%i==0)
			return false;
	}
	return true;
}

void display_prime_in_range(int range_start, int range_end) {
    int prime_count = 0;
	
	if (range_start > range_end) swap(range_start, range_end);

    cout << "Prime numbers between " << range_start << " and " << range_end << ":\n";

    for (int i = range_start; i <= range_end; i++) {
        if (isprime(i)) {
            cout << i << " ";
            prime_count++;
        }
    }

    if (prime_count == 0) {
        cout << "No prime numbers found in this range.\n";
    } else {
        cout << "\nTotal prime numbers found: " << prime_count << "\n";
    }
}