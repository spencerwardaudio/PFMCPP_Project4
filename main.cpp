/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A {};

struct HeapA
{
    A* a1; 
    
    HeapA() : a1 ( new A() )
    {

    }
    ~HeapA()
    {
        delete a1;  
        a1 = nullptr;
    }

};


 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!

*/

// #include <iostream>

// int main()
// {   
//     //testing instruction 0
//     HeapA heapA; 

//     //assign heap primitives
//     FloatType ft ( 2.0f );
//     DoubleType dt ( 2 );
//     IntType it ( 2 ) ;

//     std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
//     std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
//     std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
//     std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

//     std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
//     std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
//     std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
//     std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

//     std::cout << "IntType add result=" << it.add(2).value << std::endl;
//     std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
//     std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
//     std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
//     std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

//         // FloatType object instanciation and method tests
//     // --------
//     std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
//     std::cout << "---------------------\n" << std::endl; 
    
//     // DoubleType/IntType object instanciation and method tests
//     // --------
//     std::cout << "Initial value of dt: " << dt.value << std::endl;
//     std::cout << "Initial value of it: " << it.value << std::endl;
//     // --------
//     std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
//     std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

//     std::cout << "---------------------\n" << std::endl; 
    
//     // Intercept division by 0
//     // --------
//     std::cout << "Intercept division by 0 " << std::endl;
//     std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
//     std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
//     std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

//     std::cout << "---------------------\n" << std::endl; 

//     std::cout << "good to go!\n";

//     return 0;
// }



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>

struct FloatType 
{
    float* value;

    FloatType(float fTValue) : value( new float (fTValue){}
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    FloatType& add( float rhs);
    FloatType& subtract(float rhs);
    FloatType& multiply(float rhs);
    FloatType& divide(float rhs);

    FloatType& add(FloatType& fType);
    FloatType& subtract(FloatType& fType);
    FloatType& multiply(FloatType& fType);
    FloatType& divide(FloatType& fType);

    FloatType& add(DoubleType& dType);
    FloatType& subtract(DoubleType& dType);
    FloatType& multiply(DoubleType& dType);
    FloatType& divide(DoubleType& dType);

    FloatType& add(IntType& iType);
    FloatType& subtract(IntType& iType);
    FloatType& multiply(IntType& iType);
    FloatType& divide(IntType& iType);
};

//------------------------------------------------

struct DoubleType 
{
    double* value;

    DoubleType(double dTValue) : value( new double (dTValue){}
    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add(double rhs);
    DoubleType& subtract(double rhs);
    DoubleType& multiply(double rhs);
    DoubleType& divide(double rhs);

    DoubleType& add(FloatType& fType);
    DoubleType& subtract(FloatType& fType);
    DoubleType& multiply(FloatType& fType);
    DoubleType& divide(FloatType& fType);

    DoubleType& add(DoubleType& dType);
    DoubleType& subtract(DoubleType& dType);
    DoubleType& multiply(DoubleType& dType);
    DoubleType& divide(DoubleType& dType);

    DoubleType& add(IntType& iType);
    DoubleType& subtract(IntType& iType);
    DoubleType& multiply(IntType& iType);
    DoubleType& divide(IntType& iType);
};

//------------------------------------------------

struct IntType 
{

    int* value;

