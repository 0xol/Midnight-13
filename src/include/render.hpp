#ifndef RENDER_HPP
#define RENDER_HPP

extern unsigned short windowWidth;
extern unsigned short windowHeight;

class renderer{
    public:
        void update(void);
        void init(void);
        void renderUnits(void);
};

#endif