/**This program example applies to the calculation of the circle**/
/*
The program was written by ÀîË¸å«(17207080110)
*/
/*
Formula used by the program:
circleArea = Pi*R*R
ballSurfaceArea = 4*Pi*R*R
ballVolume = 4/3*R*R*R
cylindricalVolume = Pi*R*R*H
*/

#include "stdio.h"

// Pi
const double Pi = 3.14159265;

/***Main***/
int main (){
	
	//Input var
	double R,H;
	
	//Output var
	double circleArea,ballSurfaceArea,ballVolume,cylindricalVolume;
	
	//OutHead
	printf ("This program example applies to the calculation of the circle.\n\n");
	printf ("Program was written by ÀîË¸å«(17207080110)\n\n");
	printf ("-------------------------\n\n");
	
	//Assignment OutHead
	printf ("\tWhen H=3,R=1.5\n\n");
	
	//Assignment
	H = 3.0;
	R = 1.5;
	
	//Operation
	circleArea = Pi*R*R;
	ballSurfaceArea = 4*Pi*R*R;
	ballVolume = 4/3*R*R*R;
	cylindricalVolume = Pi*R*R*H;
	
	//Basic output
	printf ("\tCircle Area = %f\n",circleArea);
	printf ("\tSurface Area of ball = %f\n",ballSurfaceArea);
	printf ("\tVolume of ball = %f\n",ballVolume);
	printf ("\tVolume of cylindrical = %f\n",cylindricalVolume);
	
	
	//Cycle
	while (1){
		
		//Interaction
		printf ("\n-------------------------\nPlease enter values for Radius and Height.\n");
		printf ("!!! Ctrl+C End Program !!!\n\n");
		
		//Initialization
		double radius,height;
		
		//Data entry
		printf ("\tRadius = ");
		scanf  ("%lf",&radius);
		printf ("\tHeight = ");
		scanf  ("%lf",&height);
			
		//Operation
		circleArea = Pi*radius*radius;
		ballSurfaceArea = 4*Pi*radius*radius;
		ballVolume = 4/3*radius*radius*radius;
		cylindricalVolume = Pi*radius*radius*height;
		
		//Basic output
		printf ("\n");
		printf ("\tCircle Area = %f\n",circleArea);
		printf ("\tSurface Area of ball = %f\n",ballSurfaceArea);
		printf ("\tVolume of ball = %f\n",ballVolume);
		printf ("\tVolume of cylindrical = %f\n",cylindricalVolume);
	
	}
	
	return 0;
}