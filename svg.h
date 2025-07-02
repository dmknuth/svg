#include <iostream>
#include <string>

class svg
{
    public:
        svg
        (
            int width       = 100,
            int heigth      = 100,
            int vb_x        = 0,
            int vb_y        = 0,
            int vb_width    = 100,
            int vb_height   = 100
        );

        ~svg();
    
    void    rect(
        int x,
        int y,
        int width,
        int height,   
        int stroke_width = 1,
        std::string stroke = "black",
        std::string fill = "transparent"
    );

    private:
        void    open_element(std::string element);
        void    close_element(std::string element);
        void    attribute(std::string name, int value);
        void    attribute(std::string name, double value);
        void    attribute(std::string name, std::string value);
        void    end_attributes(bool close = false);
};