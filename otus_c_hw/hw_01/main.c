#include <stdio.h>
#include <string.h>

static const unsigned short cp1251_to_unicode[128] = {
    0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
    0x20AC, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
    0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x003F, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
    0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
    0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
    0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
    0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
    0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
    0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
    0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
    0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F
};


typedef struct
{
    char* bits;
    int len;
} utf8;


int unicode_to_utf8(unsigned int code, unsigned char* utf8) 
{
    if (code <= 0x7F) {
        utf8[0] = code;
        return 1;
    } else if (code <= 0x7FF) {
        utf8[0] = 0xC0 | (code >> 6);
        utf8[1] = 0x80 | (code & 0x3F);
        return 2;
    } else if (code <= 0xFFFF) {
        utf8[0] = 0xE0 | (code >> 12);
        utf8[1] = 0x80 | ((code >> 6) & 0x3F);
        utf8[2] = 0x80 | (code & 0x3F);
        return 3;
    }
}


void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);

    printf("\n");
}

/*char* cp1251_to_utf8(const char* str)
{
    if(!str) return NULL;

    size_t len = strlen(str);
    unsigned char* result = malloc(len * 3 + 1);
    if (!result) return NULL;

    for (size_t i = 0; i < len; i++) 
    {
        unsigned char c = str[i];
        unsigned int unicode;

        if(c<128)
        {
            unicode=c;
        }
        else
        {
            unicode = cp1251_to_unicode[c-128];
        }

        int utf8_len = unicode_to_utf8(unicode, result);
        result += utf8_len;
    }
    return result;
}*/

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    //const char *output_filename = argv[2];

    FILE *input_file = fopen(input_filename, "rb");
    
    int byte;
    while ((byte = fgetc(input_file)) != EOF) 
    {
        if(byte < 127)
        {
            continue;
        }
        else
        {
            utf8 b = unicode_to_utf8(cp1251_to_unicode[byte-128]);
            //decToBinary(cp1251_to_unicode[byte-128]);
            printf("%d", b.len);
            //printf("%d ", cp1251_to_unicode[byte-128]);
        }
    }
    printf("%s", input_filename);
    
}