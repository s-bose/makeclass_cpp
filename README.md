## makeclass is a C++ program to build skeleton directory for C++ classes.


## **Build**: 

Use `make` to build the executable.
Run `./makeclass` to generate C++ class files (see below)

<br/>

## **Usage**:

```
./makeclass class [namespace]

class : name of the class + the directory
namespace  : (optional) custom namespace for the class
```

You will be prompted with the following two: (default N)

```
> Allow copy support? [y/N]

and

> Allow move support [y/N]
```

These create additional copy & move constructors and assignment operator overloads for the class.
The files generated are:
    1. class.h          // main header file
    2. class.ih         // internal header file
    3. class1.cc        // default constructor file
    4. desctructor.cc   // destructor file

additionally, if copy and move supports are specified:
    5. class2.cc        // copy constructor file
    6. class3.cc        // move constructor file
    7. operator1.cc     // assignment operator file (for copy)
    8. operator2.cc     // assignment operator file (for move)

<br/>

## **Dependencies**

This requires the [Boost](https://www.boost.org/users/download/) library for C++ 

