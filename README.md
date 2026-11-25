# Kviz

A terminal quiz game in C++. Players choose a quiz, answer multiple-choice questions, and their score is saved to a per-quiz leaderboard. Quizzes and questions are stored in an SQLite database, so new ones can be added without changing the code.

Built during my internship at ITEN Engineering, using C++20, SQLite, CMake and GoogleTest.

## Features

- Multiple quizzes, each with its own set of questions
- Questions with four answers and one correct answer
- Score tracking during the game
- Leaderboard per quiz, sorted by points (top 10)
- Quizzes, questions and results stored in SQLite
- Unit tests for questions, scoring, the database layer and the leaderboard

## Getting started

### Requirements

- A C++20 compiler
- CMake 3.20 or newer
- GoogleTest
- SQLite 3.54.1 (source amalgamation)
- The `sqlite3` command-line tool, to create the database

### SQLite

Download from [sqlite.org/download.html](https://sqlite.org/download.html):

- `sqlite-amalgamation-3540100.zip`: take `sqlite3.c` and `sqlite3.h`
- `sqlite-tools-win-x64-3540100.zip`: take `sqlite3.exe` (command-line tool)

Place the library files in `lib/sqlite/`:

```
lib/sqlite/
  sqlite3.c
  sqlite3.h
```

SQLite is compiled together with the project, so no DLL is needed.

### Create the database

The database is created from `db/kviz.sql`, which contains the tables and the starting data (quizzes and questions). From the project folder:

```
sqlite3 db/kviz.db < db/kviz.sql
```

### Build and run

```
cmake -B build
cmake --build build
./build/kviz
```

Run the program from the project folder, since it opens `db/kviz.db` by relative path.

### Run tests

```
ctest --test-dir build
```

## Project structure

```
src/
  main.cpp        entry point
  igra.h/.cpp     game flow: choosing a quiz, asking questions, scoring
  kviz.h/.cpp     a quiz and its questions
  pitanje.h/.cpp  a question with its answers
  baza.h/.cpp     SQLite access: loading quizzes and questions, saving results
tests/            GoogleTest suites
db/               SQL script for the database
lib/sqlite/       SQLite source (not included, see above)
```
