/**
 * 
 * @author shovon
 * 
**/
abstract class Abstract {
    abstract public void abstract_method();
}

class Abstract_inherit extends Abstract {
   public void abstract_method() {
        System.out.println("This is abstract class & methood.");
    }
}
