/**
 *
 * @author shovon
 * 
 */
public class Swapping_Two_Numbers {
    public Swapping_Two_Numbers() {
        int n1 = 43;
        int n2 = 312;
        System.out.println("Before Swapping : number one = " + n1 + " & number two = " + n2);
        
        //___ With extra variable ___//
        /*
        int temp = n1;
        n1 = n2;
        n2 = temp;
        System.out.println("After Swapping : number one = " + n1 + " & number two = " + n2);
        */
        
        
        //___ Without extra variable ___//
        n1 = n1 + n2;
        n2 = n1 - n2;
        n1 = n1 - n2;
        System.out.println("After Swapping : number one = " + n1 + " & number two = " + n2);
        
    
    }
    
}
