# Arduino Library for PM2.5 AQI Particle Sensor : ZPH02



## Description
*ZPH02* is a simple Arduino library for Reading AQI moving averages Or Duty Cycle from the sensor ZPH02.

This sensor operates as a pwm source with duty cycle as a output variable in the default mode.

The user specifies the interval (number of data points) for the moving average in the constructor. When the `begin(pin)` function is called, an array is dynamically allocated to hold the number of data points in the interval. This array is never deallocated, and the user should call `begin()` only once (for a given `zph02` instance) in setup or other initialization code. Dynamic allocation is used strictly with the intent of creating the proper size array for the user's purposes, and not to free up the memory at a later point. It is strongly recommended that `zph02` objects remain allocated as long as the code is running. Failure to observe these guidelines can result in heap fragmentation, crashes and other undesired behavior.

## Constructor
### zph02(float interval)
##### Description
Defines a `zph02` object where the average is calculated using *interval* data points.
##### Syntax
`zph02(interval);`
##### Parameters
**interval:** The number of data points to use when calculating the moving average. *(float)*
##### Returns
None.
##### Example
```c++
zph02 aqi_sensor(10);    // use 10 data points for the moving average
```

## Methods
### begin(pin)
##### Description
Initializes a `zph02` object. Call `begin(pin)` once and only once for any given `zph02` instance. See comments in the **Description** section above.
##### Syntax
`begin(5);`
##### Parameters
GPIO Pin
##### Returns
None.
##### Example
```c++
aqi_sensor.begin(5);
```

### reading(bool getdutycycle)
##### Description
Adds a new data point to the moving average. Returns the new moving average value. Until the interval array is filled, the average is calculated from those data points from AQI of the sensor output pulses, i.e. a fewer number of points than defined by the constructor.
###### Syntax

###Read AQI
`reading(false);`
###Read Duty Cycle
`reading(true);`
##### Parameters
True = DutyCycle, No = AQI Moving Average
##### Returns
The new moving average value OR DutyCycle 
##### Example
```c++
// Get Duty Cycle from Sensor
float dutycycle = aqi_sensor.reading(true);

// Get AQI Moving Average from Sensor
float AQI = aqi_sensor.reading(false);

```

### getAvg()
##### Description
Returns the current moving average value without adding a new reading.
##### Syntax
`getAvg();`
##### Parameters
None.
##### Returns
The moving average value. *(float)*
##### Example
```c++
float formulaResultAvg = aqi_sensor.getAvg();
```

### reset()
##### Description
Restarts the moving average. Zeros the interval array and associated data.
##### Syntax
`reset();`
##### Parameters
None.
##### Returns
None.
##### Example
```c++
aqi_sensor.reset();
```



















##This library is written with the help of :
https://github.com/ThingEngineer/movingAvg
Written by Jack Christensen  
Mar 2012
