
#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

const int N = 50000;

// Custom Stack
template <class T>
class MyStack
{
private:
    T data[N];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (top < N - 1)
            data[++top] = value;
    }

    T pop()
    {
        if (top >= 0)
            return data[top--];

        return T();
    }

    bool empty()
    {
        return top == -1;
    }
};

// Custom Queue
template <class T>
class MyQueue
{
private:
    T data[N];
    int front, rear;

public:
    MyQueue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(T value)
    {
        if (rear < N - 1)
            data[++rear] = value;
    }

    T dequeue()
    {
        if (front <= rear)
            return data[front++];

        return T();
    }

    bool empty()
    {
        return front > rear;
    }
};

int main()
{
    long long checksum = 0;

    cout << "\n========================================" << endl;
    cout << "       STACK AND QUEUE BENCHMARK        " << endl;
    cout << "========================================" << endl;

    cout << "\nNumber of Operations: " << N << endl;

    // 1. Custom Stack Benchmark
    auto start = steady_clock::now();

    MyStack<int> myStack;

    for (int i = 0; i < N; i++)
        myStack.push(i + 10);

    long long stackSum = 0;

    while (!myStack.empty())
        stackSum += myStack.pop();

    auto end = steady_clock::now();

    auto customStackTime =
        duration_cast<microseconds>(end - start);

    // 2. STL Stack Benchmark
    start = steady_clock::now();

    stack<int> stlStack;

    for (int i = 0; i < N; i++)
        stlStack.push(i + 10);

    long long stlStackSum = 0;

    while (!stlStack.empty())
    {
        stlStackSum += stlStack.top();
        stlStack.pop();
    }

    end = steady_clock::now();

    auto stlStackTime =
        duration_cast<microseconds>(end - start);

    // 3. Custom Queue Benchmark
    start = steady_clock::now();

    MyQueue<int> myQueue;

    for (int i = 0; i < N; i++)
        myQueue.enqueue(i + 10);

    long long queueSum = 0;

    while (!myQueue.empty())
        queueSum += myQueue.dequeue();

    end = steady_clock::now();

    auto customQueueTime =
        duration_cast<microseconds>(end - start);

    // 4. STL Queue Benchmark
    start = steady_clock::now();

    queue<int> stlQueue;

    for (int i = 0; i < N; i++)
        stlQueue.push(i + 10);

    long long stlQueueSum = 0;

    while (!stlQueue.empty())
    {
        stlQueueSum += stlQueue.front();
        stlQueue.pop();
    }

    end = steady_clock::now();

    auto stlQueueTime =
        duration_cast<microseconds>(end - start);

    // Display Results
    cout << "\n------------- STACK RESULTS -------------" << endl;

    cout << "Custom Stack Time : "
         << customStackTime.count() << " microseconds" << endl;

    cout << "STL Stack Time    : "
         << stlStackTime.count() << " microseconds" << endl;

    cout << "Custom Stack Sum  : " << stackSum << endl;
    cout << "STL Stack Sum     : " << stlStackSum << endl;

    cout << "\n------------- QUEUE RESULTS -------------" << endl;

    cout << "Custom Queue Time : "
         << customQueueTime.count() << " microseconds" << endl;

    cout << "STL Queue Time    : "
         << stlQueueTime.count() << " microseconds" << endl;

    cout << "Custom Queue Sum  : " << queueSum << endl;
    cout << "STL Queue Sum     : " << stlQueueSum << endl;

    cout << "\n------------- VALIDATION ----------------" << endl;

    if (stackSum == stlStackSum &&
        queueSum == stlQueueSum &&
        stackSum == queueSum)
    {
        cout << "All operations completed successfully!" << endl;
        cout << "All validation checks passed!" << endl;
    }
    else
    {
        cout << "Validation failed!" << endl;
    }

    cout << "\n========================================" << endl;
    cout << "          BENCHMARK COMPLETED           " << endl;
    cout << "========================================" << endl;

    return 0;
}
