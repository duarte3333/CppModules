# CppModules - C+++++
<p align="center">
  <img src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41" data-canonical-src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41.png" width="200" height="200" />
</p>

# Cpp00

## The four pilars of OOP

### Abstraction

Abstraction focuses on representing the essential features of an object while hiding unnecessary details. It provides a simplified view of objects, emphasizing only the relevant characteristics and behaviors. Abstraction is achieved through **abstract classes and interfaces**. 

An ***abstract class*** is a class that **cannot be instantiated** and **serves as a blueprint for derived classes**. It can contain both concrete and abstract methods. 

An ***interface***, on the other hand, is a **collection of abstract methods** that define a contract for classes to implement. Abstraction allows developers to model real-world concepts and build modular systems by defining common behaviors and characteristics without specifying implementation details.

### Encapsulation

Encapsulation is the mechanism of **bundling data (attributes) and methods (functions) together** into a **single unit** called a class. 

It enables the class to control access to its internal data, ensuring that data is accessed and modified only through defined methods. Encapsulation provides data hiding, abstraction, and data protection, as the internal implementation details are hidden from the outside world.

### Inheritance

Inheritance allows the **creation of new classes** (derived classes) **based on existing classes** (base or parent classes). The derived class inherits the attributes and methods of the base class and can also add its own unique attributes and methods. Inheritance promotes code reuse and the concept of specialization, as the **derived classes can extend or modify the behavior of the base class.** It establishes a hierarchical relationship between classes, forming an "is-a" relationship.

### Polymorphism

Polymorphism is a fundamental concept in object-oriented programming that allows objects of different classes to be **treated in a unified manner**. It is based on the idea that an object can take on multiple forms or have multiple implementations, depending on the context in which it is used.


<p align="center">
	  <img src="https://github.com/duarte3333/CppModules/assets/76222459/7c46846a-7621-485a-b02b-a63e05ddd110" data-canonical-src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41.png" width="500" height="250" />
</p>

**Method Overloading**: This type of polymorphism occurs when a class has multiple methods with the same name but different parameters. The selection of which method to call is determined at **compile-time** based on the types of arguments passed to the method.

Example: a "Calculator" class may have an "add" method that can be overloaded to accept different types of arguments, such as integers, floating-point numbers, or strings.

**Method Overriding:** This type of polymorphism occurs when a derived class provides a specific implementation for a method that is already defined in its base class. The derived class overrides or replaces the behavior of the base class method.

Example: if you have an "Animal" class with a "makeSound()" method, and you have derived classes like "Dog" and "Cat", each of them can override the "makeSound()" method to produce different sounds.

## Namespace

In C++, a namespace is a mechanism used to **organize and group related declarations**, such as variables, functions, and classes, into distinct named scopes. It helps prevent naming conflicts and provides a way to **organize code modules**.

```cpp
namespace MyNamespace {
	int myVariable;
	void myFunction();
}
int main() {
	MyNamespace::myVariable = 42;
	MyNamespace::myFunction();
}
```

### std::iostreams

**`std::iostreams`** refers to the standard input/output streams provided by the C++ Standard Library. These streams are used for **input and output operations** in C++ programs and are part of the **`<iostream>`** header.

- **`std::cin`**: The standard input stream is used for reading input from the user.
- **`std::cout`**: The standard output stream is used for writing output to the console.
- **`std::cerr`**: The standard error stream is used for writing error messages or diagnostic information to the console.

Example:

```cpp
int num;
std::cout << "Enter a number: ";
std::cin >> num;
```

### Class

Class: In programming, a class is a blueprint or a **template** that describes the attributes (data) and behaviors (methods or functions) that objects of that class will have. It defines the structure and characteristics of objects.

Example:

```cpp
class MyClass {
public:
	// Member variables
	int myVariable;
	// Member function
	void myMethod() {
	    // Code here
	}
};
```

### Instance

An instance, also known as an object, is a **concrete realization or occurrence of a class**. It is created using the blueprint provided by the class.

### Member attributes and member functions in C++

- **Private**: Attributes/methods that can be only accessible from within the class itself.
- **Protected:** Can be accessed by the class itself and derived classes as well.
- **Public:** Can be accessed from outside the class.

