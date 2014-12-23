#ifndef GIF_H_
#define GIF_H_

#include <iostream>
#include <fstream>

#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

using namespace std;

struct gif_header
{
    char signature[4];
    char version[4];
    uint16_t width; // canvas width
    uint16_t height; // canvas height
    bool gct_flag;
    uint8_t colour_res;
    bool sort_flag;
    int gct_size;
    uint8_t bgcolour_index;
    uint8_t pixel_aspect_ratio;
    uint8_t *gct;
};

struct gif_gce
{
    uint8_t block_size;
    uint16_t disposal_method;
    bool user_input_flag;
    bool transparent_colour_flag;
    uint16_t delay_time;
    uint8_t transparent_colour_index;
};

class GIF
{
    ifstream gif_file;
    struct gif_header header;
    struct gif_gce gce;
public:
    GIF();
    GIF(const string filename);
    void open(const string filename);
    void parse();

    virtual ~GIF();

protected:
    void parse_header();
    void parse_gce();
};


class GIFParseException : public exception
{
    // const char *message;
// public:
//     GIFParseException();
//     GIFParseException(const char * mgs);

};



#endif