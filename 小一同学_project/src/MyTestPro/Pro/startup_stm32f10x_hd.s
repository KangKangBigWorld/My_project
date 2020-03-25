;******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
;* File Name          : startup_stm32f10x_hd.s
;* Author             : MCD Application Team
;* Version            : V3.5.0
;* Date               : 11-March-2011
;* Description        : STM32F10x High Density Devices vector table for MDK-ARM 
;*                      toolchain. 
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Configure the clock system and also configure the external 
;*                        SRAM mounted on STM3210E-EVAL board to be used as data 
;*                        memory (optional, to be enabled by user)
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>   
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00001500

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp
                                                  
; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00001500

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler
                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     MemManage_Handler          ; MPU Fault Handler
                DCD     BusFault_Handler           ; Bus Fault Handler
                DCD     UsageFault_Handler         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     DebugMon_Handler           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
                DCD     IRQ_Desacth            ; Window Watchdog
                DCD     IRQ_Desacth             ; PVD through EXTI Line detect
                DCD     IRQ_Desacth          ; Tamper
                DCD     IRQ_Desacth             ; RTC
                DCD     IRQ_Desacth           ; Flash
                DCD     IRQ_Desacth             ; RCC
                DCD     IRQ_Desacth           ; EXTI Line 0
                DCD     IRQ_Desacth           ; EXTI Line 1
                DCD     IRQ_Desacth           ; EXTI Line 2
                DCD     IRQ_Desacth           ; EXTI Line 3
                DCD     IRQ_Desacth           ; EXTI Line 4
                DCD     IRQ_Desacth   ; DMA1 Channel 1
                DCD     IRQ_Desacth   ; DMA1 Channel 2
                DCD     IRQ_Desacth   ; DMA1 Channel 3
                DCD     IRQ_Desacth   ; DMA1 Channel 4
                DCD     IRQ_Desacth   ; DMA1 Channel 5
                DCD     IRQ_Desacth   ; DMA1 Channel 6
                DCD     IRQ_Desacth   ; DMA1 Channel 7
                DCD     IRQ_Desacth          ; ADC1 & ADC2
                DCD     IRQ_Desacth  ; USB High Priority or CAN1 TX
                DCD     IRQ_Desacth ; USB Low  Priority or CAN1 RX0
                DCD     IRQ_Desacth        ; CAN1 RX1
                DCD     IRQ_Desacth        ; CAN1 SCE
                DCD     IRQ_Desacth         ; EXTI Line 9..5
                DCD     IRQ_Desacth        ; TIM1 Break
                DCD     IRQ_Desacth         ; TIM1 Update
                DCD     IRQ_Desacth    ; TIM1 Trigger and Commutation
                DCD     IRQ_Desacth         ; TIM1 Capture Compare
                DCD     IRQ_Desacth            ; TIM2
                DCD     IRQ_Desacth            ; TIM3
                DCD     IRQ_Desacth            ; TIM4
                DCD     IRQ_Desacth         ; I2C1 Event
                DCD     IRQ_Desacth         ; I2C1 Error
                DCD     IRQ_Desacth         ; I2C2 Event
                DCD     IRQ_Desacth          ; I2C2 Error
                DCD     IRQ_Desacth            ; SPI1
                DCD     IRQ_Desacth            ; SPI2
                DCD     IRQ_Desacth          ; USART1
                DCD     IRQ_Desacth          ; USART2
                DCD     IRQ_Desacth          ; USART3
                DCD     IRQ_Desacth       ; EXTI Line 15..10
                DCD     IRQ_Desacth        ; RTC Alarm through EXTI Line
                DCD     IRQ_Desacth       ; USB Wakeup from suspend
                DCD     IRQ_Desacth        ; TIM8 Break
                DCD     IRQ_Desacth         ; TIM8 Update
                DCD     IRQ_Desacth    ; TIM8 Trigger and Commutation
                DCD     IRQ_Desacth         ; TIM8 Capture Compare
                DCD     IRQ_Desacth            ; ADC3
                DCD     IRQ_Desacth            ; FSMC
                DCD     IRQ_Desacth            ; SDIO
                DCD     IRQ_Desacth            ; TIM5
                DCD     IRQ_Desacth            ; SPI3
                DCD     IRQ_Desacth           ; UART4
                DCD     IRQ_Desacth           ; UART5
                DCD     IRQ_Desacth            ; TIM6
                DCD     IRQ_Desacth            ; TIM7
                DCD     IRQ_Desacth   ; DMA2 Channel1
                DCD     IRQ_Desacth   ; DMA2 Channel2
                DCD     IRQ_Desacth   ; DMA2 Channel3
                DCD     IRQ_Desacth ; DMA2 Channel4 & Channel5
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY
                
; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                IMPORT  SystemInit
                LDR     R0, =SystemInit
                BLX     R0  

                LDR     R0, =__main
                BX      R0
                ENDP
                
; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  IRQ_Desacth            [WEAK]
                

IRQ_Desacth
                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap
                 
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****
