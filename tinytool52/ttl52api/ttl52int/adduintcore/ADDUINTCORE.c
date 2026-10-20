#include "../ttl52int.h"

void ADDUINTC(uint8t* out , const uint8t* inp1 ,const uint8t* inp2 , uint8t size) __reentrant {
    uint16t temp;
    uint8t carry = 0;
    uint8t counter = 0;
    while(counter < size){
        temp =  inp1[counter] +  inp2[counter] + carry;
        out[counter] = temp & 0xFF;
        carry = temp > 255;
        counter++;
    };
    return;
}