**Member Attributes** (or Member Variables): Member attributes are variables declared within a class. They represent the data or state associated with objects of that class. These attributes store information that describes the object's properties or characteristics.

```cpp
class MyClass {
private:
    int myVariable; // Member attribute

public:
    // Member functions
};
```

**Member Functions** (or Methods): Member functions are functions declared within a class. They define the behavior or actions that objects of the class can perform. Member functions operate on the member attributes of the class and can modify their values or perform operations using them.

### this in C++

In C++, **`this`** is a keyword that represents **a pointer to the current instance of a class**. It is an implicit parameter available within member functions and refers to the object for which the member function is called.

When a member function is called on an object, **`this`** is **automatically created and points to the memory location of that object.** It allows the member function to access and manipulate the member attributes and member functions of the current instance.

```cpp
class MyClass {
private:
    int myVariable;

public:
    void setMyVariable(int value) {
        this->myVariable = value;  // Accessing the member attribute using 'this'
				myVariable = value;  //Also a possibility, line above is opcional
    }
};
```

***Notes:***

-The usage of **`this`** is **optional in most cases**, as the compiler automatically understands the context of member attributes and member functions.

-**`this`** is **only available within non-static member functions**. Static member functions, which do not operate on a specific instance, do not have a **`this`** pointer.

### Inicialization list in C++?

In C++, the initialization list is a feature used to initialize member variables of a class within the constructor. It provides a way to **initialize the member variables before the body of the constructor is executed.**

The initialization list is specified after the constructor's parameter list and before the opening curly brace that starts the constructor's body. It consists of a colon (**`:`**) followed by a comma-separated list of member variable initializations.

```cpp
class MyClass {
private:
    int myVariable;
    float myFloat;

public:
    MyClass(int value, float floatValue) : myVariable(value), myFloat(floatValue) {
        // Constructor body
    }
};
```

### C++98

C++98, released in 1998, was the first official standardization of the C++ programming language by ISO. 

It introduced important features including the Standard Template Library (STL) for data structures and algorithms, namespaces for organizing code, exception handling for handling exceptional conditions, run-time type information (RTTI) for type identification, refined template syntax, and a standardized iostream library for input/output operations.

### Const

In C++, **`const`** is a keyword that is used to declare constants or variables that cannot be modified after initialization.

**Constant Variables:** When **`const`** is used to declare a variable, it means that the value of the variable cannot be changed once it is initialized. The variable becomes a **read-only entity,** and any attempt to modify its value will result in a compilation error.

```cpp
const int VALUE_MAX = 100;
```

**Const Member Functions:** When a member function of a class is declared as **`const`**, it means that the member function **will not modify the state of the object** on which it is called.

It **guarantees** that the member function **does not modify any non-static member variables** of the class. A **`const`** member function can be called on both **`const`** and non-**`const`** objects of the class.

Duvida: Um metodo constante pode mudar variaveis estáticas?

```cpp
class MyClass {
public:
    int getValue() const {
        // Function body
    }
};
```

### Struct vs Class

Here are the main differences between **`class`** and **`struct`** in C++:

1. **Default Visibility**:

```cpp
class MyClass {
    // By default, member variables and member functions are private
};

struct MyStruct {
    // By default, member variables and member functions are public
};
```

 2.  **Usage Convention**:

Historically, **`struct`** has been used in C++ to represent a collection of data members, often with little or no associated behavior. It is commonly used as a **lightweight data container**.

On the other hand, **`class`** is used to represent objects with **associated behavior and encapsulation**, often with private data members and public member functions.

1. **Inheritance:**

```cpp
class BaseClass {
public:
    int publicVariable;
};

class DerivedClass : BaseClass {
    // 'publicVariable' will become private within 'DerivedClass'
};

struct BaseStruct {
    int publicVariable;
};

struct DerivedStruct : BaseStruct {
    // 'publicVariable' remains public within 'DerivedStruct'
};
```

### Acessors in C++ (Getters and Setters)

**Accessors,** also known as getters and setters, are member functions that **provide controlled access to the private member variables of a class**. 

Getters retrieve the values of member variables, while setters modify or update their values.

