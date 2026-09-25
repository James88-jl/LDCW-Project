#include <iostream>
#include <string>

using namespace std;

int main() {
	int location, surgeryType;

	cout << "=== Hospital Finder - Surgery Specialist Locator ===\n";
	cout << "=== Malaysia ===\n";
	cout << "\nSelect your location:\n";
	cout << "1. Kuala Lumpur & Selangor\n";
	cout << "2. Penang\n";
	cout << "3. Johor\n";
	cout << "4. Sabah\n";
	cout << "5. Sarawak\n";
	cout << "Enter your choice: ";
	cin >> location;

	if (location < 1 || location > 5) {
		cout << "Invalid location. Please choose 1-5.\n";
		return 0;
	}

	cout << "\nSelect surgery type needed:\n";
	cout << "1. Cardiac Surgery (Heart)\n";
	cout << "2. Neurosurgery (Brain & Spine)\n";
	cout << "3. Orthopedic Surgery (Bones & Joints)\n";
	cout << "4. General Surgery\n";
	cout << "5. Emergency Surgery\n";
	cout << "Enter your choice: ";
	cin >> surgeryType;

	if (surgeryType < 1 || surgeryType > 5) {
		cout << "Invalid surgery type. Please choose 1-5.\n";
		return 0;
	}

	cout << "\n=== RECOMMENDED HOSPITAL ===\n";

	switch (location) {
		case 1:
			cout << "Location: Kuala Lumpur & Selangor\n";
			if (surgeryType == 1)
				cout << "Hospital: Institut Jantung Negara (IJN)\nSpecialty: Advanced Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Kuala Lumpur\nSpecialty: Neurosurgery & Brain Surgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Hospital Sungai Buloh\nSpecialty: Orthopedic & Joint Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Selayang\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Sungai Buloh\nSpecialty: 24/7 Emergency & Trauma Surgery\n";
			break;

		case 2:
			cout << "Location: Penang\n";
			if (surgeryType == 1)
				cout << "Hospital: Penang Adventist Hospital\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Pulau Pinang\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Loh Guan Lye Specialists Centre\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Pulau Pinang\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Penang General Hospital\nSpecialty: Emergency Surgery\n";
			break;

		case 3:
			cout << "Location: Johor\n";
			if (surgeryType == 1)
				cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Heart Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: Brain & Spine Surgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Columbia Asia Hospital JB\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: 24/7 Emergency Care\n";
			break;

		case 4:
			cout << "Location: Sabah\n";
			if (surgeryType == 1)
				cout << "Hospital: Queen Elizabeth Hospital\nSpecialty: Cardiovascular Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Queen Elizabeth Hospital\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Gleneagles Kota Kinabalu\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Queen Elizabeth Hospital\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Queen Elizabeth Hospital\nSpecialty: Emergency & Trauma\n";
			break;

		case 5:
			cout << "Location: Sarawak\n";
			if (surgeryType == 1)
				cout << "Hospital: Sarawak Heart Centre\nSpecialty: Advanced Cardiac Care\n";
			else if (surgeryType == 2)
				cout << "Hospital: Sarawak General Hospital\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: Bone & Joint Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Sarawak General Hospital\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Sarawak General Hospital\nSpecialty: Trauma & Emergency Surgery\n";
			break;
	}

	return 0;
}