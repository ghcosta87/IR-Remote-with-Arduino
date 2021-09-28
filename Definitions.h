#define POTENTIOMETER A0 // not in use ~ int pot = A0;
#define BUTTON 5         // not in use ~ int bot = 5;
#define IR_PIN 5 // const int RECV_PIN = 11;

#define PWM_OUTPUT_A 9 // int led = 9;
#define RELAY 8        //  int rele = 8;

#define DIMMER_STEPS 5

#define TURN_LIGHT_ON 0
#define TURN_LIGHT_OFF 1
#define INCREASE_LIGHT 2
#define TIMER_ON 3
#define TURN_OFF_NOW 4

#define SERIAL_DEBUG true
#define PRESET_TIMER 30*60000 // turn off time * 60000

const long int IR_ON[] = {0xA3C8EDDB, 0xFFA857};

const long int IR_TRY[] = {0xFFFFFFFF};

const long int IR_OFF[] =  {0xAB91951F,0xFFA05F,0xB28FED50};
const long int IR_SHINE[] =  {0xE5CFBD7F,0xFF906F};
const long int IR_TIMER[] =  {0xFF28D7,0x13549BDF};

// int led_write = 0; // not in use