**Getters typically** have a **`const`** qualifier to indicate that they do **not modify** the object's state. Setters, on the other hand, take a parameter to set the value of a member variable.

```cpp
class MyClass {
private:
    int myVariable;

public:
    int getMyVariable() const {
        return myVariable;
    }

    void setMyVariable(int value) {
        myVariable = value;
    }
};
```

### Comparisons in C++

Comparisons allow you to compare objects of a class for **equality, inequality, or ordering**. To enable comparisons, you can overload comparison operators (**`==`**, **`!=`**, **`<`**, **`>`**, **`<=`**, **`>=`**) as member functions or as standalone friend functions.

```cpp
class MyClass {
private:
    int myVariable;

public:
    bool operator==(const MyClass& other) const {
        return myVariable == other.myVariable;
    }

    bool operator!=(const MyClass& other) const {
        return myVariable != other.myVariable;
    }
};
```

Nota: quando mando uma referência nao tenho de me preocupar com se existiu ou não malloc(), daí ser &other.

### Non member attributes and non member functions

**Non-Member Attributes:** 

Non-member attributes, also known as **global variables**, are variables that are **declared and defined outside of any class or function**. They have a global scope and can be accessed from any part of the program.

Example:

```cpp
int globalVariable; // Non-member attribute (global variable)
```

**Non-Member Functions:**
Non-member functions are functions that are **declared and defined outside of any class or struct**. They are not member functions of a class and can be accessed globally. Non-member functions can be used to perform specific operations that are not associated with a particular class or to provide utility functions that can be reused across multiple classes.

```cpp
#include <iostream>

// Non-member function declaration
void myFunction(int value);

int main() {
    myFunction(10); // Function call
    return 0;
}

// Non-member function definition
void myFunction(int value) {
    std::cout << "Value: " << value << std::endl;
}
```

### Pointers to members in C++

Pointers to members in C++ are a feature that allows you to **store and manipulate pointers** to **non-static member variables** and **member functions** of a class or struct. They provide a way to access and invoke members dynamically at runtime.

1. **Pointer to Data Member**:

A pointer to a non-static data member of a class or struct holds the address of a specific member variable within an object. It allows you to **indirectly access and modify the value** of the member variable.

```cpp
class MyClass {
public:
    int myVariable;
};

int main() {
    int MyClass::*ptr;  // Pointer to a non-static data member

    ptr = &MyClass::myVariable;  // Assign address of myVariable to the pointer

    MyClass obj;
    obj.myVariable = 42;

    // Access the member variable using the pointer
    std::cout << obj.*ptr << std::endl;  // Output: 42

    return 0;
}
```

1. **Pointer to Member Function**:

A pointer to a non-static member function holds the address of a specific member function within a class or struct. It allows you to **indirectly invoke the member function** on an object.

```cpp
class MyClass {
public:
    void myFunction() {
        std::cout << "Hello, world!" << std::endl;
    }
};

int main() {
    void (MyClass::*ptr)();  // Pointer to a non-static member function

    ptr = &MyClass::myFunction;  // Assign address of myFunction to the pointer

    MyClass obj;

    // Invoke the member function using the pointer
    (obj.*ptr)();  // Output: Hello, world!

    return 0;
}
```

### The Orthodox Canonical Form

The Orthodox Canonical Form, also known as the **Rule of Three (or Five) in C++**, refers to a set of guidelines that ensure the proper handling of resources and **prevent issues related to copy construction, assignment, and destruction**. It applies when a class defines a destructor, copy constructor, or copy assignment operator.

The Orthodox Canonical Form consists of three key components:

1. Destructor (`~ClassName()`):
The class **should define a destructor** to release any resources acquired by the object. The destructor is responsible for **cleaning up memory, closing file handles, releasing locks**, or performing any **other necessary cleanup operations**. It ensures that the **object is properly destroyed** when it goes out of scope or is explicitly deleted.
2. Copy Constructor (`ClassName(const ClassName&)`):
If the class manages resources or has pointer members, it **should** define a **copy constructor to create a deep copy of the object.** The copy constructor is called when a new object is initialized with an existing object. It should allocate new memory (if needed) and copy the values of member variables to ensure that both objects are independent and don't share resources.
3. Copy Assignment Operator (`operator=(const ClassName&)`):
The class should **define a copy assignment operator to properly assign one object to another.** It is invoked when an existing object is assigned the value of another existing object. The copy assignment operator should handle the resource management and data copying in a way similar to the copy constructor.

