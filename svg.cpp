// clang++ -std=c++17 svg.cpp -o svg

#include "svg.h"

//----------------------------------------------------------------------------------------
void
svg::open_element(std::string element)
{
    std::cout << "<" << element << " ";
}

//----------------------------------------------------------------------------------------
void
svg::close_element(std::string element)
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
svg::end_attributes(bool close)
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
    open_element("svg");
    attribute("version", "2");
    attribute("xmlns", "http://www.w3.org/2000/svg");
    attribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
    attribute("width", width);
    attribute("height", heigth);
    attribute("viewBox", std::to_string(vb_x) + " " + \
                         std::to_string(vb_y) + " " + \
                         std::to_string(vb_width) + " " + \
                         std::to_string(vb_height));
    end_attributes();
}

//----------------------------------------------------------------------------------------
svg::~svg()
{
    close_element("svg");
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
    const std::optional<std::string> stroke,
    const std::optional<std::string> fill
)
{
    open_element("rect");
    attribute("x", x);
    attribute("y", y);
    attribute("width", width);
    attribute("height", height);
    if(stroke_width != 1)
        attribute("stroke_width", stroke_width);
    if(stroke)
        attribute("stroke", stroke.value());
    if(fill)
        attribute("fill", fill.value());
    end_attributes(true);
}

//----------------------------------------------------------------------------------------
int main(int argv, char* argc[])
{
    svg output(400, 400, 0, 0, 400, 400);
    output.rect(1, 1, 399, 399, 1, "red");
    output.rect(3, 3, 395, 395, 1, std::nullopt, "yellow");
    output.rect(5, 5, 391, 391);
    return 0;
}