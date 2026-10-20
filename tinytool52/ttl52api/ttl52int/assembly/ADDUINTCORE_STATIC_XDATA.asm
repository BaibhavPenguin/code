;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module ADDUINTCORE_STATIC_XDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ADDUINTC_STATIC_XDATA_PARM_4
	.globl _ADDUINTC_STATIC_XDATA_PARM_3
	.globl _ADDUINTC_STATIC_XDATA_PARM_2
	.globl _ADDUINTC_STATIC_XDATA
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
_ADDUINTC_STATIC_XDATA_PARM_2:
	.ds 2
_ADDUINTC_STATIC_XDATA_PARM_3:
	.ds 2
_ADDUINTC_STATIC_XDATA_PARM_4:
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
;Allocation info for local variables in function 'ADDUINTC_STATIC_XDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_ADDUINTC_STATIC_XDATA_PARM_2'
;inp2          Allocated with name '_ADDUINTC_STATIC_XDATA_PARM_3'
;size          Allocated with name '_ADDUINTC_STATIC_XDATA_PARM_4'
;out           Allocated to registers r6 r7 
;temp          Allocated to registers r3 r2 
;carry         Allocated to registers r5 
;counter       Allocated to registers r4 
;------------------------------------------------------------
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:3: void ADDUINTC_STATIC_XDATA(uint8t __xdata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size){
;	-----------------------------------------
;	 function ADDUINTC_STATIC_XDATA
;	-----------------------------------------
_ADDUINTC_STATIC_XDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6, dpl
	mov	r7, dph
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:5: uint8t carry = 0;
	mov	r5,#0x00
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:7: while(counter < size){
	mov	r4,#0x00
00101$:
	clr	c
	mov	a,r4
	subb	a,_ADDUINTC_STATIC_XDATA_PARM_4
	jnc	00103$
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:8: temp =  inp1[counter] +  inp2[counter] + carry;
	mov	a,r4
	add	a, _ADDUINTC_STATIC_XDATA_PARM_2
	mov	dpl,a
	clr	a
	addc	a, (_ADDUINTC_STATIC_XDATA_PARM_2 + 1)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	r2,#0x00
	mov	a,r4
	add	a, _ADDUINTC_STATIC_XDATA_PARM_3
	mov	dpl,a
	clr	a
	addc	a, (_ADDUINTC_STATIC_XDATA_PARM_3 + 1)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r1,#0x00
	add	a, r3
	mov	r3,a
	mov	a,r1
	addc	a, r2
	mov	r2,a
	mov	ar0,r5
	mov	a,r0
	add	a, r3
	mov	r3,a
	mov	a,r1
	addc	a, r2
	mov	r2,a
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:9: out[counter] = temp & 0xFF;
	mov	a,r4
	add	a, r6
	mov	dpl,a
	clr	a
	addc	a, r7
	mov	dph,a
	mov	ar1,r3
	mov	a,r1
	movx	@dptr,a
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:10: carry = temp > 255;
	clr	c
	mov	a,#0xff
	subb	a,r3
	clr	a
	subb	a,r2
	clr	a
	rlc	a
	mov	r5,a
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:11: counter++;
	inc	r4
	sjmp	00101$
00103$:
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:13: return;
;	adduintcore/ADDUINTCORE_STATIC_XDATA.c:14: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
