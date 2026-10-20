;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.0 #15242 (Linux)
;--------------------------------------------------------
	.module MULUINTCORE_IDATA
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _MULUINTC_IDATA_PARM_4
	.globl _MULUINTC_IDATA_PARM_3
	.globl _MULUINTC_IDATA_PARM_2
	.globl _MULUINTC_IDATA
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
_MULUINTC_IDATA_PARM_2:
	.ds 1
_MULUINTC_IDATA_PARM_3:
	.ds 1
_MULUINTC_IDATA_PARM_4:
	.ds 1
_MULUINTC_IDATA_out_10000_136:
	.ds 1
_MULUINTC_IDATA_index2_10000_137:
	.ds 1
_MULUINTC_IDATA_sloc0_1_0:
	.ds 2
_MULUINTC_IDATA_sloc1_1_0:
	.ds 2
_MULUINTC_IDATA_sloc2_1_0:
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
;Allocation info for local variables in function 'MULUINTC_IDATA'
;------------------------------------------------------------
;inp1          Allocated with name '_MULUINTC_IDATA_PARM_2'
;inp2          Allocated with name '_MULUINTC_IDATA_PARM_3'
;size          Allocated with name '_MULUINTC_IDATA_PARM_4'
;out           Allocated with name '_MULUINTC_IDATA_out_10000_136'
;temp          Allocated to registers r2 r3 
;index2        Allocated with name '_MULUINTC_IDATA_index2_10000_137'
;index1        Allocated to registers 
;sloc0         Allocated with name '_MULUINTC_IDATA_sloc0_1_0'
;sloc1         Allocated with name '_MULUINTC_IDATA_sloc1_1_0'
;sloc2         Allocated with name '_MULUINTC_IDATA_sloc2_1_0'
;------------------------------------------------------------
;	muluintcore/MULUINTCORE_IDATA.c:3: void MULUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 ,const uint8t __idata* inp2 , uint8t size){
;	-----------------------------------------
;	 function MULUINTC_IDATA
;	-----------------------------------------
_MULUINTC_IDATA:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_MULUINTC_IDATA_out_10000_136,dpl
;	muluintcore/MULUINTCORE_IDATA.c:4: uint16t temp = 0;
	clr	a
	mov	_MULUINTC_IDATA_sloc2_1_0,a
	mov	(_MULUINTC_IDATA_sloc2_1_0 + 1),a
;	muluintcore/MULUINTCORE_IDATA.c:7: while(index1 < size){
	clr	c
	subb	a,_MULUINTC_IDATA_PARM_4
	clr	a
	rlc	a
	mov	r5,a
00101$:
	mov	a,r5
	jz	00103$
;	muluintcore/MULUINTCORE_IDATA.c:8: out[index1] = 0;
	mov	r0,_MULUINTC_IDATA_out_10000_136
	mov	@r0,#0x00
	sjmp	00101$
00103$:
;	muluintcore/MULUINTCORE_IDATA.c:11: while(index2 < size){
	mov	_MULUINTC_IDATA_index2_10000_137,#0x00
00107$:
	clr	c
	mov	a,_MULUINTC_IDATA_index2_10000_137
	subb	a,_MULUINTC_IDATA_PARM_4
	jnc	00109$
;	muluintcore/MULUINTCORE_IDATA.c:13: while(index1 < (size - index2)){
	mov	a,_MULUINTC_IDATA_index2_10000_137
	add	a, _MULUINTC_IDATA_PARM_3
	mov	r0,a
	mov	r4,#0x00
00104$:
	mov	r2,_MULUINTC_IDATA_PARM_4
	mov	r3,#0x00
	mov	_MULUINTC_IDATA_sloc0_1_0,_MULUINTC_IDATA_index2_10000_137
	mov	(_MULUINTC_IDATA_sloc0_1_0 + 1),r3
	mov	a,r2
	clr	c
	subb	a,_MULUINTC_IDATA_sloc0_1_0
	mov	r2,a
	mov	a,r3
	subb	a,(_MULUINTC_IDATA_sloc0_1_0 + 1)
	mov	r3,a
	mov	_MULUINTC_IDATA_sloc1_1_0,r4
	mov	(_MULUINTC_IDATA_sloc1_1_0 + 1),#0x00
	clr	c
	mov	a,_MULUINTC_IDATA_sloc1_1_0
	subb	a,r2
	mov	a,(_MULUINTC_IDATA_sloc1_1_0 + 1)
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00106$
;	muluintcore/MULUINTCORE_IDATA.c:14: temp+= inp1[index1] * inp2[index2] + out[index1 + index2];
	mov	a,r4
	add	a, _MULUINTC_IDATA_PARM_2
	mov	r1,a
	mov	ar3,@r1
	mov	ar2,@r0
	mov	b,r3
	mov	a,r2
	mul	ab
	mov	r2,a
	mov	r3,b
	mov	a,_MULUINTC_IDATA_sloc0_1_0
	add	a, _MULUINTC_IDATA_sloc1_1_0
	mov	r5,a
	mov	a,(_MULUINTC_IDATA_sloc0_1_0 + 1)
	addc	a, (_MULUINTC_IDATA_sloc1_1_0 + 1)
	mov	a,r5
	add	a, _MULUINTC_IDATA_out_10000_136
	mov	r1,a
	mov	ar7,@r1
	mov	r6,#0x00
	mov	a,r7
	add	a, r2
	mov	r2,a
	mov	a,r6
	addc	a, r3
	mov	r3,a
	mov	a,r2
	add	a, _MULUINTC_IDATA_sloc2_1_0
	mov	r2,a
	mov	a,r3
	addc	a, (_MULUINTC_IDATA_sloc2_1_0 + 1)
	mov	r3,a
;	muluintcore/MULUINTCORE_IDATA.c:15: out[index1 + index2] = temp & 0xFF;
	mov	ar7,r2
	mov	@r1,ar7
;	muluintcore/MULUINTCORE_IDATA.c:16: temp = temp >>8;
	mov	_MULUINTC_IDATA_sloc2_1_0,r3
	mov	(_MULUINTC_IDATA_sloc2_1_0 + 1),#0x00
;	muluintcore/MULUINTCORE_IDATA.c:17: index1++;
	inc	r4
	sjmp	00104$
00106$:
;	muluintcore/MULUINTCORE_IDATA.c:19: index2++;
	inc	_MULUINTC_IDATA_index2_10000_137
;	muluintcore/MULUINTCORE_IDATA.c:20: index1 = 0;
	sjmp	00107$
00109$:
;	muluintcore/MULUINTCORE_IDATA.c:23: return;
;	muluintcore/MULUINTCORE_IDATA.c:24: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
