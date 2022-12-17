import java.util.Scanner;
import java.util.Stack;

public class G_v2 {
    public static void main(String args[]){

        Scanner s = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        int n = s.nextInt();
        int m=1,p=2,flag = 1;
        int supm=0;
        while(supm!=n) {
            p+=1;
            for (int i = 2; i <= p / 2; i++) {
                if (p % i == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                m += 1;
                if (m == 2) {
                    supm += 1;
                    stack.push(p);
                } else {
                    for (int i = 2; i <= m / 2; i++) {
                        if (m % i == 0) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1) {
                        supm += 1;
                        stack.push(p);
                    } else {
                        flag = 1;
                    }
                }
            } else {
                flag = 1;
            }
        }
        System.out.println(stack.pop());
    }
}