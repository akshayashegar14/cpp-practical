
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Resource Class
class Resource
{
private:
    string resourceName;

public:
    Resource(string name)
    {
        resourceName = name;
        cout << "[+] " << resourceName
             << " initialized successfully!" << endl;
    }

    ~Resource()
    {
        cout << "[-] " << resourceName
             << " released from memory!" << endl;
    }

    void use()
    {
        cout << "Using resource: " << resourceName << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
        cout << "Manual smart pointer created!" << endl;
    }

    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed!" << endl;
    }

    Resource* operator->()
    {
        return ptr;
    }

    // Prevent copying
    MySmartPointer(const MySmartPointer&) = delete;

    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    cout << "======================================" << endl;
    cout << "       SMART RESOURCE MANAGER         " << endl;
    cout << "======================================" << endl;

    // Manual RAII Smart Pointer
    cout << "\n--- 1. MANUAL SMART POINTER ---" << endl;
    {
        MySmartPointer smartPtr(new Resource("Database Connection"));
        smartPtr->use();
    }

    // Unique Pointer
    cout << "\n--- 2. UNIQUE POINTER ---" << endl;
    {
        unique_ptr<Resource> uniquePtr =
            make_unique<Resource>("File Management System");

        uniquePtr->use();

        cout << "Unique pointer owns the resource exclusively." << endl;
    }

    // Shared Pointer
    cout << "\n--- 3. SHARED POINTER ---" << endl;
    {
        shared_ptr<Resource> sharedPtr1 =
            make_shared<Resource>("Cloud Storage");

        cout << "Initial Reference Count: "
             << sharedPtr1.use_count() << endl;

        {
            shared_ptr<Resource> sharedPtr2 = sharedPtr1;

            cout << "After sharing: "
                 << sharedPtr1.use_count() << endl;

            sharedPtr1->use();
        }

        cout << "After second pointer is destroyed: "
             << sharedPtr1.use_count() << endl;
    }

    cout << "\n======================================" << endl;
    cout << "    ALL RESOURCES RELEASED SAFELY     " << endl;
    cout << "======================================" << endl;

    return 0;
}
