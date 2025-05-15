#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

// Function to convert big endian to little endian
uint32_t littleToBig(uint32_t value);

int main() {
    string binaryInput;
    
    // Accept binary input from user
    cout << "Enter a 32-bit binary number: ";
    cin >> binaryInput;
    
    // Convert binary string to integer using bitset
    bitset<32> bits(binaryInput);
    uint32_t number = bits.to_ulong();
    
    // Convert to hexadecimal (big endian)
    cout << "Hexadecimal (Big Endian): 0x" 
         << uppercase << hex << setfill('0') << setw(8) 
         << number << endl;
    
    // Convert to little endian
    uint32_t littleEndian = convertEndianness(number);
    
    // Display in hexadecimal (little endian)
    cout << "Hexadecimal (Little Endian): 0x" 
         << uppercase << hex << setfill('0') << setw(8) 
         << littleEndian << endl;
    
    return 0;
}

// Function to convert big endian to little endian
uint32_t littleToBig(uint32_t value) {
    return ((value & 0xFF000000) >> 24) |
           ((value & 0x00FF0000) >> 8)  |
           ((value & 0x0000FF00) << 8)  |
           ((value & 0x000000FF) << 24);
}
