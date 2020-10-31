
#include <iostream>
/*
Project 4: Part 7 / 9
Video: Chapter 5 Part 4

Create a branch named Part7

Do not delete your previous main. you will be adding to it.

Templates and Containers

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
    it's very easy to mess this task up. 

0) comment out part6(), both the function and where it is called.

#1) if you're not using std::unique_ptr to own your heap-allocated type as a member variable, 
    replace your manual memory management techniques with a private std::unique_ptr member variable.

#2) replace your Heap-Allocated Numeric Type-owning classes with a single templated class called 'Numeric'.
        replace all instances of your previous classes (IntType, etc) with this templated class.

#3) add a 'using Type = <your class template parameter>;' 
        treat this type declaration via 'using' as a static member variable
        use this Type alias as the argument everywhere you previously used the template argument.
        this will make it very easy to change the type if needed.
            i.e. if you have 'std::unique_ptr<NumericType> value;' before
                you'd replace NumericType in that variable declaration with 'Type'
        
#4) you'll need to pair it with decltype() to help the compiler figure out the type of the object 
    your class owns when you make your lambda and free function that takes your unique_ptr.  
    i.e. like this for determining the template parameter of the unique_ptr function argument to your class's apply() function
        std::unique_ptr< decltype( <instance of class> )::Type >
    
#5) template your free function for the apply() that takes a function pointer so it can be used with your Wrapper class's apply() function

#6) add an explicit template specialization for 'double' of your wrapper class
        this template specialization will have one apply() function instead of 2. 

#7) this apply() function will be templated, and expect a Callable object, not std::function<>. 
        the function should allow for chaining.  
        the callable object should return void, like the function pointer-based apply() function in the primary class template

#8) instantiate your explicit template specialization

#9) call the apply function twice, once with a lambda and once with the free function
        the free function is templated, so you might need to call it including the template arguments.
        
#10) in addition to using the lambda argument to modify the owned object:  (your previous task's lambdas did this same thing) 
        make the lambda use your explicit template instance (maybe via a std::cout), 

#11) now that your class is templated, you'll need to adjust your logic in your division function to handle if your input is a zero or not, based on your templated type.  
        - look up how to use std::is_same<>::value on cppreference to determine the type of your template parameter.
        
        - look up how to use std::numeric_limits<>::epsilon() to determine if you're dividing by a floating point 0
        
        - read about Knuth's algorithm here: https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/

        - in plain-english, you'll need to implement this logic:
        if your template type is an int
                if your parameter's type is also an int
                        if your parameter is 0
                                don't do the division
                else if it's less than epsilon
                        dont do the divison
        else if it's less than epsilon
                warn about doing the division

        - to make these checks work during compilation, your if() statements will need to be 'constexpr':  if constexpr (expression)

        - pay attention to the 2nd line in the plain-english logic.
                most people don't get this part of the assignment correct.

12) move part7() to before main()
        call part7() in main(), after where you were calling part6()

If you need to view an example, see: https://bitbucket.org/MatkatMusic/pfmcpptasks/src/master/Projects/Project4/Part7Example.cpp
*/

void part7()
{
    Numeric ft3(3.0f);
    Numeric dt3(4.0);
    Numeric it3(5);
    
    std::cout << "Calling Numeric<float>::apply() using a lambda (adds 7.0f) and Numeric<float> as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;

    {
        using Type = #4;
        ft3.apply( [](std::unique...){} );
    }

    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "Calling Numeric<float>::apply() twice using a free function (adds 7.0f) and void as return type:" << std::endl;
    std::cout << "ft3 before: " << ft3 << std::endl;
    ft3.apply(myNumericFreeFunct).apply(myNumericFreeFunct);
    std::cout << "ft3 after: " << ft3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric<double>::apply() using a lambda (adds 6.0) and Numeric<double> as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;

    {
        using Type = #4;
        dt3.apply( [](std::unique...){} ); // This calls the templated apply fcn
    }
    
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "Calling Numeric<double>::apply() twice using a free function (adds 7.0) and void as return type:" << std::endl;
    std::cout << "dt3 before: " << dt3 << std::endl;
    dt3.apply(myNumericFreeFunct<double>).apply(myNumericFreeFunct<double>); // This calls the templated apply fcn
    std::cout << "dt3 after: " << dt3 << std::endl;
    std::cout << "---------------------\n" << std::endl;

    std::cout << "Calling Numeric<int>::apply() using a lambda (adds 5) and Numeric<int> as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;

    {
        using Type = #4;
        it3.apply( [](std::unique...){} );
    }
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "Calling Numeric<int>::apply() twice using a free function (adds 7) and void as return type:" << std::endl;
    std::cout << "it3 before: " << it3 << std::endl;
    it3.apply(myNumericFreeFunct).apply(myNumericFreeFunct);
    std::cout << "it3 after: " << it3 << std::endl;
    std::cout << "---------------------\n" << std::endl;    
}

