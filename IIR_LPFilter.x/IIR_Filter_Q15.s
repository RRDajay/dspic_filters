
;------------------------------------------------------------------------------
;file start
	.nolist
	.list
	
		
;------------------------------------------------------------------------------
;local inclusions.
	.section .data    ; place constant data in the data section
	
;------------------------------------------------------------------------------
;local inclusions.
	.section .text    ; place code in the code section
	
;------------------------------------------------------------------------------
; Global function declaration
; 
;------------------------------------------------------------------------------
	
	.global _IIR_LPFilter_Q15_Update
    
_IIR_LPFilter_Q15_Update:    ; provide global scope to routine
;------------------------------------------------------------------------------
    push.s					    ; save shadowed working registers
    
    push w4
    push w6
    push w8
    push w10
    push ACCA
    push ACCAH
    push ACCAL
    push ACCB
    push ACCBH
    push ACCBL  
    push CORCON
    push SR
    
    ;------------------------------------------------------------------------------
    ; DSP Configuration
    ; Enable accumulator saturation; DSP engine multiplication are signed; Q1.31; fractional multiplier Mode
    mov #0x00c0, w4
    mov w4, _CORCON		
    
    ;------------------------------------------------------------------------------
    ; Setup pointers to A-Coeffecient arrays
    mov [w0], w8				    ; load pointer to first index of A coeffecients array
    
    ;------------------------------------------------------------------------------
    ; Load pointer to first element of control history array
    mov [w0 + #4], w10				    ; load pointer address into working register
    
    ;------------------------------------------------------------------------------
    ; Update history array
    mov [w10 + #0], w6				    
    mov w6, [w10 + #2]				    ; x[n] -> x[n-1]
    
    ;------------------------------------------------------------------------------
    ; Read data from input source
    mov w1, [w10 + #0]				    ; adc input in q15 format
    
    ;------------------------------------------------------------------------------
    ; Compute A-Term of the compensation filter
    clr a, [w8]+=2, w4, [w10]+=2, w6
    mac w4*w6, a, [w8]+=2, w4, [w10]+=2, w6	    ; A0 * x[n]
    mac w4*w6, a				    ; A1 * x[n-1]
    
    ;------------------------------------------------------------------------------
    ; Load pointer to first element of error history array
    mov [w0 + #6], w10				    ; load pointer address into working register
    
    ;------------------------------------------------------------------------------
    ; Setup pointers to B-Term data arrays
    mov [w0 + #2], w8				    ; load pointer to first index of B coeffecients array to working register
    
    ;------------------------------------------------------------------------------
    ; Compute B-Term of the compensation filter
    clr b, [w8]+=2, w4, [w10]+=2, w6		    
    mac w4*w6, b				    ; B0 * y[n-1]
    
   
    ;------------------------------------------------------------------------------
    ; Add accumulators A & B to finalize LDE computation
    add a					    ; add accumulator b to accumulator a

    ;------------------------------------------------------------------------------
    ; Update error array
    sftac a, #0
    sac.r a, w4			            ; store most recent accumulator result in error array
    
    ;------------------------------------------------------------------------------
    ; Controller Anti-Windup (control output value clamping)
     
    ; Check for lower limit violation
;    mov [w0 + #14], w6				    ; load lower limit value
;    cpsgt w4, w6				    ; compare values and skip next instruction if control output is within operating range (control output > lower limit)
;    mov w6, w4					    ; override most recent controller output
;    FILTER_CLAMP_MIN_EXIT:
    
;    ; Check for upper limit violation
;    mov [w0 + #16], w6				    ; load upper limit value
;    cpslt w4, w6				    ; compare values and skip next instruction if control output is within operating range (control output < upper limit)
;    mov w6, w4					    ; override most recent controller output
;    FILTER_CLAMP_MAX_EXIT:
    
    
    mov w4, [w10 - #2]  
    
    
    pop SR 
    pop CORCON
    pop ACCBL
    pop ACCBH
    pop ACCB
    pop ACCAL
    pop ACCAH
    pop ACCA
    pop w10			
    pop w8
    pop w6
    pop w4  
    
    pop.s			; restore shadowed working registers
    
;------------------------------------------------------------------------------
; End of routine
	return
;------------------------------------------------------------------------------
	
;------------------------------------------------------------------------------
; End of file
	.end
;------------------------------------------------------------------------------


