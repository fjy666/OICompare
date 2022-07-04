//Code by fjy666
//luogu-judger-enable-O2
#include <bits/stdc++.h>
using namespace std;
#define _rep(i_,a_,b_) for(int i_ = a_; i_ <= b_; ++i_)
#define mid ((L+R) >> 1)
#define get(x) (((x) - 1) / kb + 1)
#define multiCase() int testCnt = in(); _rep(curCase,1,testCnt)
typedef long long ll;

int in(void) { int x; scanf("%d", &x); return x; }
ll inl(void) { ll x; scanf("%lld", &x); return x; }
template<typename T> void chkmax(T &a, const T &b) { a = max(a, b); } 
template<typename T> void chkmin(T &a, const T &b) { a = min(a, b); } 

void complie(const char *filename, const char *flag) {
	string s1 = "g++ ", s2 = ".cpp -Ofast -Wall -Wextra -o ";
	string cmd = s1 + filename + s2 + flag;
	printf("%s\n", cmd.c_str());
	system(cmd.c_str());
	puts("Successful complie!");
}

int main(int argc, char** argv) {
	if(argc == 1) {
		freopen("compare_settings.txt", "r", stdin);
		string s; cin >> s; 
		if(s != "configure_success") {
			puts("Can`t read properties, please set it before use!");
			return -1;
		}
		string a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		complie(a1.c_str(), "MySolution");
		complie(a2.c_str(), "StanderdSolution"); 
		complie(a3.c_str(), "DataGenerator"); 
	} else if(argc == 4) {
		complie(argv[1], "MySolution"); 
		complie(argv[2], "StanderdSolution"); 
		complie(argv[3], "DataGenerator"); 
	} else if(!strcmp(argv[1], "set")) {
		puts("Start to set properties...");
		if(argc != 5) {
			puts("Too much or too less argv!");
			return -1;
		}
		freopen("compare_settings.txt", "w", stdout);
		puts("configure_success");
		printf("%s\n%s\n%s\n", argv[2], argv[3], argv[4]);
		freopen("CON", "w", stdout);
		puts("Success!");
		return 0;
	} else {
		puts("Can`t understand what you meen, sorry :(");
		return -1;
	}
	int cur = 0;
	puts("Starting compare!");
	while(1) {
		system("DataGenerator>data.txt");
		system("StanderdSolution<data.txt>currect.txt");
		system("MySolution<data.txt>wrongAnswer.txt");
		printf("Case %d: ", ++cur);
		if(system("fc currect.txt wrongAnswer.txt>nul")) {
			puts("WA"); break;
		} else puts("Ac");
	}
	return 0;
}

/* 
a list of keywords
clear empty push_back pop_back push pop top front back
emplace_back emplace push_front pop_front insert erase
find count set reset bitset map vector string multiset
first second iterator prev next deque multimap reverse
sort begin end list modify query init check calc prime 
*/