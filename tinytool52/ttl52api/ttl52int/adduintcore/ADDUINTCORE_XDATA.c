#include "../ttl52int.h"

void ADDUINTC_XDATA(uint8t __xdata* out , const uint8t __xdata* inp1 , const uint8t __xdata* inp2 , uint8t size){
    uint16t temp;
    uint8t carry = 0;
    uint8t counter = 0;
    while(counter < size){
        temp = inp1[counter] + inp2[counter] + carry;
        out[counter] = temp & 0xFF;
        carry = temp > 255;
        counter++;
    };
    return;
}