/*
your program should generate the following output EXACTLY.
This includes the warnings. 
 The output should have zero warnings.


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

The result of FloatType^3 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
can't divide integers by zero!
can't divide integers by zero!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
Power tests with FloatType 
pow(ft1, floatExp) = 2^2 = 4
pow(ft1, itExp) = 4^2 = 16
pow(ft1, ftExp) = 16^2 = 256
pow(ft1, dtExp) = 256^2 = 65536
---------------------

Power tests with DoubleType 
pow(dt1, doubleExp) = 2^2 = 4
pow(dt1, itExp) = 4^2 = 16
pow(dt1, ftExp) = 16^2 = 256
pow(dt1, dtExp) = 256^2 = 65536
---------------------

Power tests with IntType 
pow(it1, intExp) = 2^2 = 4
pow(it1, itExp) = 4^2 = 16
pow(it1, ftExp) = 16^2 = 256
pow(it1, dtExp) = 256^2 = 65536
===============================

Point tests with float argument:
Point { x: 3, y: 6 }
Multiplication factor: 6
Point { x: 18, y: 36 }
---------------------

Point tests with FloatType argument:
Point { x: 3, y: 3 }
Multiplication factor: 3
Point { x: 9, y: 9 }
---------------------

Point tests with DoubleType argument:
Point { x: 3, y: 4 }
Multiplication factor: 4
Point { x: 12, y: 16 }
---------------------

Point tests with IntType argument:
Point { x: 3, y: 4 }
Multiplication factor: 5
Point { x: 15, y: 20 }
---------------------

Calling Numeric<float>::apply() using a lambda (adds 7.0f) and Numeric<float> as return type:
ft3 before: 3
ft3 after: 10
Calling Numeric<float>::apply() twice using a free function (adds 7.0f) and void as return type:
ft3 before: 10
ft3 after: 24
---------------------

Calling Numeric<double>::apply() using a lambda (adds 6.0) and Numeric<double> as return type:
dt3 before: 4
dt3 after: 10
Calling Numeric<double>::apply() twice using a free function (adds 7.0) and void as return type:
dt3 before: 10
dt3 after: 24
---------------------

Calling Numeric<int>::apply() using a lambda (adds 5) and Numeric<int> as return type:
it3 before: 5
it3 after: 10
Calling Numeric<int>::apply() twice using a free function (adds 7) and void as return type:
it3 before: 10
it3 after: 24
---------------------

good to go!


Use a service like https://www.diffchecker.com/diff to compare your output. 
*/


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
#include <cmath>
#include <memory>
#include <functional>

struct DoubleType;
struct IntType; 

struct FloatType    
{
private:
    std::unique_ptr<float> value = nullptr;
    FloatType& powInternal(const float ft);
public:
    FloatType(float fTValue) : value( std::make_unique_ptr<float> (fTValue) ){}
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    FloatType& operator+=(float rhs);
    FloatType& operator-=(float rhs);
    FloatType& operator*=(float rhs);
    FloatType& operator/=(float rhs);

    FloatType& pow(float ft);
    FloatType& pow(const FloatType& ft);
    FloatType& pow(const DoubleType& dt);
    FloatType& pow(const IntType& it);
    operator float() const { return *value; }

    FloatType& apply(std::function<FloatType&(std::unique_ptr<float>&)> f);
    FloatType& apply(void(*f)(std::unique_ptr<float>&));
};

