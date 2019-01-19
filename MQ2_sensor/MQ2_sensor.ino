#define a_in A0 //AOUT-> A0

void setup(){

	pinMode(a_in, INPUT);

	Serial.begin(9600);
}

void loop(){
	Serial.println(analogRead(a_in));
 
	if(analogRead(a_in) > 200){
		digitalWrite(5, HIGH);
		delay(50);
		digitalWrite(5, LOW);

	}

}
