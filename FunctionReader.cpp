#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int priority(char & a) {
	if ((a == '+') || (a == '-')) {
		return 3;
	}
	if ((a == '*') || (a == '/')) {
		return 2;
	}
	if (a == '^') {
		return 1;
	}
}
bool znak(char & b) {
	if (b == '+') {
		return 1;
	}
	if (b == '-') {
		return 1;
	}
	if (b == '*') {
		return 1;
	}
	if (b == '/') {
		return 1;
	}
	if (b == '^') {
		return 1;
	}
	else {
		return 0;
	}
}
vector<string> split(string & a) {
	vector<string> p;
	if (a[0] == '-') { p.push_back("0"); }
	string n = "";
	a.erase(std::remove_if(a.begin(), a.end(), [](char & b) {return b == ' '; }), a.end());
	int i = 0;
	int skobka = 0;
	for (auto & g : a) {
		if (g == '(') {
			if ((n != "") && (skobka == 0)) {
				p.push_back(n);
				n = "";
			}
			skobka += 1;
			if (skobka > 1) {
				n += g;
			}
			i = 1;
		}
		else if (g == ')') {
			if (skobka - 1 > 0) {
				n += g;
			}
			skobka -= 1;
		}
		else if ((skobka == 0) && (znak(g))) {
			if (n != "") {
				p.push_back(n);
				n = "";
			}
			n += g;
			p.push_back(n);
			n = "";
		}
		else if ((skobka == 0) && (i == 1) && (n != "")) {
			p.push_back(n);
			n = "";
			n += g;
			i = 0;
		}
		else {
			n += g;
		}
	}
	p.push_back(n);

	return p;
}

struct FunctionTree {
	string p;
	FunctionTree * left = nullptr;
	FunctionTree * right = nullptr;

	FunctionTree() = default;

	friend FunctionTree Make_Tree(string b);

};

//void middle(FunctionTree & a) {
//	int k = 0;
//	int cur = 0;
//	for (int j = 0; j < r.size(); j++) {
//		if ((r[j].size == 1) && (znak(r[j][0]))) {
//			if (priority(r[j][0]) >= k) {
//				k = priority(r[j][0]);
//				a->p = r[j];
//				cur = j;
//			}
//		}
//	}
//}

FunctionTree Make_Tree(string b) 
{
	FunctionTree * tmp = new FunctionTree;
	size_t size = count(b.begin(), b.end(), '(');
	for (size_t i = 0; i < size; i++) {
		auto r = split(b);
		int k = 0;
		int cur = 0;
		for (int j = 0; j < r.size(); j++) {
			if ((r[j].size == 1) && (znak(r[j][0]))) {
				if (priority(r[j][0]) >= k) {
					k = priority(r[j][0]);
					tmp->p = r[j];
					cur = j;
				}
			}
		}
	}
}

int main() {
	string g;
	getline(cin, g);

	auto k = split(g);
	for (auto & i : k) {
		cout << i << "\n";
	}

	/*while (cin >> g) {
		vector<string> p;

		cin.ignore();
		cin.clear();
	}*/
}
