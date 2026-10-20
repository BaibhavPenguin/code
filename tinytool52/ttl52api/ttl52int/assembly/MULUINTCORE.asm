;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module MULUINTCORE
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _MULUINTC
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
;Allocation info for local variables in function 'MULUINTC'
;------------------------------------------------------------
;inp1          Allocated to stack - _bp -5 +3 
;inp2          Allocated to stack - _bp -8 +3 
;size          Allocated to stack - _bp -9 +1 
;out           Allocated to stack - _bp +1 +3 
;temp          Allocated to registers r3 r6 
;index2        Allocated to registers r2 
;index1        Allocated to registers 
;sloc0         Allocated to stack - _bp +4 +3 
;sloc1         Allocated to stack - _bp +7 +1 
;sloc2         Allocated to stack - _bp +8 +2 
;sloc3         Allocated to stack - _bp +10 +2 
;sloc4         Allocated to stack - _bp +12 +2 
;sloc5         Allocated to stack - _bp +14 +2 
;------------------------------------------------------------
;	muluintcore/MULUINTCORE.c:3: void MULUINTC(uint8t* out , const uint8t* inp1 ,const uint8t* inp2 , uint8t size) __reentrant {
;	-----------------------------------------
;	 function MULUINTC
;	-----------------------------------------
_MULUINTC:
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
	add	a,#0x0c
	mov	sp,a
;	muluintcore/MULUINTCORE.c:4: uint16t temp = 0;
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	clr	a
	mov	@r0,a
	inc	r0
	mov	@r0,a
;	muluintcore/MULUINTCORE.c:7: while(index1 < size){
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	clr	c
	clr	a
	subb	a,@r0
	clr	a
	rlc	a
	mov	r2,a
00101$:
	mov	a,r2
	jz	00103$
;	muluintcore/MULUINTCORE.c:8: out[index1] = 0;
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
	sjmp	00101$
00103$:
;	muluintcore/MULUINTCORE.c:11: while(index2 < size){
	mov	r2,#0x00
00107$:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	jc	00156$
	ljmp	00109$
00156$:
;	muluintcore/MULUINTCORE.c:13: while(index1 < (size - index2)){
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,r2
	add	a, @r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a, @r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	@r0,#0x00
00104$:
	mov	a,_bp
	add	a,#0xf7
	mov	r0,a
	mov	ar3,@r0
	mov	r4,#0x00
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,#0x00
	mov	a,_bp
	add	a,#0x08
	mov	r0,a
	mov	a,r3
	clr	c
	subb	a,@r0
	mov	r3,a
	mov	a,r4
	inc	r0
	subb	a,@r0
	mov	r4,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r1
	mov	@r1,#0x00
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	c
	mov	a,@r0
	subb	a,r3
	inc	r0
	mov	a,@r0
	xrl	a,#0x80
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	jc	00157$
	ljmp	00106$
00157$:
;	muluintcore/MULUINTCORE.c:14: temp+= inp1[index1] * inp2[index2] + out[index1 + index2];
	push	ar2
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	a,_bp
	add	a,#0x07
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
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	b,r2
	mov	a,r7
	mul	ab
	mov	@r0,a
	inc	r0
	mov	@r0,b
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,_bp
	add	a,#0x08
	mov	r1,a
	mov	a,@r1
	add	a, @r0
	mov	r5,a
	inc	r1
	mov	a,@r1
	inc	r0
	addc	a, @r0
	mov	r7,a
	mov	r0,_bp
	inc	r0
	mov	a,r5
	add	a, @r0
	mov	r5,a
	mov	a,r7
	inc	r0
	addc	a, @r0
	mov	r4,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r4
	mov	b,r7
	lcall	__gptrget
	mov	r3,a
	mov	r6,#0x00
	mov	a,_bp
	add	a,#0x0e
	mov	r0,a
	mov	a,r3
	add	a, @r0
	mov	r3,a
	mov	a,r6
	inc	r0
	addc	a, @r0
	mov	r6,a
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	a,r3
	add	a, @r0
	mov	r3,a
	mov	a,r6
	inc	r0
	addc	a, @r0
	mov	r6,a
;	muluintcore/MULUINTCORE.c:15: out[index1 + index2] = temp & 0xFF;
	mov	ar2,r3
	mov	dpl,r5
	mov	dph,r4
	mov	b,r7
	mov	a,r2
	lcall	__gptrput
;	muluintcore/MULUINTCORE.c:16: temp = temp >>8;
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	@r0,ar6
	inc	r0
	mov	@r0,#0x00
;	muluintcore/MULUINTCORE.c:17: index1++;
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	inc	@r0
	pop	ar2
	ljmp	00104$
00106$:
;	muluintcore/MULUINTCORE.c:19: index2++;
	inc	r2
;	muluintcore/MULUINTCORE.c:20: index1 = 0;
	ljmp	00107$
00109$:
;	muluintcore/MULUINTCORE.c:23: return;
;	muluintcore/MULUINTCORE.c:24: }
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
