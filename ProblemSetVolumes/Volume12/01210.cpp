#include <iostream>
#include <cstring>
#define SIZE 10050

using namespace std;

int prime[SIZE], n;
bool visit[SIZE];

void createPrime(){
    memset(visit, false, sizeof(visit));
    int count = 0;
	for (int i = 2 ; i < SIZE ; ++ i){
		if (!visit[i]) {
			prime[count++] = i;
			for (int j = i + i ; j < SIZE ; j += i)
				visit[j] = true;
		}
    }
}

int main(){
    createPrime();
    while(cin >> n && n){
        int l = 0, ans = 0, sum = 0;
		for (int r = 0 ; n >= prime[r] ; ++r) {
			sum += prime[r];
			while (sum > n) sum -= prime[l++];
			if (sum == n) ans++;
		}
		cout << ans << endl;
    }
}
