#include <iostream>
#include <limits>

int main() {

    // Character types
    char myChar = 'A';
    char16_t myChar16 = u'B';
    char32_t myChar32 = U'C';
    wchar_t myWideChar = L'D';

    // Integer types (signed)
    signed char mySignedChar = -10;
    signed short int mySignedShortInt = -200;
    signed int mySignedInt = -3000;
    signed long int mySignedLongInt = -40000;
    signed long long int mySignedLongLongInt = -500000;

    // Integer types (unsigned)
    unsigned char myUnsignedChar = 10;
    unsigned short int myUnsignedShortInt = 200;
    unsigned int myUnsignedInt = 3000;
    unsigned long int myUnsignedLongInt = 40000;
    unsigned long long int myUnsignedLongLongInt = 500000;
    
    // these types are built in std
    std::int8_t m_int8 = 9;                 
    std::uint8_t m_uint8 = 10;
    std::int16_t m_int16 = 9;
    std::uint16_t m_uint16 = 10;
    std::int32_t m_int32 = 11;
    std::uint32_t m_uint32 = 12;
    std::int64_t m_int64 = 13;
    std::uint64_t m_uint64 = 14;

    // Floating-point types
    float myFloat = 3.14f;
    double myDouble = 2.71828;
    long double myLongDouble = 1.414213562373095;

    // Boolean type
    bool myBool = true;

    // Void type
    void* myVoidPtr = nullptr;

    // Null pointer
    decltype(nullptr) myNullPtr = nullptr;

    // Create pointers to the variables
    char* pChar = &myChar;
    char16_t* pChar16 = &myChar16;
    char32_t* pChar32 = &myChar32;
    wchar_t* pWideChar = &myWideChar;

    signed char* pSignedChar = &mySignedChar;
    signed short int* pSignedShortInt = &mySignedShortInt;
    signed int* pSignedInt = &mySignedInt;
    signed long int* pSignedLongInt = &mySignedLongInt;
    signed long long int* pSignedLongLongInt = &mySignedLongLongInt;

    unsigned char* pUnsignedChar = &myUnsignedChar;
    unsigned short int* pUnsignedShortInt = &myUnsignedShortInt;
    unsigned int* pUnsignedInt = &myUnsignedInt;
    unsigned long int* pUnsignedLongInt = &myUnsignedLongInt;
    unsigned long long int* pUnsignedLongLongInt = &myUnsignedLongLongInt;

    std::int8_t* pInt8 = &m_int8;
    std::uint8_t* pUint8 = &m_uint8;
    std::int16_t* pInt16 = &m_int16;
    std::uint16_t* pUint16 = &m_uint16;
    std::int32_t* pInt32 = &m_int32;
    std::uint32_t* pUint32 = &m_uint32;
    std::int64_t* pInt64 = &m_int64;
    std::uint64_t* pUint64 = &m_uint64;

    float* pFloat = &myFloat;
    double* pDouble = &myDouble;
    long double* pLongDouble = &myLongDouble;

    bool* pBool = &myBool;

    
    // Output the size and address
    std::cout << "Size of myChar: " << sizeof(myChar) << " bytes, Address: " << static_cast<void*>(&myChar) << std::endl;
    std::cout << "Size of myChar16: " << sizeof(myChar16) << " bytes, Address: " << static_cast<void*>(&myChar16) << std::endl;
    std::cout << "Size of myChar32: " << sizeof(myChar32) << " bytes, Address: " << static_cast<void*>(&myChar32) << std::endl;
    std::wcout << L"Size of myWideChar: " << sizeof(myWideChar) << " bytes, Address: " << static_cast<void*>(&myWideChar) << std::endl;

    std::cout << "Size of mySignedChar: " << sizeof(mySignedChar) << " bytes, Address: " << static_cast<void*>(&mySignedChar) << std::endl;
    std::cout << "Size of mySignedShortInt: " << sizeof(mySignedShortInt) << " bytes, Address: " << static_cast<void*>(&mySignedShortInt) << std::endl;
    std::cout << "Size of mySignedInt: " << sizeof(mySignedInt) << " bytes, Address: " << static_cast<void*>(&mySignedInt) << std::endl;
    std::cout << "Size of mySignedLongInt: " << sizeof(mySignedLongInt) << " bytes, Address: " << static_cast<void*>(&mySignedLongInt) << std::endl;
    std::cout << "Size of mySignedLongLongInt: " << sizeof(mySignedLongLongInt) << " bytes, Address: " << static_cast<void*>(&mySignedLongLongInt) << std::endl;

    std::cout << "Size of myUnsignedChar: " << sizeof(myUnsignedChar) << " bytes, Address: " << static_cast<void*>(&myUnsignedChar) << std::endl;
    std::cout << "Size of myUnsignedShortInt: " << sizeof(myUnsignedShortInt) << " bytes, Address: " << static_cast<void*>(&myUnsignedShortInt) << std::endl;
    std::cout << "Size of myUnsignedInt: " << sizeof(myUnsignedInt) << " bytes, Address: " << static_cast<void*>(&myUnsignedInt) << std::endl;
    std::cout << "Size of myUnsignedLongInt: " << sizeof(myUnsignedLongInt) << " bytes, Address: " << static_cast<void*>(&myUnsignedLongInt) << std::endl;
    std::cout << "Size of myUnsignedLongLongInt: " << sizeof(myUnsignedLongLongInt) << " bytes, Address: " << static_cast<void*>(&myUnsignedLongLongInt) << std::endl;

    std::cout << "Size of m_int8: " << sizeof(m_int8) << " bytes" << std::endl;
    std::cout << "Size of m_uint8: " << sizeof(m_uint8) << " bytes" << std::endl;
    std::cout << "Size of m_int16: " << sizeof(m_int16) << " bytes" << std::endl;
    std::cout << "Size of m_uint16: " << sizeof(m_uint16) << " bytes" << std::endl;
    std::cout << "Size of m_int32: " << sizeof(m_int32) << " bytes" << std::endl;
    std::cout << "Size of m_uint32: " << sizeof(m_uint32) << " bytes" << std::endl;
    std::cout << "Size of m_int64: " << sizeof(m_int64) << " bytes" << std::endl;
    std::cout << "Size of m_uint64: " << sizeof(m_uint64) << " bytes" << std::endl;

    std::cout << "Size of myFloat: " << sizeof(myFloat) << " bytes, Address: " << static_cast<void*>(&myFloat) << std::endl;
    std::cout << "Size of myDouble: " << sizeof(myDouble) << " bytes, Address: " << static_cast<void*>(&myDouble) << std::endl;
    std::cout << "Size of myLongDouble: " << sizeof(myLongDouble) << " bytes, Address: " << static_cast<void*>(&myLongDouble) << std::endl;

    std::cout << "Size of myBool: " << sizeof(myBool) << " bytes, Address: " << static_cast<void*>(&myBool) << std::endl;

    std::cout << "Size of myVoidPtr: " << sizeof(myVoidPtr) << " bytes, Address: " << static_cast<void*>(&myVoidPtr) << std::endl;
    std::cout << "Size of myNullPtr: " << sizeof(myNullPtr) << " bytes, Address: " << static_cast<void*>(&myNullPtr) << std::endl;

    // Print the size of each pointer
    std::cout << "Size of pChar: " << sizeof(pChar) << " bytes" << std::endl;
    std::cout << "Size of pChar16: " << sizeof(pChar16) << " bytes" << std::endl;
    std::cout << "Size of pChar32: " << sizeof(pChar32) << " bytes" << std::endl;
    std::cout << "Size of pWideChar: " << sizeof(pWideChar) << " bytes" << std::endl;

    std::cout << "Size of pSignedChar: " << sizeof(pSignedChar) << " bytes" << std::endl;
    std::cout << "Size of pSignedShortInt: " << sizeof(pSignedShortInt) << " bytes" << std::endl;
    std::cout << "Size of pSignedInt: " << sizeof(pSignedInt) << " bytes" << std::endl;
    std::cout << "Size of pSignedLongInt: " << sizeof(pSignedLongInt) << " bytes" << std::endl;
    std::cout << "Size of pSignedLongLongInt: " << sizeof(pSignedLongLongInt) << " bytes" << std::endl;

    std::cout << "Size of pUnsignedChar: " << sizeof(pUnsignedChar) << " bytes" << std::endl;
    std::cout << "Size of pUnsignedShortInt: " << sizeof(pUnsignedShortInt) << " bytes" << std::endl;
    std::cout << "Size of pUnsignedInt: " << sizeof(pUnsignedInt) << " bytes" << std::endl;
    std::cout << "Size of pUnsignedLongInt: " << sizeof(pUnsignedLongInt) << " bytes" << std::endl;
    std::cout << "Size of pUnsignedLongLongInt: " << sizeof(pUnsignedLongLongInt) << " bytes" << std::endl;

    std::cout << "Size of pInt8: " << sizeof(pInt8) << " bytes" << std::endl;
    std::cout << "Size of pUint8: " << sizeof(pUint8) << " bytes" << std::endl;
    std::cout << "Size of pInt16: " << sizeof(pInt16) << " bytes" << std::endl;
    std::cout << "Size of pUint16: " << sizeof(pUint16) << " bytes" << std::endl;
    std::cout << "Size of pInt32: " << sizeof(pInt32) << " bytes" << std::endl;
    std::cout << "Size of pUint32: " << sizeof(pUint32) << " bytes" << std::endl;
    std::cout << "Size of pInt64: " << sizeof(pInt64) << " bytes" << std::endl;
    std::cout << "Size of pUint64: " << sizeof(pUint64) << " bytes" << std::endl;

    std::cout << "Size of pFloat: " << sizeof(pFloat) << " bytes" << std::endl;
    std::cout << "Size of pDouble: " << sizeof(pDouble) << " bytes" << std::endl;
    std::cout << "Size of pLongDouble: " << sizeof(pLongDouble) << " bytes" << std::endl;

    std::cout << "Size of pBool: " << sizeof(pBool) << " bytes" << std::endl;



    // Print the max and min values
    std::cout << "Max value of myChar: " << std::numeric_limits<decltype(myChar)>::max() << std::endl;
    std::cout << "Min value of myChar: " << std::numeric_limits<decltype(myChar)>::min() << std::endl;

    std::cout << "Max value of myChar16: " << std::numeric_limits<decltype(myChar16)>::max() << std::endl;
    std::cout << "Min value of myChar16: " << std::numeric_limits<decltype(myChar16)>::min() << std::endl;

    std::cout << "Max value of myChar32: " << std::numeric_limits<decltype(myChar32)>::max() << std::endl;
    std::cout << "Min value of myChar32: " << std::numeric_limits<decltype(myChar32)>::min() << std::endl;

    std::cout << "Max value of myWideChar: " << std::numeric_limits<decltype(myWideChar)>::max() << std::endl;
    std::cout << "Min value of myWideChar: " << std::numeric_limits<decltype(myWideChar)>::min() << std::endl;

    std::cout << "Max value of mySignedChar: " << std::numeric_limits<decltype(mySignedChar)>::max() << std::endl;
    std::cout << "Min value of mySignedChar: " << std::numeric_limits<decltype(mySignedChar)>::min() << std::endl;

    std::cout << "Max value of mySignedShortInt: " << std::numeric_limits<decltype(mySignedShortInt)>::max() << std::endl;
    std::cout << "Min value of mySignedShortInt: " << std::numeric_limits<decltype(mySignedShortInt)>::min() << std::endl;

    std::cout << "Max value of mySignedInt: " << std::numeric_limits<decltype(mySignedInt)>::max() << std::endl;
    std::cout << "Min value of mySignedInt: " << std::numeric_limits<decltype(mySignedInt)>::min() << std::endl;

    std::cout << "Max value of mySignedLongInt: " << std::numeric_limits<decltype(mySignedLongInt)>::max() << std::endl;
    std::cout << "Min value of mySignedLongInt: " << std::numeric_limits<decltype(mySignedLongInt)>::min() << std::endl;

    std::cout << "Max value of mySignedLongLongInt: " << std::numeric_limits<decltype(mySignedLongLongInt)>::max() << std::endl;
    std::cout << "Min value of mySignedLongLongInt: " << std::numeric_limits<decltype(mySignedLongLongInt)>::min() << std::endl;

    std::cout << "Max value of myUnsignedChar: " << std::numeric_limits<decltype(myUnsignedChar)>::max() << std::endl;
    std::cout << "Min value of myUnsignedChar: " << std::numeric_limits<decltype(myUnsignedChar)>::min() << std::endl;

    std::cout << "Max value of myUnsignedShortInt: " << std::numeric_limits<decltype(myUnsignedShortInt)>::max() << std::endl;
    std::cout << "Min value of myUnsignedShortInt: " << std::numeric_limits<decltype(myUnsignedShortInt)>::min() << std::endl;

    std::cout << "Max value of myUnsignedInt: " << std::numeric_limits<decltype(myUnsignedInt)>::max() << std::endl;
    std::cout << "Min value of myUnsignedInt: " << std::numeric_limits<decltype(myUnsignedInt)>::min() << std::endl;

    std::cout << "Max value of myUnsignedLongInt: " << std::numeric_limits<decltype(myUnsignedLongInt)>::max() << std::endl;
    std::cout << "Min value of myUnsignedLongInt: " << std::numeric_limits<decltype(myUnsignedLongInt)>::min() << std::endl;

    std::cout << "Max value of myUnsignedLongLongInt: " << std::numeric_limits<decltype(myUnsignedLongLongInt)>::max() << std::endl;
    std::cout << "Min value of myUnsignedLongLongInt: " << std::numeric_limits<decltype(myUnsignedLongLongInt)>::min() << std::endl;

    std::cout << "Max value of m_int8: " << std::numeric_limits<std::int8_t>::max() << std::endl;
    std::cout << "Min value of m_int8: " << std::numeric_limits<std::int8_t>::min() << std::endl;

    std::cout << "Max value of m_uint8: " << std::numeric_limits<std::uint8_t>::max() << std::endl;
    std::cout << "Min value of m_uint8: " << std::numeric_limits<std::uint8_t>::min() << std::endl;

    std::cout << "Max value of m_int16: " << std::numeric_limits<std::int16_t>::max() << std::endl;
    std::cout << "Min value of m_int16: " << std::numeric_limits<std::int16_t>::min() << std::endl;

    std::cout << "Max value of m_uint16: " << std::numeric_limits<std::uint16_t>::max() << std::endl;
    std::cout << "Min value of m_uint16: " << std::numeric_limits<std::uint16_t>::min() << std::endl;

    std::cout << "Max value of m_int32: " << std::numeric_limits<std::int32_t>::max() << std::endl;
    std::cout << "Min value of m_int32: " << std::numeric_limits<std::int32_t>::min() << std::endl;

    std::cout << "Max value of m_uint32: " << std::numeric_limits<std::uint32_t>::max() << std::endl;
    std::cout << "Min value of m_uint32: " << std::numeric_limits<std::uint32_t>::min() << std::endl;

    std::cout << "Max value of m_int64: " << std::numeric_limits<std::int64_t>::max() << std::endl;
    std::cout << "Min value of m_int64: " << std::numeric_limits<std::int64_t>::min() << std::endl;

    std::cout << "Max value of m_uint64: " << std::numeric_limits<std::uint64_t>::max() << std::endl;
    std::cout << "Min value of m_uint64: " << std::numeric_limits<std::uint64_t>::min() << std::endl;


    std::cout << "Max value of myFloat: " << std::numeric_limits<decltype(myFloat)>::max() << std::endl;
    std::cout << "Min value of myFloat: " << std::numeric_limits<decltype(myFloat)>::min() << std::endl;

    std::cout << "Max value of myDouble: " << std::numeric_limits<decltype(myDouble)>::max() << std::endl;
    std::cout << "Min value of myDouble: " << std::numeric_limits<decltype(myDouble)>::min() << std::endl;

    std::cout << "Max value of myLongDouble: " << std::numeric_limits<decltype(myLongDouble)>::max() << std::endl;
    std::cout << "Min value of myLongDouble: " << std::numeric_limits<decltype(myLongDouble)>::min() << std::endl;

    std::cout << "Max value of myBool: " << std::numeric_limits<decltype(myBool)>::max() << std::endl;
    std::cout << "Min value of myBool: " << std::numeric_limits<decltype(myBool)>::min() << std::endl;

    std::cout << "Max value of myVoidPtr: " << std::numeric_limits<decltype(myVoidPtr)>::max() << std::endl;
    std::cout << "Min value of myVoidPtr: " << std::numeric_limits<decltype(myVoidPtr)>::min() << std::endl;

    std::cout << "Max value of myNullPtr: " << std::numeric_limits<decltype(myNullPtr)>::max() << std::endl;
    std::cout << "Min value of myNullPtr: " << std::numeric_limits<decltype(myNullPtr)>::min() << std::endl;


    return 0;
}
