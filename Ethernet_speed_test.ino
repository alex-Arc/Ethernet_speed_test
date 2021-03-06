
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(2, 0, 0, 10);

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[600];  // buffer to hold incoming packet,
char ReplyBuffer[] = "acknola";        // a string to send back

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

#if defined(__MK64FX512__) || defined(__MK66FX1M0__)
#define resetpin 24
#else
#define resetpin 9
#endif

void setup() {
  // put your setup code here, to run once:
    // start the Ethernet and UDP:
pinMode(resetpin, OUTPUT);
digitalWrite(resetpin,LOW);
delayMicroseconds(2);
digitalWrite(resetpin,HIGH);
delay(200);

  Ethernet.begin(mac, ip);
  Udp.begin(localPort);
  //Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Udp.read(packetBuffer, packetSize);
        // send a reply to the IP address and port that sent us the packet we received
    ReplyBuffer[0] = packetSize;
    ReplyBuffer[1] = packetSize>>8;
    ReplyBuffer[2] = packetBuffer[packetSize-1];
    //Serial.printf("%d %d %d\n",ReplyBuffer[0], ReplyBuffer[1], ReplyBuffer[2]);
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer, 3);
    Udp.endPacket();
  }
}

/*
void setup() {
udp = new UDP( this, 6000 );  // create a new datagram connection on port 6000
//udp.log( true );     // <-- printout the connection activity
udp.listen( true );           // and wait for incoming message
}

void draw()
{
}

void keyPressed() {
if (key == ENTER) {
numPackRec = 0;
 String ip       = "2.0.0.10";  // the remote IP address
 int port        = 8888;    // the destination port
 String str = "";
 String str1 = "pjamlstont";
 for(int i  = 0; i < packetSizeMultip; i++) {
   str += str1;
 }

for(int i  = 0; i < burstSize; i++) {
  udp.send(str, ip, port );   // the message to send
  //delayMicroseconds(spacing);
}
delay(16);
println("loss = " + (burstSize - numPackRec) + " of " + burstSize);
if (burstSize - numPackRec >= 1) {
  burstSize--;
}else {
  burstSize++;
}
}
}

void receive( byte[] data ) {       // <-- default handler
//void receive( byte[] data, String ip, int port ) {  // <-- extended handler
long len = (data[0]&0xFF) | data[1]<<8;
if (len != packetSizeMultip*10) {
 println("len error");
}
if (char(data[2]) != 't') {
 println("data error");
}
numPackRec++;
}
 */
