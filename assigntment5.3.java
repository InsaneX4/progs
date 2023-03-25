import static java.lang.Math.sin;
import static java.lang.Math.cos;

import java.util.Scanner;

// JAVA code for implementing sin function

class assignment5_3 {

// Function for calculating sin value
static float cal_sin(float n)
{	
	float accuracy = (float) 0.0001, denominator, sinx, sinval;
	
	// Converting degrees to radian
	n = n * (float)(3.142 / 180.0);

	float x1 = n;
	
	// maps the sum along the series
	sinx = n;		
	
	// holds the actual value of sin(n)
	sinval = (float)sin(n);	
	int i = 1;
	do
	{
		denominator = 2 * i * (2 * i + 1);
		x1 = -x1 * n * n / denominator;
		sinx = sinx + x1;
		i = i + 1;
	} while (accuracy <= sinval - sinx);
	System.out.println(sinx);
    return sinx;
}
static float cal_cos(float n) {
    float accuracy = (float) 0.0001, x1, denominator, cosx, cosval;
    // Converting degrees to radian
    n = n * (float) (3.142 / 180.0);
    x1 = 1;
    // maps the sum along the series
    cosx = x1;
    // holds the actual value of sin(n)
    cosval = (float) cos(n);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i - 1);
        x1 = -x1 * n * n / denominator;
        cosx = cosx + x1;
        i = i + 1;
          
    }
    while (accuracy <= cosval - cosx);
    System.out.println(cosx);

    return cosx;
      
}

// Main function


	public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the value of n");
		float n = s.nextFloat();
	    float sinx = cal_sin(n);
        float cosx = cal_cos(n);
        verify(sinx, cosx);
        cal_cos(n);
	
	}
    private static void verify(float sinx, float cosx) {
        float sinsquarex = 2*sinx*cosx;
        float cossquarex = cosx*cosx - sinx*sinx;
        if(cossquarex + sinsquarex == 1){
            System.out.println("True values"+sinsquarex + cossquarex);
        } else{
            System.out.print("false values"+(sinsquarex + cossquarex));
        }
        
    }
}
