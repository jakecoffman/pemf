# pemf
Pulsed Electromagnetic Field device

This is a pseudo-sciency medical device you can build yourself for a fraction of the cost of buying one from a company, and when you decide it doesn't actually work you can reuse the components for something fun.

## Buy

- https://www.adafruit.com/product/3333
- https://www.adafruit.com/product/3093
- https://www.adafruit.com/product/3875
- https://www.adafruit.com/product/1466

## Install

- Arduino software
- Attach the board via USB, it should automatically install software for the board
- Select Tools -> Board -> Adafruit Circuit Playground Express... **not** Adafruit Circuit Playground -- that is apparently different
- Select Sketch -> Include Libary -> Manage Libraries and search for `seesaw`, install the library that appears there
- Select Tools -> Port and select the correct port (Serial USB?)
- Open `pemf.ino`
- Click upload

Try Googling a bunch too, there's 900 tutorials on how to use these things.
