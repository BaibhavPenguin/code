;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module MULUINTCORE_STATIC_IDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _MULUINTC_STATIC_IDATA_PARM_4
	.globl _MULUINTC_STATIC_IDATA_PARM_3
	.globl _MULUINTC_STATIC_IDATA_PARM_2
	.globl _MULUINTC_STATIC_IDATA
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
_MULUINTC_STATIC_IDATA_PARM_2:
	.ds 2
_MULUINTC_STATIC_IDATA_PARM_3:
	.ds 2
_MULUINTC_STATIC_IDATA_PARM_4:
	.ds 1
_MULUINTC_STATIC_IDATA_out_10000_136:
	.ds 1
_MULUINTC_STATIC_IDATA_index2_10000_137:
	.ds 1
_MULUINTC_STATIC_IDATA_sloc0_1_0:
	.ds 2
_MULUINTC_STATIC_IDATA_sloc1_1_0:
	.ds 2
_MULUINTC_STATIC_IDATA_sloc2_1_0:
	.ds 1
_MULUINTC_STATIC_IDATA_sloc3_1_0:
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
;Allocation info for local variables in function 'MULUINTC_STATIC_IDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_MULUINTC_STATIC_IDATA_PARM_2'
;inp2          Allocated with name '_MULUINTC_STATIC_IDATA_PARM_3'
;size          Allocated with name '_MULUINTC_STATIC_IDATA_PARM_4'
;out           Allocated with name '_MULUINTC_STATIC_IDATA_out_10000_136'
;temp          Allocated to registers r4 r5 
;index2        Allocated with name '_MULUINTC_STATIC_IDATA_index2_10000_137'
;index1        Allocated to registers 
;sloc0         Allocated with name '_MULUINTC_STATIC_IDATA_sloc0_1_0'
;sloc1         Allocated with name '_MULUINTC_STATIC_IDATA_sloc1_1_0'
;sloc2         Allocated with name '_MULUINTC_STATIC_IDATA_sloc2_1_0'
;sloc3         Allocated with name '_MULUINTC_STATIC_IDATA_sloc3_1_0'
;------------------------------------------------------------
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:3: void MULUINTC_STATIC_IDATA(uint8t __idata* out , const uint8t __code* inp1 ,const uint8t __code* inp2 , uint8t size) {
;	-----------------------------------------
;	 function MULUINTC_STATIC_IDATA
;	-----------------------------------------
_MULUINTC_STATIC_IDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_MULUINTC_STATIC_IDATA_out_10000_136,dpl
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:4: uint16t temp = 0;
	clr	a
	mov	_MULUINTC_STATIC_IDATA_sloc3_1_0,a
	mov	(_MULUINTC_STATIC_IDATA_sloc3_1_0 + 1),a
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:7: while(index1 < size){
	clr	c
	subb	a,_MULUINTC_STATIC_IDATA_PARM_4
	clr	a
	rlc	a
	mov	r5,a
00101$:
	mov	a,r5
	jz	00103$
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:8: out[index1] = 0;
	mov	r0,_MULUINTC_STATIC_IDATA_out_10000_136
	mov	@r0,#0x00
	sjmp	00101$
00103$:
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:12: while(index2 < size){
	mov	_MULUINTC_STATIC_IDATA_index2_10000_137,#0x00
00107$:
	clr	c
	mov	a,_MULUINTC_STATIC_IDATA_index2_10000_137
	subb	a,_MULUINTC_STATIC_IDATA_PARM_4
	jc	00156$
	ret
00156$:
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:14: while(index1 < (size - index2)){
	mov	a,_MULUINTC_STATIC_IDATA_index2_10000_137
	add	a, _MULUINTC_STATIC_IDATA_PARM_3
	mov	r3,a
	clr	a
	addc	a, (_MULUINTC_STATIC_IDATA_PARM_3 + 1)
	mov	r4,a
	mov	r2,#0x00
00104$:
	mov	r5,_MULUINTC_STATIC_IDATA_PARM_4
	mov	r7,#0x00
	mov	_MULUINTC_STATIC_IDATA_sloc0_1_0,_MULUINTC_STATIC_IDATA_index2_10000_137
	mov	(_MULUINTC_STATIC_IDATA_sloc0_1_0 + 1),r7
	mov	a,r5
	clr	c
	subb	a,_MULUINTC_STATIC_IDATA_sloc0_1_0
	mov	r5,a
	mov	a,r7
	subb	a,(_MULUINTC_STATIC_IDATA_sloc0_1_0 + 1)
	mov	r7,a
	mov	_MULUINTC_STATIC_IDATA_sloc1_1_0,r2
	mov	(_MULUINTC_STATIC_IDATA_sloc1_1_0 + 1),#0x00
	clr	c
	mov	a,_MULUINTC_STATIC_IDATA_sloc1_1_0
	subb	a,r5
	mov	a,(_MULUINTC_STATIC_IDATA_sloc1_1_0 + 1)
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00106$
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:15: temp+= inp1[index1] * inp2[index2] + out[index1 + index2];
	mov	a,r2
	add	a, _MULUINTC_STATIC_IDATA_PARM_2
	mov	dpl,a
	clr	a
	addc	a, (_MULUINTC_STATIC_IDATA_PARM_2 + 1)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	_MULUINTC_STATIC_IDATA_sloc2_1_0,a
	mov	dpl,r3
	mov	dph,r4
	clr	a
	movc	a,@a+dptr
	mov	r5,a
	push	ar3
	push	ar4
	mov	b,_MULUINTC_STATIC_IDATA_sloc2_1_0
	mov	a,r5
	mul	ab
	mov	r4,a
	mov	r5,b
	mov	a,_MULUINTC_STATIC_IDATA_sloc0_1_0
	add	a, _MULUINTC_STATIC_IDATA_sloc1_1_0
	mov	r3,a
	mov	a,(_MULUINTC_STATIC_IDATA_sloc0_1_0 + 1)
	addc	a, (_MULUINTC_STATIC_IDATA_sloc1_1_0 + 1)
	mov	a,r3
	add	a, _MULUINTC_STATIC_IDATA_out_10000_136
	mov	r1,a
	mov	ar7,@r1
	mov	r6,#0x00
	mov	a,r7
	add	a, r4
	mov	r4,a
	mov	a,r6
	addc	a, r5
	mov	r5,a
	mov	a,r4
	add	a, _MULUINTC_STATIC_IDATA_sloc3_1_0
	mov	r4,a
	mov	a,r5
	addc	a, (_MULUINTC_STATIC_IDATA_sloc3_1_0 + 1)
	mov	r5,a
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:16: out[index1 + index2] = temp & 0xFF;
	mov	ar7,r4
	mov	@r1,ar7
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:17: temp = temp >>8;
	mov	_MULUINTC_STATIC_IDATA_sloc3_1_0,r5
	mov	(_MULUINTC_STATIC_IDATA_sloc3_1_0 + 1),#0x00
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:18: index1++;
	inc	r2
	pop	ar4
	pop	ar3
	sjmp	00104$
00106$:
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:20: index2++;
	inc	_MULUINTC_STATIC_IDATA_index2_10000_137
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:21: index1 = 0;
	ljmp	00107$
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:24: return;
;	muluintcore/MULUINTCORE_STATIC_IDATA.c:25: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
