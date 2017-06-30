
#include <MD_MAX72xx.h>

#define MAX_DEVICES 4
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

#define DISPLAY_MAX_X 31
#define DISPLAY_MIN_X 0
#define DISPLAY_MAX_Y 7
#define DISPLAY_MIN_Y 0

#define BTN_LEFT 7
#define BTN_RIGHT 8
#define BTN_UP 9

#define BTN_READ_LEFT !digitalRead(BTN_LEFT)
#define BTN_READ_RIGHT !digitalRead(BTN_RIGHT)
#define BTN_READ_UP !digitalRead(BTN_UP)

// SPI hardware interface
MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);

#define BORDER_CURSOR 23


#define GAME_OVER_Y 8
#define GAME_OVER_X 64

#define LEVEL_Y 8
#define LEVEL_X 96

bool level[LEVEL_Y][LEVEL_X] =
    {

    /*0*/{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    /*1*/{0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    /*2*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    /*3*/{0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,0},
    /*4*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0},
    /*5*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0},
    /*6*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0},
    /*7*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,0},
    };z



bool game_over[GAME_OVER_Y][GAME_OVER_X] =
    {

    /*0*/{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    /*1*/{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    /*2*/{0,0,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0},
    /*3*/{0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0},
    /*4*/{0,0,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0},
    /*5*/{0,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,0,0},
    /*6*/{0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0},
    /*7*/{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

struct Collider
{
    bool left;
    bool right;
    bool up;
    bool down;
};

struct Object
{
    int x;
    int y;
    int width;
    int height;
    struct Collider colliding;
};

struct Object myChar = {1,DISPLAY_MIN_Y+1, 1,1, {0,0,0,0}};


bool isJumping = false;
bool isFalling = false;
bool btn_down_right=false, btn_down_left=false, btn_down_up=false;

void setup()
{
    mx.begin();
    Serial.begin(9600);
    
    pinMode(BTN_RIGHT,INPUT);
    pinMode(BTN_LEFT,INPUT);
    pinMode(BTN_UP,INPUT);
    digitalWrite(BTN_RIGHT, HIGH);
    digitalWrite(BTN_LEFT, HIGH);
    digitalWrite(BTN_UP, HIGH);
    
    drawObject(&myChar);
    paint();
    updateCollider(&myChar);
    
}

int gametimer=0;
int cursorX=0;

void loop()
{
    if(myChar.y == 0 || myChar.x >= LEVEL_X-1)
    {
        clearObject(&myChar);
        sleep(100);
        //#define LEVEL_Y int(GAME_OVER_Y)
        //#define LEVEL_X int(GAME_OVER_X)
        cursorX=0;
        //memcpy(level, game_over, sizeof(game_over));
        myChar.x = 1;
        myChar.y = 2;
        //myChar.height = 1;
        resetCollider(&myChar);
    }
    if( isJumping==false && btn_down_up )
    {
        gametimer=0;
        isJumping=true;
    }
    if( isJumping )
    {
        jump(&myChar);
        gametimer++;
        updateCollider(&myChar);
    }

    if(isFalling==false && isJumping==false && getPO(myChar.y-1,myChar.x)==0)
    {
        isFalling=true;
    }
    
    if(isFalling)
    {
      fall(&myChar);   
      updateCollider(&myChar);
    }
    
    if( btn_down_right )
    {  
        if(myChar.colliding.right==false)
        {
            goRight(&myChar);
            updateCollider(&myChar);
        }
        btn_down_right = false;
    }
    
    if( btn_down_left )
    {
        if(myChar.colliding.left==false)
        {
            goLeft(&myChar);
            updateCollider(&myChar);
        }
        btn_down_left = false;
    }
    
    if( myChar.x>cursorX+BORDER_CURSOR )
    {
        if(cursorX+DISPLAY_MAX_X<LEVEL_X-1)
            cursorX++;
    }
    
    updateCollider(&myChar);
    paint();
    
    sleep(55);
}

void updateCollider(struct Object* thing)
{
    int y=0, x=0;
    
    resetCollider(thing);
    
    for(y=thing->y; y<thing->y+thing->height; y++)
    {
        if( getP( y,thing->x-1)==true )
        {
            thing->colliding.left = true;
            break;
        }
    }
    
    for(y=thing->y; y < thing->y+thing->height; y++)
    {
        if( getP( y, thing->x+thing->width)==true )
        {
            thing->colliding.right = true;
            break;
        }    
    }
    
    for(x=thing->x; x<thing->x+thing->width; x++)
    {
        if( getP(thing->y-1,x) == true   )
        {
            thing->colliding.down = true;
            break;
        }    
    }    
    for(x=thing->x; x < thing->x+thing->width; x++)
    {
        if( getP(thing->y+thing->height,x)==true  )
        {
            thing->colliding.up = true;
            break;
        }    
    }
}

void resetCollider(struct Object* thing)
{
    thing->colliding.left = false;
    thing->colliding.right = false;
    thing->colliding.up = false;
    thing->colliding.down = false;
}

void paint()
{
    int x=0, y=0;

    for(y=0; y<=DISPLAY_MAX_Y; y++)
    {
        for(x=0; x<=DISPLAY_MAX_X; x++)
        {
            setP(y,x, level[y][x+cursorX]);
        }
    }
}

void sleep(unsigned long n)
{
    unsigned long finishTime = millis()+n;
    int c = 0;
    
    while( millis()<finishTime )
    //for(c=0; c<n; c++)
    {
        if(btn_down_left==false && !BTN_READ_RIGHT && BTN_READ_LEFT)
            btn_down_left = true;

        if(btn_down_right==false && !BTN_READ_LEFT && BTN_READ_RIGHT)
            btn_down_right = true;

        if(btn_down_up==false && BTN_READ_UP)
            btn_down_up = true;
    }
}

void fall(struct Object* thing)
{
    clearObject(thing);
    {
        if(thing->colliding.down==false)
        {    
            thing->y += -1;
            
        }
        else if(thing->colliding.down==true)
        {
            isFalling = false;
        }
    }
    drawObject(thing);
    
}

void jump(struct Object* thing)
{
    clearObject(thing);
    if(gametimer==0)
    {
        if(thing->colliding.up==false)
        {
            thing->y += 1;
        }
        else
        {
            gametimer = -1;
            isJumping = false;
            isFalling = true;
        }
    }
    else if(gametimer==1)
    {
        if(thing->colliding.up==false)
        {
            thing->y += 1;
        }
        else
        {
            gametimer = -1;
            isJumping = false;
            isFalling = true;
        }
    }
    else if(gametimer==2)
    {
        if(thing->colliding.up==false)
        {
            thing->y += 1;
        }
        else
        {
            gametimer = -1;
            isJumping = false;
            isFalling = true;
        }
    }
    else if(gametimer==4)
    {
        if(thing->colliding.down == false)
        {    
            thing->y += -1;    
        }
        else
        {
            gametimer = -1;
            isJumping = false;
        }
    }
    
    else if(gametimer==6)
    {        
        if(thing->colliding.down == false)
        {    
            thing->y += -1;    
        }
        else
        {
            gametimer = -1;
            isJumping = false;
        }
    }
    else if(gametimer==7)
    {
        if(thing->colliding.down == false)
        {    
            thing->y = thing->y-1;
            gametimer = -1;
            isJumping = false;
        }
        else
        {
            gametimer = -1;
            isJumping = false;
            isFalling = true;
        }
    }
    drawObject(thing);

    btn_down_up = false;
}

void goRight(struct Object* thing)
{
    //if(getP(thing->y,thing->x+1)==0 && getP(thing->y+1,thing->x+1)==0 && getP(thing->y+2,thing->x+1)==0)
    //{
        if( thing->x >= LEVEL_X-1 )
            return;
    
        clearObject(thing);
        if(isFalling==true || isJumping==true)
        {
            if(getPO(thing->y-1+thing->height,thing->x+1)==0)
            {
            thing->x += 1;
            }
        }
        else
        {
            thing->x += 1;   
        }
        drawObject(thing);
    
        btn_down_right = false;
    //}
}

void goLeft(struct Object* thing)
{
    //if(getP(thing->y,thing->x-1)==0 && getP(thing->y+1,thing->x-1)==0 && getP(thing->y+2,thing->x-1)==0 )
    //{
        if( thing->x<=cursorX )
            return;
    
        clearObject(thing);
        thing->x -= 1;
        drawObject(thing);

        btn_down_left = false;
    //}
}

void clearObject(struct Object *thing)
{
    int x=0, y=0;

    for(x=0; x< thing->width; x++)
    {
        for(y=0; y< thing->height; y++)
        {
            level[thing->y+y][thing->x+x] = false;
        }
    }
}

void drawObject(struct Object *thing)
{
    int x=0, y=0;

    for(x=0; x< thing->width; x++)
    {
        for(y=0; y< thing->height; y++)
        {
            level[thing->y+y][thing->x+x] = true;
        }
    }
}

bool getP(int y, int x)
{
    return level[y][x];
}

void setP(int y, int x, bool state)
{
    int a,z;
    if(x<=7)
    {
        z=7;
        a=z-x;
        x=a;
    }
    else if(x<16)
    {
        if(x>7)
        {
            z=15;
            a=z-x;
            x=8+a;  
        }
    }
    else if(x<24)
    {
        if(x>15)
        {
            z=23;
            a=z-x;
            x=16+a;
        }
    }
    else if(x<32)
    {
        if(x>23)
        {
            z=31;
            a=z-x;
            x=24+a;
        }
    }
    mx.setPoint(y,x, state);
}

bool getPO(int y, int x)
{
    int a,z;
    if(x<=7)
    {
        z=7;
        a=z-x;
        x=a;
    }
    else if(x<16)
    {
        if(x>7)
        {
            z=15;
            a=z-x;
            x=8+a;  
        }
    }
    else if(x<24)
    {
        if(x>15)
        {
            z=23;
            a=z-x;
            x=16+a;
        }
    }
    else if(x<32)
    {
        if(x>23)
        {
            z=31;
            a=z-x;
            x=24+a;
        }
    }
    return mx.getPoint(y,x);
}
