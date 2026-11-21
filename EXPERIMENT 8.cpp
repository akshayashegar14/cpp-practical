
#include <iostream>
#include <cstring>
#include <chrono>
#include <utility>
using namespace std;
using namespace chrono;

class String
{
private:
    char* data;
    size_t length;

public:

    // Constructor
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        cout << "String Created!" << endl;
    }

    // Copy Constructor
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "Copy Constructor Called!" << endl;
    }

    // Move Constructor
    String(String&& other) noexcept
    {
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;

        cout << "Move Constructor Called!" << endl;
    }

    // Copy Assignment
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            char* newData = new char[other.length + 1];
            strcpy(newData, other.data);

            delete[] data;
            data = newData;
            length = other.length;
        }

        cout << "Copy Assignment Called!" << endl;
        return *this;
    }

    // Move Assignment
    String& operator=(String&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }

        cout << "Move Assignment Called!" << endl;
        return *this;
    }

    // String Concatenation
    String operator+(const String& other) const
    {
        char* temp = new char[length + other.length + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        String result(temp);
        delete[] temp;

        return result;
    }

    // Get Length
    size_t getLength() const
    {
        return length;
    }

    // Display
    void display() const
    {
        if (data != nullptr)
            cout << data << endl;
    }

    // Destructor
    ~String()
    {
        delete[] data;
    }
};

// Perfect Forwarding
template <typename T>
String createString(T&& value)
{
    return String(forward<T>(value));
}

int main()
{
    cout << "===== COPY AND MOVE SEMANTICS =====" << endl;

    // Original String
    cout << "\n1. Creating Original String" << endl;

    String original("C++ Programming");

    // Copy Constructor
    cout << "\n2. Copy Constructor" << endl;

    String copied = original;
    copied.display();

    // Move Constructor
    cout << "\n3. Move Constructor" << endl;

    String temporary("Advanced C++ Concepts");
    String moved = move(temporary);

    cout << "Moved String: ";
    moved.display();

    // Copy Assignment
    cout << "\n4. Copy Assignment" << endl;

    String first("Hello");
    String second("World");

    first = second;
    first.display();

    // Move Assignment
    cout << "\n5. Move Assignment" << endl;

    String third("Temporary Data");
    String fourth("Empty");

    fourth = move(third);

    cout << "After Move: ";
    fourth.display();

    // String Concatenation
    cout << "\n6. String Concatenation" << endl;

    String a("Smart ");
    String b("Programming");

    String combined = a + b;

    cout << "Combined String: ";
    combined.display();

    cout << "String Length: "
         << combined.getLength() << endl;

    // Perfect Forwarding
    cout << "\n7. Perfect Forwarding" << endl;

    String forwarded = createString("Modern C++ Features");

    cout << "Forwarded String: ";
    forwarded.display();

    cout << "\n===== PROGRAM COMPLETED =====" << endl;

    return 0;
}
