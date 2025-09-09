#pragma once
#include <limits> // for std::numeric_limits

void ignoreLine();

// returns true if extraction failed, false otherwise
bool clearFailedExtraction();

// returns true if std::cin has unextracted input on the current line, false otherwise
bool hasUnextractedInput();