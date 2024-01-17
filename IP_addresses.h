#pragma once

#include <vector>
#include <iostream>

#include "IP_addr.h"

class IP_addresses
{
public:	
	bool ReadData(std::string fileName);
	void ReadDataFromCin();
	void PrintAll();
	void PrintSelected(bool (*predicat)(IP_addr));
	void BubleSort(); // Since there was no lecture on algorithms yet, simple custom sorting was added.

private:
	std::vector<IP_addr> addresses;

	// The better return IP_addr, but by the topic of the lesson made with using tuple.
	std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> StrToIPParts(const std::string& str);
	void TryDecodeAndThenAdd(const std::string& line);
};