#include <string>
using namespace std;

int up_down(char part_name) {
	if (part_name - 'A' < 14)
		return part_name - 'A';
	else return 26 - ((part_name) -'A');
}

int solution(string name) {
	int answer = 0;
    int turn = name.size()-1;
    
    for(int i = 0; i<name.size(); i++){
        answer += up_down(name[i]);
        int index = i+1;
        while(index < name.size() && name[index] == 'A')
            index++;
        
        int a = i;
        int b = name.size() - index;
        turn = min(turn, min(2*a+b, a+2*b));
    }
    
    answer += turn;
	return answer;
}
