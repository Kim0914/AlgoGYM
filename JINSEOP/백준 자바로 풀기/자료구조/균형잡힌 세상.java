import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String targetString = br.readLine();
            Stack<Character> parenthesisValidator = new Stack<>();

            if(targetString.equals("."))
                break;

            for(int i = 0; i < targetString.length(); i++){
                if(parenthesisValidator.isEmpty() && (targetString.charAt(i) == ']' || targetString.charAt(i) == ')')) {
                    parenthesisValidator.push(targetString.charAt(i));
                    break;
                }

                if(targetString.charAt(i) == '(' || targetString.charAt(i) == '[') {
                    parenthesisValidator.push(targetString.charAt(i));
                    continue;
                }

                if(!parenthesisValidator.isEmpty() && parenthesisValidator.peek() == '('){
                    if(targetString.charAt(i) == ')')
                        parenthesisValidator.pop();
                    if(targetString.charAt(i) == ']')
                        break;

                    continue;
                }

                if(!parenthesisValidator.isEmpty() && parenthesisValidator.peek() == '['){
                    if(targetString.charAt(i) == ']')
                        parenthesisValidator.pop();
                    if(targetString.charAt(i) == ')')
                        break;

                    continue;
                }
            }

            if(!parenthesisValidator.isEmpty())
                System.out.println("no");
            else
                System.out.println("yes");
        }
    }
}
