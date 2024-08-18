#include <iostream>
#include <thread>
#include <vector>

void memoryExample() {
    int* ptr = new int(42);  // Dynamically allocated memory
    std::cout << "Value at ptr: " << *ptr << std::endl;
    delete ptr; // Memory freed
    // Uncommenting the following line will cause a use-after-free error
    // std::cout << "Value at ptr after delete: " << *ptr << std::endl;
}

void threadExample() {
    auto threadFunc = [](int id) {
        std::cout << "Thread " << id << " is running" << std::endl;
    };

    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();
}

void UBExample() {
    int a = 42;
    int b = 0;
    // Uncommenting the following line will cause undefined behavior (division by zero)
    // int c = a / b;
    int arr[5];
    for (int i = 0; i < 10; ++i) { // UB: accessing out-of-bounds array elements
        arr[i] = i;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}

int main() {
    std::cout << "Memory Example:\n";
    memoryExample();

    std::cout << "\nThread Example:\n";
    threadExample();

    std::cout << "\nUndefined Behavior Example:\n";
    UBExample();

    return 0;
}