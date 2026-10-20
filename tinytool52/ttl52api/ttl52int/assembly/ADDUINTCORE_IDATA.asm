;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module ADDUINTCORE_IDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ADDUINTC_IDATA_PARM_4
	.globl _ADDUINTC_IDATA_PARM_3
	.globl _ADDUINTC_IDATA_PARM_2
	.globl _ADDUINTC_IDATA
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_ADDUINTC_IDATA_PARM_2:
	.ds 1
_ADDUINTC_IDATA_PARM_3:
	.ds 1
_ADDUINTC_IDATA_PARM_4:
	.ds 1
_ADDUINTC_IDATA_out_10000_136:
	.ds 1
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; uninitialized external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; initialized external ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'ADDUINTC_IDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_ADDUINTC_IDATA_PARM_2'
;inp2          Allocated with name '_ADDUINTC_IDATA_PARM_3'
;size          Allocated with name '_ADDUINTC_IDATA_PARM_4'
;out           Allocated with name '_ADDUINTC_IDATA_out_10000_136'
;temp          Allocated to registers r4 r3 
;carry         Allocated to registers r6 
;counter       Allocated to registers r5 
;------------------------------------------------------------
;	adduintcore/ADDUINTCORE_IDATA.c:3: void ADDUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 , const uint8t __idata* inp2 , uint8t size){
;	-----------------------------------------
;	 function ADDUINTC_IDATA
;	-----------------------------------------
_ADDUINTC_IDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_ADDUINTC_IDATA_out_10000_136,dpl
;	adduintcore/ADDUINTCORE_IDATA.c:5: uint8t carry = 0;
	mov	r6,#0x00
;	adduintcore/ADDUINTCORE_IDATA.c:7: while(counter < size){
	mov	r5,#0x00
00101$:
	clr	c
	mov	a,r5
	subb	a,_ADDUINTC_IDATA_PARM_4
	jnc	00103$
;	adduintcore/ADDUINTCORE_IDATA.c:8: temp = inp1[counter] + inp2[counter] + carry;
	mov	a,r5
	add	a, _ADDUINTC_IDATA_PARM_2
	mov	r1,a
	mov	ar4,@r1
	mov	r3,#0x00
	mov	a,r5
	add	a, _ADDUINTC_IDATA_PARM_3
	mov	r1,a
	mov	ar2,@r1
	mov	r7,#0x00
	mov	a,r2
	add	a, r4
	mov	r4,a
	mov	a,r7
	addc	a, r3
	mov	r3,a
	mov	ar2,r6
	mov	a,r2
	add	a, r4
	mov	r4,a
	mov	a,r7
	addc	a, r3
	mov	r3,a
;	adduintcore/ADDUINTCORE_IDATA.c:9: out[counter] = temp & 0xFF;
	mov	a,r5
	add	a, _ADDUINTC_IDATA_out_10000_136
	mov	r1,a
	mov	ar7,r4
	mov	@r1,ar7
;	adduintcore/ADDUINTCORE_IDATA.c:10: carry = temp > 255;
	clr	c
	mov	a,#0xff
	subb	a,r4
	clr	a
	subb	a,r3
	clr	a
	rlc	a
	mov	r6,a
;	adduintcore/ADDUINTCORE_IDATA.c:11: counter++;
	inc	r5
	sjmp	00101$
00103$:
;	adduintcore/ADDUINTCORE_IDATA.c:13: return;
;	adduintcore/ADDUINTCORE_IDATA.c:14: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
