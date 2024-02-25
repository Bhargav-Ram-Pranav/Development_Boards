
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void dummy ( unsigned int );

#define GPIOABASE 0x48000000
#define GPIOBBASE 0x48000400
#define GPIOCBASE 0x48000800

#define RCCBASE 0x40021000

const unsigned int stuff[60][4]=
{
{0x28000005,0x00000000,0x00020001,0x00000000,}, // 00 0 1
{0x28004040,0x00000000,0x00080080,0x00000000,}, // 01 7 3
{0x28004010,0x00000000,0x00040080,0x00000000,}, // 02 7 2
{0x28004004,0x00000000,0x00020080,0x00000000,}, // 03 7 1
{0x28004001,0x00000000,0x00010080,0x00000000,}, // 04 7 0
{0x28001000,0x00000004,0x00000040,0x00020000,}, // 05 6 8
{0x28005000,0x00000000,0x00800040,0x00000000,}, // 06 6 7
{0x28001400,0x00000000,0x00200040,0x00000000,}, // 07 6 5
{0x28001100,0x00000000,0x00100040,0x00000000,}, // 08 6 4
{0x28001040,0x00000000,0x00080040,0x00000000,}, // 09 6 3
{0x28001010,0x00000000,0x00040040,0x00000000,}, // 10 6 2
{0x28001004,0x00000000,0x00020040,0x00000000,}, // 11 6 1
{0x28001001,0x00000000,0x00010040,0x00000000,}, // 12 6 0
{0x28000400,0x00000004,0x00000020,0x00020000,}, // 13 5 8
{0x28004400,0x00000000,0x00800020,0x00000000,}, // 14 5 7
{0x28001400,0x00000000,0x00400020,0x00000000,}, // 15 5 6
{0x28000500,0x00000000,0x00100020,0x00000000,}, // 16 5 4
{0x28000440,0x00000000,0x00080020,0x00000000,}, // 17 5 3
{0x28000410,0x00000000,0x00040020,0x00000000,}, // 18 5 2
{0x28000404,0x00000000,0x00020020,0x00000000,}, // 19 5 1
{0x28000401,0x00000000,0x00010020,0x00000000,}, // 20 5 0
{0x28000100,0x00000004,0x00000010,0x00020000,}, // 21 4 8
{0x28004100,0x00000000,0x00800010,0x00000000,}, // 22 4 7
{0x28001100,0x00000000,0x00400010,0x00000000,}, // 23 4 6
{0x28000500,0x00000000,0x00200010,0x00000000,}, // 24 4 5
{0x28000140,0x00000000,0x00080010,0x00000000,}, // 25 4 3
{0x28000110,0x00000000,0x00040010,0x00000000,}, // 26 4 2
{0x28000104,0x00000000,0x00020010,0x00000000,}, // 27 4 1
{0x28000101,0x00000000,0x00010010,0x00000000,}, // 28 4 0
{0x28000040,0x00000004,0x00000008,0x00020000,}, // 29 3 8
{0x28004040,0x00000000,0x00800008,0x00000000,}, // 30 3 7
{0x28001040,0x00000000,0x00400008,0x00000000,}, // 31 3 6
{0x28000440,0x00000000,0x00200008,0x00000000,}, // 32 3 5
{0x28000140,0x00000000,0x00100008,0x00000000,}, // 33 3 4
{0x28000050,0x00000000,0x00040008,0x00000000,}, // 34 3 2
{0x28000044,0x00000000,0x00020008,0x00000000,}, // 35 3 1
{0x28000041,0x00000000,0x00010008,0x00000000,}, // 36 3 0
{0x28000010,0x00000004,0x00000004,0x00020000,}, // 37 2 8
{0x28004010,0x00000000,0x00800004,0x00000000,}, // 38 2 7
{0x28001010,0x00000000,0x00400004,0x00000000,}, // 39 2 6
{0x28000410,0x00000000,0x00200004,0x00000000,}, // 40 2 5
{0x28000110,0x00000000,0x00100004,0x00000000,}, // 41 2 4
{0x28000050,0x00000000,0x00080004,0x00000000,}, // 42 2 3
{0x28000014,0x00000000,0x00020004,0x00000000,}, // 43 2 1
{0x28000011,0x00000000,0x00010004,0x00000000,}, // 44 2 0
{0x28000004,0x00000004,0x00000002,0x00020000,}, // 45 1 8
{0x28004004,0x00000000,0x00800002,0x00000000,}, // 46 1 7
{0x28001004,0x00000000,0x00400002,0x00000000,}, // 47 1 6
{0x28000404,0x00000000,0x00200002,0x00000000,}, // 48 1 5
{0x28000104,0x00000000,0x00100002,0x00000000,}, // 49 1 4
{0x28000044,0x00000000,0x00080002,0x00000000,}, // 50 1 3
{0x28000014,0x00000000,0x00040002,0x00000000,}, // 51 1 2
{0x28000005,0x00000000,0x00010002,0x00000000,}, // 52 1 0
{0x28000001,0x00000004,0x00000001,0x00020000,}, // 53 0 8
{0x28004001,0x00000000,0x00800001,0x00000000,}, // 54 0 7
{0x28001001,0x00000000,0x00400001,0x00000000,}, // 55 0 6
{0x28000401,0x00000000,0x00200001,0x00000000,}, // 56 0 5
{0x28000101,0x00000000,0x00100001,0x00000000,}, // 57 0 4
{0x28000041,0x00000000,0x00080001,0x00000000,}, // 58 0 3
{0x28000011,0x00000000,0x00040001,0x00000000,}, // 59 0 2
};

int notmain ( void )
{
    unsigned int ra;
    unsigned int rx;

    ra=GET32(RCCBASE+0x14);
    ra|=1<<17; //enable port a
    ra|=1<<18; //enable port a
    PUT32(RCCBASE+0x14,ra);

    //moder
    PUT32(GPIOABASE+0x00,0x28000000);
    PUT32(GPIOBBASE+0x00,0x00000000);
    //OTYPER
    PUT32(GPIOABASE+0x04,0x00000000);
    PUT32(GPIOBBASE+0x04,0x00000000);
    //BSRR
    PUT32(GPIOABASE+0x18,0x00FF0000);
    PUT32(GPIOBBASE+0x18,0x00FF0000);

    while(1)
    {
        for(rx=0;rx<60;rx++)
        {
            //PUT32(GPIOABASE+0x00,0x00000000);
            //PUT32(GPIOBBASE+0x00,0x00000000);
            //PUT32(GPIOABASE+0x18,0x00FF0000);
            //PUT32(GPIOBBASE+0x18,0x00FF0000);
            PUT32(GPIOABASE+0x00,stuff[rx][0]);
            PUT32(GPIOBBASE+0x00,stuff[rx][1]);
            PUT32(GPIOABASE+0x18,stuff[rx][2]);
            PUT32(GPIOBBASE+0x18,stuff[rx][3]);
            for(ra=0;ra<10000;ra++) dummy(ra);
        }
    }
    return(0);
}


/*

halt
flash write_image erase clock61/spinner00/spinner00.elf
reset

*/