//------------------------------------------------

struct DoubleType 
{
private:
    std::unique_ptr<double> value = nullptr;
    DoubleType& powInternal(double dt);
public:
    DoubleType(double dtValue) : value( std::make_unique_ptr<double> (dtValue) ){}
    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& operator+=(double rhs);
    DoubleType& operator-=(double rhs);
    DoubleType& operator*=(double rhs);
    DoubleType& operator/=(double rhs);

    DoubleType& pow(double dt);
    DoubleType& pow(const FloatType& ft);
    DoubleType& pow(const DoubleType& dt);
    DoubleType& pow(const IntType& it);
    operator double() const { return *value; }

    DoubleType& apply(std::function<DoubleType&(std::unique_ptr<double>&)> f);
    DoubleType& apply(void(*f)(std::unique_ptr<double>&&));
};

//------------------------------------------------

struct IntType 
{
private:
    std::unique_ptr<int> value = nullptr;
    IntType& powInternal(int it);
public:
    IntType(int itValue) : value( std::make_unique_ptr<int> (itValue) ){}
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& operator+=(int rhs);
    IntType& operator-=(int rhs);
    IntType& operator*=(int rhs);
    IntType& operator/=(int rhs);

    IntType& pow(int it);
    IntType& pow(const FloatType& ft);
    IntType& pow(const DoubleType& dt);
    IntType& pow(const IntType& it);
    operator int() const { return *value; }

    IntType& apply(std::function<IntType&(std::unique_ptr<int>&)> f);
    IntType& apply(void(*f)(std::unique_ptr<int>&&));
};

//------------------------------------------------

struct Point
{
    Point(const FloatType& a, const FloatType& b);
    Point(const DoubleType& a, const DoubleType& b);
    Point(const IntType& a, const IntType& b);

    ~Point() {}

    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }

    Point& multiply(const FloatType& input);
    Point& multiply(const DoubleType& input);
    Point& multiply(const IntType& input);

    void toString();

private:
    float x{0}, y{0};
};


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


FloatType& FloatType::operator+=(float rhs)
{
    *value += rhs;
    return *this;
}

FloatType& FloatType::operator-=(float rhs)
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::operator*=(float rhs)
{
    *value *= rhs;
    return *this;
}

FloatType& FloatType::operator/=(float rhs)
{
    if (rhs == 0.f)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    }

    *value /= rhs;
    return *this;
}

FloatType& FloatType::pow(float ft)
{
    return powInternal( ft );
}

FloatType& FloatType::powInternal(const float ft)
{
    *value = std::pow( *value, ft );
    return *this;
}

FloatType& FloatType::pow(const FloatType& ft)
{
    return powInternal(static_cast<float>(ft));
}

FloatType& FloatType::pow(const DoubleType& dt)
{
    return powInternal( static_cast<float>(dt) );
}

FloatType& FloatType::pow(const IntType& it)
{
    return powInternal( static_cast<float>(it) );
}

FloatType& FloatType::apply(std::function<FloatType&(std::unique_ptr<float>&)> f)
{
    if(f)
    {
        return f(*value);
    }

    return *this;
}

FloatType& FloatType::apply(void(*f)(std::unique_ptr<float>&))
{
    if(f)
    {
        f(*value);
    }

    return *this;
}

//------------------------------------------------

DoubleType& DoubleType::operator+=(double rhs)
{
    *value += rhs;
    return *this;
}

DoubleType& DoubleType::operator-=(double rhs)
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::operator*=(double rhs)
{
    *value *= rhs;
    return *this;
}

DoubleType& DoubleType::operator/=(double rhs)
{
    if (rhs == 0.0)
    { 
        std::cout << "warning: floating point division by zero!" << std::endl; 
    } 

    *value /= rhs;
    return *this;
}

DoubleType& DoubleType::pow(double dt)
{
    return powInternal( dt );
}

DoubleType& DoubleType::powInternal(double dt)
{
    *value = std::pow( *value, dt );
    return *this;
}

DoubleType& DoubleType::pow(const FloatType& ft)
{
    return powInternal( static_cast<double>(ft) );
}

