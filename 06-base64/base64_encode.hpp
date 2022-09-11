
#ifndef _BASE64_ENCODE_
#define _BASE64_ENCODE_

#include <array>
#include <vector>
#include <cmath>

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

    void sbi(uint8_t &data, unsigned int bit)
    {
        data |= (1 << bit);
    }

    void cbi(uint8_t& data, unsigned int bit)
    {
        data &= ~(1 << bit);
    } 

    bool get_bit(uint8_t *data, uint16_t bitoffset)
    {
        return ((1 << ((7 - bitoffset) % 8)) & data[bitoffset / 8]) ? 1 : 0;
    }

    uint8_t bitcpy(uint8_t *source, uint16_t sourceOffset, uint16_t noBits)
    {
        uint8_t dest = 0;
        for (uint16_t i = 0; i < noBits; i++)
        {
            if (get_bit(source, i + sourceOffset))
                sbi(dest, 5 - (i % 8));
            else
                cbi(dest, 5 - (i % 8));
        }
        return dest;
    }

    unsigned int num_pads()
    {
        unsigned int num_bytes = input_data.size();
        for (unsigned int i = num_bytes, j = 0;; i++, j++)
        {
            if (((i * 8) % 6) == 0)
            {
                return j;
            }
        }
        return 0;
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

    std::string convert()
    {
        std::string encoded;
        unsigned int num_encoded_char = std::ceil(input_data.size() * 8 / 6.0);
        for (int i = 0; i < num_encoded_char; i++)
        {
            uint8_t temp = bitcpy(input_data.data(), i * 6, 6);
            encoded += base64_alphabet[temp];
        }
        for (unsigned int i = 0; i < num_pads(); i++)
        {
            encoded += '=';
        }
        return encoded;
    }
};

#endif