#include <string>
using namespace std;

int up_down(char part_name) {
	if (part_name - 'A' < 14)
		return part_name - 'A';
	else return 26 - ((part_name) -'A');
}

int solution(string name) {
	int answer = 0;
    int turn = name.size()-1; // 커서가 한 쪽 방향으로만 가는 경우
    
    for(int i = 0; i<name.size(); i++){
		if(name[i] == 'A') continue; // A인 자리는 검사할 필요 없음
        answer += up_down(name[i]);
        int index = i+1; // 다음 바꿀 index
        while(index < name.size() && name[index] == 'A')
            index++; // A가 아닌 다음 문자 찾기
        
        int a = i; // 원점 ~ 현재 index
        int b = name.size() - index; // 배열 끝 ~ 다음 바꿀 index
        turn = min(turn, min(2*a+b, a+2*b));
		// (a + a) + b : 시작점 -> i -> 시작점 -> index
		// (b + b) + a : 시작점 -> index -> 시작점 -> i
    }
    
    if(answer != 0) answer += turn; // A로만 구성된 name일 때,
				    // turn을 더해주지 않도록.
	return answer;
}