    IntType(int iTValue) : value( new int (iTValue){}
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    int add(int lhs,int rhs);
    int subtract(int lhs,int rhs);
    int multiply(int lhs,int rhs);
    int divide(int lhs,int rhs);

    IntType& add(FloatType& fType);
    IntType& subtract(FloatType& fType);
    IntType& multiply(FloatType& fType);
    IntType& divide(FloatType& fType);

    IntType& add(DoubleType& dType);
    IntType& subtract(DoubleType& dType);
    IntType& multiply(DoubleType& dType);
    IntType& divide(DoubleType& dType);

    IntType& add(IntType& iType);
    IntType& subtract(IntType& iType);
    IntType& multiply(IntType& iType);
    IntType& divide(IntType& iType);
};

//------------------------------------------------

FloatType& FloatType::add(float rhs)
{
    *value += rhs;
    return  *this;
}

FloatType& FloatType::subtract(float rhs)
{
    *value -= rhs;
    return  *this;
}

FloatType& FloatType::multiply(float rhs)
{
    *value *= rhs;
    return  *this;
}

FloatType& FloatType::divide(float rhs)
{
    if (rhs == 0.f)
    { 
        std::cout << " " << std::endl;
        std::cout << "warning, floating point division by zero returns 'inf' !" << std::endl; 
    }

    *value /= rhs;
    return  *this;
}

//------------------------------------------------

FloatType& add(FloatType& fType)
{
    return add(*fType.value);
}
FloatType& subtract(FloatType& fType)
{
    return subtract(*fType.value);
}
FloatType& multiply(FloatType& fType)
{
    return multiply(*fType.value);
}
FloatType& divide(FloatType& fType)
{
    return divide(*fType.value);
}

//------------------------------------------------

FloatType& add(DoubleType& dType)
{
    return add(*dType.value);
}
FloatType& subtract(DoubleType& dType)
{
    return subtract(*dType.value);
}
FloatType& multiply(DoubleType& dType)
{
    return multiply(*dType.value);
}
FloatType& divide(DoubleType& dType)
{
    return divide(*dType.value);
}

//------------------------------------------------

FloatType& add(IntType& iType)
{
    return add(*iType.value);
}
FloatType& subtract(IntType& iType)
{
    return subtract(*iType.value);
}
FloatType& multiply(IntType& iType)
{
    return multiply(*iType.value);
}
FloatType& divide(IntType& iType)
{
    return divide(*iType.value);
}

//------------------------------------------------


DoubleType& DoubleType::add(double rhs)
{
    *value += rhs;
    return  *this;
}

DoubleType& DoubleType::subtract(double rhs)
{
    *value -= rhs;
    return  *this;
}

DoubleType& DoubleType::multiply(double rhs)
{
    *value *= rhs;
    return  *this;
}

DoubleType& DoubleType::divide(double rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << " " << std::endl;
        std::cout << "warning, floating point division by zero returns 'inf' !" << std::endl; 
    } 
    
