import java.util.Scanner;
/**
 *
 * @author shovon
 * 
 */
public class Multiplier_Table {
    Scanner input = new Scanner(System.in);
    
    public void Multiplier() {
        System.out.print("Which table do you want : ");
        int num = input.nextInt();
        int mul = 1;
        
        System.out.println("\n>> You want to see the multiplier table of " + num +  " <<");
        for(int i=1; i<=10; i+=1) {
            mul = i * num;
            System.out.println(i +  " * " + num + " = " + mul);
        }
    }
}
