/**
 *
 * @author shovon
 * 
 */
public class Copy_Constractor {
    String a, c; int b, d;
    public void Copy_Constractor() {
        a = "Shovon";
        b = 520157;
        System.out.println("First = " + a + ", " + b);
    }
    
    public void Copy_Constractor(Copy_Constractor ref) {
        c = ref.a;
        d = ref.b;
        System.out.println("Second = " + a + ", " + b);
    }
}
