// Inspired from ...

#define SPI_CHANNEL  0
#define SPI_SPEED 1000000
#define SPI_MODE 0
#define BITS_PER_CHAR 8
#define CHARS_PER_VAR 2

#include <wiringPiSPI.h>
#include <thread>
#include <chrono>
#include <utility>
#include <iostream>

/*
Variables to update on Pi side:
_state
_score1
_score2

The SPI API sends data over the bus using chars. Chars are 8 bits long.
Ints are 32 bits long. The extern ints will need to be split into 4 separate chars.
*/

extern int  _state,
            _ballX,
            _ballY,
            _car1,
            _car2,
            _score1,
            _score2;

void convertToChar(unsigned char *buffer, int input, int word)
{
//    unsigned char sec1[BITS_PER_CHAR], sec2[BITS_PER_CHAR], sec3[BITS_PER_CHAR], sec4[BITS_PER_CHAR];
//    unsigned int bitMask = 0xFF000000;
//
////    buffer[0] = 1;
//
//    sec1 = static_cast<const unsigned char>(input & (bitMask >> (0x0 + 8 * 0)));
//    sec2 = static_cast<const unsigned char>(input & (bitMask >> (0x8 + 8 * 0)));
//    sec3 = static_cast<const unsigned char>(input & (bitMask >> (0x8 + 8 * 1)));
//    sec4 = static_cast<const unsigned char>(input & (bitMask >> (0x8 + 8 * 2)));
//
//    for (int i = 0; i < BITS_PER_CHAR; i++)
//    {
//        buffer[i + word + 8 * 0] = sec1[i];
//        buffer[i + word + 8 * 1] = sec2[i];
//        buffer[i + word + 8 * 2] = sec3[i];
//        buffer[i + word + 8 * 3] = sec4[i];
//    }


    std::cout << buffer;
}

int convertToInt(unsigned char &buffer, int word)
{
    unsigned int output = 0;

//    output |= (static_cast<unsigned int>(buffer[word]) << 24);
//    output |= (static_cast<unsigned int>(buffer[word + 8]) << 16);
//    output |= (static_cast<unsigned int>(buffer[word + 16]) << 8);
//    output |= static_cast<unsigned int>(buffer[word + 24]);

    return output;
}

void do_spi()
{
    enum word { update,
                state = update + (BITS_PER_CHAR * CHARS_PER_VAR),
                score1 = state  + (BITS_PER_CHAR * CHARS_PER_VAR),
                score2 = score1  + (BITS_PER_CHAR * CHARS_PER_VAR),
                ballX = score2 + (BITS_PER_CHAR * CHARS_PER_VAR),
                ballY = ballX + (BITS_PER_CHAR * CHARS_PER_VAR),
                car1 = ballY + (BITS_PER_CHAR * CHARS_PER_VAR),
                car2 = car1 + (BITS_PER_CHAR * CHARS_PER_VAR),
                bufferSize = car2 + (BITS_PER_CHAR * CHARS_PER_VAR)};

    int fd, result;
    unsigned char buffer[2];

    fd = wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED);

    _ballX = 0x1;
    _ballY = 0x2;
    _car1 = 0x3;
    _car2 = 0x4;

    while (true)
    {
        for (int i = 1; i <= 0xFF; i <<= 1)
        {
            // Following are received bits; don't care about transmit values
//            buffer[0] = 0x12;
//            buffer[1] = 0x20;
//            buffer[2] = 0x35;
//            buffer[3] = 0x43;
//
//            buffer[4] = 0x65;
//            buffer[5] = 0x87;
//            buffer[6] = 0x90;
//            buffer[7] = 0x63;


            // Following are transmitted bits; must convert ints to chars
//            convertToChar(&buffer[word::bufferSize / (BITS_PER_CHAR * CHARS_PER_VAR)], ballX, word::ballX);
//            convertToChar(&buffer[word::bufferSize / (BITS_PER_CHAR * CHARS_PER_VAR)], ballY, word::ballY);
//            convertToChar(&buffer[word::bufferSize / (BITS_PER_CHAR * CHARS_PER_VAR)], car1, word::car1);
//            convertToChar(&buffer, car2, word::car2);

//            buffer[word::ballX] = (_ballX >> 8) * 0xFF;
//            buffer[word::ballX + 8] = (_ballX) * 0xFF;
//            buffer[word::ballY] = (_ballX >> 8) * 0xFF;
//            buffer[word::ballY + 8] = (_ballX) * 0xFF;
//            buffer[word::car1] = (_car1 >> 8) * 0xFF;
//            buffer[word::car1+ 8] = (_car1) * 0xFF;
//            buffer[word::car2] = (_car2 >> 8) * 0xFF;
//            buffer[word::car2 + 8] = (_car2) * 0xFF;
//            buffer[0] = 0;
            buffer[0] = 23;
            buffer[1] = 32;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

//            _state |= (buffer[word::state] << 8);
//            _state |= (buffer[word::state + 8]);
            _state = (unsigned int)buffer[1];

//            output |= (static_cast<unsigned int>(buffer[word]) << 24);
//            output |= (static_cast<unsigned int>(buffer[word + 8]) << 16);
//            output |= (static_cast<unsigned int>(buffer[word + 16]) << 8);
//            output |= static_cast<unsigned int>(buffer[word + 24]);


//            _state = convertToInt(&buffer, word::state);
//            _score1 = convertToInt(&buffer, word::score1);;
//            _score2 = convertToInt(&buffer, word::score2);

//            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}



void spi_test()
{
    int fd, result;
    unsigned char buffer [100];

    fd = wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED);

    while (true)
    {
//        wiringPiSPIDataRW(SPI_CHANNEL, buffer, 1);

        for (int i = 1; i <= 0x7f; i <<= 1)
        {
            buffer[0] = 0x77;
            buffer[1] = i;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

            buffer[0] = 0x7b;
            buffer[1] = i;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

            buffer[0] = 0x7c;
            buffer[1] = i;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

            buffer[0] = 0x7d;
            buffer[1] = i;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

            buffer[0] = 0x7e;
            buffer[1] = i;
            wiringPiSPIDataRW(SPI_CHANNEL, buffer, 2);

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

//        buffer[0]++;
    }
}
