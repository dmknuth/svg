#include <iostream>
#include <string>
#include <optional>

class svg
{
    public:
        svg
        (
            const int width       = 100,
            const int heigth      = 100,
            const int vb_x        = 0,
            const int vb_y        = 0,
            const int vb_width    = 100,
            const int vb_height   = 100
        );

        ~svg();
    
    void    rect(
        const int x,
        const int y,
        const int width,
        const int height,   
        const int stroke_width = 1,
        const std::optional<std::string> stroke = "black",
        const std::optional<std::string> fill = "transparent"
    );

    private:
        void    open_element(std::string element);
        void    close_element(std::string element);
        void    attribute(std::string name, int value);
        void    attribute(std::string name, double value);
        void    attribute(std::string name, std::string value);
        void    end_attributes(bool close = false);
};