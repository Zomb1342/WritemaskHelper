#include <Windows.h>
#include <iostream>
#include <string>
#include <bitset>
#include <intrin.h>

// Validates that input is 32 characters and only contains '0' or '1'
bool IsInputValid(const std::string& input)
{
    if (input.length() != 32)
        return false;

    for (char c : input)
    {
        if (c != '0' && c != '1')
            return false;
    }

    return true;
}

// Converts binary string to uint32_t
uint32_t ConvertBinaryStringToUInt32(const std::string& input)
{
    return static_cast<uint32_t>(std::bitset<32>(input).to_ulong());
}

int main()
{
    std::string userInput;

    while (true)
    {
        std::cout << "Please enter a 32-character binary number consisting of 0's and 1's:\n> ";
        std::cin >> userInput;

        if (IsInputValid(userInput))
        {
            uint32_t value = ConvertBinaryStringToUInt32(userInput);
            value = _byteswap_ulong(value);
            std::cout << "Converted Value: 0x" << std::hex << value << std::dec << "\n\n";
        }
        else
        {
            std::cout << "Invalid input. Please ensure it's 32 binary digits (0 or 1 only).\n\n";
        }
    }

    return 0;
}
