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
#include <algorithm>

using namespace std;

int main() {
	// Variable declarations
	int location, surgeryType;
	char searchAgain, mapChoice, locationChoice;
	string mapURL, userInput;
	bool autoDetected = false;
	
	// Main program loop - allows multiple searches
	do {
		// Display program header
		cout << "=== Hospital Finder - Surgery Specialist Locator ===\n";
		cout << "=== Malaysia ===\n";
		
		// Section 1: Auto-detect location or manual selection
		// Keep asking until valid input (A or B) is entered
		bool validChoice = false;
		while (!validChoice) {
			cout << "\nHow would you like to find hospitals?\n";
			cout << "A. Auto-detect my location (enter postcode/city)\n";
			cout << "B. Manually select my state\n";
			cout << "Enter your choice (A/B): ";
			cin >> locationChoice;
			
			// Validate input
			if (locationChoice == 'A' || locationChoice == 'a' || 
			    locationChoice == 'B' || locationChoice == 'b') {
				validChoice = true;
			} else {
				cout << "Invalid choice. Please enter A or B.\n\n";
			}
		}
		
		if (locationChoice == 'A' || locationChoice == 'a') {
			// Auto-detect based on postcode or city name
			cout << "\nEnter your postcode or city name: ";
			cin.ignore(); // Clear input buffer
			getline(cin, userInput);
			
			// Convert input to uppercase for comparison
			transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
			
			// Postcode/City mapping to states
			autoDetected = true;
			
			// Kuala Lumpur & Selangor postcodes: 40000-63000, 68000
			if (userInput.find("KL") != string::npos || userInput.find("KUALA LUMPUR") != string::npos ||
			    userInput.find("SELANGOR") != string::npos || userInput.find("SHAH ALAM") != string::npos ||
			    userInput.find("PETALING JAYA") != string::npos || userInput.find("SUBANG") != string::npos ||
			    userInput.find("KLANG") != string::npos || userInput.find("AMPANG") != string::npos ||
			    (userInput.length() == 5 && userInput[0] >= '4' && userInput[0] <= '6')) {
				location = 1;
				cout << "Area detected: Kuala Lumpur & Selangor\n";
			}
			// Penang postcodes: 10000-14400
			else if (userInput.find("PENANG") != string::npos || userInput.find("GEORGETOWN") != string::npos ||
			         userInput.find("BUTTERWORTH") != string::npos || userInput.find("BAYAN LEPAS") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '1' && userInput[1] >= '0' && userInput[1] <= '4')) {
				location = 2;
				cout << "Area detected: Penang\n";
			}
			// Perak postcodes: 30000-36810
			else if (userInput.find("PERAK") != string::npos || userInput.find("IPOH") != string::npos ||
			         userInput.find("TAIPING") != string::npos || userInput.find("TELUK INTAN") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '3')) {
				location = 4;
				cout << "Area detected: Perak\n";
			}
			// Negeri Sembilan postcodes: 70000-73500
			else if (userInput.find("NEGERI SEMBILAN") != string::npos || userInput.find("SEREMBAN") != string::npos ||
			         userInput.find("PORT DICKSON") != string::npos || userInput.find("NILAI") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '7' && userInput[1] >= '0' && userInput[1] <= '3')) {
				location = 6;
				cout << "Area detected: Negeri Sembilan\n";
			}
			// Melaka postcodes: 75000-78300
			else if (userInput.find("MELAKA") != string::npos || userInput.find("MALACCA") != string::npos ||
			         userInput.find("ALOR GAJAH") != string::npos || userInput.find("JASIN") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '7' && userInput[1] >= '5' && userInput[1] <= '8')) {
				location = 5;
				cout << "Area detected: Melaka\n";
			}
			// Johor postcodes: 79000-86900
			else if (userInput.find("JOHOR") != string::npos || userInput.find("JB") != string::npos ||
			         userInput.find("JOHOR BAHRU") != string::npos || userInput.find("BATU PAHAT") != string::npos ||
			         userInput.find("MUAR") != string::npos || userInput.find("SKUDAI") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '7' && userInput[1] == '9') ||
			         (userInput.length() == 5 && userInput[0] == '8' && userInput[1] >= '0' && userInput[1] <= '6')) {
				location = 3;
				cout << "Area detected: Johor\n";
			}
			// Pahang postcodes: 25000-28800, 39000-39200, 49000-49400
			else if (userInput.find("PAHANG") != string::npos || userInput.find("KUANTAN") != string::npos ||
			         userInput.find("TEMERLOH") != string::npos || userInput.find("BENTONG") != string::npos ||
			         (userInput.length() == 5 && (userInput[0] == '2' || userInput[0] == '4'))) {
				location = 7;
				cout << "Area detected: Pahang\n";
			}
			// Kedah postcodes: 05000-09800
			else if (userInput.find("KEDAH") != string::npos || userInput.find("ALOR SETAR") != string::npos ||
			         userInput.find("SUNGAI PETANI") != string::npos || userInput.find("LANGKAWI") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '0' && userInput[1] >= '5' && userInput[1] <= '9')) {
				location = 8;
				cout << "Area detected: Kedah\n";
			}
			// Kelantan postcodes: 15000-19800
			else if (userInput.find("KELANTAN") != string::npos || userInput.find("KOTA BHARU") != string::npos ||
			         userInput.find("KOTA BAHRU") != string::npos || userInput.find("TANAH MERAH") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '1' && userInput[1] >= '5' && userInput[1] <= '9')) {
				location = 9;
				cout << "Area detected: Kelantan\n";
			}
			// Terengganu postcodes: 20000-24300
			else if (userInput.find("TERENGGANU") != string::npos || userInput.find("KUALA TERENGGANU") != string::npos ||
			         userInput.find("DUNGUN") != string::npos || userInput.find("KEMAMAN") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '2' && userInput[1] >= '0' && userInput[1] <= '4')) {
				location = 10;
				cout << "Area detected: Terengganu\n";
			}
			// Perlis postcodes: 01000-02600
			else if (userInput.find("PERLIS") != string::npos || userInput.find("KANGAR") != string::npos ||
			         userInput.find("ARAU") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '0' && userInput[1] >= '1' && userInput[1] <= '2')) {
				location = 11;
				cout << "Area detected: Perlis\n";
			}
			// Sabah postcodes: 87000-91309
			else if (userInput.find("SABAH") != string::npos || userInput.find("KOTA KINABALU") != string::npos ||
			         userInput.find("KK") != string::npos || userInput.find("SANDAKAN") != string::npos ||
			         (userInput.length() == 5 && userInput[0] >= '8' && userInput[0] <= '9')) {
				location = 12;
				cout << "Area detected: Sabah\n";
			}
			// Sarawak postcodes: 93000-98859
			else if (userInput.find("SARAWAK") != string::npos || userInput.find("KUCHING") != string::npos ||
			         userInput.find("MIRI") != string::npos || userInput.find("SIBU") != string::npos ||
			         (userInput.length() == 5 && userInput[0] == '9' && userInput[1] >= '3')) {
				location = 13;
				cout << "Area detected: Sarawak\n";
			}
			else {
				cout << "Sorry, we couldn't detect your area. Please select manually.\n";
				autoDetected = false;
			}
		}
		
		// Manual selection if auto-detect failed or user chose manual
		if (!autoDetected || locationChoice == 'B' || locationChoice == 'b') {
			bool validLocation = false;
			while (!validLocation) {
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
				if (location >= 1 && location <= 13) {
					validLocation = true;
				} else {
					cout << "Invalid location. Please choose 1-13.\n\n";
				}
			}
		}
		
		// Section 2: Get surgery type needed
		bool validSurgery = false;
		while (!validSurgery) {
			cout << "\nSelect surgery type needed:\n";
			cout << "1. Cardiac Surgery (Heart)\n";
			cout << "2. Neurosurgery (Brain & Spine)\n";
			cout << "3. Orthopedic Surgery (Bones & Joints)\n";
			cout << "4. General Surgery\n";
			cout << "5. Emergency Surgery\n";
			cout << "Enter your choice: ";
			cin >> surgeryType;

			// Validate surgery type input
			if (surgeryType >= 1 && surgeryType <= 5) {
				validSurgery = true;
			} else {
				cout << "Invalid surgery type. Please choose 1-5.\n\n";
			}
		}

		// Section 3: Display recommended hospitals based on location and surgery type
		cout << "\n=== RECOMMENDED HOSPITALS ===\n";

		// Variables to store Google Maps URLs for each option
		string mapURL1, mapURL2, mapURL3;

		// Process recommendation using switch-case for different locations
		switch (location) {
			// Case 1: Kuala Lumpur & Selangor Region
			case 1:
				cout << "Location: Kuala Lumpur & Selangor\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Institut Jantung Negara (IJN)\nSpecialty: Advanced Cardiac Surgery\nArea: Jalan Tun Razak, KL City Centre\nDistance: ~3 km from KLCC\nContact: +603-2617 8200\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Institut+Jantung+Negara+IJN+Kuala+Lumpur";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Kuala Lumpur\nSpecialty: Cardiac & Heart Surgery\nArea: Jalan Ampang, KLCC Area\nDistance: ~1 km from KLCC\nContact: +603-4141 3000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kuala+Lumpur";
					
					cout << "Option 3:\n";
					cout << "Hospital: Prince Court Medical Centre\nSpecialty: Cardiovascular Surgery\nArea: Jalan Kia Peng, Near KLCC\nDistance: ~1.5 km from KLCC\nContact: +603-2160 0000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Prince+Court+Medical+Centre+Kuala+Lumpur";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Kuala Lumpur (HKL)\nSpecialty: Neurosurgery & Brain Surgery\nArea: Jalan Pahang, Central KL\nDistance: ~5 km from KLCC\nContact: +603-2615 5555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Kuala+Lumpur+HKL";
					
					cout << "Option 2:\n";
					cout << "Hospital: University of Malaya Medical Centre (UMMC)\nSpecialty: Neurosurgery & Spine Surgery\nArea: Lembah Pantai, Near Universiti Malaya\nDistance: ~10 km from KLCC\nContact: +603-7949 2052\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=University+Malaya+Medical+Centre+UMMC";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Kuala Lumpur\nSpecialty: Brain & Spine Surgery\nArea: Jalan Ampang, KLCC Area\nDistance: ~1 km from KLCC\nContact: +603-4141 3000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kuala+Lumpur";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: University of Malaya Medical Centre (UMMC)\nSpecialty: Orthopedic & Joint Surgery\nArea: Lembah Pantai, Near Universiti Malaya\nDistance: ~10 km from KLCC\nContact: +603-7949 2052\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=University+Malaya+Medical+Centre+UMMC";
					
					cout << "Option 2:\n";
					cout << "Hospital: Sunway Medical Centre\nSpecialty: Orthopedic & Sports Surgery\nArea: Bandar Sunway, Petaling Jaya\nDistance: ~15 km from KLCC\nContact: +603-7491 9191\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Sunway+Medical+Centre+Bandar+Sunway";
					
					cout << "Option 3:\n";
					cout << "Hospital: Prince Court Medical Centre\nSpecialty: Joint Replacement Surgery\nArea: Jalan Kia Peng, Near KLCC\nDistance: ~1.5 km from KLCC\nContact: +603-2160 0000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Prince+Court+Medical+Centre+Kuala+Lumpur";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Selayang\nSpecialty: General Surgery\nArea: Selayang, North of KL\nDistance: ~18 km from KLCC\nContact: +603-6126 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Selayang";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Kuala Lumpur (HKL)\nSpecialty: General Surgery\nArea: Jalan Pahang, Central KL\nDistance: ~5 km from KLCC\nContact: +603-2615 5555\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Kuala+Lumpur+HKL";
					
					cout << "Option 3:\n";
					cout << "Hospital: Pantai Hospital Kuala Lumpur\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Bukit Pantai, Bangsar\nDistance: ~8 km from KLCC\nContact: +603-2296 0888\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Kuala+Lumpur+Bangsar";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sungai Buloh\nSpecialty: 24/7 Emergency & Trauma Surgery\nArea: Sungai Buloh, Near KLIA Highway\nDistance: ~25 km from KLCC\nContact: +603-6145 5555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sungai+Buloh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Kuala Lumpur (HKL)\nSpecialty: Emergency & Trauma Centre\nArea: Jalan Pahang, Central KL\nDistance: ~5 km from KLCC\nContact: +603-2615 5555\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Kuala+Lumpur+HKL";
					
					cout << "Option 3:\n";
					cout << "Hospital: Hospital Selayang\nSpecialty: 24/7 Emergency Surgery\nArea: Selayang, North of KL\nDistance: ~18 km from KLCC\nContact: +603-6126 3333\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Selayang";
				}
				break;

			// Case 2: Penang Region
			case 2:
				cout << "Location: Penang\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Penang Adventist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Burma, Georgetown\nDistance: ~2 km from Komtar\nContact: +604-222 7200\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Penang+Adventist+Hospital+Georgetown";
					
					cout << "Option 2:\n";
					cout << "Hospital: Island Hospital Penang\nSpecialty: Heart & Vascular Surgery\nArea: Jalan Macalister, Central Georgetown\nDistance: ~1 km from Komtar\nContact: +604-228 8222\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Island+Hospital+Penang";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: Cardiovascular Surgery\nArea: Jalan Pangkor, Penang Island\nDistance: ~3 km from Komtar\nContact: +604-222 9111\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Penang";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Pulau Pinang\nSpecialty: Neurosurgery\nArea: Jalan Residensi, Georgetown\nDistance: ~2 km from Komtar\nContact: +604-222 5333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Pulau+Pinang+Georgetown";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: Brain & Spine Surgery\nArea: Jalan Pangkor, Penang Island\nDistance: ~3 km from Komtar\nContact: +604-222 9111\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Penang";
					
					cout << "Option 3:\n";
					cout << "Hospital: Island Hospital Penang\nSpecialty: Neurosurgery & Spine Centre\nArea: Jalan Macalister, Central Georgetown\nDistance: ~1 km from Komtar\nContact: +604-228 8222\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Island+Hospital+Penang";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Loh Guan Lye Specialists Centre\nSpecialty: Orthopedic Surgery\nArea: Jalan Logan, Georgetown\nDistance: ~1.5 km from Komtar\nContact: +604-238 8888\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Loh+Guan+Lye+Specialists+Centre+Penang";
					
					cout << "Option 2:\n";
					cout << "Hospital: Island Hospital Penang\nSpecialty: Orthopedic & Joint Replacement\nArea: Jalan Macalister, Central Georgetown\nDistance: ~1 km from Komtar\nContact: +604-228 8222\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Island+Hospital+Penang";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: Orthopedic & Sports Surgery\nArea: Jalan Pangkor, Penang Island\nDistance: ~3 km from Komtar\nContact: +604-222 9111\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Penang";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: General Surgery\nArea: Jalan Pangkor, Penang Island\nDistance: ~3 km from Komtar\nContact: +604-222 9111\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Penang";
					
					cout << "Option 2:\n";
					cout << "Hospital: Loh Guan Lye Specialists Centre\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Logan, Georgetown\nDistance: ~1.5 km from Komtar\nContact: +604-238 8888\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Loh+Guan+Lye+Specialists+Centre+Penang";
					
					cout << "Option 3:\n";
					cout << "Hospital: Hospital Pulau Pinang\nSpecialty: General Surgery\nArea: Jalan Residensi, Georgetown\nDistance: ~2 km from Komtar\nContact: +604-222 5333\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Pulau+Pinang+Georgetown";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Island Hospital Penang\nSpecialty: Emergency Surgery\nArea: Jalan Macalister, Central Georgetown\nDistance: ~1 km from Komtar\nContact: +604-228 8222\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Island+Hospital+Penang";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Pulau Pinang\nSpecialty: 24/7 Emergency & Trauma\nArea: Jalan Residensi, Georgetown\nDistance: ~2 km from Komtar\nContact: +604-222 5333\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Pulau+Pinang+Georgetown";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Penang\nSpecialty: Emergency Care\nArea: Jalan Pangkor, Penang Island\nDistance: ~3 km from Komtar\nContact: +604-222 9111\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Penang";
				}
				break;

			// Case 3: Johor Region
			case 3:
				cout << "Location: Johor\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Heart Surgery\nArea: Jalan Abdul Samad, Johor Bahru\nDistance: ~3 km from JB City Centre\nContact: +607-225 3000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Johor+Specialist+Hospital+Johor+Bahru";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Cardiac & Vascular Surgery\nArea: Medini Iskandar, Near Legoland\nDistance: ~25 km from JB City Centre\nContact: +607-560 1000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Medini+Johor";
					
					cout << "Option 3:\n";
					cout << "Hospital: Hospital Sultanah Aminah (HSA)\nSpecialty: Cardiothoracic Surgery\nArea: Jalan Abu Bakar, JB City Centre\nDistance: ~1 km from JB City Centre\nContact: +607-225 7000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Aminah+Johor+Bahru";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Aminah (HSA)\nSpecialty: Brain & Spine Surgery\nArea: Jalan Abu Bakar, JB City Centre\nDistance: ~1 km from JB City Centre\nContact: +607-225 7000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Aminah+Johor+Bahru";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Neurosurgery & Spine Centre\nArea: Medini Iskandar, Near Legoland\nDistance: ~25 km from JB City Centre\nContact: +607-560 1000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Medini+Johor";
					
					cout << "Option 3:\n";
					cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Neurosurgery\nArea: Jalan Abdul Samad, Johor Bahru\nDistance: ~3 km from JB City Centre\nContact: +607-225 3000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Johor+Specialist+Hospital+Johor+Bahru";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Orthopedic Surgery\nArea: Medini Iskandar, Near Legoland\nDistance: ~25 km from JB City Centre\nContact: +607-560 1000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Medini+Johor";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: Orthopedic & Joint Replacement\nArea: Jalan Abdul Samad, Johor Bahru\nDistance: ~3 km from JB City Centre\nContact: +607-225 3000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Johor+Specialist+Hospital+Johor+Bahru";
					
					cout << "Option 3:\n";
					cout << "Hospital: Pantai Hospital Johor\nSpecialty: Orthopedic Surgery\nArea: Batu Pahat Town\nDistance: ~50 km from JB City Centre\nContact: +607-433 8811\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Batu+Pahat+Johor";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Aminah\nSpecialty: General Surgery\nArea: Jalan Abu Bakar, JB City Centre\nDistance: ~1 km from JB City Centre\nContact: +607-225 7000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Aminah+Johor+Bahru";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Johor Specialist Hospital\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Abdul Samad, Johor Bahru\nDistance: ~3 km from JB City Centre\nContact: +607-225 3000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Johor+Specialist+Hospital+Johor+Bahru";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: General Surgery\nArea: Medini Iskandar, Near Legoland\nDistance: ~25 km from JB City Centre\nContact: +607-560 1000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Medini+Johor";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Pantai Hospital Johor\nSpecialty: 24/7 Emergency Care\nArea: Batu Pahat Town\nDistance: ~50 km from JB City Centre\nContact: +607-433 8811\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Batu+Pahat+Johor";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Sultanah Aminah (HSA)\nSpecialty: Emergency & Trauma Centre\nArea: Jalan Abu Bakar, JB City Centre\nDistance: ~1 km from JB City Centre\nContact: +607-225 7000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Aminah+Johor+Bahru";
					
					cout << "Option 3:\n";
					cout << "Hospital: Gleneagles Hospital Medini Johor\nSpecialty: Emergency Surgery\nArea: Medini Iskandar, Near Legoland\nDistance: ~25 km from JB City Centre\nContact: +607-560 1000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Medini+Johor";
				}
				break;

			// Case 4: Perak Region
			case 4:
				cout << "Location: Perak\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Cardiovascular Surgery\nArea: Jalan Tambun, Ipoh Town\nDistance: ~5 km from Ipoh City Centre\nContact: +605-540 5555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Ipoh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Cardiac Surgery\nArea: Jalan Hospital, Ipoh City Centre\nDistance: ~1 km from Ipoh City Centre\nContact: +605-208 5000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Permaisuri+Bainun+Ipoh";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Ipoh City Centre\nDistance: ~1 km from Ipoh City Centre\nContact: +605-208 5000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Permaisuri+Bainun+Ipoh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Neurosurgery & Spine Surgery\nArea: Jalan Tambun, Ipoh Town\nDistance: ~5 km from Ipoh City Centre\nContact: +605-540 5555\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Ipoh";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: Orthopedic Surgery\nArea: Jalan Tambun, Ipoh Town\nDistance: ~5 km from Ipoh City Centre\nContact: +605-540 5555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Ipoh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Hospital, Ipoh City Centre\nDistance: ~1 km from Ipoh City Centre\nContact: +605-208 5000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Permaisuri+Bainun+Ipoh";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: General Surgery\nArea: Jalan Hospital, Ipoh City Centre\nDistance: ~1 km from Ipoh City Centre\nContact: +605-208 5000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Permaisuri+Bainun+Ipoh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Tambun, Ipoh Town\nDistance: ~5 km from Ipoh City Centre\nContact: +605-540 5555\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Ipoh";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Permaisuri Bainun\nSpecialty: Emergency & Trauma\nArea: Jalan Hospital, Ipoh City Centre\nDistance: ~1 km from Ipoh City Centre\nContact: +605-208 5000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Permaisuri+Bainun+Ipoh";
					
					cout << "Option 2:\n";
					cout << "Hospital: Pantai Hospital Ipoh\nSpecialty: 24/7 Emergency Care\nArea: Jalan Tambun, Ipoh Town\nDistance: ~5 km from Ipoh City Centre\nContact: +605-540 5555\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Pantai+Hospital+Ipoh";
				}
				break;

			// Case 5: Melaka Region
			case 5:
				cout << "Location: Melaka\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Cardiac Surgery\nArea: Jalan Merdeka, Melaka Town Centre\nDistance: ~1 km from Melaka Town Square\nContact: +606-285 2999\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Mahkota+Medical+Centre+Melaka";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Melaka\nSpecialty: Cardiology & Heart Surgery\nArea: Jalan Mufti Haji Khalil, City Centre\nDistance: ~2 km from Melaka Town Square\nContact: +606-289 2345\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Melaka";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Melaka\nSpecialty: Neurosurgery\nArea: Jalan Mufti Haji Khalil, City Centre\nDistance: ~2 km from Melaka Town Square\nContact: +606-289 2345\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Melaka";
					
					cout << "Option 2:\n";
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Neurology & Neurosurgery\nArea: Jalan Merdeka, Melaka Town Centre\nDistance: ~1 km from Melaka Town Square\nContact: +606-285 2999\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Mahkota+Medical+Centre+Melaka";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Orthopedic Surgery\nArea: Jalan Merdeka, Melaka Town Centre\nDistance: ~1 km from Melaka Town Square\nContact: +606-285 2999\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Mahkota+Medical+Centre+Melaka";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Melaka\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Mufti Haji Khalil, City Centre\nDistance: ~2 km from Melaka Town Square\nContact: +606-289 2345\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Melaka";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Melaka\nSpecialty: General Surgery\nArea: Jalan Mufti Haji Khalil, City Centre\nDistance: ~2 km from Melaka Town Square\nContact: +606-289 2345\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Melaka";
					
					cout << "Option 2:\n";
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: General & Minimally Invasive Surgery\nArea: Jalan Merdeka, Melaka Town Centre\nDistance: ~1 km from Melaka Town Square\nContact: +606-285 2999\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Mahkota+Medical+Centre+Melaka";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Mahkota Medical Centre\nSpecialty: Emergency Care\nArea: Jalan Merdeka, Melaka Town Centre\nDistance: ~1 km from Melaka Town Square\nContact: +606-285 2999\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Mahkota+Medical+Centre+Melaka";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Melaka\nSpecialty: 24/7 Emergency & Trauma\nArea: Jalan Mufti Haji Khalil, City Centre\nDistance: ~2 km from Melaka Town Square\nContact: +606-289 2345\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Melaka";
				}
				break;

			// Case 6: Negeri Sembilan Region
			case 6:
				cout << "Location: Negeri Sembilan\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: Cardiac Surgery\nArea: Jalan Penghulu Cantik, Seremban 2\nDistance: ~3 km from Seremban City Centre\nContact: +606-603 3988\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Columbia+Asia+Hospital+Seremban";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Cardiovascular Surgery\nArea: Jalan Toman, Seremban Centre\nDistance: ~2 km from Seremban City Centre\nContact: +606-768 6000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Seremban+Specialist+Hospital";
					
					cout << "Option 3:\n";
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: Cardiac Surgery\nArea: Jalan Rasah, Seremban Town\nDistance: ~4 km from Seremban City Centre\nContact: +606-768 4000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Jaafar+Seremban";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Ja'afar Seremban\nSpecialty: Neurosurgery\nArea: Jalan Rasah, Seremban Town\nDistance: ~4 km from Seremban City Centre\nContact: +606-768 4000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Jaafar+Seremban";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Brain & Spine Surgery\nArea: Jalan Toman, Seremban Centre\nDistance: ~2 km from Seremban City Centre\nContact: +606-768 6000\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Seremban+Specialist+Hospital";
					
					cout << "Option 3:\n";
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: Neurosurgery\nArea: Jalan Penghulu Cantik, Seremban 2\nDistance: ~3 km from Seremban City Centre\nContact: +606-603 3988\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Columbia+Asia+Hospital+Seremban";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Toman, Seremban Centre\nDistance: ~2 km from Seremban City Centre\nContact: +606-768 6000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Seremban+Specialist+Hospital";
					
					cout << "Option 2:\n";
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: Orthopedic & Joint Surgery\nArea: Jalan Penghulu Cantik, Seremban 2\nDistance: ~3 km from Seremban City Centre\nContact: +606-603 3988\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Columbia+Asia+Hospital+Seremban";
					
					cout << "Option 3:\n";
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: Orthopedic Surgery\nArea: Jalan Rasah, Seremban Town\nDistance: ~4 km from Seremban City Centre\nContact: +606-768 4000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Jaafar+Seremban";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: General Surgery\nArea: Jalan Rasah, Seremban Town\nDistance: ~4 km from Seremban City Centre\nContact: +606-768 4000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Jaafar+Seremban";
					
					cout << "Option 2:\n";
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Penghulu Cantik, Seremban 2\nDistance: ~3 km from Seremban City Centre\nContact: +606-603 3988\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Columbia+Asia+Hospital+Seremban";
					
					cout << "Option 3:\n";
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: General Surgery\nArea: Jalan Toman, Seremban Centre\nDistance: ~2 km from Seremban City Centre\nContact: +606-768 6000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Seremban+Specialist+Hospital";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Ja'afar\nSpecialty: Emergency Surgery\nArea: Jalan Rasah, Seremban Town\nDistance: ~4 km from Seremban City Centre\nContact: +606-768 4000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Jaafar+Seremban";
					
					cout << "Option 2:\n";
					cout << "Hospital: Columbia Asia Hospital Seremban\nSpecialty: 24/7 Emergency Care\nArea: Jalan Penghulu Cantik, Seremban 2\nDistance: ~3 km from Seremban City Centre\nContact: +606-603 3988\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Columbia+Asia+Hospital+Seremban";
					
					cout << "Option 3:\n";
					cout << "Hospital: KPJ Seremban Specialist Hospital\nSpecialty: Emergency Surgery\nArea: Jalan Toman, Seremban Centre\nDistance: ~2 km from Seremban City Centre\nContact: +606-768 6000\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Seremban+Specialist+Hospital";
				}
				break;

			// Case 7: Pahang Region
			case 7:
				cout << "Location: Pahang\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Tanjung Lumpur, Kuantan\nDistance: ~5 km from Kuantan City Centre\nContact: +609-511 2692\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Pahang+Specialist+Hospital+Kuantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Cardiology & Heart Surgery\nArea: Jalan Tanah Putih, Kuantan Town\nDistance: ~3 km from Kuantan City Centre\nContact: +609-513 3333\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tengku+Ampuan+Afzan+Kuantan";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Neurosurgery\nArea: Jalan Tanah Putih, Kuantan Town\nDistance: ~3 km from Kuantan City Centre\nContact: +609-513 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tengku+Ampuan+Afzan+Kuantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Neurology & Neurosurgery\nArea: Jalan Tanjung Lumpur, Kuantan\nDistance: ~5 km from Kuantan City Centre\nContact: +609-511 2692\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Pahang+Specialist+Hospital+Kuantan";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Tanjung Lumpur, Kuantan\nDistance: ~5 km from Kuantan City Centre\nContact: +609-511 2692\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Pahang+Specialist+Hospital+Kuantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Tanah Putih, Kuantan Town\nDistance: ~3 km from Kuantan City Centre\nContact: +609-513 3333\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tengku+Ampuan+Afzan+Kuantan";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: General Surgery\nArea: Jalan Tanah Putih, Kuantan Town\nDistance: ~3 km from Kuantan City Centre\nContact: +609-513 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tengku+Ampuan+Afzan+Kuantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Tanjung Lumpur, Kuantan\nDistance: ~5 km from Kuantan City Centre\nContact: +609-511 2692\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Pahang+Specialist+Hospital+Kuantan";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tengku Ampuan Afzan\nSpecialty: Emergency & Trauma\nArea: Jalan Tanah Putih, Kuantan Town\nDistance: ~3 km from Kuantan City Centre\nContact: +609-513 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tengku+Ampuan+Afzan+Kuantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: KPJ Pahang Specialist Hospital\nSpecialty: 24/7 Emergency Care\nArea: Jalan Tanjung Lumpur, Kuantan\nDistance: ~5 km from Kuantan City Centre\nContact: +609-511 2692\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Pahang+Specialist+Hospital+Kuantan";
				}
				break;

			// Case 8: Kedah Region
			case 8:
				cout << "Location: Kedah\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Cardiac Surgery\nArea: Bandar Baru Mergong, Alor Setar\nDistance: ~3 km from Alor Setar City Centre\nContact: +604-740 6100\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Aurelius+Hospital+Alor+Setar";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Cardiology & Heart Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nDistance: ~6 km from Alor Setar City Centre\nContact: +604-740 6233\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Bahiyah+Alor+Setar";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Neurosurgery\nArea: Km6 Jalan Langgar, Alor Setar\nDistance: ~6 km from Alor Setar City Centre\nContact: +604-740 6233\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Bahiyah+Alor+Setar";
					
					cout << "Option 2:\n";
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Neurosurgery & Spine Centre\nArea: Bandar Baru Mergong, Alor Setar\nDistance: ~3 km from Alor Setar City Centre\nContact: +604-740 6100\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Aurelius+Hospital+Alor+Setar";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: Orthopedic Surgery\nArea: Bandar Baru Mergong, Alor Setar\nDistance: ~3 km from Alor Setar City Centre\nContact: +604-740 6100\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Aurelius+Hospital+Alor+Setar";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Orthopedic & Trauma Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nDistance: ~6 km from Alor Setar City Centre\nContact: +604-740 6233\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Bahiyah+Alor+Setar";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: General Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nDistance: ~6 km from Alor Setar City Centre\nContact: +604-740 6233\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Bahiyah+Alor+Setar";
					
					cout << "Option 2:\n";
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: General & Minimally Invasive Surgery\nArea: Bandar Baru Mergong, Alor Setar\nDistance: ~3 km from Alor Setar City Centre\nContact: +604-740 6100\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Aurelius+Hospital+Alor+Setar";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Bahiyah\nSpecialty: Emergency Surgery\nArea: Km6 Jalan Langgar, Alor Setar\nDistance: ~6 km from Alor Setar City Centre\nContact: +604-740 6233\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Bahiyah+Alor+Setar";
					
					cout << "Option 2:\n";
					cout << "Hospital: Aurelius Hospital Alor Setar\nSpecialty: 24/7 Emergency Care\nArea: Bandar Baru Mergong, Alor Setar\nDistance: ~3 km from Alor Setar City Centre\nContact: +604-740 6100\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Aurelius+Hospital+Alor+Setar";
				}
				break;

			// Case 9: Kelantan Region
			case 9:
				cout << "Location: Kelantan\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Cardiac Surgery\nArea: Kubang Kerian, Near USM Campus\nDistance: ~12 km from Kota Bharu City Centre\nContact: +609-767 3000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Universiti+Sains+Malaysia+HUSM+Kelantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Cardiology & Heart Surgery\nArea: Jalan Hospital, Kota Bharu Centre\nDistance: ~2 km from Kota Bharu City Centre\nContact: +609-745 2000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Perempuan+Zainab+II+Kota+Bharu";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Kota Bharu Centre\nDistance: ~2 km from Kota Bharu City Centre\nContact: +609-745 2000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Perempuan+Zainab+II+Kota+Bharu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Neurosurgery & Spine Surgery\nArea: Kubang Kerian, Near USM Campus\nDistance: ~12 km from Kota Bharu City Centre\nContact: +609-767 3000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Universiti+Sains+Malaysia+HUSM+Kelantan";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: Orthopedic Surgery\nArea: Kubang Kerian, Near USM Campus\nDistance: ~12 km from Kota Bharu City Centre\nContact: +609-767 3000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Universiti+Sains+Malaysia+HUSM+Kelantan";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Hospital, Kota Bharu Centre\nDistance: ~2 km from Kota Bharu City Centre\nContact: +609-745 2000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Perempuan+Zainab+II+Kota+Bharu";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: General Surgery\nArea: Jalan Hospital, Kota Bharu Centre\nDistance: ~2 km from Kota Bharu City Centre\nContact: +609-745 2000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Perempuan+Zainab+II+Kota+Bharu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: General & Advanced Surgery\nArea: Kubang Kerian, Near USM Campus\nDistance: ~12 km from Kota Bharu City Centre\nContact: +609-767 3000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Universiti+Sains+Malaysia+HUSM+Kelantan";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Raja Perempuan Zainab II\nSpecialty: Emergency & Trauma\nArea: Jalan Hospital, Kota Bharu Centre\nDistance: ~2 km from Kota Bharu City Centre\nContact: +609-745 2000\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Raja+Perempuan+Zainab+II+Kota+Bharu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Universiti Sains Malaysia (HUSM)\nSpecialty: 24/7 Emergency Surgery\nArea: Kubang Kerian, Near USM Campus\nDistance: ~12 km from Kota Bharu City Centre\nContact: +609-767 3000\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Universiti+Sains+Malaysia+HUSM+Kelantan";
				}
				break;

			// Case 10: Terengganu Region
			case 10:
				cout << "Location: Terengganu\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Cardiac Surgery\nArea: Jalan Air Jernih, KT Town Centre\nDistance: ~2 km from Kuala Terengganu City Centre\nContact: +609-624 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Kuala+Terengganu+Specialist+Hospital";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Cardiology & Heart Surgery\nArea: Jalan Sultan Mahmud, KT City\nDistance: ~3 km from Kuala Terengganu City Centre\nContact: +609-621 2121\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Nur+Zahirah+Kuala+Terengganu";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Neurosurgery\nArea: Jalan Sultan Mahmud, KT City\nDistance: ~3 km from Kuala Terengganu City Centre\nContact: +609-621 2121\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Nur+Zahirah+Kuala+Terengganu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Neurology & Neurosurgery\nArea: Jalan Air Jernih, KT Town Centre\nDistance: ~2 km from Kuala Terengganu City Centre\nContact: +609-624 3333\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Kuala+Terengganu+Specialist+Hospital";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: Orthopedic Surgery\nArea: Jalan Air Jernih, KT Town Centre\nDistance: ~2 km from Kuala Terengganu City Centre\nContact: +609-624 3333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Kuala+Terengganu+Specialist+Hospital";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Sultan Mahmud, KT City\nDistance: ~3 km from Kuala Terengganu City Centre\nContact: +609-621 2121\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Nur+Zahirah+Kuala+Terengganu";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: General Surgery\nArea: Jalan Sultan Mahmud, KT City\nDistance: ~3 km from Kuala Terengganu City Centre\nContact: +609-621 2121\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Nur+Zahirah+Kuala+Terengganu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Air Jernih, KT Town Centre\nDistance: ~2 km from Kuala Terengganu City Centre\nContact: +609-624 3333\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Kuala+Terengganu+Specialist+Hospital";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Sultanah Nur Zahirah\nSpecialty: Emergency Surgery\nArea: Jalan Sultan Mahmud, KT City\nDistance: ~3 km from Kuala Terengganu City Centre\nContact: +609-621 2121\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Sultanah+Nur+Zahirah+Kuala+Terengganu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Kuala Terengganu Specialist Hospital\nSpecialty: 24/7 Emergency Care\nArea: Jalan Air Jernih, KT Town Centre\nDistance: ~2 km from Kuala Terengganu City Centre\nContact: +609-624 3333\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Kuala+Terengganu+Specialist+Hospital";
				}
				break;

			// Case 11: Perlis Region
			case 11:
				cout << "Location: Perlis\n";
				cout << "Note: Perlis has limited specialist hospitals. Main referral hospital listed.\n\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Cardiac Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nDistance: ~2 km from Kangar City Centre\nContact: +604-973 8333\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Fauziah+Kangar+Perlis";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Neurosurgery\nArea: Jalan Tun Abd Razak, Kangar Town\nDistance: ~2 km from Kangar City Centre\nContact: +604-973 8333\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Fauziah+Kangar+Perlis";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Orthopedic Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nDistance: ~2 km from Kangar City Centre\nContact: +604-973 8333\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Fauziah+Kangar+Perlis";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: General Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nDistance: ~2 km from Kangar City Centre\nContact: +604-973 8333\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Fauziah+Kangar+Perlis";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Tuanku Fauziah\nSpecialty: Emergency Surgery\nArea: Jalan Tun Abd Razak, Kangar Town\nDistance: ~2 km from Kangar City Centre\nContact: +604-973 8333\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Tuanku+Fauziah+Kangar+Perlis";
				}
				break;

			// Case 12: Sabah Region
			case 12:
				cout << "Location: Sabah\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Cardiovascular Surgery\nArea: Riverson, Near Imago Mall\nDistance: ~3 km from KK City Centre\nContact: +6088-518 888\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kota+Kinabalu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Cardiac Surgery\nArea: Jalan Penampang, KK City Centre\nDistance: ~2 km from KK City Centre\nContact: +6088-517 555\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Queen+Elizabeth+Kota+Kinabalu";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Neurosurgery\nArea: Jalan Penampang, KK City Centre\nDistance: ~2 km from KK City Centre\nContact: +6088-517 555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Queen+Elizabeth+Kota+Kinabalu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Brain & Spine Surgery\nArea: Riverson, Near Imago Mall\nDistance: ~3 km from KK City Centre\nContact: +6088-518 888\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kota+Kinabalu";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: Orthopedic Surgery\nArea: Riverson, Near Imago Mall\nDistance: ~3 km from KK City Centre\nContact: +6088-518 888\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kota+Kinabalu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Orthopedic & Trauma Surgery\nArea: Jalan Penampang, KK City Centre\nDistance: ~2 km from KK City Centre\nContact: +6088-517 555\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Queen+Elizabeth+Kota+Kinabalu";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: General Surgery\nArea: Jalan Penampang, KK City Centre\nDistance: ~2 km from KK City Centre\nContact: +6088-517 555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Queen+Elizabeth+Kota+Kinabalu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: General & Minimally Invasive Surgery\nArea: Riverson, Near Imago Mall\nDistance: ~3 km from KK City Centre\nContact: +6088-518 888\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kota+Kinabalu";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Queen Elizabeth\nSpecialty: Emergency & Trauma\nArea: Jalan Penampang, KK City Centre\nDistance: ~2 km from KK City Centre\nContact: +6088-517 555\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Queen+Elizabeth+Kota+Kinabalu";
					
					cout << "Option 2:\n";
					cout << "Hospital: Gleneagles Hospital Kota Kinabalu\nSpecialty: 24/7 Emergency Care\nArea: Riverson, Near Imago Mall\nDistance: ~3 km from KK City Centre\nContact: +6088-518 888\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Gleneagles+Hospital+Kota+Kinabalu";
				}
				break;

			// Case 13: Sarawak Region
			case 13:
				cout << "Location: Sarawak\n";
				if (surgeryType == 1) {
					cout << "Surgery Type: Cardiac Surgery (Heart)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Sarawak Heart Centre\nSpecialty: Advanced Cardiac Care\nArea: Kota Samarahan, Near UNIMAS\nDistance: ~20 km from Kuching City Centre\nContact: +6082-833 333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Sarawak+Heart+Centre+Kota+Samarahan";
					
					cout << "Option 2:\n";
					cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: Cardiovascular Surgery\nArea: Jalan Tun Abdul Rahman Yakub, Kuching\nDistance: ~3 km from Kuching City Centre\nContact: +6082-440 055\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Normah+Medical+Specialist+Centre+Kuching";
					
					cout << "Option 3:\n";
					cout << "Hospital: Borneo Medical Centre\nSpecialty: Cardiac Surgery\nArea: Jalan Tun Ahmad Zaidi, Kuching\nDistance: ~2 km from Kuching City Centre\nContact: +6082-507 333\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Borneo+Medical+Centre+Kuching";
				}
				else if (surgeryType == 2) {
					cout << "Surgery Type: Neurosurgery (Brain & Spine)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Umum Sarawak\nSpecialty: Neurosurgery\nArea: Jalan Hospital, Kuching City Centre\nDistance: ~1 km from Kuching City Centre\nContact: +6082-276 666\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Umum+Sarawak+Kuching";
					
					cout << "Option 2:\n";
					cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: Neurosurgery & Spine Surgery\nArea: Jalan Tun Abdul Rahman Yakub, Kuching\nDistance: ~3 km from Kuching City Centre\nContact: +6082-440 055\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Normah+Medical+Specialist+Centre+Kuching";
					
					cout << "Option 3:\n";
					cout << "Hospital: Borneo Medical Centre\nSpecialty: Brain & Spine Surgery\nArea: Jalan Tun Ahmad Zaidi, Kuching\nDistance: ~2 km from Kuching City Centre\nContact: +6082-507 333\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Borneo+Medical+Centre+Kuching";
				}
				else if (surgeryType == 3) {
					cout << "Surgery Type: Orthopedic Surgery (Bones & Joints)\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Borneo Medical Centre\nSpecialty: Bone & Joint Surgery\nArea: Jalan Tun Ahmad Zaidi, Kuching\nDistance: ~2 km from Kuching City Centre\nContact: +6082-507 333\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Borneo+Medical+Centre+Kuching";
					
					cout << "Option 2:\n";
					cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: Orthopedic Surgery\nArea: Jalan Tun Abdul Rahman Yakub, Kuching\nDistance: ~3 km from Kuching City Centre\nContact: +6082-440 055\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Normah+Medical+Specialist+Centre+Kuching";
					
					cout << "Option 3:\n";
					cout << "Hospital: KPJ Kuching Specialist Hospital\nSpecialty: Orthopedic & Joint Replacement\nArea: Jalan Tun Jugah, Kuching Town\nDistance: ~4 km from Kuching City Centre\nContact: +6082-365 777\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Kuching+Specialist+Hospital";
				}
				else if (surgeryType == 4) {
					cout << "Surgery Type: General Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: Hospital Umum Sarawak\nSpecialty: General Surgery\nArea: Jalan Hospital, Kuching City Centre\nDistance: ~1 km from Kuching City Centre\nContact: +6082-276 666\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Umum+Sarawak+Kuching";
					
					cout << "Option 2:\n";
					cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: General & Laparoscopic Surgery\nArea: Jalan Tun Abdul Rahman Yakub, Kuching\nDistance: ~3 km from Kuching City Centre\nContact: +6082-440 055\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Normah+Medical+Specialist+Centre+Kuching";
					
					cout << "Option 3:\n";
					cout << "Hospital: Borneo Medical Centre\nSpecialty: General Surgery\nArea: Jalan Tun Ahmad Zaidi, Kuching\nDistance: ~2 km from Kuching City Centre\nContact: +6082-507 333\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Borneo+Medical+Centre+Kuching";
				}
				else {
					cout << "Surgery Type: Emergency Surgery\n\n";
					cout << "Option 1:\n";
					cout << "Hospital: KPJ Kuching Specialist Hospital\nSpecialty: Trauma & Emergency Surgery\nArea: Jalan Tun Jugah, Kuching Town\nDistance: ~4 km from Kuching City Centre\nContact: +6082-365 777\n\n";
					mapURL1 = "https://www.google.com/maps/dir/?api=1&destination=KPJ+Kuching+Specialist+Hospital";
					
					cout << "Option 2:\n";
					cout << "Hospital: Hospital Umum Sarawak\nSpecialty: 24/7 Emergency & Trauma\nArea: Jalan Hospital, Kuching City Centre\nDistance: ~1 km from Kuching City Centre\nContact: +6082-276 666\n\n";
					mapURL2 = "https://www.google.com/maps/dir/?api=1&destination=Hospital+Umum+Sarawak+Kuching";
					
					cout << "Option 3:\n";
					cout << "Hospital: Normah Medical Specialist Centre\nSpecialty: Emergency Care\nArea: Jalan Tun Abdul Rahman Yakub, Kuching\nDistance: ~3 km from Kuching City Centre\nContact: +6082-440 055\n";
					mapURL3 = "https://www.google.com/maps/dir/?api=1&destination=Normah+Medical+Specialist+Centre+Kuching";
				}
				break;
		}

		// Google Maps Integration Feature
		cout << "\n========================================\n";
		cout << "View hospital location on Google Maps?\n";
		cout << "1 = Option 1 | 2 = Option 2 | 3 = Option 3 | N = Skip\n";
		cout << "Enter your choice: ";
		cin >> mapChoice;
		
		if (mapChoice == '1' || mapChoice == '2' || mapChoice == '3') {
			string selectedURL;
			if (mapChoice == '1') selectedURL = mapURL1;
			else if (mapChoice == '2') selectedURL = mapURL2;
			else if (mapChoice == '3') selectedURL = mapURL3;
			
			// Open Google Maps in browser (with quotes for Windows compatibility)
			string command = "start \"\" \"" + selectedURL + "\"";
			system(command.c_str());
			cout << "Opening Google Maps in your browser...\n";
			cout << "Note: Google Maps will show you the distance from your location.\n";
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

