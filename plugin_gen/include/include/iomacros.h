/* ============================================================================
 * Copyright (c) 2011, Peter A. Bigot (pabigot@users.sourceforge.net)
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  *  Neither the name of the copyright owner nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ============================================================================
 */

/* Glue to convert TI-provided headers to GCC-compatible declarations */

#if !defined(__MSP430_IOMACROS_H_)
#define __MSP430_IOMACROS_H_

#if defined(__ASSEMBLER__)

//#define sfrb(x,x_) x=x_
//#define sfrw(x,x_) x=x_
//#define sfra(x,x_) x=x_

#define const_sfrb(x,x_) sfrb(x,x_)
#define const_sfrw(x,x_) sfrw(x,x_)
#define const_sfra(x,x_) sfra(x,x_)

#else /* __ASSEMBLER__ */

//#define sfrb_(x,x_) volatile unsigned char x __asm__("__" #x)
//#define sfrb(x,x_) extern sfrb_(x,x_)

//#define sfrw_(x,x_) volatile unsigned int x __asm__("__" #x)
//#define sfrw(x,x_) extern sfrw_(x,x_)

#define const_sfrb(x,x_) extern const sfrb_(x,x_)
#define const_sfrw(x,x_) extern const sfrw_(x,x_)

#if __MSP430_CPU__ & __MSP430_CPU_MSP430X__
#define __MSPGCC_ATTRIBUTE_A20__ __attribute__((__a20__))
#else
#define __MSPGCC_ATTRIBUTE_A20__
#endif /* 430X available */
#define sfra_(x,x_) volatile unsigned long int __MSPGCC_ATTRIBUTE_A20__ x __asm__("__" #x)
#define sfra(x,x_) extern sfra_(x,x_)
#define const_sfra(x,x_) extern const sfra_(x,x_)

#ifdef __GNUC__
#define __interrupt __attribute__((__interrupt__))
#endif /* __GNUC__ */

#endif /* __ASSEMBLER__ */

#endif /* __MSP430_IOMACROS_H_ */