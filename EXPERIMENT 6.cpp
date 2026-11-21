
#include <iostream>
#include <memory>
using namespace std;

// Resource Class
class Resource
{
private:
    string name;

public:
    Resource(string n)
    {
        name = n;
        cout << name << " Resource Created!" << endl;
    }

    ~Resource()
    {
        cout << name << " Resource Destroyed!" << endl;
    }

    void use()
    {
        cout << "Using Resource: " << name << endl;
    }
};

// Manual Smart Pointer
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
        cout << "Manual Smart Pointer Initialized" << endl;
    }

    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual Smart Pointer Released" << endl;
    }

    Resource* operator->()
    {
        return ptr;
    }

    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    cout << "===== SMART POINTER DEMONSTRATION =====" << endl;

    // Manual RAII
    cout << "\n1. MANUAL SMART POINTER" << endl;
    {
        MySmartPointer p(new Resource("File"));
        p->use();
    }

    // Unique Pointer
    cout << "\n2. UNIQUE POINTER" << endl;
    {
        unique_ptr<Resource> p =
            make_unique<Resource>("Database");

        p->use();
        cout << "Unique Pointer owns the resource exclusively" << endl;
    }

    // Shared Pointer
    cout << "\n3. SHARED POINTER" << endl;
    {
        shared_ptr<Resource> p1 =
            make_shared<Resource>("Network");

        shared_ptr<Resource> p2 = p1;

        p1->use();

        cout << "Number of owners: "
             << p1.use_count() << endl;
    }

    cout << "\n===== PROGRAM EXECUTION COMPLETED =====" << endl;

    return 0;
}
