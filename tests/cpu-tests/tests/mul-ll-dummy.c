#include "trap.h"

long long mul(long long a,long long b) {
	long long ans = a*b;
	return ans;
}

int test_data[] = { 0xaeb1c2aa, 0x4500ff2b};
long long ans[] = { 0x19d29ab9db1a18e4LL, 0xea15986d3ac3088eLL, 0x1299898e2c56b139LL};

int main() {
	check(ans[1] == mul(test_data[0],test_data[1]));
	return 0;
}

