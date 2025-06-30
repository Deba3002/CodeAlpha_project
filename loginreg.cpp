#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(const string& username) {
    ifstream file("users.txt");
    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Register\nUsername: ";
    cin >> username;

    if (userExists(username)) {
        cout << "❌ Username already exists. Try a different one.\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "✅ Registration successful!\n";
}

// Function to login an existing user
void loginUser() {
    string username, password;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUsername, storedPassword;
    bool found = false;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "✅ Login successful. Welcome, " << username << "!\n";
    } else {
        cout << "❌ Invalid username or password.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "❌ Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}