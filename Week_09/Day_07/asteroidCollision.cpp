#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        // Collisions only happen if top is moving right (positive) and current is moving left (negative)
        while (!st.empty() && st.top() > 0 && a < 0) {
            if (abs(st.top()) < abs(a)) {
                // Top asteroid is smaller → it explodes
                st.pop();
                continue; // check again with the new stack top
            } else if (abs(st.top()) == abs(a)) {
                // Both same size → both explode
                st.pop();
                destroyed = true; // current also explodes
                break;
            } else {
                // Top asteroid is larger → current one explodes
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            st.push(a); // current asteroid survives
        }
    }

    // Build result from stack (in reverse order)
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);

    cout << "[ ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}
