# 🗳️ Voter Management System

> A comprehensive C++ application for managing democratic elections with voter registration, candidate management, voting, and result computation.

---

## 📋 Table of Contents

- [✨ Features](#-features)
- [🏗️ Architecture](#️-architecture)
- [⚙️ Requirements](#️-requirements)
- [🚀 Compilation & Execution](#-compilation--execution)
- [📖 Usage Guide](#-usage-guide)
- [📁 File Structure](#-file-structure)
- [🔧 Core Functions](#-core-functions)
- [💾 Data Storage](#-data-storage)
- [⚡ Important Notes](#-important-notes)

---

## ✨ Features

### 🎯 Core Functionality

| Feature | Description |
|---------|-------------|
| 🏛️ **Add Candidates** | Register candidates for the election (max 5) |
| 👤 **Register Voters** | Register voters with age validation (must be 18+) |
| 📋 **Display Voters** | View all registered voters and their voting status |
| ✅ **Cast Vote** | Allow voters to vote for candidates with duplicate vote prevention |
| 👥 **Display Candidates** | View all candidates with their vote counts |
| 🏆 **Display Results** | View election results and determine the winner |

### 🔒 Built-in Validations

- ✅ **Age Verification**: Voters must be 18 years or older
- ✅ **Duplicate Vote Prevention**: Each voter can only vote once
- ✅ **Candidate ID Validation**: Only valid candidate IDs are accepted
- ✅ **Data Persistence**: All data automatically saved to files

---

## 🏗️ Architecture

### Data Structures

#### 👤 Voter Structure
```cpp
struct Voter {
    int id;              // Unique voter identifier
    string name;         // Voter's name
    int age;             // Voter's age (must be ≥18)
    bool has_voted;      // Voting status flag
    string vote;         // Candidate name voted for
};
```

#### 🎖️ Candidate Structure
```cpp
struct Candidate {
    int id;              // Unique candidate identifier
    string name;         // Candidate's name
    int votes;           // Total votes received
};
```

### System Limits

| Parameter | Limit |
|-----------|-------|
| **Maximum Voters** | 1000 |
| **Maximum Candidates** | 5 |

---

## ⚙️ Requirements

### Compiler & Libraries

- **C++ Compiler**: GCC/G++, Clang, or MSVC with C++11 or later
- **Standard Libraries Used**:
  - `<iostream>` - Input/Output operations
  - `<cmath>` - Mathematical functions
  - `<cctype>` - Character handling
  - `<cstring>` - String operations
  - `<fstream>` - File I/O operations

### System Requirements

- Operating System: Windows, Linux, or macOS
- Disk Space: Minimal (for data files)
- RAM: 1 MB minimum

---

## 🚀 Compilation & Execution

### Step 1: Compile the Program

```bash
g++ -o voter_system voter_management_system.cpp
```

### Step 2: Run the Program

```bash
./voter_system
```

### Expected Output

```
<------------------------------------- Menu --------------------------------------------->

To add candidate:      1
To register voter:     2
To display voters:     3
To cast vote:          4
To display candidates: 5
To display results:    6
<----------------------------------------------------------------------------------------->

Enter the total number of operations you want to perform :
```

---

## 📖 Usage Guide

### 🎖️ Option 1: Add Candidate

```
Enter your choice: 1
Enter candidate's name : Alice
<-----------candidate registered successfully----------------->
```

**How it works:**
- Candidates are automatically assigned IDs (1-5)
- First candidate gets ID 1, second gets ID 2, etc.
- Maximum 5 candidates can be added
- Vote count initializes to 0

### 👤 Option 2: Register Voter

```
Enter your choice: 2
Enter voter's name : John Doe
Enter voter's age : 25
<-----------voter registered successfully----------------->
```

**How it works:**
- Voters are automatically assigned IDs (1-1000)
- Age must be 18 or above (validated automatically)
- Initial voting status set to `false`
- Maximum 1000 voters can be registered

### 📋 Option 3: Display Voters

```
Enter your choice: 3
<--->
Voter ID :      1
Voter Name :    John Doe
voter Age :     25
voter voted for : Alice
<--->
<--->
Voter ID :      2
Voter Name :    Jane Smith
voter Age :     30
voter hasn't voted yet....  
<--->
```

### ✅ Option 4: Cast Vote

```
Enter your choice: 4
Enter voter ID :1
Enter candidate id you want to vote from the list below : 
1 Alice
2 Bob
3 Charlie
candidate ID : 1
Vote has been casted successfully......
```

**How it works:**
- Voter ID must exist in the system
- Voters can only vote once (duplicate voting prevented)
- Must select from available candidates
- Candidate ID is validated
- Vote count automatically incremented

### 👥 Option 5: Display Candidates

```
Enter your choice: 5
<--->
Candidate ID :    1
Candidate Name :  Alice
Candidate votes : 450
<--->
<--->
Candidate ID :    2
Candidate Name :  Bob
Candidate votes : 380
<--->
```

### 🏆 Option 6: Display Results

```
Enter your choice: 6
<--->
Candidate ID :    1
Candidate Name :  Alice
Candidate votes : 450
<--->
<--->
Candidate ID :    2
Candidate Name :  Bob
Candidate votes : 380
<--->

Alice has won the election
```

---

## 📁 File Structure

### Project Files

```
Voter-Management-System/
├── voter_management_system.cpp    # Main program source code
├── voters.txt                      # Voter data (auto-generated)
├── candidates.txt                  # Candidate data (auto-generated)
└── README.md                       # This documentation file
```

### Data File Formats

#### 📄 voters.txt
```
1
John Doe
25
1
Alice
2
Jane Smith
30
0
```

**Format:**
- Voter ID
- Voter Name
- Voter Age
- Voting Status (1=true, 0=false)
- Candidate Name (if voted)

#### 📄 candidates.txt
```
1
Alice
450
2
Bob
380
```

**Format:**
- Candidate ID
- Candidate Name
- Vote Count

---

## 🔧 Core Functions

### File Operations

| Function | Purpose |
|----------|---------|
| `load_voters()` | Load voter data from voters.txt |
| `save_voters()` | Save voter data to voters.txt |
| `load_candidates()` | Load candidate data from candidates.txt |
| `save_candidates()` | Save candidate data to candidates.txt |

### Voter Management

| Function | Parameters | Returns | Purpose |
|----------|-----------|---------|---------|
| `register_voter()` | `Voter*[], string` | `bool` | Register a new voter with age validation |
| `display_voters()` | `Voter*[]` | `void` | Display all registered voters |
| `cast_vote()` | `Voter*[], Candidate*[], int, string, string` | `bool` | Process voting with duplicate prevention |

### Candidate Management

| Function | Parameters | Returns | Purpose |
|----------|-----------|---------|---------|
| `add_candidate()` | `Candidate*[], string` | `bool` | Add a new candidate |
| `display_candidates()` | `Candidate*[]` | `void` | Display all candidates with votes |
| `display_result()` | `Candidate*[]` | `void` | Display results and declare winner |

---

## 💾 Data Storage

### Persistent Storage

- All voter and candidate data is automatically saved to text files
- Data persists between program sessions
- Files are created automatically on first run

### Load Mechanism

- Program loads all existing voters and candidates on startup
- Data seamlessly integrates with new entries

### File Management

- `voters.txt` stores voter records
- `candidates.txt` stores candidate records
- Both files are updated after each operation

---

## ⚡ Important Notes

### ✅ Voter Age Validation

- **Minimum Age**: 18 years
- **Input Validation**: Program will repeatedly prompt for valid age until ≥18 is entered
- **No Upper Age Limit**: Any age ≥18 is accepted

### 🔐 Vote Security

- **One Vote Per Voter**: `has_voted` flag prevents duplicate voting
- **Permanent Record**: Once voted, voter status cannot be changed through UI
- **Candidate Verification**: Only valid candidate IDs are accepted

### 💾 Memory Management

- All voter and candidate objects are dynamically allocated
- Proper deallocation occurs at program termination
- Memory leaks prevented through structured cleanup

### 🏆 Winner Declaration

- Winner determined by **highest vote count**
- If multiple candidates have the same highest count, all are declared winners
- Results display all candidates with vote counts

### ⚠️ Capacity Limitations

- **Voter Registration**: Stops at 1000 voters (message: "no vacant space for voters")
- **Candidate Registration**: Stops at 5 candidates (message: "no vacant space for candidates")
- Plan accordingly for election scale

### 📝 Input Handling

- Voter names and candidate names support spaces
- ID-based lookups are case-sensitive for names
- Vote input is validated before processing

---

## 🎓 Learning Outcomes

This project demonstrates:
- ✨ **Struct Implementation** in C++
- 📁 **File I/O Operations** (reading and writing)
- 🔄 **Dynamic Memory Allocation** and deallocation
- ✅ **Input Validation** and error handling
- 🎯 **Menu-Driven Programming**
- 💾 **Data Persistence** across sessions

---

## 📞 Support

For issues or questions:
1. Check the file operation error messages
2. Ensure `voters.txt` and `candidates.txt` are not corrupted
3. Verify you have read/write permissions in the program directory
4. Check that voter age is ≥18 during registration

---

**Last Updated**: July 15, 2024  
**Language**: C++  
**License**: Open Source  
**Author**: IrajFatima
