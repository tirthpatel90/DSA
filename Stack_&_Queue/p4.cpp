// Implement Min Stack 
#include <iostream>
#include <stack>
#include <climits>
using namespace std;


// Brute Force Approach: 
// use pair to store the value and the current minimum at that point in time.
// Step 1: Create a stack of pairs, where each pair contains the value and the current minimum at that point in time.
// Step 2: When pushing a new value onto the stack, compare it with the current minimum (the second element of the top pair in the stack). If the new value is smaller, update the current minimum to be the new value; otherwise, keep the current minimum unchanged.
// Step 3: When popping a value from the stack, simply pop the top pair.
// Step 4: To get the current minimum, return the second element of the top pair in the stack.  
// Time Complexity: O(1) for push, pop, and getMin operations
// Space Complexity: O(2xn) for storing elements in the stack
class MinStack {
    private:
    stack<pair<int, int>> st; // Stack to store pairs of (value, current minimum)

    public:
    MinStack() {
        // Constructor to initialize the MinStack
    }

    void push(int value) {
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }

        int currentMin = st.top().second; // Get the current minimum from the top pair
        int newMin = min(value, currentMin); // Calculate the new minimum
        st.push( {value, newMin} ); // Push the new value and the updated minimum onto the stack
    }   

    void pop() {
        if(!st.empty()) {
            st.pop(); // Pop the top pair from the stack
        }
    }

    int top() {
        if(!st.empty()) {
            return st.top().first; // Return the value of the top pair
        }
        return -1; // Return -1 if the stack is empty
    } 

    int getMin() {
        if(!st.empty()) {
            return st.top().second; // Return the current minimum from the top pair
        }
        return -1; // Return -1 if the stack is empty
    }
};

// Optimized Approach:
// store the current minimum and use math to calculate the previous minimum when popping an element.
// Step 1: Create a stack to store the values and a variable to keep track of the current minimum.
// Step 2: When pushing a new value onto the stack, if the stack is empty, set the current minimum to the new value and push it onto the stack. If the new value is less than the current minimum, push a special value (2 * new value - current minimum) onto the stack and update the current minimum to the new value. Otherwise, simply push the new value onto the stack.
// Step 3: When popping a value from the stack, if the popped value is less than the current minimum, calculate the previous minimum using the formula (2 * current minimum - popped value) and update the current minimum accordingly. Otherwise, simply pop the value from the stack.
// Step 4: To get the current minimum, return the current minimum variable.
// Time Complexity: O(1) for push, pop, and getMin operations
// Space Complexity: O(n) for storing elements in the stack

class MinStackOptimized {
    private:
    stack<int> st; // Stack to store values
    int currentMin; // Variable to keep track of the current minimum

    public:
    MinStackOptimized() {
        // Constructor to initialize the MinStack
        currentMin = INT_MAX; // Initialize current minimum to maximum integer value
    }

    void push(int value) {
        if(st.empty()) {
            currentMin = value; // Set current minimum to the new value if stack is empty
            st.push(value); // Push the new value onto the stack
        } else {
            if(value < currentMin) {
                st.push(2 * value - currentMin); // Push special value onto the stack
                currentMin = value; // Update current minimum to the new value
            } else {
                st.push(value); // Push the new value onto the stack
            }
        }
    }

    void pop() {
        if(!st.empty()) {
            int topValue = st.top(); // Get the top value from the stack
            st.pop(); // Pop the top value from the stack
            if(topValue < currentMin) {
                currentMin = 2 * currentMin - topValue; // Calculate previous minimum using the formula
            }
        }
    }

    int top() {
        if(!st.empty()) {
            int topValue = st.top(); // Get the top value from the stack
            if(topValue < currentMin) {
                return currentMin; // Return current minimum if top value is less than current minimum
            } else {
                return topValue; // Return top value otherwise
            }
        }
        return -1; // Return -1 if the stack is empty
    }

    int getMin() {
        return currentMin; // Return the current minimum
    }
};

int main() {
    MinStackOptimized minStack; // Create a MinStackOptimized object

    minStack.push(1); // Push elements onto the stack
    minStack.push(4);
    minStack.push(-3);

    cout << "Current minimum: " << minStack.getMin() << endl; // Get the current minimum
    minStack.pop(); // Pop the top element from the stack
    cout << "Top element: " << minStack.top() << endl; // Get the top element
    cout << "Current minimum: " << minStack.getMin() << endl; // Get the current minimum again

    return 0;
}