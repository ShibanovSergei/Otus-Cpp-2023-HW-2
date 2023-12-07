#include <stdint.h>

struct IP_addr
{
	uint8_t p1, p2, p3, p4; // parts of IP address.
	friend bool operator < (const IP_addr& addr1, const IP_addr& addr2) noexcept;

	IP_addr(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4);
};