In addition to these three components, there are two optional components that complete the Rule of Five:

1. Move Constructor (`ClassName(ClassName&&)`):
Introduced in C++11, the move constructor is responsible for efficiently transferring the resources (such as memory ownership) from a temporary or expiring object to a newly created object. It is used in move semantics to enable efficient resource management and avoid unnecessary copying.
2. Move Assignment Operator (`operator=(ClassName&&)`):
Also introduced in C++11, the move assignment operator allows efficient transfer of resources from a temporary or expiring object to an already existing object. It is used in move semantics to enable efficient resource management and assignment.

By following the Orthodox Canonical Form, you ensure that the class properly handles resource management, prevents issues such as double deletion or memory leaks, and provides correct behavior when objects are copied or assigned. It promotes the principle of **RAII (Resource Acquisition Is Initialization)** and helps ensure the correct and expected behavior of the class when used in various contexts.

```cpp
class MyClass {
public:
    MyClass() = default;  // Default constructor

    ~MyClass();  // Destructor

    MyClass(const MyClass& other);  // Copy constructor

    MyClass& operator=(const MyClass& other);  // Copy assignment operator

    MyClass(MyClass&& other);  // Move constructor

    MyClass& operator=(MyClass&& other);  // Move assignment operator
};
```

### Coding Formats

Here are some of the most well-known coding formats:

1. Camel Case:
In camel case, compound words or phrases are concatenated together, and each word after the first is capitalized. There are variations like lower camel case (e.g., **`myVariable`**, **`calculateTotal()`**) where the first word starts with a lowercase letter, and upper camel case or Pascal case (e.g., **`MyClass`**, **`CalculateTotal()`**) where the first word starts with an uppercase letter.
2. Snake Case:
In snake case, compound words or phrases are separated by underscores. All letters are usually lowercase. For example: **`my_variable`**, **`calculate_total()`**.
3. Kebab Case:
Kebab case is similar to snake case, but instead of underscores, hyphens are used to separate words. All letters are usually lowercase. For example: **`my-variable`**, **`calculate-total()`**.
4. Pascal Case:
Pascal case, also known as upper camel case, is similar to camel case, but each word starts with an uppercase letter. For example: **`MyVariable`**, **`CalculateTotal()`**.
5. Hungarian Notation:
Hungarian notation, popularized by Microsoft, prefixes variable or function names with a tag indicating their data type. For example, **`strName`** for a string, **`nCount`** for an integer count, **`bIsReady`** for a boolean value.
6. Screaming Snake Case:
Screaming snake case is similar to snake case, but all letters are uppercase, and words are separated by underscores. It is typically used for constant values. For example: **`MAX_VALUE`**, **`PI`**.

### The standard library in C++

The C++ Standard Library consists of several components:

1. **Standard Template Library (STL):** The STL provides generic algorithms and data structures, such as vectors, lists, queues, stacks, sets, maps, and algorithms like sorting and searching. It also includes utility classes like iterators, function objects, and smart pointers.
2. **Input/Output Streams:** The iostream library provides classes and functions for input and output operations. It includes the classes **`std::cin`**, **`std::cout`**, **`std::ifstream`**, **`std::ofstream`**, etc., for reading from and writing to different sources, such as the console or files.
3. **Containers:** The containers library provides various container classes like **`std::array`**, **`std::vector`**, **`std::deque`**, **`std::list`**, **`std::set`**, **`std::map`**, etc. These containers offer different data structures for storing and manipulating collections of objects.
4. **Algorithms:** The algorithms library contains a set of generic algorithms, such as sorting, searching, transforming, and manipulating elements in containers. It includes functions like **`std::sort`**, **`std::find`**, **`std::transform`**, **`std::copy`**, and more.
5. **Iterators:** The iterators library provides a way to traverse and manipulate elements of containers in a generic manner. It includes different types of iterators, such as input iterators, output iterators, forward iterators, bidirectional iterators, and random access iterators.
6. **Utilities:** The utilities library contains various utility classes and functions. It includes classes like **`std::pair`** for storing pairs of objects, **`std::tuple`** for storing multiple objects, **`std::function`** for function objects, and more.

