	EXPORT SETTEN
	AREA SetTen,CODE,READONLY
SETTEN
	MOV R0,#10
	MOV R2,#0x20000000
	LDR R3,=0x20000010
LOOP

	CMP R2,R3
	BEQ LOOPFINSH
	STR R0,[R2],#4
	B LOOP
LOOPFINSH
    BX LR
	NOP
	END
		