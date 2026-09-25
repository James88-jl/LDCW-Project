#include <iostream>
#include <string>

using namespace std;

int main() {
	int genre;

	cout << "=== Simple Netflix Movie Finder ===\n";
	cout << "Choose a genre:\n";
	cout << "1. Action\n";
	cout << "2. Comedy\n";
	cout << "3. Science Fiction\n";
	cout << "Enter your choice: ";
	cin >> genre;

	switch (genre) {
		case 1:
			cout << "Recommended movie: Extraction\n";
			break;
		case 2:
			cout << "Recommended movie: The Intern\n";
			break;
		case 3:
			cout << "Recommended movie: The Adam Project\n";
			break;
		default:
			cout << "Invalid choice. Please choose 1, 2, or 3.\n";
	}

	return 0;
}