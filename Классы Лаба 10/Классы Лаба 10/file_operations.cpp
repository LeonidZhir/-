#include "file_operations.h"

void saveToFile(const std::vector<Money>& records, const std::string& filename) 
{
    std::ofstream outFile(filename, std::ios::binary);
    for (const auto& record : records) 
    {
        outFile.write(reinterpret_cast<const char*>(&record), sizeof(record));
    }
    outFile.close();
}

std::vector<Money> loadFromFile(const std::string& filename) 
{
    std::vector<Money> records;
    std::ifstream inFile(filename, std::ios::binary);
    Money record;
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record)))
    {
        records.push_back(record);
    }
    inFile.close();
    return records;
}

void removeRecords(std::vector<Money>& records, const Money& k1, const Money& k2) 
{
    records.erase(std::remove_if(records.begin(), records.end(), [&](const Money& m) 
        {
        return (m < k1 || m > k2);
        }), records.end());
}

void doubleRecords(std::vector<Money>& records) 
{
    for (auto& record : records) 
    {
        long r = record.getRubles();
        int k = record.getKopecks() * 2;
        if (k >= 100) 
        {
            r += k / 100;
            k %= 100;
        }
        record.setRubles(r);
        record.setKopecks(k);
    }
}

void addRecords(std::vector<Money>& records, const Money& newRecord, int count)
{
    for (int i = 0; i < count; ++i) 
    {
        records.insert(records.begin(), newRecord);
    }
}