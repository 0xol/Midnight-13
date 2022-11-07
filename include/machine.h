#ifndef MACHINE_H
#define MACHINE_H

//TYPES
#define CONVEYOR    1
#define RTG         2

struct machine {
    unsigned short TYPE;
    unsigned short RECIPE;

    unsigned char INV1;
    unsigned char INV2;
    unsigned char INV3;
    unsigned char INV4;
    unsigned char INV5;
    unsigned char INV6;
    unsigned char INV7;
    unsigned char INV8;

    unsigned char OUT1;
    unsigned char OUT2;
    unsigned char OUT3;

    unsigned char PROGRESS;
};

struct machineTILE {
    unsigned int machineID;
    unsigned int TextureID;
};



#endif