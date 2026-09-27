# Hospital Finder - Surgery Specialist Locator

A C++ console application that helps users find suitable hospitals for major surgeries across Malaysia based on their location and required surgery type.

## 📋 Project Information

**Course:** LDCW6123 - Fundamentals of Digital Competence for Programmer  
**Project:** Innovation Technology Life Cycle & Interactive Program  
**Part:** Part 2 - C++ Programming (20%)  
**Technology Focus:** Healthcare Digital Innovation System

## ✨ Features

- **Comprehensive Coverage:** All 13 Malaysian states/regions
- **5 Surgery Types:** 
  - Cardiac Surgery (Heart)
  - Neurosurgery (Brain & Spine)
  - Orthopedic Surgery (Bones & Joints)
  - General Surgery
  - Emergency Surgery
- **140 Hospital Recommendations:** 2-3 options per search for better choices
- **Real Malaysian Hospitals:** Verified government and private hospitals
- **Complete Contact Information:** Phone numbers for all hospitals
- **Location Details:** Area/street information to help locate hospitals
- **User-Friendly Interface:** Menu-driven selection system
- **Input Validation:** Robust error handling
- **Search Again Feature:** Multiple searches without restarting
- **Well-Documented Code:** Comprehensive comments throughout

## 🏥 Covered Regions

1. Kuala Lumpur & Selangor
2. Penang
3. Johor
4. Perak
5. Melaka
6. Negeri Sembilan
7. Pahang
8. Kedah
9. Kelantan
10. Terengganu
11. Perlis
12. Sabah
13. Sarawak

## 🏗️ Program Structure

```
Hospital Finder
├── Location Selection (13 states)
├── Surgery Type Selection (5 types)
├── Multiple Hospital Recommendations (2-3 options)
│   ├── Hospital Name
│   ├── Specialty
│   ├── Area/Location
│   └── Contact Number
└── Search Again Option
```

## 🚀 How to Use

### Compilation

**Using g++:**
```bash
g++ project.cpp -o hospital_finder
./hospital_finder
```

**Using Dev-C++:**
1. Open `project.cpp`
2. Press F9 (Compile & Run)

**Using Visual Studio:**
1. Open `project.cpp`
2. Press Ctrl+F5 (Run without debugging)

### Running the Program

1. Select your state/region (1-13)
2. Choose the type of surgery needed (1-5)
3. View the recommended hospital with contact information
4. Choose to search again (Y) or exit (N)

### Example Usage

```
=== Hospital Finder - Surgery Specialist Locator ===
=== Malaysia ===

Select your state/region:
1. Kuala Lumpur & Selangor
...
Enter your choice: 1

Select surgery type needed:
1. Cardiac Surgery (Heart)
...
Enter your choice: 1

=== RECOMMENDED HOSPITALS ===
Location: Kuala Lumpur & Selangor
Surgery Type: Cardiac Surgery (Heart)

Option 1:
Hospital: Institut Jantung Negara (IJN)
Specialty: Advanced Cardiac Surgery
Area: Jalan Tun Razak, KL City Centre
Contact: +603-2617 8200

Option 2:
Hospital: Gleneagles Hospital Kuala Lumpur
Specialty: Cardiac & Heart Surgery
Area: Jalan Ampang, KLCC Area
Contact: +603-4141 3000

Option 3:
Hospital: Prince Court Medical Centre
Specialty: Cardiovascular Surgery
Area: Jalan Kia Peng, Near KLCC
Contact: +603-2160 0000

Would you like to search for another hospital? (Y/N): N

Thank you for using Hospital Finder!
Stay healthy and take care!
```

## 📊 Sample Hospitals Included

### Major Hospital Networks
- **Institut Jantung Negara (IJN)** - Premier heart hospital
- **Gleneagles Hospitals** - Premium private healthcare (KL, Penang, Johor, Sabah)
- **KPJ Specialist Hospitals** - Nationwide specialist network
- **Hospital Kuala Lumpur (HKL)** - Major government hospital
- **Prince Court Medical Centre** - International medical center
- **Sunway Medical Centre** - Leading private hospital
- **Island Hospital Penang** - Award-winning private hospital
- **Mahkota Medical Centre** - Melaka's premier hospital
- **Borneo Medical Centre** - Leading hospital in East Malaysia
- **Normah Medical Specialist Centre** - Sarawak's top private hospital
- And many more government and private hospitals across Malaysia!

## 🛠️ Technical Details

- **Language:** C++ (Standard C++11 or later)
- **Input/Output:** Console-based (iostream)
- **Logic Control:** Switch-case and if-else statements
- **Validation:** Input range checking with loop continuation
- **Data Structure:** Static data with comprehensive hospital database

## 📝 Code Quality

- ✅ Comprehensive header comments
- ✅ Section comments for major code blocks
- ✅ Inline comments for logic explanation
- ✅ Meaningful variable names
- ✅ Proper indentation and formatting
- ✅ Input validation and error handling

## 🔄 Development History

View the complete development history with:
```bash
git log --oneline --graph
```

### Key Milestones
1. Initial Netflix Movie Finder (baseline)
2. Conversion to Hospital Finder
3. Expansion to 13 Malaysian states
4. Verification of real hospital names
5. Addition of comprehensive documentation
6. Implementation of search again loop
7. Integration of complete contact information
8. Addition of area/location descriptions for all hospitals
9. **Major upgrade: Multiple hospital options (2-3 per category) for better user choice**

## 📦 Repository Structure

```
LDCW-Project/
├── project.cpp          # Main C++ source code
├── README.md           # This file
└── .git/               # Git version control
```

## 🎯 Assignment Requirements Met

- ✅ Connected to healthcare technology innovation
- ✅ Real-world feature (hospital recommendations)
- ✅ Clear inputs and outputs
- ✅ Uses if/else and switch statements
- ✅ Complete Git development history
- ✅ Meaningful commit messages
- ✅ Well-documented code

## 📸 Screenshots

For assignment submission, screenshots include:
- Source code in IDE
- Program execution with sample outputs
- Multiple test cases showing different states and surgery types
- Git log history
- Contact information display

## 🔗 Links

- **GitHub Repository:** [https://github.com/James88-jl/LDCW-Project](https://github.com/James88-jl/LDCW-Project)
- **Source Code:** [project.cpp](project.cpp)

## 📄 License

This project is created for educational purposes as part of LDCW6123 coursework.

## 👨‍💻 Author

**James88-jl**  
Student Project - LDCW6123  
Multimedia University

## 🙏 Acknowledgments

- Hospital information sourced from official hospital websites
- Contact numbers verified as of 2026
- Part of Innovation Technology Life Cycle project
- Connected to healthcare digital transformation analysis

## 📞 Hospital Data Accuracy

All hospital names and contact numbers in this program are based on real Malaysian hospitals. Contact information is accurate as of the project development date. Users should verify current contact details before making actual hospital visits.

---

**Note:** This is an educational project demonstrating C++ programming skills, user input handling, control structures, and software development practices using version control.
