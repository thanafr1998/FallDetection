#include <TridentTD_LineNotify.h>
#include <SoftwareSerial.h>


#define SSID        "nnut98"
#define PASSWORD    "nnnnnnutt"
#define LINE_TOKEN  "b35EzB7rQ24rzkmzDbnktGWXQykdeyvPpGdifZGyw0H"
#define RX 13
#define TX 15 

int n = 0;
char rc;

SoftwareSerial mySerial(RX, TX); // RX | TX
boolean newData = false;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);

  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT); 
  Serial.println("Connected!");
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(400); 
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}

int s=0;
int stopp=0;
void loop(){  
  if(mySerial.available()>0){
       rc=mySerial.read();
       Serial.println(rc);
       if(rc=='f' && stopp==0){
        Serial.println("fall");
        LINE.notify("คนแก่ล้ม!!!!!!");
        s++;
        if(s==3){
          stopp=1;
          }
        }
       else if(rc=='n'){
         Serial.println("not fall");
        }   
    }
       n=mySerial.available();
  delay(500);
  }
