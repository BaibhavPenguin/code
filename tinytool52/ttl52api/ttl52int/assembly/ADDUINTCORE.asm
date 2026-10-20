;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module ADDUINTCORE
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ADDUINTC
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
;Allocation info for local variables in function 'ADDUINTC'
;------------------------------------------------------------
;inp1          Allocated to stack - _bp -5 +3 
;inp2          Allocated to stack - _bp -8 +3 
;size          Allocated to stack - _bp -9 +1 
;out           Allocated to stack - _bp +1 +3 
;temp          Allocated to stack - _bp +4 +2 
;carry         Allocated to registers r4 
;counter       Allocated to stack - _bp +6 +1 
;------------------------------------------------------------
;	adduintcore/ADDUINTCORE.c:3: void ADDUINTC(uint8t* out , const uint8t* inp1 ,const uint8t* inp2 , uint8t size) __reentrant {
;	-----------------------------------------
;	 function ADDUINTC
;	-----------------------------------------
_ADDUINTC:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	inc	sp
	inc	sp
	inc	sp
;	adduintcore/ADDUINTCORE.c:5: uint8t carry = 0;
	mov	r4,#0x00
;	adduintcore/ADDUINTCORE.c:7: while(counter < size){
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	@r0,#0x00
00101$:
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	a,_bp
	add	a,#0xf7
	mov	r1,a
	clr	c
	mov	a,@r0
	subb	a,@r1
	jc	00119$
	ljmp	00103$
00119$:
;	adduintcore/ADDUINTCORE.c:8: temp =  inp1[counter] +  inp2[counter] + carry;
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	mov	r7,#0x00
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r3
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r6,#0x00
	add	a, r2
	mov	r2,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	ar5,r4
	mov	a,r5
	add	a, r2
	mov	r2,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar7
;	adduintcore/ADDUINTCORE.c:9: out[counter] = temp & 0xFF;
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r5,a
	inc	r0
	mov	ar6,@r0
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	ar7,@r0
	mov	dpl,r3
	mov	dph,r5
	mov	b,r6
	mov	a,r7
	lcall	__gptrput
;	adduintcore/ADDUINTCORE.c:10: carry = temp > 255;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	clr	c
	mov	a,#0xff
	subb	a,@r0
	clr	a
	inc	r0
	subb	a,@r0
	clr	a
	rlc	a
	mov	r4,a
;	adduintcore/ADDUINTCORE.c:11: counter++;
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	inc	@r0
	ljmp	00101$
00103$:
;	adduintcore/ADDUINTCORE.c:13: return;
;	adduintcore/ADDUINTCORE.c:14: }
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
