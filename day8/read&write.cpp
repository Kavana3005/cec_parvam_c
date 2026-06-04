#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // For setw, setprecision
using namespace std;

int main() {
    // === WRITING STRUCTURED DATA ===
    ofstream outFile("students.txt");
    
    if (outFile.is_open()) {
        // Write header
        outFile << left << setw(10) << "ID"
                << setw(20) << "Name"
                << setw(10) << "CGPA" << endl;
        outFile << string(40, '-') << endl;
        
        // Write records
        outFile << setw(10) << 101 
                << setw(20) << "Arjun"
                << setw(10) << fixed << setprecision(2) << 8.75 << endl;
        
        outFile << setw(10) << 102
                << setw(20) << "Priya"
                << setw(10) << fixed << setprecision(2) << 9.20 << endl;
        
        outFile.close();
    }
    
    // === READING STRUCTURED DATA ===
    ifstream inFile("students.txt");
    string line;
    
    if (inFile.is_open()) {
        cout << "=== Student Records ===" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    
    // === READING NUMBERS ===
    ifstream numFile("numbers.txt");
    int sum = 0, num;
    
    // Create numbers file first
    ofstream createNum("numbers.txt");
    createNum << 10 << " " << 20 << " " << 30 << " " << 40 << " " << 50;
    createNum.close();
    
    // Now read and sum
    numFile.open("numbers.txt");
    while (numFile >> num) {  // Read numbers using >> operator
        sum += num;
    }
    numFile.close();
    
    cout << "\nSum of numbers: " << sum << endl;
    
    return 0;
}