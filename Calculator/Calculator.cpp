#include <iostream>

using namespace std;

int add(int a,int b) {
	return a+b;
}

int sub(int a,int b) {
	return a-b;
}

int multiply(int a,int b) {
	return a*b;
}

double divi(int a,double b) {
	if (b==0) {
		cout<<"Error! Division by zero.\n";
		return -1;
	}
	return a/b;
}


int main(){
	
	char choice;
	
	cout<<"Welcome to Python Calculator!";

    do {
        cout<<"\nChoose an operation:\n";
        cout<<"\t1. Add\n";
        cout<<"\t2. Subtract\n";
        cout<<"\t3. Multiply\n";
        cout<<"\t4. Divide\n";
        cout<<"\t5. Exit\n";

		cout<<"Enter choice (1/2/3/4/5): ";
        cin>>choice;

        if (choice == '5'){
            cout<<"Thank you for using the calculator. Goodbye!";
            break;
		}
		else if (choice == '1' || choice == '2' || choice == '3' || choice == '4') {
        double num1, num2;

        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Please enter a numeric value: ";
			cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Please enter a numeric value: ";
			cin.clear();
            cin.ignore(1000, '\n');
        }

			switch (choice) {
				case '1':
					cout << "Result: " << add(num1, num2) << endl;
					break;
				case '2':
					cout << "Result: " << sub(num1, num2) << endl;
					break;
				case '3':
					cout << "Result: " << multiply(num1, num2) << endl;
					break;
				case '4':
					if (divi(num1, num2)!=-1) {
						cout << "Result: " << divi(num1, num2) << endl;
						break;
					}
					break;
			}
		} else {
        cout << "Invalid choice. Please select a valid option." << endl;
		}
	}while (true);
}