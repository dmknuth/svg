#include <iostream>
#include <string>

enum UNIT
{
    NONE = 0,
    INCH,
    CM,
    PIXEL
};

class shape
{
    private:
        std::string id;
        std::string fill;
        std::string stroke;
        double      stroke_width;
        double      stroke_opacity;
        std::string font_family;
        std::string font_size;
        UNIT        units;
    
    public:
        shape() : 
            id("0"), 
            fill("transparent"), 
            stroke("black"), 
            stroke_width(1.0), 
            stroke_opacity(1.0),
            font_family("helvetica"),
            font_size("12"),
            units(PIXEL) {}
        ~shape() {}
        void virtual draw() = 0;
        
        void    translate(double tx, double ty);
        void    scale(double sx, double sy);
        void    rotate(double rx, double ry, double theta);
        
        void    set_id(std::string in_id) { id = in_id; }
        void    set_fill(std::string in_fill) { fill = in_fill; }
        void    set_stroke(std::string in_stroke) { stroke = in_stroke; }
        void    set_stroke_width(double in_stroke_width) { stroke_width = in_stroke_width; }
        void    set_stroke_opacity(double in_stroke_opacity) {stroke_opacity = in_stroke_opacity; }
        void    set_font_family(std::string in_font_family) {font_family = in_font_family; }
        void    set_font_size(std::string in_font_size) {font_size = in_font_size; }
        void    set_units(UNIT in_unit);
        const std::string get_id() { return id; }
};

class rect : public shape
{
    private:
        double  length;
        double  width;
        double  x;
        double  y;
        
    public:
        rect(double in_length, double in_width) : length(in_length), width(in_width) {}
        void    draw();
        
};