### String in C++

**In C++, `std::string` is a class provided by the C++ Standard Library that represents a sequence of characters.**

The **`<string>`** library in C++ provides various functions for working with strings. Here are some commonly used functions available in the **`<string>`** library:

1. String Construction and Initialization:
- **`string()`** - Default constructor, creates an empty string.
- **`string(const char*)`** - Constructs a string from a null-terminated character array.
- **`string(const string&)`** - Copy constructor, creates a string by copying another string.
- **`string(size_t, char)`** - Constructs a string with a specified number of copies of a character.
1. String Assignment:
- **`operator=`** - Assigns a new value to a string.
- **`assign()`** - Assigns a new value to a string.
- **`append()`** - Appends a string or a portion of a string to another string.
1. String Access:
- **`operator[]`** - Accesses individual characters of a string.
- **`at()`** - Accesses individual characters of a string with bounds checking.
- **`c_str()`** - Returns a pointer to a null-terminated character array representing the string.
1. String Modification:
- **`insert()`** - Inserts characters into a string.
- **`erase()`** - Erases characters from a string.
- **`replace()`** - Replaces characters in a string with other characters.
- **`substr()`** - Returns a substring of a string.
1. String Information:
- **`length()`** - Returns the length of a string.
- **`size()`** - Returns the size of a string (same as **`length()`**).
- **`empty()`** - Checks if a string is empty.
- **`capacity()`** - Returns the storage capacity of a string.
- **`max_size()`** - Returns the maximum possible size of a string.
1. String Comparison:
- **`compare()`** - Compares two strings lexicographically.
- **`operator==`**, **`operator!=`**, **`operator<`**, **`operator>`**, **`operator<=`**, **`operator>=`** - Comparison operators for strings.
1. String Searching and Manipulation:
- **`find()`** - Searches for a substring within a string.
- **`rfind()`** - Searches for a substring within a string in reverse.
- **`find_first_of()`** - Searches for the first occurrence of any character in a set.
- **`find_last_of()`** - Searches for the last occurrence of any character in a set.
- **`find_first_not_of()`** - Searches for the first occurrence of a character not in a set.
- **`find_last_not_of()`** - Searches for the last occurrence of a character not in a set.

These are just some of the commonly used functions available in the **`<string>`** library. There are more functions and member functions available that provide additional functionality for manipulating and working with strings. You can refer to the C++ documentation or a good C++ reference book for a complete list of functions and their detailed usage.

### Main casting operators in C++:

1. **`static_cast`**: Used for **safe conversions** between related types, such as numeric conversions, pointer/reference conversions, and conversions within an inheritance hierarchy. It is checked **at compile-time**.
2. **`dynamic_cast`**: Used for **pointer/reference conversions at runtime** in a polymorphic inheritance hierarchy. Verifies if the conversion is valid at runtime.
3. **`reinterpret_cast`**: Performs conversions between **unrelated pointer/reference types**. It reinterpret the binary representation of an object as if it were of another type. Can lead to undefined behavior if used incorrectly.
4. **`const_cast`**: Allows adding or removing constness qualifiers from an object. Used for **converting between constant and non-constant objects**.

# Cpp01

### new()

The **`new`** operator is used to dynamically allocate memory for an object on the heap during runtime. It's often used when you need to create objects whose size or lifetime cannot be determined at compile-time, such as when dealing with arrays or objects with unknown sizes.

```cpp
#include <iostream>

int main() {
    // Allocate memory for an integer on the heap
    int *ptr = new int;
    // Assign a value to the dynamically allocated integer
    *ptr = 42;
    // Print the value of the dynamically allocated integer
    std::cout << "Value: " << *ptr << std::endl;
    // Deallocate the memory to prevent memory leaks
    delete ptr;
    return 0;
}
```

### References

