/**
 * 
 * @author shovon
 * 
**/
public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Al Jubair Shovon");
         //__________ Learning __________//
        
        //___ Operators ___//
        /***
         * 1. Arithmetic -> (Binary-> +, -, *, /, %), (Unary -> ++, --, +, -, ~, !)
         * 2. Relational -> ==, <, >, <=, >=, !=
         * 3. Logical -> &&, ||, !
         *      (&&-> when all expression is true, then return true;
         *       ||-> when only one expression is true, then return true)
         * 4. Assignment -> =, +=, -=, *=, /=
         * 5. Bit wise -> &, |, ~, ^,. <<, >>,
         *      (&/Biwise and -> It multiplies multiple operands as binary.
         *      |/Bitwise or -> It addition multiple operands as binary.
         *      ^/Xor -> .
         *      <</Left shift-> .
         *      >>/Right shift-> .
         *      ~/Inverse-> .)
         * 6. Conditional -> ?, : (It also called ternary operator)
         * 7. Special -> , . Instance of 
         *      (,/comma-> Used to separate different variables of the same data type.
         *      Instance of-> Used to check whether an object belongs to a class.
         *      ./Dot-> Used to access the instance variable/method of a class.)
         * 
        ***/
        
        
        //___ Ternary operator ___//
        /*
        int a = 5, b = 0, c;
        c = (a>b) ? a:b;
        System.out.println(c);
        */
        
        //___ Increment/Decrement ___//
        /***
         * 1. Prefix -> ++x, --x, (First of all add/remove 1 & then execute)
         * 2. Postfix -> x++, x--, (First of all execute & then add/remove 1)
        ***/
        
        
        //___ Data type ___//
        /***
         * 1. Primitive -> int, float, double, char, boolean, long, short, byte
         * 2. Non primitive -> array, String, class, interface
        ***/
        
        
        //___ Type casting ___//
        /***
         * 1. Implicit(auto) -> byte->short->char->int->float->double (smaller - larger)
         * 2. Explicit(manual) -> double->float->long->int->char->short->byte (larger - smaller)
        ***/
        /* Implicit */
        /*
        short shortData = 12345;
        int shortToInt = shortData; // short - integer
        System.out.println(shortToInt);
        */        
        /* Explicit */
        /*Inherited
        double doubleData = 10.123456789;
        short doubleToShort = (short) doubleData;
        float doubleToFloat = (float) doubleData;
        System.out.println(doubleToShort);
        System.out.println(doubleToFloat);
        */
        
        
        //___ Get user input ___//
        /*
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a value : ");
        float floatData = input.nextFloat();
        char charData = input.next().charAt(0);
        System.out.println(charData);
        */
        
        
        //___ Loop ___//
        /***
         * There are 3 type of loop.
         * 1. For loop
         * 2. While loop
         * 3. Do while loop
         * Labeled loop => This used for naming in any loop.
         * 
         * For loop Syntax =>
         * for(int i=1; i<=5; i++/i+=1) {};
         * 
         * While loop Syntax =>
         * int = 1;
         * while(i<=5) {
         * i++/i+=1;
         * }
         * 
         * Do while loop Syntax =>
         * int i = 1;
         * do {
         * i++/i+=1;
         * } while(i<=5)
         * 
         * Labeled loop syntax =>
         * MyLoop : for(int i=1; i<=5; i++/i+=1) {};
        ***/
        
        
        //___ Array ___//
        /*
        int roll[] = {1,2,3,4,5};
        System.out.println(roll[2]);
        System.out.println(roll.length); // It return array length
        */
        
        
        //___ Math function ___//
        /*
        System.out.println("Maximum = " + Math.max(10, 20));
        System.out.println("Minmum = " + Math.min(10, 20));
        System.out.println("Absulute = " + Math.abs(-20));
        System.out.println("Squre root = " + Math.sqrt(16));
        System.out.println("Cube root = " + Math.cbrt(100));
        System.out.println("Random = " + Math.random());
        */
                
        
        //___ Static keyword ___//
        /***
         * Why we use it?
         *  1. Mainly use of memory management (It use one memory space)
         *  2. If we use static, no need instance or object
        ***/
        
        
    //_____ Java OOP _____//
        /***
         * ==> OOP concepts
         * 1. Class
         * 2. Object
         * 3. Constractor Method
         * 4. Abstraction
         * 5. Inheritance
         * 6. Interface
         * 7. Method overloading
         * 8. Encapsulation
         * 9. Polymorphism
         * 
         * => Additional Concepts
         * 1. Instance variable
        ***/
        //___ 1. Class ___//
        /* class Cars {
            String carName;
            int carPrice;
            public void details() {}
        } */

        //___ 2. Object ___//
        /* Cars c = new Cars();
        c.carName = "BMW"
        c.carPrice = 5000000
        c.details(); */
        
        //___ 3. Constractor ___//
        /***
         * It's like a methood with same name of class. It has no return type. 
            - Their are 3 types of constractor :
            a. Default, b. Simple, c. Parametarize
            
         * Syntax -> 
         * class constract {
             public constract() {}
           }
        ***/
        /* Constractor methood */
        //Constractor Constract = new Constractor("Shovon", 20, "Male");
        
        //___ Copy Constractor ___//
        //Copy_Constractor copy = new Copy_Constractor();
        //copy.Copy_Constractor();
        //copy.Copy_Constractor(copy);
        
        
        //___ 4. Abstraction ___//
        /***
         * => When the abstract keyword is placed in front of a class or method, the                    object of that class cannot be created and used. That class inherits from                  another class and creates and uses objects of that class.
         * => Abstract method don't have any body part. You can create body in inherited                class.
        ***/
        /* Abstract class */
        //Abstract_inherit abs = new Abstract_inherit();
        //abs.abstract_method();
        
        
        /* 5. Inheritance */
        /***
         * Syntax => 
         * public class ChildClass extends SupperClass {}
        ***/
