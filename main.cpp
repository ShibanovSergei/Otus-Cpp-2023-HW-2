#include <iostream>

#include "IP_addresses.h"

using namespace std;

int main()
{
    const string fileName = "ip_filter.tsv";

    IP_addresses ip_pool;

    if (!ip_pool.ReadData(fileName))
    {
        cout << "Something wrong when read data from: " << fileName << endl;
        return 1;
    }
        
    ip_pool.BubleSort();    
    ip_pool.PrintAll();
    ip_pool.PrintSelected([](IP_addr ip) {return ip.get_p1() == 1; });
    ip_pool.PrintSelected([](IP_addr ip) {return ip.get_p(0) == 46 && ip.get_p(1) == 70; });
    ip_pool.PrintSelected([](IP_addr ip) {return ip.get_p1() == 46 || ip.get_p2() == 46 || ip.get_p3() == 46 || ip.get_p4() == 46; });

	return 0;
}