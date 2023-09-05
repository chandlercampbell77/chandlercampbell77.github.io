#pragma once
#include <string>
enum BookType { UNDECIDED, FICTION, NONFICTION };

// Parallel array pops out a string for each book type - use the boook type as an index
static const std::string bookTypeStrings[] = { "UNDECIDED","FICTION","NONFICTION" };