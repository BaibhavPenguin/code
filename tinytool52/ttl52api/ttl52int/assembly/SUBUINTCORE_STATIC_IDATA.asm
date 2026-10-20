;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module SUBUINTCORE_STATIC_IDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _SUBUINTC_STATIC_IDATA_PARM_4
	.globl _SUBUINTC_STATIC_IDATA_PARM_3
	.globl _SUBUINTC_STATIC_IDATA_PARM_2
	.globl _SUBUINTC_STATIC_IDATA
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
_SUBUINTC_STATIC_IDATA_PARM_2:
	.ds 2
_SUBUINTC_STATIC_IDATA_PARM_3:
	.ds 2
_SUBUINTC_STATIC_IDATA_PARM_4:
	.ds 1
_SUBUINTC_STATIC_IDATA_out_10000_136:
	.ds 1
_SUBUINTC_STATIC_IDATA_carry_10000_137:
	.ds 1
_SUBUINTC_STATIC_IDATA_counter_10000_137:
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
;Allocation info for local variables in function 'SUBUINTC_STATIC_IDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_SUBUINTC_STATIC_IDATA_PARM_2'
;inp2          Allocated with name '_SUBUINTC_STATIC_IDATA_PARM_3'
;size          Allocated with name '_SUBUINTC_STATIC_IDATA_PARM_4'
;out           Allocated with name '_SUBUINTC_STATIC_IDATA_out_10000_136'
;temp          Allocated to registers r2 
;carry         Allocated with name '_SUBUINTC_STATIC_IDATA_carry_10000_137'
;counter       Allocated with name '_SUBUINTC_STATIC_IDATA_counter_10000_137'
;------------------------------------------------------------
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:3: void SUBUINTC_STATIC_IDATA(uint8t __idata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size){
;	-----------------------------------------
;	 function SUBUINTC_STATIC_IDATA
;	-----------------------------------------
_SUBUINTC_STATIC_IDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_SUBUINTC_STATIC_IDATA_out_10000_136,dpl
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:5: uint8t carry = 0;
	mov	_SUBUINTC_STATIC_IDATA_carry_10000_137,#0x00
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:7: while(counter < size){
	mov	_SUBUINTC_STATIC_IDATA_counter_10000_137,#0x00
00101$:
	clr	c
	mov	a,_SUBUINTC_STATIC_IDATA_counter_10000_137
	subb	a,_SUBUINTC_STATIC_IDATA_PARM_4
	jnc	00103$
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:8: temp =  inp1[counter] -  (inp2[counter] + carry);
	mov	a,_SUBUINTC_STATIC_IDATA_counter_10000_137
	add	a, _SUBUINTC_STATIC_IDATA_PARM_2
	mov	r3,a
	clr	a
	addc	a, (_SUBUINTC_STATIC_IDATA_PARM_2 + 1)
	mov	r4,a
	mov	dpl,r3
	mov	dph,r4
	clr	a
	movc	a,@a+dptr
	mov	r2,a
	mov	a,_SUBUINTC_STATIC_IDATA_counter_10000_137
	add	a, _SUBUINTC_STATIC_IDATA_PARM_3
	mov	r6,a
	clr	a
	addc	a, (_SUBUINTC_STATIC_IDATA_PARM_3 + 1)
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	clr	a
	movc	a,@a+dptr
	add	a,_SUBUINTC_STATIC_IDATA_carry_10000_137
	setb	c
	subb	a,r2
	cpl	a
	mov	r2,a
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:9: out[counter] = temp & 0xFF;
	mov	a,_SUBUINTC_STATIC_IDATA_counter_10000_137
	add	a, _SUBUINTC_STATIC_IDATA_out_10000_136
	mov	r0,a
	mov	@r0,ar2
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:10: carry = inp1[counter] < (inp2[counter] + carry);
	mov	dpl,r3
	mov	dph,r4
	clr	a
	movc	a,@a+dptr
	mov	r3,a
	mov	dpl,r6
	mov	dph,r7
	clr	a
	movc	a,@a+dptr
	mov	r6,a
	mov	r7,#0x00
	mov	r4,_SUBUINTC_STATIC_IDATA_carry_10000_137
	mov	r5,#0x00
	mov	a,r4
	add	a, r6
	mov	r6,a
	mov	a,r5
	addc	a, r7
	mov	r7,a
	clr	c
	mov	a,r3
	subb	a,r6
	mov	a,r5
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	clr	a
	rlc	a
	mov	_SUBUINTC_STATIC_IDATA_carry_10000_137,a
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:11: counter++;
	inc	_SUBUINTC_STATIC_IDATA_counter_10000_137
	sjmp	00101$
00103$:
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:13: return;
;	subuintcore/SUBUINTCORE_STATIC_IDATA.c:14: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
