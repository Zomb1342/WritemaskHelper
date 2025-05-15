#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
#include <iomanip>
#include <limits>


bool is_valid_binary(const std::string& input);

int main() {
    std::string binary_input;
    char continue_choice;

    do {
        system("cls");
        bool valid_input = false;

        while (!valid_input) {
            std::cout << "Enter a 32-bit binary number (32 0's and 1's only):\n";
            std::getline(std::cin, binary_input);

            if (!is_valid_binary(binary_input)) {
                std::cout << "Invalid input! Please enter exactly 32 binary digits (0s and 1s).\n\n";
                continue;
            }
            valid_input = true;
        }

        // Convert binary string to integer
        uint32_t big_endian = std::bitset<32>(binary_input).to_ulong();
        
        // Show hex conversion step
        std::cout << "\nResults:\n";
        std::cout << "Big Endian (binary):    " << std::bitset<32>(big_endian) << "\n";
        std::cout << "Big Endian (hex):       0x" << std::hex << std::setfill('0') 
                  << std::setw(8) << big_endian << "\n";

        // Convert to little endian using Windows byte swap
        uint32_t little_endian = _byteswap_ulong(big_endian);
        
        std::cout << "Little Endian (hex):    0x" << std::hex << std::setfill('0') 
                  << std::setw(8) << little_endian << "\n";
        std::cout << "Little Endian (binary): " << std::bitset<32>(little_endian) << "\n\n";

        // Ask if user wants to continue
        std::cout << "Would you like to convert another number? (y/n): ";
        std::cin >> continue_choice;
        
        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (continue_choice == 'y' || continue_choice == 'Y');

    return 0;
}

// Function to validate binary input
bool is_valid_binary(const std::string& input) {
    if (input.length() != 32) return false;
    
    for (char c : input) {
        if (c != '0' && c != '1') return false;
    }
    
    return true;
}
