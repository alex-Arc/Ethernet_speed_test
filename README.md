# Ethernet speed test
testing ethernet "speed" by sending a number of packet in bursts and testing if there is a correct reply  for each

because this is ment to optimizing for reciving ArtNet packets, that have a size of abount 550 bytes, the test is run with a packet size of 600 bytes

## Teensy 3.6
### using SPI1 without FIFO
Ethernet module | F_CPU | F_BUS | SPI | burst size
------------ | ------------ | ------------- | ------------- | -------------
Wiz850io 16K | 96MHz | 48MHz | 24MHz | 28
Wiz850io 16K | 144MHz | 48MHz | 24MHz | 29
Wiz850io 16K | 192MHz | 48MHz | 24MHz | 29
Wiz850io 16K | 216MHz | 54MHz | 27MHz | 29
Wiz850io 16K | 168MHz | 56MHz | 28MHz | 29
Wiz850io 16K | 120MHz | 60MHz | 30MHz | 29
Wiz850io 16K | 180MHz | 60MHz | 30MHz | 30
Wiz850io 16K | 240MHz | 60MHz | 30MHz | 30
Wiz850io 16K | 192MHz | 64MHz | 32MHz | 30
Wiz850io 16K | 216MHz | 72MHz | 36MHz | 30
Wiz850io 16K | 240MHz | 80MHz | 40MHz | 31
Wiz850io 16K | 240MHz | 120MHz | 40MHz | 32
Wiz850io 16K | 180MHz | 90MHz | 45MHz | 31/32
Wiz850io 16K | 192MHz | 96MHz | 48MHz | NA
Wiz850io 16K | 216MHz | 108MHz | 54MHz | NA
Wiz850io 16K | 240MHz | 120MHz | 60MHz | NA

### using SPI1 without FIFO but "correct" SPI.transfer method, maybe?
replace
```C++
for (uint16_t i=0; i<len; i++) {
  buf[i] = SPI1.transfer(0);
}
```
with
```C++
SPI1.transfer(buf, buf, len);
```
in `W5100::read`

Ethernet module | F_CPU | F_BUS | SPI | burst size
------------ | ------------ | ------------- | ------------- | -------------
Wiz850io 16K | 96MHz | 48MHz | 24MHz | 31
Wiz850io 16K | 240MHz | 120MHz | 40MHz | 37
Wiz850io 16K | 180MHz | 90MHz | 45MHz | 37


## Teensy 3.2
### using SPI0 with FIFO
Ethernet module | F_CPU | F_BUS | SPI | burst size
------------ | ------------ | ------------- | ------------- | -------------
Wiz820io 16K | 96MHz | 48MHz | 24MHz | 31
Wiz820io 16K | 120MHz | 60MHz | 30MHz | 33

### using SPI0 without FIFO
Ethernet module | F_CPU | F_BUS | SPI | burst size
------------ | ------------ | ------------- | ------------- | -------------
Wiz820io 16K | 96MHz | 48MHz | 24MHz | 28
Wiz820io 16K | 120MHz | 60MHz | 30MHz | 29
