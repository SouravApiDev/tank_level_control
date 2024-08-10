int tank_level_indicator = 7;
int relay_1 = 3;
int sensor_data = 2;
bool pump_state = false;
void setup() {
  pinMode(tank_level_indicator, OUTPUT);
  pinMode(relay_1, OUTPUT);
  pinMode(sensor_data, INPUT);
}

void loop() {
  int sensor_data_temp = map_function(analogRead(sensor_data), 0, 1023, 0, 255);
  analogWrite(tank_level_indicator, sensor_data_temp);
  if(sensor_data_temp<5 && !pump_state){
    digitalWrite(relay_1, HIGH);
  }
  else if(sensor_data_temp>254 && pump_state){
    digitalWrite(relay_1, LOW);
  }
}
long map_function(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
