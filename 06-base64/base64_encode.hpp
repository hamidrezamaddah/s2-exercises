
#ifndef _BASE64_ENCODE_
#define _BASE64_ENCODE_

#include <array>
#include <vector>
#include <cmath>

#define sbi(port, bit) (port |= (1 << (bit)))
#define cbi(port, bit) (port &= ~(1 << (bit)))

class base64_encode_t
{
private:
    std::array<char, 64> base64_alphabet;
    std::vector<uint8_t> input_data;

    constexpr void fill_base64_alphabet_table()
    {
        for (int i = 0; i < 26; i++)
        {
            base64_alphabet[i] = 'A' + i;
        }
        for (int i = 0; i < 26; i++)
        {
            base64_alphabet[26 + i] = 'a' + i;
        }
        for (int i = 0; i < 10; i++)
        {
            base64_alphabet[52 + i] = '0' + i;
        }
        base64_alphabet[62] = '+';
        base64_alphabet[63] = '/';
    }

public:
    base64_encode_t()
    {
        fill_base64_alphabet_table();
    }

    void add(uint8_t *data, unsigned int len)
    {
        for (unsigned int i = 0; i < len; i++)
        {
            input_data.push_back(data[i]);
        }
    }

    void add(std::string str)
    {
        for (unsigned int i = 0; i < str.length(); i++)
        {
            input_data.push_back(str[i]);
        }
    }

    bool get_bit(uint8_t *data, uint16_t bitoffset)
    {
        return ((1 << ((7 - bitoffset) % 8)) & data[bitoffset / 8]) ? 1 : 0;
    }

    void bitcpy(uint8_t *source, uint16_t sourceOffset, uint8_t *dest, uint16_t destOffset, uint16_t noBits)
    {
        for (uint16_t i = 0; i < noBits; i++)
        {
            if (get_bit(source, i + sourceOffset))
                sbi(dest[(destOffset + i) / 8], (i + destOffset) % 8);
            else
                cbi(dest[(destOffset + i) / 8], (i + destOffset) % 8);
        }
    }

    std::string encode()
    {
        std::string encoded;
        unsigned int num_encoded_char = std::ceil(input_data.size() * 8 / 6.0);
        for (int i = 0; i < num_encoded_char; i++)
        {
            uint8_t temp;
            bitcpy(input_data.data(), i * 6, &temp, 0, 6);
            encoded += base64_alphabet[temp];
        }
        return encoded;
    }
};

#endif