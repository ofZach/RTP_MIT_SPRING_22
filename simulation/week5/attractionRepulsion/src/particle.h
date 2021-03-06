#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void addRepulsionForce( float px, float py, float radius, float strength);
		void addAttractionForce( float px, float py, float radius, float strength);
		void addClockwiseForce( float px, float py, float radius, float strength);
		void addCounterClockwiseForce( float px, float py, float radius, float strength);
	
	
		float damping;

    protected:
    private:
};

#endif // PARTICLE_H
