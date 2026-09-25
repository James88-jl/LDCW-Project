#include <iostream>
#include <string>

using namespace std;

int main() {
	int location;

	cout << "=== Hospital Finder - Surgery Specialist Locator ===\n";
	cout << "Select your location:\n";
	cout << "1. North Region\n";
	cout << "2. South Region\n";
	cout << "3. East Region\n";
	cout << "4. West Region\n";
	cout << "5. Central Region\n";
	cout << "Enter your choice: ";
	cin >> location;

	switch (location) {
		case 1:
			cout << "Recommended hospital: Northern Medical Center\n";
			break;
		case 2:
			cout << "Recommended hospital: Southern General Hospital\n";
			break;
		case 3:
			cout << "Recommended hospital: Eastern Specialist Hospital\n";
			break;
		case 4:
			cout << "Recommended hospital: Western Regional Hospital\n";
			break;
		case 5:
			cout << "Recommended hospital: Central City Hospital\n";
			break;
		default:
			cout << "Invalid choice. Please choose 1-5.\n";
	}

	return 0;
}