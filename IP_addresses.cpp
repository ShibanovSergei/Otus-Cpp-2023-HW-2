﻿#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
using namespace std;

#include "IP_addresses.h"

bool IP_addresses::ReadData(std::string fileName)
{
    ifstream src_file(fileName);
    if (src_file.is_open())
    {
        addresses.clear();

        string line;
        while (getline(src_file, line))
        {
            TryDecodeAndThenAdd(line);
        }
        src_file.close();
        return true;
    }
    else
        return false;
}

void IP_addresses::ReadDataFromCin()
{
    for (std::string line; std::getline(std::cin, line);)
    {
        TryDecodeAndThenAdd(line);
    }
}

void IP_addresses::PrintAll()
{
    for (IP_addr& v: addresses)
    {
        cout << v << endl;
    }
}

void IP_addresses::PrintSelected(bool(*predicat)(IP_addr))
{
    for (IP_addr& v : addresses)
    {
        if (predicat(v))
            cout << v << endl;
    }
}

void IP_addresses::BubleSort()
{
    bool swappedFlag = false;
    size_t n = addresses.size();

    for (size_t i = 1; i < n; i++)
    {
        swappedFlag = false;

        for (size_t j = 0; j < n - i; j++)
        {
            if(addresses[j] < addresses[j+1])
            {
                swap(addresses[j], addresses[j + 1]);               
                swappedFlag = true;
            }
        }
        
        if (!swappedFlag)
            break;
    }
}

void IP_addresses::TryDecodeAndThenAdd(const std::string& line)
{
    try
    {
        auto parts = StrToIPParts(line);
        addresses.push_back(IP_addr(std::get<0>(parts), std::get<1>(parts), std::get<2>(parts), std::get<3>(parts)));
    }
    catch (...)
    {
        cout << "for line: " << line << " trown exception" << endl;
    }
}

// If any invalidations present in str - exception wil be trown.
std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> IP_addresses::StrToIPParts(const std::string& str)
{
    uint8_t parts[3];
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of('.');

    for (uint8_t i = 0; i < 3; ++i)
    {
        if (stop == std::string::npos)
            throw invalid_argument(std::string("uncorrect IP address:") + str);

        parts[i] = stoi(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of('.', start);
    }

    uint8_t part3 = stoi(str.substr(start));

    return make_tuple(parts[0], parts[1], parts[2], part3);
}
