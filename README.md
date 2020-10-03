## **makeclass**
makeclass is a C++ program to build skeleton directory for C++ classes.


## **Build**: 

Use `make` to build the executable.

Run `./makeclass` to generate C++ class files (see below).

Use `make clean` for cleanup.

**Additionally: adding to path**

for UNIX and Linux, open a terminal from home and run

`vi .bash_profile`

then add the following line at the end and save.

`export PATH=$PATH:<path-to-the-executable>`

now you will be able to use `makeclass` command from anywhere.

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
```
1. class.h          // main header file
2. class.ih         // internal header file
3. class1.cc        // default constructor file
4. desctructor.cc   // destructor file
```
additionally, if copy and move supports are specified:
```
5. class2.cc        // copy constructor file
6. class3.cc        // move constructor file
7. operator1.cc     // assignment operator file (for copy)
8. operator2.cc     // assignment operator file (for move)
```

<br/>

## **Important**


This program uses features from c++11 standard or more, so please make sure your g++ or clang++ compiler is up-to-date.
