// Arduino Library for zph02 PM2.5 Sensor
// https://github.com/ajaybnl/ZPH02-PM2.5-Particle-Sensor-Library-for-Arduino


#include <zph02.h>
#include <arduino.h>

// initialize - allocate the interval array
void zph02::begin(int pin)
{
	_pin = pin;
	pinMode(_pin,INPUT);
	
	
    m_readings = new float[m_interval];
}







// Read and report the average
float zph02::getAqi(bool getdutycycle)
{
	
long x = pulseIn(_pin, LOW,2000000);

//Duty Cycle
m_duty = (float)(((float)x / (float)1000000) * (float)100);

//Average to AQI Convertion (as per datasheet)
float newReading = map(m_duty,0,50,0,400);


 
  
    // add each new data point to the sum until the m_readings array is filled
    if (m_nbrReadings < m_interval)
    {
        (float)++m_nbrReadings;
        m_sum = m_sum + newReading;
    }
    // once the array is filled, subtract the oldest data point and add the new one
    else
    {
        m_sum = (float)m_sum - m_readings[m_next] + newReading;
    }

    m_readings[m_next] = newReading;
    if (++m_next >= m_interval) m_next = 0;
    
	
	if(getdutycycle){
	//Return Current Duty Cycle
	return (float) (m_duty);	
	
	}else{
	//Return Average AQI	
	return (float)(m_sum / m_nbrReadings);
	
	}
	
	
	
}







// just return the current moving average
float zph02::getAvg()
{
    return (float)(m_sum / m_nbrReadings);
}

// start the moving average over again
void zph02::reset()
{
    m_nbrReadings = 0.0;
    m_sum = 0.0;
    m_next = 0;
}
