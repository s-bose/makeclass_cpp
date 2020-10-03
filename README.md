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

<br/>

## **Dependencies**

This requires the [Boost](https://www.boost.org/users/download/) library for C++ 

