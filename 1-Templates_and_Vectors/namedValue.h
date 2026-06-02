/**
 * @file namedValue.h
 * @author Bob Lowe
 * @brief Template for a named value class template.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <string>

template <typename T>
class NamedValue
{
public:
    ////////////////
    // Constructors
    ////////////////
    NamedValue();
    NamedValue(const std::string &_name);
    NamedValue(const std::string &_name, const T& _value);

    // Destructor
    virtual ~NamedValue();

    /**
     * @brief Get the name of this object.
     * 
     * @return std::string 
     */
    virtual std::string name() const;

    /**
     * @brief Change the name of this object.
     * 
     * @param _name 
     */
    virtual void name(const std::string& _name);

    /**
     * @brief Get the value of this object.
     * 
     * @return T 
     */
    virtual T value() const;

    /**
     * @brief Set the value of this object
     * 
     * @param _value 
     */
    virtual void value(const T& _value);

    /**
     * @brief Assign a new value to this object
     * 
     * @param _value 
     * @return NamedValue<T>& 
     */
    virtual NamedValue<T>& operator=(const T& _value);

private:
    /**
     * @brief Name of this object.
     * 
     */
    std::string _name; 

    /**
     * @brief Value of this object.
     * 
     */
    T _value;
};

//////////////////////////////////////////////////
// Implementation of the template
//////////////////////////////////////////////////

////////////////
// Constructors
////////////////
template<typename T>
NamedValue<T>::NamedValue() : NamedValue("")
{
    // This space left intentionally blank
}

template<typename T>
NamedValue<T>::NamedValue(const std::string& _name) : NamedValue(_name, T())
{
    // This space left intentionally blank
}

template<typename T>
NamedValue<T>::NamedValue(const std::string& _name, const T& _value)
{
    this->_name = _name;
    this->_value = _value;
}

// Destructor
template<typename T>
NamedValue<T>::~NamedValue()
{
    // This space left intentionally blank
}


// Get the name of this object
template<typename T>
std::string NamedValue<T>::name() const
{
    return _name;
}

// Change the name of this object
template<typename T>
void NamedValue<T>::name(const std::string& _name)
{
    this->_name = _name;
}

// Get the value of this object
template<typename T>
T NamedValue<T>::value() const
{
    return _value;
}


// Change the value of this object
template<typename T>
void NamedValue<T>::value(const T& _value)
{
    this->_value = _value;
}


// Assignment operator for the object
template<typename T>
NamedValue<T>& NamedValue<T>::operator=(const T& _value)
{
    value(_value);
    return *this;
}


//////////////////////////////////////////////////
// I/O Operator Templates
//////////////////////////////////////////////////

// insertion operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const NamedValue<T>& nv)
{
    return os << nv.name() << ": " << nv.value();
}

// extraction operator
template<typename T>
std::istream& operator>>(std::istream& is, NamedValue<T>& nv)
{
    T value;
    
    //get the value
    is >> value;
    nv = value;

    return is;
}

#endif