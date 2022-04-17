#include <iostream>

using namespace std;

long long N, K;


int main(void){
	cin >> N >> K;
	
	long long start = 1;
	long long end = N * N;
	
	int ans = 0;
	
	while (start <= end){
		long long mid = (start + end) / 2;
		
		long long cnt = 0;
		
		for(int i = 1; i <= N; i++){
			
			if (i > mid) break;
			
			int ind = mid / i;
			
			if (ind > N){
				cnt += N;
			}
			
			else{
				cnt += ind;
			}
		}
		
		if (cnt < K) start = mid + 1;
		
		else{
			ans = mid;
			end = mid - 1;
		}
		
	}
	cout << ans;
	
	return 0;
}