/**
 * 
 * @author shovon
 * 
**/
public class My_class extends Scanner_class {
    
    public void program_using_if_else() {
        System.out.print("Enter your age : ");
        int age = input.nextInt();
        if(age < 0) {
            System.out.println("Please select a valid date of birth.");
        } else if(age < 18) {
            System.out.println("You are ineligible for create account.");
        } else {
            System.out.println("Account create succeded.");
        }
    }
    
    public void program_using_switch() {
        System.out.print("Enter first number : ");
        int n1 = input.nextInt();
                
        System.out.print("Enter second number : ");
        int n2 = input.nextInt();
        
        System.out.println("You can +, -, *, /.");
        System.out.print("Enter a operator : ");
        String operator = input.next();
        
        switch(operator) {
            case "+" :
                System.out.println("Sum = " + (n1+n2));
                break;
            case "-" :
                System.out.println("Sub = " + (n1-n2));
                break;
            case "*" :
                System.out.println("Sub = " + (n1*n2));
                break;
            case "/" :
                System.out.println("Sub = " + (n1/n2));
                break;
            default :
                System.out.println("Enter valid operator.");
        }
        
    }
    
    public void seris_addition() {
        System.out.print("Enter a number : ");
        int num = input.nextInt();
        int sum = 0;
        
        int i = 1;
        while(i<=num) {
            System.out.print(i + " ");
            sum = sum + i;
            i++;
        }
        System.out.println("\nSum = " + sum);
        
    }
    
    public void even_seris_addition() {
        System.out.print("Enter a number : ");
        int num = input.nextInt();
        int sum = 0;
        
        for(int i=2; i<=num; i+=2) {
            System.out.print(i + " ");
            sum = sum + i;
        }
        System.out.println("\nSum = " + sum);
    }
    
    public void factorial() {
        System.out.print("Enter a number : ");
        int num = input.nextInt();
        double fact = 1;
        
        for(int i=1; i<=num; i++) {
            System.out.print(i + " ");
            fact = fact * i;
        }
        System.out.println("\n" + num + "! = " + fact);
    }
    
    public void prime_number_1_100() {
        int num = 100;
        int count = 0;
        
        for(int i=2; i<num; i++) {
            for(int j=2; j<i; j++) {
                if(i % j == 0) {
                    count++;
                    break;
                }
            }
            if(count == 0) {
                System.out.print(i);
            }
            count = 0;
        }
    }
    
    public void even_odd() {
        System.out.print("Enter a number : ");
        int num = input.nextInt();
        if(num % 2 == 0) {
            System.out.println("This number is even.");
        } else {
            System.out.println("This number is odd.");
        }
    }
    
    public void fibonacci() {
        int firstNumber = 0;
        int secondNumber = 1;
        int fibo;
        System.out.print(firstNumber + " ");
        for(int i=0; i<=10; i++) {
            fibo = firstNumber + secondNumber;
            System.out.print(fibo + " ");
            secondNumber = firstNumber;
            firstNumber = fibo;
        }
    }
    
    public void PrintDigit() {
        int num = 123;
        while(num>0) {
            System.out.println(num % 10);
            num = num / 10;
        }
    }
    
    public void A_Z_Print() {
        char ch = 'A';
        do {
            System.out.print(" "+ ch + " ");
            ch++;
        } while((ch<='Z'));
    }
    
    
    
    
    
    
    
    
}
