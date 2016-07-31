#include <iostream>
#include <string>
namespace a {
	int i1 = 8;
	int i2 = 9;
}

namespace b {
	int max(int n1, int n2) {
		return (n1 > n2) ? n1 : n2;
	}
}

namespace aVeryLongNamespaceName {
	using namespace std;
	string var1 = "var1";
	string var2 = "var2";
}

namespace shortn = aVeryLongNamespaceName;

int main() {
	using namespace std;
	cout << a::i1 << endl;
	cout << b::max(a::i1, a::i2) << endl;
	
	cout << shortn::var1 << endl;
	cout << shortn::var2 << endl;
}
