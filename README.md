# TP_S4 Repository

This repository contains the solutions for the C++ module assignments in Semester 4. Each folder represents a specific TP (Travaux Pratiques) session.

## Folder Structure

TP_S4 / TP1_Mamze_walid / main.cpp # Contains all the solutions for TP1 exercises and so on.

## How to Run the Files

Each folder contains a `main.cpp` file, which includes the solutions for all the exercises in that TP. To specify which exercise to run, a macro called `EXO` is used. This macro defines the exercise to be executed.

### Steps to Run

1. Open a terminal.
2. Navigate to the folder of the desired TP:
   ```bash
   cd path/to/TP1_Mamze_walid
3. Compile and run the file using the g++ command, specifying the exercise number (i) with the -DEXO flag. For example:
  .To run exercise 1:
   ```bash
      g++ main.cpp -DEXO=1 -o output && ./output
4.The program will execute the solution for the specified exercise.
  
