# Ethernet speed test
testing ethernet "speed" by sending a number of packet in burst and testing if there is a correct reply  for each

because this is ment to optimizing for reciving ArtNet packets, that have a size of abount 550 bytes, the test is run with a packet size of 600 bytes

## Teensy 3.6
Ethernet module | F_CPU | F_BUS | SPI | burst size
------------ | ------------ | ------------- | ------------- 
Wiz850io 16K | 96MHz | 48MHz | 24MHz | 28
Content in the first column | Content in the second column |
