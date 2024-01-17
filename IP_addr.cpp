#include "IP_addr.h"

IP_addr::IP_addr(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4)
{
	adr[0] = part1;
	adr[1] = part2;
	adr[2] = part3;
	adr[3] = part4;
}

bool operator<(const IP_addr& addr1, const IP_addr& addr2) noexcept
{
	return addr1.adr < addr2.adr;
}

std::ostream& operator<<(std::ostream& os, const IP_addr& address)
{
	os << (short)address.adr[0] << '.' << (short)address.adr[1] << '.' << (short)address.adr[2] << '.' << (short)address.adr[3];
	return os;
}

uint8_t IP_addr::get_p1()
{
	return adr[0];
}

uint8_t IP_addr::get_p2()
{
	return adr[1];
}

uint8_t IP_addr::get_p3()
{
	return adr[2];
}

uint8_t IP_addr::get_p4()
{
	return adr[3];
}

uint8_t IP_addr::get_p(uint8_t i)
{
	return adr[i];
}
