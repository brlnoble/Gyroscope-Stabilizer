<h1>Gyroscope-Stabilizer</h1>

<p>Image stabilizing gyroscope to be used for a Raspberry Pi camera. This will eventually be attached to an RC car, allowing for smoother video footage.</p>

<hr>

<h3>Current Progress</h3>
<p>X and Y axis being continuously read and converted to their respective angles between -90 and 90 degrees. The X axis movements have been translated to a servo, whose rotations follow the same angle. Angle measurements being displayed in a serial monitor on a computer.</p>
<ul style="list-style-type:circle;">
  <li><del>Analog reading from X axis</del></li>
  <li><del>Angle conversion of X reading</del></li>
  <li><del>Analog reading from Y axis</del></li>
  <li><del>Angle conversion of Y reading</del></li>
  <li>Analog reading from Z axis</li>
  <li>Height conversion of Z reading</li>
  <br>
  <li><del>Low pass filters for signal noise</del></li>
  <li><del>Sample averages for signal noise</del></li>
  <br>
  <li>Mount for X axis servo</li>
  <li>Mount for Y axis servo</li>
  <li>Mount for Z axis stepper/rod</li>
  <br>
  <li><del>Servo replicating X axis movement</del></li>
  <li>Servo counteracting X axis movement</li>
  <li>Servo replicating Y axis movement</li>
  <li>Servo counteracting Y axis movement</li>
  <li>Stepper motor following Z axis movement</li>
  <li>Stepper motor counteracting Z axis movement</li>
  <br>
  <li>Completed mount for all motors</li>
  <li>Camera mounted and stabilized</li>
</ul>

<hr>

<p>For this project, I am using the following:</p>
<ul>
  <li>Uno R3 Microcontroller(<a href="https://wiki.keyestudio.com/Ks0001_keyestudio_UNO_R3_BOARD">Keystudio</a>)</li>
  <li>MG995 Servo Motors (<a href="https://www.towerpro.com.tw/product/mg995/">Towerpro</a>)</li>
  <li>5014-861 Stepper Motor (<a href="https://shop.sayal.com/products/2621-ca1">???</a>)</li>
  <li>ADXL 337 Accelerometer (<a href="https://www.analog.com/media/en/technical-documentation/data-sheets/ADXL337.pdf">Analog Devices</a>)</li>
</ul>
