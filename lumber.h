
enum lumber_type
{
    COMMON = 0,
    HIP,
    JACK
};

enum lumber_size
{
    LUMBER_2X4 = 0,
    LUMBER_2X6,
    LUMBER_2X8,
    LUMBER_2X10,
    LUMBER_2X12,
    LUMBER_CUSTOM
};

class lumber
{
    private:
        double      length;
        double      tail;
        lumber_size size;
        lumber_type type;
        int         pitch;
 
        double      get_size_inches(lumber_size the_size);
        
    public:
        lumber();
        lumber
        (
            const   double      length,
            const   double      tail    = 18.0,
            const   lumber_size size    = LUMBER_2X8,
            const   lumber_type type    = COMMON,
            const   int         pitch   = 4
        );
        ~lumber();
        void    draw();

};