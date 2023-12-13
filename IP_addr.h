#include <stdint.h>
#include <array>
#include <iostream>
struct IP_addr
{
	IP_addr(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4);
	uint8_t get_p1();
	uint8_t get_p2();
	uint8_t get_p3();
	uint8_t get_p4();
	uint8_t get_p(uint8_t i);

	friend bool operator < (const IP_addr& addr1, const IP_addr& addr2) noexcept;
	friend std::ostream& operator<<(std::ostream& os, const IP_addr& address);

private:
	std::array<uint8_t, 4> adr; // Array of parts of IP address.
};