class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;

        while(a != b){
            answer++;
            
            if(a%2 == 1){
                a += 1;
            }
            
            if(b%2 == 1){
                b += 1;
            }
            
            a = a / 2;
            b = b / 2;
        }
        return answer;
    }
}