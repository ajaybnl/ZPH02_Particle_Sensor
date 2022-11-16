// Arduino Library for zph02 PM2.5 Sensor
// https://github.com/ajaybnl/ZPH02-PM2.5-Particle-Sensor-Library-for-Arduino

#ifndef ZPH02_H_INCLUDED
#define ZPH02_H_INCLUDED

class zph02
{
    public:
        zph02(int interval)
            : m_interval(interval), m_nbrReadings(0), m_sum(0), m_next(0) {}
        void begin(int _pin);
        float getAqi(bool getdutycycle);
        float getAvg();
        void reset();

    private:
		int _pin;
		float m_duty;
        int m_interval;       // number of data points for the moving average
        float m_nbrReadings;  // number of readings
        float m_sum;          // sum of the m_readings array
        int m_next;           // index to the next reading
        float *m_readings;    // pointer to the dynamically allocated interval array
};
#endif