    *value /= rhs;
    return  *this;
}

//------------------------------------------------

DoubleType& add(FloatType& fType)
{
    return add(*fType.value);
}
DoubleType& subtract(FloatType& fType)
{
    return subtract(*fType.value);
}
DoubleType& multiply(FloatType& fType)
{
    return multiply(*fType.value);
}
DoubleType& divide(FloatType& fType)
{
    return divide(*fType.value);
}

//------------------------------------------------

DoubleType& add(DoubleType& dType)
{
    return add(*dType.value);
}
DoubleType& subtract(DoubleType& dType)
{
    return subtract(*dType.value);
}
DoubleType& multiply(DoubleType& dType)
{
    return multiply(*dType.value);
}
DoubleType& divide(DoubleType& dType)
{
    return divide(*dType.value);
}

//------------------------------------------------

DoubleType& add(IntType& iType)
{
    return add(*iType.value);
}
DoubleType& subtract(IntType& iType)
{
    return subtract(*iType.value);
}
DoubleType& multiply(IntType& dType)
{
    return multiply(*iType.value);
}
DoubleType& divide(IntType& iType)
{
    return divide(*iType.value);
}

//------------------------------------------------

IntType& IntType::add(int rhs)
{
    *value += rhs;
    return  *this;
}

IntType& IntType::subtract(int rhs)
{
    *value -= rhs;
    return  *this;
}

IntType& IntType::multiply(int rhs)
{
    *value *= rhs;
    return  *this;
}

IntType& IntType::divide(int rhs)
{
    if (rhs == 0)
    {
        std::cout << "error, integer division by zero will crash the program!" << std::endl;
        std::cout << "returning lhs" << std::endl;
        return lhs; 
    } 

    *value /= rhs;
    return  *this;
}

IntType& add(FloatType& fType)
{
    return add(*fType.value);
}
IntType& subtract(FloatType& fType)
{
    return subtract(*fType.value);
}
IntType& multiply(FloatType& fType)
{
    return multiply(*fType.value);
}
IntType& divide(FloatType& fType)
{
    return divide(*fType.value);
}

//------------------------------------------------

IntType& add(DoubleType& dType)
{
    return add(*dType.value);
}
IntType& subtract(DoubleType& dType)
{
    return subtract(*dType.value);
}
IntType& multiply(DoubleType& dType)
{
    return multiply(*dType.value);
}
IntType& divide(DoubleType& dType)
{
    return divide(*dType.value);
}

//------------------------------------------------

IntType& add(IntType& iType)
{
    return add(*iType.value);
}
IntType& subtract(IntType& iType)
{
    return subtract(*iType.value);
}
IntType& multiply(IntType& dType)
{
    return multiply(*iType.value);
}
IntType& divide(IntType& iType)
{
    return divide(*iType.value);
}



int main() 
{
    FloatType ft;
    std::cout << "result of ft.add(): " << ft.add( 123.456f, 432.1f) << std::endl;
    // std::cout << "result of ft.subtract(): " << ft.subtract( 123.456f, 432.1f) << std::endl;
    // std::cout << "result of ft.multiply(): " << ft.multiply( 123.456f, 432.1f) << std::endl;
    // std::cout << "result of ft.divide(): " << ft.divide( 123.456f, 432.1f) << std::endl;

    // std::cout << "result of ft.add(): " << ft.add( 4444.56f, 0.0f)  << std::endl;
    // std::cout << "result of ft.subtract(): " << ft.subtract( 4444.56f, 0.0f) << std::endl;
    // std::cout << "result of ft.multiply(): " << ft.multiply( 4444.56f, 0.0f) << std::endl;
    // std::cout << "result of ft.divide(): " << ft.divide( 4444.56f, 0.0f) << std::endl;

    // DoubleType db;
    // std::cout << "result of db.add(): " << db.add( 123.456, 432.1) << std::endl;
    // std::cout << "result of db.subtract(): " << db.subtract( 123.456, 432.1) << std::endl;
    // std::cout << "result of db.multiply(): " << db.multiply( 123.456, 432.1) << std::endl;
    // std::cout << "result of db.divide(): " << db.divide( 123.456, 432.1) << std::endl;

    // std::cout << "result of db.add(): " << db.add( 123.456, 0.0) << std::endl;
    // std::cout << "result of db.subtract(): " << db.subtract( 123.456, 0.0) << std::endl;
    // std::cout << "result of db.multiply(): " << db.multiply( 123.456, 0.0) << std::endl;
    // std::cout << "result of db.divide(): " << db.divide( 123.456, 0.0) << std::endl;

    // IntType i;
    // std::cout << "result of i.add(): " << i.add( 10, 20) << std::endl;
    // std::cout << "result of i.subtract(): " << i.subtract( 10, 20) << std::endl;
    // std::cout << "result of i.multiply(): " << i.multiply( 10, 20) << std::endl;
    // std::cout << "result of i.divide(): " << i.divide( 10, 20) << std::endl;

    // std::cout << "result of i.add(): " << i.add( 10, 0) << std::endl;
    // std::cout << "result of i.subtract(): " << i.subtract( 10, 0) << std::endl;
    // std::cout << "result of i.multiply(): " << i.multiply( 10, 0) << std::endl;
    // std::cout << "result of i.divide(): " << i.divide( 10, 0) << std::endl;

    std::cout << "good to go!" << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you should have no errors or warnings.


clang++ -std=c++17 -Weverything -Wno-c++98-compat -Wno-missing-prototypes main.cpp && ./a.out
result of ft.add(): 555.556
result of ft.subtract(): -308.644
result of ft.multiply(): 53345.3
result of ft.divide(): 0.285712
result of ft.add(): 4444.56
result of ft.subtract(): 4444.56
result of ft.multiply(): 0
result of ft.divide(): 
warning, floating point division by zero returns 'inf' !
inf
result of db.add(): 555.556
result of db.subtract(): -308.644
result of db.multiply(): 53345.3
result of db.divide(): 0.285712
result of db.add(): 123.456
result of db.subtract(): 123.456
result of db.multiply(): 0
result of db.divide(): 
warning, floating point division by zero returns 'inf' !
inf
result of i.add(): 30
result of i.subtract(): -10
result of i.multiply(): 200
result of i.divide(): 0
result of i.add(): 10
result of i.subtract(): 10
result of i.multiply(): 0
result of i.divide(): error, integer division by zero will crash the program!
returning lhs
10
good to go!
*/