DoubleType& DoubleType::pow(const DoubleType& dt)
{
    return powInternal( static_cast<double>(dt) );
}

DoubleType& DoubleType::pow(const IntType& it)
{
    return powInternal( static_cast<double>(it) );
}

DoubleType& DoubleType::apply(std::function<DoubleType&(std::unique_ptr<double>&)> func)
{
    if(func)
    {
        return func(*value);
    }

    return *this;
}
    
DoubleType& DoubleType::apply(void(*f)(std::unique_ptr<double>&&))
{
    if(func)
    {
        func(*value);
    }

    return *this;
}

//------------------------------------------------

IntType& IntType::operator+=(int rhs)
{
    *value += rhs;
    return *this;
}

IntType& IntType::operator-=(int rhs)
{
    *value -= rhs;
    return *this;
}

IntType& IntType::operator*=(int rhs)
{
    *value *= rhs;
    return *this;
}

IntType& IntType::operator/=(int rhs)
{
    if (rhs == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
    } 
    else
    {
        *value /= rhs;
    }

    return *this;
}

IntType& IntType::pow(int it)
{
    return powInternal( it );
}

IntType& IntType::powInternal(int it)
{
    if(this->value != nullptr)
        *value = static_cast<int> (std::pow( static_cast<double>(*value), static_cast<double>(it)));

    return *this;
}

IntType& IntType::pow(const FloatType& ft)
{
    return powInternal( static_cast<int>(ft) );
}

IntType& IntType::pow(const DoubleType& dt)
{
    return powInternal( static_cast<int>(dt) );
}

IntType& IntType::pow(const IntType& it)
{
    return powInternal( static_cast<int>(it) );
}

IntType& IntType::apply(std::function<IntType&(std::unique_ptr<int>&)> f)
{
    if(f)
    {
        return f(*value);
    }

    return *this;
}

IntType& IntType::apply(void(*f)(std::unique_ptr<int>&&))
{
    if(f)
    {
        f(*value);
    }

    return *this;
}

//------------------------------------------------

Point::Point(const FloatType& a, const FloatType& b) : x(static_cast<float>(a)), y(static_cast<float>(b)) {}

Point::Point(const DoubleType& a, const DoubleType& b) : x(static_cast<float>(a)), y(static_cast<float>(b)) {}

Point::Point(const IntType& a, const IntType& b) : x(static_cast<float>(a)), y(static_cast<float>(b)) {}

Point& Point::multiply(const FloatType& input)
{
    return multiply(static_cast<float>(input));
}

Point& Point::multiply(const DoubleType& input)
{
    return multiply(static_cast<float>(input));
}

Point& Point::multiply(const IntType& input)
{
    return multiply(static_cast<float>(input));
}

void Point::toString()
{
    std::cout << "Point { x: " << x << ", y: " << y << " }" << std::endl;
}

//------------------------------------------------

void myFloatFreeFunct(float& value)
{
    value += 7.0f;
}

void myDoubleFreeFunct(double& value)
{
    value += 6.0;
}

void myIntFreeFunct(int& value)
{
    value += 5;
}

//------------------------------------------------

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    ft *= ft;
    ft *= ft;
    ft /= static_cast<float>(it);

    std::cout << "The result of FloatType^3 divided by IntType is: " <<  ft << std::endl;

    dt *= 3;
    dt += static_cast<double>(it);

    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt << std::endl;

    it /= static_cast<int>(pi);
    it *= static_cast<int>(dt);
    it -= static_cast<int>(ft);

    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it << std::endl;

    it *= it;

    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;

    it /= 0;
    it /= static_cast<int>(0.0f); 
    it /= static_cast<int>(0.0);

    std::cout << it << std::endl;

    it *= static_cast<int>(ft);
    
    std::cout << "FloatType x IntType  =  " << it << std::endl;

    it += static_cast<int>(dt);
    it += static_cast<int>(ft);
    it *= 24;

    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it << std::endl;
}

