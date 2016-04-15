#include <mean_forward.h>
double mean_of_forward(char pre)
{
    switch(pre)
    {
        // �������������
        case 'h': return pow(10.0,2.0);
        case 'k': return pow(10.0,3.0);
        case 'M': return pow(10.0,6.0);
        case 'G': return pow(10.0,9.0);
        case 'Т': return pow(10.0,12.0);
        case 'П': return pow(10.0,15.0);
        case 'E': return pow(10.0,18.0);
        case 'З': return pow(10.0,21.0);
        case 'И': return pow(10.0,24.0);

        // �������������
        case 'd': return pow(10.0,-1.0);
        case 'c': return pow(10.0,-2.0);
        case 'm': return pow(10.0,-3.0);
        case 'µ': return pow(10.0,-6.0);
        case 'n': return pow(10.0,-9.0);
        case 'p': return pow(10.0,-12.0);
        case 'f': return pow(10.0,-15.0);
        case 'a': return pow(10.0,-18.0);
        case 'z': return pow(10.0,-21.0);
        case 'y': return pow(10.0,-24.0);
    }
    return 1.0;
}
