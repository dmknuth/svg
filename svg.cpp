/*
To build:
clang++ -std=c++17 svg.cpp lumber.cpp -o svg
*/

#include "svg.h"
#include <sstream>
#include <string>

//----------------------------------------------------------------------------------------
void
svg::element_open(std::string element)
{
    std::cout << "<" << element << " ";
}

//----------------------------------------------------------------------------------------
void
svg::element_close(std::string element)
{
    std::cout << "</" << element << ">" << std::endl;
}

//----------------------------------------------------------------------------------------
// Multiple instances of attribute() to accept various data types

// Accept a string value for the attribute
void
svg::attribute(std::string name, std::string value)
{
    std::cout << name << "=\"" << value << "\"" << " ";
}

// Accept an integer value for the attribute
void
svg::attribute(std::string name, int value)
{
    std::cout << name << "=\"" << value << "\"" << " ";
}

// Accept a double value for the attribute
void
svg::attribute(std::string name, double value)
{
    std::cout << name << "=\"" << value << "\"" << " ";
}

//----------------------------------------------------------------------------------------
void
svg::element_end(bool close)
{
    std::cout << (close == true ? "/" : "") << ">" << std::endl;
}

//----------------------------------------------------------------------------------------
svg::svg
(
    const int width,
    const int heigth,
    const int vb_x,
    const int vb_y,
    const int vb_width,
    const int vb_height
)
{
    element_open("svg");
    attribute("version", "2");
    attribute("xmlns", "http://www.w3.org/2000/svg");
    attribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
    attribute("width", width);
    attribute("height", heigth);
    attribute("viewBox", std::to_string(vb_x) + " " + \
                         std::to_string(vb_y) + " " + \
                         std::to_string(vb_width) + " " + \
                         std::to_string(vb_height));
    element_end();
}

svg::~svg()
{
    element_close("svg");
}

//----------------------------------------------------------------------------------------
void
svg::group_open
(
    const std::optional<std::string>& id,
    const std::optional<std::string>& transform
)
{
    element_open("g");
    if(id)
    {
        attribute("id", *id);
    }
    
    if(transform)
    {
        std::string arg("translate(");
        arg.append(transform.value());
        arg.append(")");
        attribute("transform", arg);
    }
    element_end();
}

void
svg::group_close()
{
    element_close("g");
}

//----------------------------------------------------------------------------------------
void
svg::rect
(
    const int x,
    const int y,
    const int width,
    const int height,
    const int stroke_width,
    const std::optional<std::string>& stroke,
    const std::optional<std::string>& fill
)
{
    element_open("rect");
    attribute("x", x);
    attribute("y", y);
    attribute("width", width);
    attribute("height", height);
    if(stroke_width != 1)
        attribute("stroke_width", stroke_width);
    if(stroke)
        attribute("stroke", *stroke);
    if(fill)
        attribute("fill", *fill);
    element_end(true);
}

//----------------------------------------------------------------------------------------
void
svg::circle
(
    const int cx,
    const int cy,
    const int r,
    const int stroke_width,
    const std::optional<std::string>& stroke,
    const std::optional<std::string>& fill
)
{
    element_open("circle");
    attribute("cx", cx);
    attribute("cy", cy);
    attribute("r", r);
    if(stroke_width != 1)
        attribute("stroke_width", stroke_width);
    if(stroke)
        attribute("stroke", *stroke);
    if(fill)
        attribute("fill", *fill);
    element_end(true);
}
