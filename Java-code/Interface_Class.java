/**
 * 
 * @author shovon
 * 
**/
interface Interface_Class {
    public void interface_method();
}

class Interface_Helper implements Interface_Class {
    public void interface_method() {
        System.out.println("This is interface.");
    }
}
