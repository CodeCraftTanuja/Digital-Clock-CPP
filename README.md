 # Real-Time Digital Clock in C++

A lightweight console application built in C++ that functions as a continuous, live digital clock. It fetches system time and displays an updated time output directly inside your terminal interface.

---

## Features

- **Live Time Display:** Displays hours, minutes, and seconds updated dynamically.
- **Continuous Loop:** Runs smoothly in real time until closed by the user.
- **Clean Formatting:** Clear, readable output formatted with standard double-digit padded numbers (`00:00:00`).
- **Minimal Resource Usage:** Built using native C++ standard time libraries.

---

## Tech Stack & Libraries

- **Language:** C++
- **Standard Libraries:**
  - `<iostream>` — Displaying terminal output
  - `<chrono>` & `<ctime>` — Fetching and handling system time
  - `<thread>` — Delay management for live time updates

---

## How to Run

### Prerequisites
A standard C++ compiler such as `g++` (MinGW / GCC) or MSVC.

### Compilation and Execution

1. Open your terminal in the project directory.
2. Compile the C++ file:
   ```bash
   g++ main.cpp -o clock
