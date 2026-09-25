/*
 * Program: Hospital Finder - Surgery Specialist Locator
 * Purpose: Helps users find suitable hospitals for major surgeries based on their location
 * Technology Context: Healthcare Digital Innovation System (Connected to Part 1 analysis)
 * Features: 
 *   - Covers all 13 Malaysian states/regions
 *   - Recommends hospitals by surgery specialization
 *   - Uses real Malaysian hospital names
 * Date: 2026
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Variable declarations
	int location, surgeryType;

	// Display program header
	cout << "=== Hospital Finder - Surgery Specialist Locator ===\n";
	cout << "=== Malaysia ===\n";
	
	// Section 1: Get user's location (state/region)
	cout << "\nSelect your state/region:\n";
	cout << "1. Kuala Lumpur & Selangor\n";
	cout << "2. Penang\n";
	cout << "3. Johor\n";
	cout << "4. Perak\n";
	cout << "5. Melaka\n";
	cout << "6. Negeri Sembilan\n";
	cout << "7. Pahang\n";
	cout << "8. Kedah\n";
	cout << "9. Kelantan\n";
	cout << "10. Terengganu\n";
	cout << "11. Perlis\n";
	cout << "12. Sabah\n";
	cout << "13. Sarawak\n";
	cout << "Enter your choice: ";
	cin >> location;

	// Validate location input
	if (location < 1 || location > 13) {
		cout << "Invalid location. Please choose 1-13.\n";
		return 0;
	}

	// Section 2: Get surgery type needed
	cout << "\nSelect surgery type needed:\n";
	cout << "1. Cardiac Surgery (Heart)\n";
	cout << "2. Neurosurgery (Brain & Spine)\n";
	cout << "3. Orthopedic Surgery (Bones & Joints)\n";
	cout << "4. General Surgery\n";
	cout << "5. Emergency Surgery\n";
	cout << "Enter your choice: ";
	cin >> surgeryType;

	// Validate surgery type input
	if (surgeryType < 1 || surgeryType > 5) {
		cout << "Invalid surgery type. Please choose 1-5.\n";
		return 0;
	}

	// Section 3: Display recommended hospital based on location and surgery type
	cout << "\n=== RECOMMENDED HOSPITAL ===\n";

	// Process recommendation using switch-case for different locations
	switch (location) {
		// Case 1: Kuala Lumpur & Selangor Region
		case 1:
			cout << "Location: Kuala Lumpur & Selangor\n";
			if (surgeryType == 1)
				cout << "Hospital: Institut Jantung Negara (IJN)\nSpecialty: Advanced Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Kuala Lumpur (HKL)\nSpecialty: Neurosurgery & Brain Surgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: University of Malaya Medical Centre (UMMC)\nSpecialty: Orthopedic & Joint Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Selayang\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Sungai Buloh\nSpecialty: 24/7 Emergency & Trauma Surgery\n";
			break;

		// Case 2: Penang Region
		// Case 2: Penang Region
		case 2:
			cout << "Location: Penang\n";
			if (surgeryType == 1)
				cout << "Hospital: Penang Adventist Hospital\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Pulau Pinang\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Loh Guan Lye Specialists Centre\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Island Hospital Penang\nSpecialty: Emergency Surgery\n";
			break;

		// Case 3: Johor Region
		// Case 3: Johor Region
		case 3:
			cout << "Location: Johor\n";
			if (surgeryType == 1)
				cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Heart Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Sultanah Aminah (HSA)\nSpecialty: Brain & Spine Surgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Pantai Hospital Johor\nSpecialty: 24/7 Emergency Care\n";
			break;

		// Case 4: Perak Region
		// Case 4: Perak Region
		case 4:
			cout << "Location: Perak\n";
			if (surgeryType == 1)
				cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Cardiovascular Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Emergency & Trauma\n";
			break;

		// Case 5: Melaka Region
		case 5:
			cout << "Location: Melaka\n";
			if (surgeryType == 1)
				cout << "Hospital: Mahkota Medical Centre\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Melaka\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Mahkota Medical Centre\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Melaka\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Mahkota Medical Centre\nSpecialty: Emergency Care\n";
			break;

		// Case 6: Negeri Sembilan Region
		case 6:
			cout << "Location: Negeri Sembilan\n";
			if (surgeryType == 1)
				cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Tuanku Ja'afar Seremban\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: Emergency Surgery\n";
			break;

		// Case 7: Pahang Region
		// Case 7: Pahang Region
		case 7:
			cout << "Location: Pahang\n";
			if (surgeryType == 1)
				cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Emergency & Trauma\n";
			break;

		// Case 8: Kedah Region
		case 8:
			cout << "Location: Kedah\n";
			if (surgeryType == 1)
				cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Emergency Surgery\n";
			break;

		// Case 9: Kelantan Region
		// Case 9: Kelantan Region
		case 9:
			cout << "Location: Kelantan\n";
			if (surgeryType == 1)
				cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Emergency & Trauma\n";
			break;

		// Case 10: Terengganu Region
		case 10:
			cout << "Location: Terengganu\n";
			if (surgeryType == 1)
				cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Emergency Surgery\n";
			break;

		// Case 11: Perlis Region
		case 11:
			cout << "Location: Perlis\n";
			if (surgeryType == 1)
				cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Cardiac Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Emergency Surgery\n";
			break;

		// Case 12: Sabah Region
		case 12:
			cout << "Location: Sabah\n";
			if (surgeryType == 1)
				cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Cardiovascular Surgery\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Orthopedic Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Emergency & Trauma\n";
			break;

		// Case 13: Sarawak Region
		// Case 13: Sarawak Region
		case 13:
			cout << "Location: Sarawak\n";
			if (surgeryType == 1)
				cout << "Hospital: Sarawak Heart Centre\nSpecialty: Advanced Cardiac Care\n";
			else if (surgeryType == 2)
				cout << "Hospital: Hospital Umum Sarawak\nSpecialty: Neurosurgery\n";
			else if (surgeryType == 3)
				cout << "Hospital: Borneo Medical Centre\nSpecialty: Bone & Joint Surgery\n";
			else if (surgeryType == 4)
				cout << "Hospital: Hospital Umum Sarawak\nSpecialty: General Surgery\n";
			else
				cout << "Hospital: KPJ Kuching Specialist Hospital\nSpecialty: Trauma & Emergency Surgery\n";
			break;
	}

	// Program end
	return 0;
}