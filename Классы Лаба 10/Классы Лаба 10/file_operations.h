#pragma once
#include "Money.h"
#include <fstream>
#include <vector>
#include <string>

void saveToFile(const std::vector<Money>& records, const std::string& filename);
std::vector<Money> loadFromFile(const std::string& filename);
void removeRecords(std::vector<Money>& records, const Money& k1, const Money& k2);
void doubleRecords(std::vector<Money>& records);
void addRecords(std::vector<Money>& records, const Money& newRecord, int count);