//        Multilavel_Inheritance in = new Multilavel_Inheritance();
//        in.display();
        
        
        /* 6. Interface */
        /***
         * Syntax => 
         * interface ClassName {
         *  void MethodName();
         * }
         * 
         * => This method don't have any body part.
        ***/
        /* Interface */
        //Interface_Helper interHelp = new Interface_Helper();
        //interHelp.interface_method();
        
        
        /* 7 Method overloading */
        /*** 
         * When the same class has multiple methods with the same name with different argument type and number of arguments, it is called method overloading.
        ***/
        
        /* 9. Polymorphism */
//        Polymorphism poly = new Polymorphism();
//        poly.demo("Polymorphism");
//        poly.demo(2,3);
        
        
        
        /* ==> Additional Concepts <== */
        //___ 1. Instance variable ___//
//        Instance_variable InsVar = new Instance_variable();
//        InsVar.add();
        
        
        
    //__________ Program__________// 
     
    /*** Prime number ***/
    //Prime_number prime = new Prime_number();
        //prime.check_prime_number();
        //prime.prime_number_seris();
        
        
    /*** Multiplier Table ***/
    //Multiplier_Table mul = new Multiplier_Table();
    //mul.Multiplier();
            
        
    /*** Some program ***/
    //My_class all_program = new My_class();
    
        /* Program using if else */
        //all_program.program_using_if_else();
        
        /* Program using switch */
        //all_program.program_using_switch();
        
        /* Program for seris addition */
        //all_program.seris_addition();
        
        /* Program for even seris addition */
        //all_program.even_seris_addition();
        
        /* Program for factorial */
        //all_program.factorial();
        
        /* Program for 1-100 Prime number */
        //all_program.prime_number_1_100();
        
        /* Program for even/odd  number */
        //all_program.even_odd();
        
        /* Program for Fibonacci seris */
        //all_program.fibonacci();
        
        /* Print digit */
        //all_program.PrintDigit();
        
        /* Print A-Z */
        //all_program.A_Z_Print();
        
        /* Swapping two numbers */
        //Swapping_Two_Numbers swap = new Swapping_Two_Numbers();

    
       
    }
}