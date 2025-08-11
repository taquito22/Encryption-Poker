# C++ Projects Repository

This repository contains two C++ programming projects that demonstrate different aspects of the language and problem-solving techniques.

## Projects Overview

### 1. Poker Hand Evaluator
A poker simulation built from scratch using plain C++ and raw arrays. No external libraries required!

### 2. Cryptographic Ciphers & Scrabble Game
A collection of classic cipher implementations and a Scrabble word checker, focusing on array manipulation and string processing.

---

## Project 1: Poker in C++

### Overview
A complete poker hand evaluation system that simulates a deck of cards and determines the best possible poker hand from any given set of cards.

### Features
- **Custom Hand Class**
  - Stores cards in sorted order (highest card first)
  - Dynamic resizing with heap allocation
  - Add, clear, count, and print card operations

- **Poker Hand Evaluator**
  - Detects all major poker hands:
    - High Card
    - Pair
    - Two Pair
    - Three of a Kind
    - Straight
    - Flush
    - Full House
    - Four of a Kind
    - Straight Flush
  - Automatically chooses the highest-ranking possible hand

- **Standard 52-Card Deck Support** (no jokers, no duplicates)

### How to Use
1. Navigate to the poker project folder
2. Compile the source files
3. Create and populate a Hand with cards
4. Use the `best_hand()` function to evaluate

**Example Usage:**
```cpp
Hand* myHand = make_hand();
myHand->add(Card(ACE, SPADES));
myHand->add(Card(KING, SPADES));
// ... add more cards

Hand* result = best_hand(*myHand);
result->print();
```

---

## Project 2: Ciphers & Scrabble

### Overview
A collection of four programs that work with arrays and strings to implement cryptographic ciphers and a Scrabble word checker.

### Programs Included

#### 1. Caesar Cipher (`caesar.cpp`)
Implements the classic [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) with rotation-based encryption.

**Usage:** `./caesar [-ed] [key]`
- `-e` for encryption, `-d` for decryption
- `key` must be a non-negative integer

**Example:**
```bash
./caesar -e 3
abcdefghijklmnopqrstuvwxyz
defghijklmnopqrstuvwxyzabc
```

#### 2. Scytale Cipher (`scytale.cpp`)
Implements the ancient [scytale](https://en.wikipedia.org/wiki/Scytale) cipher using grid-based transposition.

**Usage:** `./scytale [-ed] [key]`
- `key` must be greater than zero (represents circumference)

**Example:**
```bash
./scytale -e 3
'Twas brillig, and the slithy toves
'glT,iw taahsny d b trtoihvleel sis·
```

#### 3. Substitution Cipher (`substitution.cpp`)
Uses a [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher) with a custom 26-letter key.

**Usage:** `./substitution [-ed] [key]`
- `key` must contain each letter of the alphabet exactly once

**Example:**
```bash
./substitution -e egjhvakrzxpsynbtudmqiclfow
Outside of a dog, a book is man's best friend.
Bqmzhv ba e hbk, e gbbp zm yen'm gvmq adzvnh.
```

#### 4. Scrabble Word Checker (`scrabble.cpp`)
Determines if words can be formed from a given set of letters, like in [Scrabble](https://en.wikipedia.org/wiki/Scrabble).

**Usage:** `./scrabble [letters]`

**Example:**
```bash
./scrabble Gyroscope
goop
goop: Yes
poses
poses: No
```

### How to Build and Run

#### For Cipher Programs:
1. Navigate to the ciphers project folder
2. Compile each program:
   ```bash
   g++ -o caesar caesar.cpp
   g++ -o scytale scytale.cpp
   g++ -o substitution substitution.cpp
   g++ -o scrabble scrabble.cpp
   ```
3. Run with appropriate command line arguments (see individual usage above)

#### Input Methods:
- All cipher programs read from standard input line by line
- To signal end of input:
  - **Linux/Mac/WSL:** `Ctrl+D`
  - **Windows:** `Ctrl+Z` followed by `Enter`

### Key Programming Concepts Demonstrated

**Poker Project:**
- Custom data structures and dynamic memory management
- Object-oriented design with clean header/source separation
- Algorithm implementation for game logic

**Cipher Project:**
- Array and string manipulation
- Command line argument processing
- File I/O and stream processing
- Modular arithmetic for cryptographic operations

### Error Handling
All programs include proper error handling and will display usage messages for invalid arguments, exiting with code 1 to indicate errors.

---

## Repository Structure
```
repository/
├── poker/                 # Poker hand evaluator project
│   ├── [source files]
│   └── [header files]
├── ciphers/              # Cipher and Scrabble programs
│   ├── caesar.cpp
│   ├── scytale.cpp
│   ├── substitution.cpp
│   └── scrabble.cpp
└── README.md            # This file
```

## Getting Started
1. Clone this repository
2. Choose the project you want to explore
3. Navigate to the appropriate folder
4. Follow the build instructions for that specific project
5. Run and experiment with the programs!

Both projects are great for learning C++ fundamentals, from basic syntax and arrays to more advanced concepts like dynamic memory management and object-oriented programming.
