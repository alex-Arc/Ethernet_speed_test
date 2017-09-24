# Ethernet speed test
testing ethernet "speed" by sending a number of packet in burst and testing if there is a correct reply  for each

because this is ment to optimizing for reciving ArtNet packets, that have a size of abount 550 bytes, the test is run with a packet size of 600 bytes

## Teensy 3.6
### using SPI1 without FIFO
Ethernet module | F_CPU | F_BUS | SPI | burst size 
------------ | ------------ | ------------- | ------------- | -------------
Wiz850io 16K | 96MHz | 48MHz | 24MHz | 28
Wiz850io 16K | 120MHz | 60MHz | 30MHz | 29
Wiz850io 16K | 144MHz | 48MHz | 24MHz | 29
Wiz850io 16K | 168MHz | 56MHz | 28MHz | 29
Wiz850io 16K | 180MHz | 60MHz | 30MHz | 30
Wiz850io 16K | 162MHz | 48MHz | 24MHz | 30
Wiz850io 16K | 216MHz | 54MHz | 27MHz | 30
Wiz850io 16K | 240MHz | 60MHz | 30MHz | 30
