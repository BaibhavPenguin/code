#include "../ttl52int.h"

void MULUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 ,const uint8t __idata* inp2 , uint8t size){
    uint16t temp = 0;
    uint8t index2 = 0;
    uint8t index1 = 0;
    while(index1 < size){
        out[index1] = 0;
    }
    index1 = 0;
    while(index2 < size){
        
        while(index1 < (size - index2)){
            temp+= inp1[index1] * inp2[index2] + out[index1 + index2];
            out[index1 + index2] = temp & 0xFF;
            temp = temp >>8;
            index1++;
        }
        index2++;
        index1 = 0;
    
    };
    return;
}