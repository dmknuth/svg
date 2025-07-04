#include "lumber.h"
#include "svg.h"

svg     output;

//----------------------------------------------------------------------------------------
lumber::lumber
(
    const   double      length,
    const   double      tail,
    const   lumber_size size,
    const   lumber_type type,
    const   int         pitch
) : length(length), tail(tail), size(size), type(type), pitch(pitch)
{
    
}

//----------------------------------------------------------------------------------------
lumber::~lumber()
{

}

//----------------------------------------------------------------------------------------
double
lumber::get_size_inches(lumber_size the_size)
{
    switch(the_size)
    {
        case LUMBER_2X4:    return 3.5;
        case LUMBER_2X6:    return 5.5;
        case LUMBER_2X8:    return 7.25;
        case LUMBER_2X10:   return 9.25;
        case LUMBER_2X12:   return 10.5;
        default:            return 0;
    }
}

//----------------------------------------------------------------------------------------
void
lumber::draw()
{
    output.group_open("1", "10, 10");
    int pixel_length = length * 12 + tail;
    double pixel_height = get_size_inches(size);
    output.rect(0, 0, pixel_length, pixel_height, 1, "brown");
    output.group_close();
}

//----------------------------------------------------------------------------------------
int
main
(
    int     argv,
    char*   argc[]
)
{    /*
    output.group_open("123");
    output.rect(1, 1, 399, 399, 1, "red");
    output.rect(3, 3, 395, 395, 1, std::nullopt, "yellow");
    output.rect(5, 5, 391, 391);
    output.circle(150, 150, 100, 2, "#22FF00");
    output.group_close();
    */
    lumber  rafter(12.0, 18.0, LUMBER_2X8, COMMON, 6);
    rafter.draw();
    return 0;
}