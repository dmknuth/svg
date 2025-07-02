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
    int width,
    int heigth,
    int vb_x,
    int vb_y,
    int vb_width,
    int vb_height
)
{
    open_element("svg");
    attribute("version", "1.1");
    attribute("xmlns", "http://www.w3.org/2000/svg");
    attribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
    attribute("enable-background", "new 0 0 511 511");
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
    int x,
    int y,
    int width,
    int height,
    int stroke_width,
    std::string stroke,
    std::string fill
)
{
    open_element("rect");
    attribute("x", x);
    attribute("y", y);
    attribute("width", width);
    attribute("height", height);
    if(stroke_width != 1)
        attribute("stroke_width", stroke_width);
    if(!stroke.empty())
        attribute("stroke", stroke);
    if(!fill.empty())
        attribute("fill", fill);
    end_attributes(true);
}

//----------------------------------------------------------------------------------------
int main(int argv, char* argc[])
{
    svg output(200, 200, 0, 0, 400, 400);
    output.rect(1, 1, 99, 99, 1, "red");
    output.rect(3, 3, 95, 95, 1, "blue");
    output.rect(5, 5, 91, 91);
    return 0;
}