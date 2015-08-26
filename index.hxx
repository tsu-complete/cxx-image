
#pragma once

#include <cxx-array/index.hxx>

template <class t_size, std::size_t N>
using Pixel = Array<t_size, N>;

template <std::size_t N>
using PixelByte = Pixel<char, N>;

typedef PixelByte<1> Pixel1Byte;
typedef PixelByte<3> Pixel3Byte;
typedef PixelByte<4> Pixel4Byte;

template <std::size_t N>
using PixelInt = Pixel<int, N>;

typedef PixelInt<1> Pixel1Int;
typedef PixelInt<3> Pixel3Int;
typedef PixelInt<4> Pixel4Int;

template <std::size_t N>
using PixelUInt = Pixel<unsigned int, N>;

typedef PixelUInt<1> Pixel1UInt;
typedef PixelUInt<3> Pixel3UInt;
typedef PixelUInt<4> Pixel4UInt;

template <std::size_t N>
using PixelFloat = Pixel<double, N>;

typedef PixelFloat<1> Pixel1Float;
typedef PixelFloat<3> Pixel3Float;
typedef PixelFloat<4> Pixel4Float;


template <class Pixel>
class Image
{
protected:
    Pixel          *m_buffer;
    Pixel         **m_buffer_ref;
    unsigned int    m_width
               ,    m_height
               ,    m_size;

public:
    typedef Pixel value_type;

    Image ( unsigned int width, unsigned int height )
        : m_width(width), m_height(height)
    {
        int i, count;

        m_size = width * height;

        m_buffer = new Pixel[m_size];

        m_buffer_ref = new Pixel*[height];

        for (i = 0, count = 0; i < height; i++, count += width) {
            m_buffer_ref[i] = &m_buffer[count];
        }
    }

    virtual ~Image ( )
    {
        delete[] m_buffer_ref;
        delete[] m_buffer;
    }

    Pixel *operator[] ( int y ) const
    {
        return m_buffer_ref[y];
    }

};

