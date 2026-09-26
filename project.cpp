/*
 * Program: Hospital Finder - Surgery Specialist Locator
 * Purpose: Helps users find suitable hospitals for major surgeries based on their location
 * Technology Context: Healthcare Digital Innovation System (Connected to Part 1 analysis)
 * Features: 
 *   - Covers all 13 Malaysian states/regions
 *   - Recommends hospitals by surgery specialization
 *   - Uses real Malaysian hospital names
 *   - Includes contact phone numbers for all hospitals
 * Date: 2026
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Variable declarations
	int location, surgeryType;
	char searchAgain;
	
	// Main program loop - allows multiple searches
	do {
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
			continue;
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
			continue;
		}

		// Section 3: Display recommended hospital based on location and surgery type
		cout << "\n=== RECOMMENDED HOSPITAL ===\n";

		// Process recommendation using switch-case for different locations
		switch (location) {
			// Case 1: Kuala Lumpur & Selangor Region
			case 1:
				cout << "Location: Kuala Lumpur & Selangor\n";
				if (surgeryType == 1)
					cout << "Hospital: Institut Jantung Negara (IJN)\nSpecialty: Advanced Cardiac Surgery\nArea: Jalan Tun Razak, KL City Centre\nContact: +603-2617 8200\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Kuala Lumpur (HKL)\nSpecialty: Neurosurgery & Brain Surgery\nArea: Jalan Pahang, Central KL\nContact: +603-2615 5555\n";
				else if (surgeryType == 3)
					cout << "Hospital: University of Malaya Medical Centre (UMMC)\nSpecialty: Orthopedic & Joint Surgery\nArea: Lembah Pantai, Near Universiti Malaya\nContact: +603-7949 2052\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Selayang\nSpecialty: General Surgery\nArea: Selayang, North of KL\nContact: +603-6126 3333\n";
				else
					cout << "Hospital: Hospital Sungai Buloh\nSpecialty: 24/7 Emergency & Trauma Surgery\nArea: Sungai Buloh, Near KLIA Highway\nContact: +603-6145 5555\n";
				break;

			// Case 2: Penang Region
			case 2:
				cout << "Location: Penang\n";
				if (surgeryType == 1)
					cout << "Hospital: Penang Adventist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Burma, Georgetown\nContact: +604-222 7200\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Pulau Pinang\nSpecialty: Neurosurgery\nArea: Jalan Residensi, Georgetown\nContact: +604-222 5333\n";
				else if (surgeryType == 3)
					cout << "Hospital: Loh Guan Lye Specialists Centre\nSpecialty: Orthopedic Surgery\nArea: Jalan Logan, Georgetown\nContact: +604-238 8888\n";
				else if (surgeryType == 4)
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: General Surgery\nArea: Jalan Pangkor, Penang Island\nContact: +604-222 9111\n";
				else
					cout << "Hospital: Island Hospital Penang\nSpecialty: Emergency Surgery\nArea: Jalan Macalister, Central Georgetown\nContact: +604-228 8222\n";
				break;

			// Case 3: Johor Region
			case 3:
				cout << "Location: Johor\n";
				if (surgeryType == 1)
					cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Heart Surgery\nArea: Jalan Abdul Samad, Johor Bahru\nContact: +607-225 3000\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Sultanah Aminah (HSA)\nSpecialty: Brain & Spine Surgery\nArea: Jalan Abu Bakar, JB City Centre\nContact: +607-225 7000\n";
				else if (surgeryType == 3)
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Orthopedic Surgery\nArea: Medini Iskandar, Near Legoland\nContact: +607-560 1000\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: General Surgery\nArea: Jalan Abu Bakar, JB City Centre\nContact: +607-225 7000\n";
				else
					cout << "Hospital: Pantai Hospital Johor\nSpecialty: 24/7 Emergency Care\nArea: Batu Pahat Town\nContact: +607-433 8811\n";
				break;

			// Case 4: Perak Region
			case 4:
				cout << "Location: Perak\n";
				if (surgeryType == 1)
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Cardiovascular Surgery\nArea: Jalan Tambun, Ipoh Town\nContact: +605-540 5555\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Ipoh City Centre\nContact: +605-208 5000\n";
				else if (surgeryType == 3)
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Orthopedic Surgery\nArea: Jalan Tambun, Ipoh Town\nContact: +605-540 5555\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: General Surgery\nArea: Jalan Hospital, Ipoh City Centre\nContact: +605-208 5000\n";
				else
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Emergency & Trauma\nArea: Jalan Hospital, Ipoh City Centre\nContact: +605-208 5000\n";
				break;

			// Case 5: Melaka Region
			case 5:
				cout << "Location: Melaka\n";
				if (surgeryType == 1)
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Cardiac Surgery\nArea: Jalan Merdeka, Melaka Town Centre\nContact: +606-285 2999\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Melaka\nSpecialty: Neurosurgery\nArea: Jalan Mufti Haji Khalil, City Centre\nContact: +606-289 2345\n";
				else if (surgeryType == 3)
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Orthopedic Surgery\nArea: Jalan Merdeka, Melaka Town Centre\nContact: +606-285 2999\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Melaka\nSpecialty: General Surgery\nArea: Jalan Mufti Haji Khalil, City Centre\nContact: +606-289 2345\n";
				else
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Emergency Care\nArea: Jalan Merdeka, Melaka Town Centre\nContact: +606-285 2999\n";
				break;

			// Case 6: Negeri Sembilan Region
			case 6:
				cout << "Location: Negeri Sembilan\n";
				if (surgeryType == 1)
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: Cardiac Surgery\nArea: Jalan Penghulu Cantik, Seremban 2\nContact: +606-603 3988\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Tuanku Ja'afar Seremban\nSpecialty: Neurosurgery\nArea: Jalan Rasah, Seremban Town\nContact: +606-768 4000\n";
				else if (surgeryType == 3)
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Toman, Seremban Centre\nContact: +606-768 6000\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: General Surgery\nArea: Jalan Rasah, Seremban Town\nContact: +606-768 4000\n";
				else
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: Emergency Surgery\nArea: Jalan Rasah, Seremban Town\nContact: +606-768 4000\n";
				break;

			// Case 7: Pahang Region
			case 7:
				cout << "Location: Pahang\n";
				if (surgeryType == 1)
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Tanjung Lumpur, Kuantan\nContact: +609-511 2692\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Neurosurgery\nArea: Jalan Tanah Putih, Kuantan Town\nContact: +609-513 3333\n";
				else if (surgeryType == 3)
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Tanjung Lumpur, Kuantan\nContact: +609-511 2692\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: General Surgery\nArea: Jalan Tanah Putih, Kuantan Town\nContact: +609-513 3333\n";
				else
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Emergency & Trauma\nArea: Jalan Tanah Putih, Kuantan Town\nContact: +609-513 3333\n";
				break;

			// Case 8: Kedah Region
			case 8:
				cout << "Location: Kedah\n";
				if (surgeryType == 1)
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Cardiac Surgery\nArea: Bandar Baru Mergong, Alor Setar\nContact: +604-740 6100\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Neurosurgery\nArea: Km6 Jalan Langgar, Alor Setar\nContact: +604-740 6233\n";
				else if (surgeryType == 3)
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Orthopedic Surgery\nArea: Bandar Baru Mergong, Alor Setar\nContact: +604-740 6100\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: General Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nContact: +604-740 6233\n";
				else
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Emergency Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nContact: +604-740 6233\n";
				break;

			// Case 9: Kelantan Region
			case 9:
				cout << "Location: Kelantan\n";
				if (surgeryType == 1)
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Cardiac Surgery\nArea: Kubang Kerian, Near USM Campus\nContact: +609-767 3000\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Kota Bharu Centre\nContact: +609-745 2000\n";
				else if (surgeryType == 3)
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Orthopedic Surgery\nArea: Kubang Kerian, Near USM Campus\nContact: +609-767 3000\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: General Surgery\nArea: Jalan Hospital, Kota Bharu Centre\nContact: +609-745 2000\n";
				else
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Emergency & Trauma\nArea: Jalan Hospital, Kota Bharu Centre\nContact: +609-745 2000\n";
				break;

			// Case 10: Terengganu Region
			case 10:
				cout << "Location: Terengganu\n";
				if (surgeryType == 1)
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Air Jernih, KT Town Centre\nContact: +609-624 3333\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Neurosurgery\nArea: Jalan Sultan Mahmud, KT City\nContact: +609-621 2121\n";
				else if (surgeryType == 3)
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Air Jernih, KT Town Centre\nContact: +609-624 3333\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: General Surgery\nArea: Jalan Sultan Mahmud, KT City\nContact: +609-621 2121\n";
				else
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Emergency Surgery\nArea: Jalan Sultan Mahmud, KT City\nContact: +609-621 2121\n";
				break;

			// Case 11: Perlis Region
			case 11:
				cout << "Location: Perlis\n";
				if (surgeryType == 1)
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Cardiac Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nContact: +604-973 8333\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Neurosurgery\nArea: Jalan Tun Abd Razak, Kangar Town\nContact: +604-973 8333\n";
				else if (surgeryType == 3)
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Orthopedic Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nContact: +604-973 8333\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: General Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nContact: +604-973 8333\n";
				else
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Emergency Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nContact: +604-973 8333\n";
				break;

			// Case 12: Sabah Region
			case 12:
				cout << "Location: Sabah\n";
				if (surgeryType == 1)
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Cardiovascular Surgery\nArea: Riverson, Near Imago Mall\nContact: +6088-518 888\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Neurosurgery\nArea: Jalan Penampang, KK City Centre\nContact: +6088-517 555\n";
				else if (surgeryType == 3)
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Orthopedic Surgery\nArea: Riverson, Near Imago Mall\nContact: +6088-518 888\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: General Surgery\nArea: Jalan Penampang, KK City Centre\nContact: +6088-517 555\n";
				else
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Emergency & Trauma\nArea: Jalan Penampang, KK City Centre\nContact: +6088-517 555\n";
				break;

			// Case 13: Sarawak Region
			case 13:
				cout << "Location: Sarawak\n";
				if (surgeryType == 1)
					cout << "Hospital: Sarawak Heart Centre\nSpecialty: Advanced Cardiac Care\nArea: Kota Samarahan, Near UNIMAS\nContact: +6082-833 333\n";
				else if (surgeryType == 2)
					cout << "Hospital: Hospital Umum Sarawak\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Kuching City Centre\nContact: +6082-276 666\n";
				else if (surgeryType == 3)
					cout << "Hospital: Borneo Medical Centre\nSpecialty: Bone & Joint Surgery\nArea: Jalan Tun Ahmad Zaidi, Kuching\nContact: +6082-507 333\n";
				else if (surgeryType == 4)
					cout << "Hospital: Hospital Umum Sarawak\nSpecialty: General Surgery\nArea: Jalan Hospital, Kuching City Centre\nContact: +6082-276 666\n";
				else
					cout << "Hospital: KPJ Kuching Specialist Hospital\nSpecialty: Trauma & Emergency Surgery\nArea: Jalan Tun Jugah, Kuching Town\nContact: +6082-365 777\n";
				break;
		}

		// Ask user if they want to search again
		cout << "\n========================================\n";
		cout << "Would you like to search for another hospital? (Y/N): ";
		cin >> searchAgain;
		cout << "\n";
		
	} while (searchAgain == 'Y' || searchAgain == 'y');
	
	// Thank you message
	cout << "Thank you for using Hospital Finder!\n";
	cout << "Stay healthy and take care!\n";

	// Program end
	return 0;
}
