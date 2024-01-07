The system acts as a beginners 5x5 chessboard. While pieces are picked up, LEDS on certain tiles will
light up to indicate the direction in which legal moves can be made. In order to do this, we will have
LEDS attached to each tile on the chessboard as well as hall effect sensors which look for magnetic fields.
We will lastly have magnets attached to the bottom of every piece, so the sensors can detect the presence
or absence of each piece. The LEDS will be controlled by the 8x8 HT16k33 I2C backpack (multiplexer)
used in Assignment 2, while the switches will be controlled and connected to a series of GPIO pins on
BeagleBone Green.
