//#include <stddef.h>

static const byte led_pins[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
const byte num_leds = sizeof(led_pins) / sizeof(*led_pins);
int binary_count = 0;
byte pin_states[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void set_pin_states(int dec, byte* pins);

void setup()
{
  for(byte pin = 0; pin < num_leds; ++pin){
    pinMode(led_pins[pin], OUTPUT);
    digitalWrite(led_pins[pin], pin_states[pin]);
  }
  Serial.begin(9600);
  Serial.print("num_leds: ");
  Serial.println(num_leds);
}

void loop()
{
  if(binary_count > 1023){
    binary_count = 0;
  }
  Serial.println(binary_count);
  Serial.flush();
  set_pin_states(binary_count, pin_states);

  for(byte pin = 0; pin != num_leds; ++pin){
    // go through each pin and turn it on, delay, turn it off
    digitalWrite(led_pins[pin], pin_states[pin]);
    //digitalWrite(led_pins[pin], pin_states[pin]);
  }

  binary_count++;

  delay(250);
}

void set_pin_states(int dec, byte* pins)
{
  // sets pin states to the binary representation of dec
  for(byte pow = num_leds - 1; pow >= 0; --pow){
    /*
    Serial.print("pow: ");
    Serial.println(pow);
    Serial.print("val: ");
    Serial.println(1 << pow);
    Serial.flush();
    */
    if((dec - (1 << pow)) < 0){
      pins[pow] = 0;
    }else{
      pins[pow] = 1;
      dec -= (1 << pow);
    }
    if(pow == 0){
      // necessary to break out of for loop before pow rolls over to 255
      break;
    }
  }
  Serial.println("out of loop");
  Serial.flush();
  return;
}
