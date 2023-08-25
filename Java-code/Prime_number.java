/**
 * 
 * @author shovon
 * 
**/
public class Prime_number extends Scanner_class {
    
    public void check_prime_number() {
        System.out.print("Enter a number for check prime number : ");
        int num = input.nextInt();
        int count = 0;
        
        for(int i=2; i<num; i++) {
            if(num % i == 0) {
                count++;
                break;
            }
        }
        if(count == 0) {
            System.out.println(num + " is a prime number.");
        } else {
            System.out.println(num + " is not a prime number.");
        }
    }
    
    public void prime_number_seris() {
        System.out.print("Enter a number for check prime number seris : ");
        int num = input.nextInt();
        int count = 0;
        
        for(int i=2; i<num; i++) {
            for(int j=2; j<i; j++) {
                if(i % j == 0) {
                    count++;
                    break;
                }
            }
            if(count == 0) {
                System.out.print(i + " " );
            }
            count = 0;
        }
    }
    
    public void sum_prime_number_siris() {
        System.out.print("Enter a number : ");
        int num = input.nextInt();
        int sum = 0;
        boolean flag = false;
        
        for(int i=2; i<num; i++) {
            for(int j=2; j<i; j++) {
                if(i % j == 0) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                System.out.print(i + " ");
                sum = sum + i;
            }
            flag = false;
        }
        System.out.print("Sum = " + sum);
    }

    
    
}
