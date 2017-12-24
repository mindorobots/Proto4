int radio1=3;
int radio2=4;
int pulse1, pulse2;
int out1=8;
int out2=9;
int out3=10;
int out4=11;

//Threshold for signals/ obtained experimentially



void setup(){
  Serial.begin(9600);
  pinMode (radio1, INPUT);// initialises the channels
  pinMode (radio2, INPUT);// as inputs

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop (){

  pulse1 = (pulseIn (radio1, HIGH)); // Checks the value of radio1  (horizontal)
  Serial.println("Forward");
  analogWrite(6, 0);
  if (pulse1 > 1500){
     Serial.println(pulse1);
     analogWrite(5, map(pulse1,1530,1900,0,200));
     //Serial.println(map(pulse1,1530,1900,0,200));
    //analogWrite(out1, 0);
    //analogWrite(out2, 0);
    //analogWrite(out3, 0);
    //analogWrite(out4, 255); 
  }else{
    Serial.print("stop");
    analogWrite(5, 0);
  }
  Serial.print("    ");
  delay(200);

  pulse2 = (pulseIn (radio2, HIGH)); // Checks the value of radio2 (vertical)
  Serial.println("Horizontal");
  analogWrite(6, 0);
  if (pulse2 > 1500){
    Serial.println(pulse2);
     analogWrite(10, map(pulse2,1530,1900,0,200));
     //Serial.println(map(pulse2,1530,1900,0,200));
    //analogWrite(out1, 0);
    //analogWrite(out2, 0);
    //analogWrite(out3, 0);
    //analogWrite(out4, 255); 
  }else{
    Serial.print("stop");
    analogWrite(10, 0);
  }
  Serial.print("    ");
  
  
}
