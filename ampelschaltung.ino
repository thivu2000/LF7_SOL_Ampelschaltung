int Button = 4;
int ButtonStatus = 0;

int RED = 5;
int YELLOW = 6;    
int GREEN = 7;    

int STOP = 8;       
int WALK = 9;       

unsigned long previousMillis = 0;
int phase = 0;
unsigned long interval = 0;

void setup() {
    pinMode(Button, INPUT);
    
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);

    pinMode(STOP, OUTPUT);
    pinMode(WALK, OUTPUT);

    digitalWrite(GREEN, HIGH);
    digitalWrite(STOP, HIGH);
}

void loop() {
    ButtonStatus = digitalRead(Button);

    if (ButtonStatus == HIGH && phase == 0) {
        phase = 1; 
        previousMillis = millis();
        interval = 2000; 
    }

    unsigned long currentMillis = millis();

    switch (phase) {
        case 1: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(GREEN, LOW);
                digitalWrite(YELLOW, HIGH);
                previousMillis = currentMillis;
                interval = 1000; 
                phase = 2;
            }
            break;

        case 2: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(YELLOW, LOW);
                digitalWrite(RED, HIGH);
                previousMillis = currentMillis;
                interval = 2000; 
                phase = 3;
            }
            break;

        case 3: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(STOP, LOW);
                digitalWrite(WALK, HIGH);
                previousMillis = currentMillis;
                interval = 5000; 
                phase = 4;
            }
            break;

        case 4: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(WALK, LOW);
                digitalWrite(STOP, HIGH);
                previousMillis = currentMillis;
                interval = 2000; 
                phase = 5;
            }
            break;

        case 5: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(YELLOW, HIGH);
                previousMillis = currentMillis;
                interval = 1000; 
                phase = 6;
            }
            break;

        case 6: 
            if (currentMillis - previousMillis >= interval) {
                digitalWrite(RED, LOW);
                digitalWrite(YELLOW, LOW);
                digitalWrite(GREEN, HIGH);
                phase = 0; 
            }
            break;
    }
}