void part4()
{
    // ------------------------------------------------------------
    //                          Power tests
    // ------------------------------------------------------------
    FloatType ft1(2);
    DoubleType dt1(2);
    IntType it1(2);    
    int floatExp = 2.0f;
    int doubleExp = 2.0;
    int intExp = 2;
    IntType itExp(2);
    FloatType ftExp(2.0f);
    DoubleType dtExp(2.0);
    
    // Power tests with FloatType
    std::cout << "Power tests with FloatType " << std::endl;
    std::cout << "pow(ft1, floatExp) = " << ft1 << "^" << floatExp << " = " << ft1.pow(floatExp)  << std::endl;
    std::cout << "pow(ft1, itExp) = " << ft1 << "^" << itExp << " = " << ft1.pow(itExp)  << std::endl;
    std::cout << "pow(ft1, ftExp) = " << ft1 << "^" << ftExp << " = " << ft1.pow(ftExp)  << std::endl;    
    std::cout << "pow(ft1, dtExp) = " << ft1 << "^" << dtExp << " = " << ft1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;  

    // Power tests with DoubleType
    std::cout << "Power tests with DoubleType " << std::endl;
    std::cout << "pow(dt1, doubleExp) = " << dt1 << "^" << doubleExp << " = " << dt1.pow(intExp)  << std::endl;
    std::cout << "pow(dt1, itExp) = " << dt1 << "^" << itExp << " = " << dt1.pow(itExp)  << std::endl;
    std::cout << "pow(dt1, ftExp) = " << dt1 << "^" << ftExp << " = " << dt1.pow(ftExp)  << std::endl;    
    std::cout << "pow(dt1, dtExp) = " << dt1 << "^" << dtExp << " = " << dt1.pow(dtExp)  << std::endl;    
    std::cout << "---------------------\n" << std::endl;    

    // Power tests with IntType
    std::cout << "Power tests with IntType " << std::endl;
    std::cout << "pow(it1, intExp) = " << it1 << "^" << intExp << " = " << it1.pow(intExp)  << std::endl;
    std::cout << "pow(it1, itExp) = " << it1 << "^" << itExp << " = " << it1.pow(itExp)  << std::endl;
    std::cout << "pow(it1, ftExp) = " << it1 << "^" << ftExp << " = " << it1.pow(ftExp)  << std::endl;    
    std::cout << "pow(it1, dtExp) = " << it1 << "^" << dtExp << " = " << it1.pow(dtExp)  << std::endl;    
    std::cout << "===============================\n" << std::endl; 

    // ------------------------------------------------------------
    //                          Point tests
    // ------------------------------------------------------------
    FloatType ft2(3.0f);
    DoubleType dt2(4.0);
    IntType it2(5);
    float floatMul = 6.0f;

    // Point tests with float
    std::cout << "Point tests with float argument:" << std::endl;
    Point p0(ft2, floatMul);
    p0.toString();   
    std::cout << "Multiplication factor: " << floatMul << std::endl;
    p0.multiply(floatMul); 
    p0.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with FloatType
    std::cout << "Point tests with FloatType argument:" << std::endl;
    Point p1(ft2, ft2);
    p1.toString();   
    std::cout << "Multiplication factor: " << ft2 << std::endl;
    p1.multiply(ft2); 
    p1.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with DoubleType
    std::cout << "Point tests with DoubleType argument:" << std::endl;
    Point p2(ft2, static_cast<float>(dt2));
    p2.toString();   
    std::cout << "Multiplication factor: " << dt2 << std::endl;
    p2.multiply(dt2); 
    p2.toString();   
    std::cout << "---------------------\n" << std::endl;

    // Point tests with IntType
    std::cout << "Point tests with IntType argument:" << std::endl;
    Point p3(ft2, static_cast<float>(dt2));
    p3.toString();   
    std::cout << "Multiplication factor: " << it2 << std::endl;
    p3.multiply(it2); 
    p3.toString();   
    std::cout << "---------------------\n" << std::endl;
}


// void part6()
// {
//     FloatType ft3(3.0f);
//     DoubleType dt3(4.0);
//     IntType it3(5);
    
//     std::cout << "Calling FloatType::apply() using a lambda (adds 7.0f) and FloatType as return type:" << std::endl;
//     std::cout << "ft3 before: " << ft3 << std::endl;
//     ft3.apply( [&](float& f) -> FloatType&
//     {
//         f += 7.0f;
//         return ft3;
//     });

