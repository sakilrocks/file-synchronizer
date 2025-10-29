# file-synchronizer

A **C++17 command line tool** that synchronizes two directories by copying **new or updated files** using **multithreading** and **SHA256 hashing**. Built for speed, simplicity, and reliability.

---

## Features

- scans directories recursively  
- compares files using **SHA256 hashes**  
- multithreaded copying for high performance  
- automatically creates missing directories      

---

## Project Structure

```
file-synchronizer/
│
├── include/
│   ├── filehasher.h      # header for hashing files using SHA256
│   ├── filescanner.h     # recursive directory scanning
│   └── syncmanager.h     # manages the synchronization logic
├── src/
│   ├── main.cpp          # entry point
│   ├── filehasher.cpp    # file hashing function
│   ├── filescanner.cpp   # directory traversal & file listing
│   └── syncmanager.cpp   # threaded file copying & comparison 
├── Makefile
└── README.md

```

---

## How it works

	1.	Recursively scans both source and destination directories
	2.	Calculates SHA256 hash of each file
	3.	Compares hashes to detect new or modified files
	4.	Copies only the changed files using multiple threads

  ---

## Usage

```
./bin/filesync <source directory> <destination directory> [thread count]
```

**note: make sure you have OpenSSL lib for hashing**
