START 101
READ N
MOVER BREG ONE
MOVEM BREG TERM
AGAIN MULT BREG TERM
MOVER CREG TERM
ADD CREG ONE
MOVEM CREG TERM
COMP CREG N
BC LE AGAIN
MOVEM BREG RESULT
MOVER AREG =5
MOVER BREG =1
ADD CREG =1
LTORG
PRINT RESULT
STOP
N DS 1
RESULT DS 1
ONE DC 1
TERM DS 1
SUB AREG =1
ORIGIN 400
MULT AREG =1
END
