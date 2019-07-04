	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_printArr               ## -- Begin function printArr
	.p2align	4, 0x90
_printArr:                              ## @printArr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	(%rax,%rcx,4), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_sort1                  ## -- Begin function sort1
	.p2align	4, 0x90
_sort1:                                 ## @sort1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -16(%rbp)
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB1_10
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-20(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB1_8
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=2
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-8(%rbp), %rax
	movslq	-20(%rbp), %rcx
	cmpl	(%rax,%rcx,4), %edx
	jge	LBB1_6
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=2
	movq	-8(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	xorl	(%rax,%rcx,4), %edx
	movl	%edx, (%rax,%rcx,4)
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-8(%rbp), %rax
	movslq	-20(%rbp), %rcx
	xorl	(%rax,%rcx,4), %edx
	movl	%edx, (%rax,%rcx,4)
	movq	-8(%rbp), %rax
	movslq	-20(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	xorl	(%rax,%rcx,4), %edx
	movl	%edx, (%rax,%rcx,4)
LBB1_6:                                 ##   in Loop: Header=BB1_3 Depth=2
	jmp	LBB1_7
LBB1_7:                                 ##   in Loop: Header=BB1_3 Depth=2
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_3
LBB1_8:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_9
LBB1_9:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB1_1
LBB1_10:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_sort2                  ## -- Begin function sort2
	.p2align	4, 0x90
_sort2:                                 ## @sort2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -24(%rbp)
	movl	%ecx, -28(%rbp)
	movl	$0, -32(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-32(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB2_4
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-32(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-24(%rbp), %rax
	movslq	-32(%rbp), %rcx
	movl	%edx, (%rax,%rcx,4)
## %bb.3:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	LBB2_1
LBB2_4:
	movq	-24(%rbp), %rdi
	movl	-28(%rbp), %esi
	callq	_sort1
	movl	-28(%rbp), %esi
	movl	%esi, -36(%rbp)
LBB2_5:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_7 Depth 2
                                        ##     Child Loop BB2_10 Depth 2
	movl	-36(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB2_18
## %bb.6:                               ##   in Loop: Header=BB2_5 Depth=1
	movl	$0, -40(%rbp)
LBB2_7:                                 ##   Parent Loop BB2_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-40(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jge	LBB2_16
## %bb.8:                               ##   in Loop: Header=BB2_7 Depth=2
	movq	-8(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-24(%rbp), %rax
	movslq	-40(%rbp), %rcx
	cmpl	(%rax,%rcx,4), %edx
	jle	LBB2_14
## %bb.9:                               ##   in Loop: Header=BB2_5 Depth=1
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -44(%rbp)
LBB2_10:                                ##   Parent Loop BB2_5 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-44(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jle	LBB2_13
## %bb.11:                              ##   in Loop: Header=BB2_10 Depth=2
	movq	-24(%rbp), %rax
	movl	-44(%rbp), %ecx
	subl	$1, %ecx
	movslq	%ecx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movslq	-44(%rbp), %rdx
	movl	%ecx, (%rax,%rdx,4)
## %bb.12:                              ##   in Loop: Header=BB2_10 Depth=2
	movl	-44(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB2_10
LBB2_13:                                ##   in Loop: Header=BB2_5 Depth=1
	movq	-8(%rbp), %rax
	movslq	-36(%rbp), %rcx
	movl	(%rax,%rcx,4), %edx
	movq	-24(%rbp), %rax
	movslq	-40(%rbp), %rcx
	movl	%edx, (%rax,%rcx,4)
	jmp	LBB2_16
LBB2_14:                                ##   in Loop: Header=BB2_7 Depth=2
	jmp	LBB2_15
LBB2_15:                                ##   in Loop: Header=BB2_7 Depth=2
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB2_7
LBB2_16:                                ##   in Loop: Header=BB2_5 Depth=1
	jmp	LBB2_17
LBB2_17:                                ##   in Loop: Header=BB2_5 Depth=1
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB2_5
LBB2_18:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_getValueByIdx          ## -- Begin function getValueByIdx
	.p2align	4, 0x90
_getValueByIdx:                         ## @getValueByIdx
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	callq	_printArr
	movl	-16(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -20(%rbp)
	movslq	-20(%rbp), %rdi
	shlq	$2, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movq	-32(%rbp), %rdx
	movl	-20(%rbp), %ecx
	callq	_sort2
	movq	-32(%rbp), %rdi
	movl	-20(%rbp), %esi
	callq	_printArr
	movq	-32(%rbp), %rax
	movslq	-16(%rbp), %rdx
	movl	(%rax,%rdx,4), %ecx
	movl	%ecx, -36(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	movl	-36(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movl	$4, %edx
	leaq	-48(%rbp), %rax
	leaq	l_main.data(%rip), %rcx
	movl	$36, %esi
	movl	%esi, %edi
	movq	___stack_chk_guard@GOTPCREL(%rip), %r8
	movq	(%r8), %r8
	movq	%r8, -8(%rbp)
	movl	$0, -52(%rbp)
	movq	%rax, %r8
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%r8, %rdi
	movq	%rcx, %rsi
	movq	-88(%rbp), %rcx         ## 8-byte Reload
	movl	%edx, -92(%rbp)         ## 4-byte Spill
	movq	%rcx, %rdx
	movq	%rax, -104(%rbp)        ## 8-byte Spill
	callq	_memcpy
	movl	$9, -56(%rbp)
	movl	-56(%rbp), %esi
	movq	-104(%rbp), %rdi        ## 8-byte Reload
	movl	-92(%rbp), %edx         ## 4-byte Reload
	callq	_getValueByIdx
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.4(%rip), %rdi
	movl	$8, %edx
	movl	%edx, %esi
	movl	$6, %edx
                                        ## kill: def %rdx killed %edx
	leaq	L_.str.3(%rip), %rcx
	movq	%rcx, -64(%rbp)
	movl	L_main.str1(%rip), %r9d
	movl	%r9d, -70(%rbp)
	movw	L_main.str1+4(%rip), %r10w
	movw	%r10w, -66(%rbp)
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	movsbl	-65(%rbp), %esi
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.6(%rip), %rdi
	movl	$0, -76(%rbp)
	movl	$4, -80(%rbp)
	movl	-76(%rbp), %esi
	movl	-80(%rbp), %edx
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdi
	cmpq	%rdi, %rcx
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	jne	LBB4_2
## %bb.1:
	xorl	%eax, %eax
	addq	$128, %rsp
	popq	%rbp
	retq
LBB4_2:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "

L_.str.1:                               ## @.str.1
	.asciz	"\n"

	.section	__TEXT,__const
	.p2align	4               ## @main.data
l_main.data:
	.long	43                      ## 0x2b
	.long	2                       ## 0x2
	.long	53                      ## 0x35
	.long	9                       ## 0x9
	.long	63                      ## 0x3f
	.long	32                      ## 0x20
	.long	10                      ## 0xa
	.long	6                       ## 0x6
	.long	3                       ## 0x3

	.section	__TEXT,__cstring,cstring_literals
L_.str.2:                               ## @.str.2
	.asciz	"%d\n"

L_.str.3:                               ## @.str.3
	.asciz	"Hello"

L_main.str1:                            ## @main.str1
	.asciz	"Hello"

L_.str.4:                               ## @.str.4
	.asciz	"%lu %lu\n"

L_.str.5:                               ## @.str.5
	.asciz	"%d \n"

L_.str.6:                               ## @.str.6
	.asciz	"%d %d\n"


.subsections_via_symbols