References provide a way to **alias an existing object** with a different name. They are often used as function parameters or return values to avoid copying large objects.

```cpp
#include <iostream>

void modifyValue(int &ref) {
    ref = 100;
}

int main() {
    int x = 42;
    int &ref = x;

    std::cout << "Original x: " << x << std::endl;
    modifyValue(ref);
    std::cout << "Modified x: " << x << std::endl;

    return 0;
}
```

In this example, we define a function **`modifyValue`** that takes an integer reference as a parameter and modifies its value. We also create a reference **`ref`** to an integer **`x`** and use it to call the function.

### Filestreams

Filestreams provide a way to work with files in C++. They are used for **reading from and writing** to **files**.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt");

    if (outFile.is_open()) {
        outFile << "Hello, Filestream!" << std::endl;
        outFile.close();
        std::cout << "File written successfully." << std::endl;
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    std::ifstream inFile("example.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    return 0;
}
```

In this example, we first create an **`ofstream`** (output file stream) to write to a file named "example.txt". We check if the file is opened successfully, write a line to it, and then close it. Later, we create an **`ifstream`** (input file stream) to read from the same file. We use a loop to read each line from the file and print it.

### Lesson

<aside>
💡 Using a reference implies that there will always be a value associated to the variable. Using a pointer allows the state of the variable to be null, case where there is no value associate to the variable. Depends on the **lifetime of the variable.**

</aside>

# Cpp02

### **Ad-hoc Polymorphism**

Ad-hoc polymorphism allows a function to behave differently based on the types of arguments it receives. This is achieved through function overloading. Here's an example:

```cpp
#include <iostream>// Function overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    int sum_int = add(5, 3);
    double sum_double = add(3.14, 2.71);

    std::cout << "Sum (int): " << sum_int << std::endl;
    std::cout << "Sum (double): " << sum_double << std::endl;

    return 0;
}
```

### **Operator Overload**:

Operator overloading lets you define custom behaviors for operators when used with user-defined classes. Here's an example using the **`+`** operator:

```cpp
#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    void display() {
        std::cout << real << " + " << imaginary << "i";
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);

    Complex sum = c1 + c2;
    sum.display();

    return 0;
}
```

### Floats vs Integers

Integers → Complete accuracy(is the true value) but lack precision (5/2=2)

Floats → Lack accuracy but have a lot of precision

  seeeeeeeeeemmmmmmmmmmmmmmmmmmmm    meaning

31                                                                              0    bit #

the value is mantissa times 2^x in binary or 10^x in decimal

x is the expoent.

For getting 1 = 1.0*2^0 = 2^-127 so the lower exponent is -126 (1 - 127)

because the -127 become the zero (abdicou-se do expoente -127).

1. **`0 0x00000000`**
This represents the number zero. In the IEEE-754 format, when all bits are zero, including the sign bit, the number is considered zero.
2. **`1.0 0x3f800000`**
This represents the number 1.0. The sign bit is 0 (positive), the exponent is 127 (0x7f), and the mantissa is 0 (implied as 1.m).
3. **`0.5 0x3f000000`**
This represents the number 0.5. The sign bit is 0 (positive), the exponent is 126 (0x7f - 1), and the mantissa is 0 (implied as 1.m).
4. **`3 0x40400000`**
This represents the number 3.0. The sign bit is 0 (positive), the exponent is 129 (0x7f + 2), and the mantissa is 0 (implied as 1.m).

### Bits, bytes and values

4 bytes.

Cada nibble sao 4 bits.

Cada byte sao 8 bits. Logo 32 bits.

→2^32 = 4294967296 values.

| Type Name | Bytes | Range of Values |
| --- | --- | --- |
| int | 4 | -2,147,483,648 to 2,147,483,647 |

### Fixed-point number

Fixed-point number representation is a method of representing real numbers, including both integer and fractional parts, using a fixed number of bits for the fractional portion. Unlike floating-point representation, where the number of bits for the fractional part can vary, fixed-point representation **maintains a consistent precision for the fractional portion across all values**. Fixed-point representation is commonly used in applications where accuracy and performance are crucial, such as embedded systems or signal processing.

In fixed-point representation, you allocate a certain number of bits to represent the fractional part of the number. The remaining bits are used for the integer part. The position of the binary point (similar to the decimal point in decimal numbers) determines the boundary between the integer and fractional parts.

For example, in a 16-bit fixed-point representation with 8 bits for the integer part and 8 bits for the fractional part, the binary point would be placed between the 8th and 9th bits:

```cpp
Integer part  |   Fractional part
[--------][--------]
```

Here are some examples of fixed-point representation in C++:

```cpp
#include <iostream>

