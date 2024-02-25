
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void dummy ( unsigned int );

#define GPIOABASE 0x50000000
#define GPIOBBASE 0x50000400

#define RCCBASE 0x40021000

int notmain ( void )
{
    unsigned int ra;
    unsigned int rx;

    //SLOOOOW...
    ra=GET32(RCCBASE+0x04);
    ra&=~(7<<13);
    PUT32(RCCBASE+0x04,ra);

    ra=GET32(RCCBASE+0x2C);
    ra|=1<<0; //enable port a
    PUT32(RCCBASE+0x2C,ra);
    //moder
    ra=GET32(GPIOABASE+0x00);
    ra&=~(3<<8); //PA4
    ra&=~(3<<10); //PA5
    ra|=1<<8; //PA5
    ra|=1<<10; //PA5
    PUT32(GPIOABASE+0x00,ra);
    //OTYPER
    ra=GET32(GPIOABASE+0x04);
    ra&=~(1<<4); //PA4
    ra&=~(1<<5); //PA5
    PUT32(GPIOABASE+0x04,ra);

    ra=GET32(RCCBASE+0x2C);
    ra|=1<<1; //enable port b
    PUT32(RCCBASE+0x2C,ra);
    //moder
    ra=GET32(GPIOBBASE+0x00);
    ra&=~(3<<2); //PB1
    ra|=  1<<2; //PB1
    PUT32(GPIOBBASE+0x00,ra);
    //OTYPER
    ra=GET32(GPIOBBASE+0x04);
    ra&=~(1<<1); //PB1
    PUT32(GPIOBBASE+0x04,ra);

    for(rx=0;;rx++)
    {

        PUT32(GPIOBBASE+0x18, (1<<(1+16)) );

        PUT32(GPIOABASE+0x18, (1<<(4+ 0)) | (1<<(5+16)) );
        for(ra=0;ra<10;ra++) dummy(ra);

        PUT32(GPIOBBASE+0x18, (1<<(1+0)) );

        PUT32(GPIOABASE+0x18, (1<<(4+16)) | (1<<(5+16)) );
        for(ra=0;ra<4000;ra++) dummy(ra);

        //PUT32(GPIOBBASE+0x18, (1<<(1+0)) );

        PUT32(GPIOABASE+0x18, (1<<(4+16)) | (1<<(5+ 0)) );
        for(ra=0;ra<10;ra++) dummy(ra);
        PUT32(GPIOABASE+0x18, (1<<(4+16)) | (1<<(5+16)) );
        for(ra=0;ra<4000;ra++) dummy(ra);
    }

    return(0);
}
