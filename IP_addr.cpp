#include "IP_addr.h"

IP_addr::IP_addr(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4)
{
	p1 = part1;
	p2 = part2;
	p3 = part3;
	p4 = part4;
}

bool operator<(const IP_addr& addr1, const IP_addr& addr2) noexcept
{
	if (addr1.p1 == addr2.p1)
	{
		if (addr1.p2 == addr2.p2)
		{
			if (addr1.p3 == addr2.p3)
			{
				if (addr1.p4 == addr2.p4)
				{
					return false;
				}
				else
					return addr1.p4 < addr2.p4;
			}
			else
				return addr1.p3 < addr2.p3;
		}
		else
			return addr1.p2 < addr2.p2;
	}
	else
		return addr1.p1 < addr2.p1;
}
