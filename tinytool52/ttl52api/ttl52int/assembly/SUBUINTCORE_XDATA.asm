;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module SUBUINTCORE_XDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _SUBUINTC_XDATA_PARM_4
	.globl _SUBUINTC_XDATA_PARM_3
	.globl _SUBUINTC_XDATA_PARM_2
	.globl _SUBUINTC_XDATA
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
_SUBUINTC_XDATA_PARM_2:
	.ds 2
_SUBUINTC_XDATA_PARM_3:
	.ds 2
_SUBUINTC_XDATA_PARM_4:
	.ds 1
_SUBUINTC_XDATA_out_10000_136:
	.ds 2
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
;Allocation info for local variables in function 'SUBUINTC_XDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_SUBUINTC_XDATA_PARM_2'
;inp2          Allocated with name '_SUBUINTC_XDATA_PARM_3'
;size          Allocated with name '_SUBUINTC_XDATA_PARM_4'
;out           Allocated with name '_SUBUINTC_XDATA_out_10000_136'
;temp          Allocated to registers r1 
;carry         Allocated to registers r5 
;counter       Allocated to registers r4 
;------------------------------------------------------------
;	subuintcore/SUBUINTCORE_XDATA.c:3: void SUBUINTC_XDATA(uint8t __xdata* out , const uint8t __xdata* inp1 , const uint8t __xdata* inp2 , uint8t size){
;	-----------------------------------------
;	 function SUBUINTC_XDATA
;	-----------------------------------------
_SUBUINTC_XDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_SUBUINTC_XDATA_out_10000_136,dpl
	mov	(_SUBUINTC_XDATA_out_10000_136 + 1),dph
;	subuintcore/SUBUINTCORE_XDATA.c:5: uint8t carry = 0;
	mov	r5,#0x00
;	subuintcore/SUBUINTCORE_XDATA.c:7: while(counter < size){
	mov	r4,#0x00
00101$:
	clr	c
	mov	a,r4
	subb	a,_SUBUINTC_XDATA_PARM_4
	jnc	00103$
;	subuintcore/SUBUINTCORE_XDATA.c:8: temp =  inp1[counter] -  (inp2[counter] + carry);
	mov	a,r4
	add	a, _SUBUINTC_XDATA_PARM_2
	mov	r2,a
	clr	a
	addc	a, (_SUBUINTC_XDATA_PARM_2 + 1)
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	movx	a,@dptr
	mov	r1,a
	mov	a,r4
	add	a, _SUBUINTC_XDATA_PARM_3
	mov	r0,a
	clr	a
	addc	a, (_SUBUINTC_XDATA_PARM_3 + 1)
	mov	r7,a
	mov	dpl,r0
	mov	dph,r7
	movx	a,@dptr
	add	a,r5
	setb	c
	subb	a,r1
	cpl	a
	mov	r1,a
;	subuintcore/SUBUINTCORE_XDATA.c:9: out[counter] = temp & 0xFF;
	mov	a,r4
	add	a, _SUBUINTC_XDATA_out_10000_136
	mov	dpl,a
	clr	a
	addc	a, (_SUBUINTC_XDATA_out_10000_136 + 1)
	mov	dph,a
	mov	a,r1
	movx	@dptr,a
;	subuintcore/SUBUINTCORE_XDATA.c:10: carry = inp1[counter] < (inp2[counter] + carry);
	mov	dpl,r2
	mov	dph,r3
	movx	a,@dptr
	mov	r2,a
	mov	dpl,r0
	mov	dph,r7
	movx	a,@dptr
	mov	r0,a
	mov	r7,#0x00
	mov	ar3,r5
	mov	r6,#0x00
	mov	a,r3
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	clr	c
	mov	a,r2
	subb	a,r0
	mov	a,r6
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	clr	a
	rlc	a
	mov	r5,a
;	subuintcore/SUBUINTCORE_XDATA.c:11: counter++;
	inc	r4
	sjmp	00101$
00103$:
;	subuintcore/SUBUINTCORE_XDATA.c:13: return;
;	subuintcore/SUBUINTCORE_XDATA.c:14: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