//     std::cout << "ft3 after: " << ft3 << std::endl;
//     std::cout << "Calling FloatType::apply() using a free function (adds 7.0f) and void as return type:" << std::endl;
//     std::cout << "ft3 before: " << ft3 << std::endl;
//     ft3.apply(myFloatFreeFunct);
//     std::cout << "ft3 after: " << ft3 << std::endl;
//     std::cout << "---------------------\n" << std::endl;

//     std::cout << "Calling DoubleType::apply() using a lambda (adds 6.0) and DoubleType as return type:" << std::endl;
//     std::cout << "dt3 before: " << dt3 << std::endl;
//     dt3.apply( [&](double& f) -> DoubleType&
//     {
//         f += 6.0;
//         return dt3;
//     } );

//     std::cout << "dt3 after: " << dt3 << std::endl;
//     std::cout << "Calling DoubleType::apply() using a free function (adds 6.0) and void as return type:" << std::endl;
//     std::cout << "dt3 before: " << dt3 << std::endl;
//     dt3.apply(myDoubleFreeFunct);
//     std::cout << "dt3 after: " << dt3 << std::endl;
//     std::cout << "---------------------\n" << std::endl;

//     std::cout << "Calling IntType::apply() using a lambda (adds 5) and IntType as return type:" << std::endl;
//     std::cout << "it3 before: " << it3 << std::endl;
//     it3.apply( [&](int& f) -> IntType&
//     {
//         f += 5;
//         return it3;
//     } );

//     std::cout << "it3 after: " << it3 << std::endl;
//     std::cout << "Calling IntType::apply() using a free function (adds 5) and void as return type:" << std::endl;
//     std::cout << "it3 before: " << it3 << std::endl;
//     it3.apply(myIntFreeFunct);
//     std::cout << "it3 after: " << it3 << std::endl;
//     std::cout << "---------------------\n" << std::endl;    
// }


#include <iostream>

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    ft += 2.0f;

    std::cout << "FloatType add result=" << ft << std::endl;
    
    ft -= 2.0f;

    std::cout << "FloatType subtract result=" << ft << std::endl;

    ft *= 2.0f;

    std::cout << "FloatType multiply result=" << ft << std::endl;

    ft /= 16.0f;   

    std::cout << "FloatType divide result=" << ft << std::endl << std::endl;

    dt += 2.0;

    std::cout << "DoubleType add result=" << dt << std::endl;

    dt -= 2.0;

    std::cout << "DoubleType subtract result=" << dt << std::endl;

    dt *= 2.0;

    std::cout << "DoubleType multiply result=" << dt << std::endl;

    dt /= static_cast<double>(5.f);

    std::cout << "DoubleType divide result=" << dt << std::endl << std::endl;

    it += 2;

    std::cout << "IntType add result=" << it << std::endl;

    it -= 2;

    std::cout << "IntType subtract result=" << it << std::endl;

    it *= 2;

    std::cout << "IntType multiply result=" << it << std::endl;

    it /= 3;

    std::cout << "IntType divide result=" << it << std::endl << std::endl;

    it *= 1000;
    it /= 2;
    it -= 10;
    it += 100;

    std::cout << "Chain calculation = " << it << std::endl;

        // FloatType object instanciation and method tests
    // --------

    ft += 3.0f;
    ft *= 1.5f;
    ft /= 5.0f;

    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt << std::endl;
    std::cout << "Initial value of it: " << it << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;

    dt *= static_cast<double>(it);
    dt /= static_cast<double>(5.0f);
    dt += static_cast<double>(ft);

    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;

    std::cout << "New value of it = it / 0 = ";

    it /= 0;

    std::cout << it << std::endl;

    std::cout << "New value of ft = ft / 0 = ";

    ft /= 0;

    std::cout << ft << std::endl;

    std::cout << "New value of dt = dt / 0 = ";

    dt /= 0;

    std::cout << dt << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    part3();
    part4();
    // part6();

    std::cout << "good to go!\n";

    return 0;
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
