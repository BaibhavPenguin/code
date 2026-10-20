;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module SUBUINTCORE
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _SUBUINTC
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
;Allocation info for local variables in function 'SUBUINTC'
;------------------------------------------------------------
;inp1          Allocated to stack - _bp -5 +3 
;inp2          Allocated to stack - _bp -8 +3 
;size          Allocated to stack - _bp -9 +1 
;out           Allocated to stack - _bp +1 +3 
;temp          Allocated to stack - _bp +7 +1 
;carry         Allocated to stack - _bp +8 +1 
;counter       Allocated to stack - _bp +9 +1 
;sloc0         Allocated to stack - _bp +7 +1 
;sloc1         Allocated to stack - _bp +4 +3 
;------------------------------------------------------------
;	subuintcore/SUBUINTCORE.c:3: void SUBUINTC(uint8t* out , const uint8t* inp1 ,const uint8t* inp2 , uint8t size) __reentrant {
;	-----------------------------------------
;	 function SUBUINTC
;	-----------------------------------------
_SUBUINTC:
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
	mov	a,sp
	add	a,#0x06
	mov	sp,a
;	subuintcore/SUBUINTCORE.c:5: uint8t carry = 0;
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	@r0,#0x00
;	subuintcore/SUBUINTCORE.c:7: while(counter < size){
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	mov	@r0,#0x00
00101$:
	mov	a,_bp
	add	a,#0x09
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
;	subuintcore/SUBUINTCORE.c:8: temp =  inp1[counter] -  (inp2[counter] + carry);
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,_bp
	add	a,#0x09
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
	mov	r4,a
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	a,_bp
	add	a,#0x09
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	push	acc
	clr	a
	inc	r0
	addc	a, @r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	pop	acc
	mov	@r0,a
	dec	r0
	pop	acc
	mov	@r0,a
	dec	r0
	pop	acc
	mov	@r0,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r5,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,@r0
	add	a, r5
	mov	r5,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,r4
	clr	c
	subb	a,r5
	mov	@r0,a
;	subuintcore/SUBUINTCORE.c:9: out[counter] = temp & 0xFF;
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x09
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r3,a
	clr	a
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar5,@r0
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
;	subuintcore/SUBUINTCORE.c:10: carry = inp1[counter] < (inp2[counter] + carry);
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r7,a
	mov	r6,#0x00
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	ar4,@r0
	mov	r5,#0x00
	mov	a,r4
	add	a, r7
	mov	r7,a
	mov	a,r5
	addc	a, r6
	mov	r6,a
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,r7
	mov	a,r5
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	clr	a
	rlc	a
	mov	@r0,a
;	subuintcore/SUBUINTCORE.c:11: counter++;
	mov	a,_bp
	add	a,#0x09
	mov	r0,a
	inc	@r0
	ljmp	00101$
00103$:
;	subuintcore/SUBUINTCORE.c:13: return;
;	subuintcore/SUBUINTCORE.c:14: }
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
