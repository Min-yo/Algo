#include <iostream>
using namespace std;

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

int hash_f(string s) {
	int p = 1;
	int q = 1e9 + 7;
	int hashed_s = 0;
	for (int i = 0; i < s.size(); i++) {
		hashed_s = (hashed_s + (s[i] - 'a' + 1) * p) % q;
		p = (p * 31) % q;
	}
	return hashed_s;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << hash_f(s1) << endl << hash_f(s2);
}

hash<std::string>{}(str);
struct S {
    std::string first_name;
    std::string last_name;
};
bool operator==(const S& lhs, const S& rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}
std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';
 