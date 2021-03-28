/******************************************************************
 * Author : Kushal Malhotra
 *
 * Description : Program to correct the data for the sensor 
 * 		 using Honer's factorization.  
 * ***************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Runs the data through the fitting line */

int main(int argc, char *argv[])
{
    int res, real, ideal;
    double x;
    while(scanf("%d %d", &ideal, &real) != EOF)
    {
     /* Insert your polynomial here, be sure to round properly */
        x = (double) real;   
        double y = (-48.9559 + x*(0.293484  - 5.31075e-05*x));
        (y >= 0) ? (y += 0.5) : (y -= 0.5);
        res = real - (int)y;
        printf("%d %d\n", ideal, res);
    }
    return 0;
}
