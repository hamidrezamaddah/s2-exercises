
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
    static constexpr unsigned int base64_char_num_bit = 6;

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

    bool get_bit(uint8_t *data, unsigned int bitoffset)
    {
        return ((1 << ((7 - bitoffset) % 8)) & data[bitoffset / 8]) ? 1 : 0;
    }

    uint8_t get_char(uint8_t *source, unsigned int sourceOffset)
    {
        uint8_t dest = 0;
        for (unsigned int i = 0; i < base64_char_num_bit; i++)
        {
            if (get_bit(source, i + sourceOffset))
                sbi(dest, (base64_char_num_bit - 1) - i);
            else
                cbi(dest, (base64_char_num_bit - 1) - i);
        }
        return dest;
    }

    unsigned int num_pads()
    {
        unsigned int num_bytes = input_data.size();
        for (unsigned int i = num_bytes, j = 0;; i++, j++)
        {
            if (((i * 8) % base64_char_num_bit) == 0)
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

    unsigned int round_up_div(unsigned int num, unsigned int div_to)
    {
        return (num + div_to - 1) / div_to;
    }

    std::string convert()
    {
        std::string encoded;
        unsigned int num_encoded_char = round_up_div(input_data.size() * 8 , base64_char_num_bit);
        for (int i = 0; i < num_encoded_char; i++)
        {
            uint8_t temp = get_char(input_data.data(), i * base64_char_num_bit);
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