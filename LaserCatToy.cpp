#include <Arduino.h>
#include <Servo.h>

Servo pan;  // Horizontal movement.
Servo tilt; // Vertical movement.

int currentAnglePan = 90;  // Resting position for pan servo.
int currentAngleTilt = 90; // Resting position for tilt servo.

int newAnglePan;
int newAngleTilt;
int incrementPan;
int incrementTilt;

void setup()
{
  pan.attach(9);
  tilt.attach(10);

  pan.write(currentAnglePan);   // Reset pan servo to resting position.
  tilt.write(currentAngleTilt); // Reset tilt servo to resting position.

  delay(1000); // Show laser turret's resting position for 1 second.
}

void loop()
{
  newAnglePan = random(0, 181);   // New angle between 0 and 180 degrees.
  newAngleTilt = random(10, 181); // New angle between 10 and 180 degrees.
                                  // Not 0 to 180 degrees because of physical bounds.

  // If new angle is greater than current angle, increase current angle.
  // If new angle is less than current angle, decrease current angle.
  // To do this, need to determine if increment for each servo should be
  // positive or negative.
  newAnglePan > currentAnglePan ? incrementPan = 1 : incrementPan = -1;
  newAngleTilt > currentAngleTilt ? incrementTilt = 1 : incrementTilt = -1;

  // Move pan servo to new angle.
  for (; currentAnglePan != newAnglePan; currentAnglePan += incrementPan)
  {
    pan.write(currentAnglePan);
    delay(10); // Slows down servo.
  }

  // Move tilt servo to new angle.
  for (; currentAngleTilt != newAngleTilt; currentAngleTilt += incrementTilt)
  {
    tilt.write(currentAngleTilt);
    delay(10); // Slows down servo.
  }
}