// A simple fixed-point representation example using 16 bits (8 integer, 8 fractional)
typedef int16_t fixed_point_t;

// Convert a fixed-point value to a floating-point value
double fixedToFloat(fixed_point_t value) {
    return static_cast<double>(value) / (1 << 8); // Shift by the number of fractional bits
}

int main() {
    // Create some fixed-point values
    fixed_point_t value1 = 12345;       // 12345 * 2^-8 = 48.30078125
    fixed_point_t value2 = -9876;      // -9876 * 2^-8 = -38.515625
    fixed_point_t value3 = 32767;      // 32767 * 2^-8 = 127.99609375

    // Convert fixed-point values to floating-point for display
    double float1 = fixedToFloat(value1);
    double float2 = fixedToFloat(value2);
    double float3 = fixedToFloat(value3);

    std::cout << "Fixed-point values:" << std::endl;
    std::cout << "Value 1: " << value1 << " (Float: " << float1 << ")" << std::endl;
    std::cout << "Value 2: " << value2 << " (Float: " << float2 << ")" << std::endl;
    std::cout << "Value 3: " << value3 << " (Float: " << float3 << ")" << std::endl;

    return 0;
}
```

### Static member functions

```cpp
class MyClass {
public:
    static void staticFunction() {
        std::cout << "This is a static member function." << std::endl;
    }
};

int main() {
    MyClass::staticFunction(); // Chamada direta da static member function

    return 0;
}
```

Don’t have **`this` .** 

# Cpp03

### Multiple inheritance(Diamond inheritance)

For the classe A can inherit from both B and C, they both should be virtual classes and depending on the order of the constructor it will first inherit from one and the from the other, overwriting the methods that are in both classes avoiding conflits.

ex: In the following example if there is the same method for both B and C, the class A will chosse that method from de class C, because was that last called in the constructor.

```cpp
A::A() : public B(), public C(){
}
```
<p align="center">
	  <img src="https://github.com/duarte3333/CppModules/assets/76222459/b242c617-be74-4216-b9b1-5bda23435f04" data-canonical-src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41.png" width="300" height="300" />
</p>
<p align="center">
	  <img src="https://github.com/duarte3333/CppModules/assets/76222459/9d1a7c3d-6c97-4ed6-b708-00de85215e3c" data-canonical-src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41.png" width="500" height="500" />
</p>

# Cpp04

### Abstract class

An abstract function in C++ have methods like this:

```cpp
virtual void method(void) = 0;
```

which means that the class cannot be instanciate, however if there are classes that where defined in .cpp file and dont have “= 0” in the .hpp and have virtual methods means that the son of the class can overwrite the method of the father class. 

### Shallow copy

A shallow copy should be nice if i only want to copy variables in the stack but if i want to copy pointers it will have the following problem:

<p align="center">
	  <img src="https://github.com/duarte3333/CppModules/assets/76222459/b3089024-adbc-40a2-8fc6-3421b9e02bdf" data-canonical-src="https://github.com/duarte3333/CppModules/assets/76222459/5c6635f0-99b0-4c58-a0b6-63cc38a27e41.png" width="500" height="500" />
</p>

### Deep copy

In a deep copy i have to create and allocate memory to replicate the pointers.

```cpp
#include <iostream>

class DeepCopyExample {
private:
    int* data;
    int size;

public:
    // Constructor
    DeepCopyExample(int* arr, int arrSize) : size(arrSize) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // Destructor
    ~DeepCopyExample() {
        delete[] data;
    }

    // Copy constructor (deep copy)
    DeepCopyExample(const DeepCopyExample& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Print data
    void printData() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    DeepCopyExample original(arr, arrSize);
    DeepCopyExample
```
