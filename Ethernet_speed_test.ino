
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
