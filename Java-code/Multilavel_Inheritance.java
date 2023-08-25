/**
 *
 * @author shovon
 * 
 */
/*** Multilevel Inheritance ***/
class student {
    String name;
    int roll;
    float mark;
}
class studentInfo extends student {
    public void getInfo() {
        name = "Shovon";
        roll = 520157;
        System.out.println("Name = " + name + "\nRoll = " + roll);
    }
}
class exam extends studentInfo {
     public void examInfo() {
         mark = 3.79f;
         System.out.println("Mark = " + mark);
     }
}
public class Multilavel_Inheritance extends exam {
    public void display() {
        exam e = new exam();
        e.getInfo();
        e.examInfo();
    }
}
