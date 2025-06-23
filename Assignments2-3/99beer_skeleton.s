.section .rodata            # define read-only data
msg: .string "%d bottles of beer on the wall, %d bottles of beer. Take one down, pass it around, %d bottles of beer on the wall.\n"

.data                       # define writable variable
i: .quad 99
.text
.global main
.type   main, @function

main:
  /* for elf-function call compatibility. Do not touch. */
  pushq %rbp
  movq %rsp ,%rbp
  /* Program code starts here */
  leaq  msg(%rip), %rdi    # move msg to %rdi (register for parameter 1)
              # Deepseek helped me to debug the issue where the first line is printed with %d etc, I removed it and it fixed the problem.
  loop:
    movq  i(%rip), %rsi
    movq  i(%rip), %rdx
    movq  i(%rip), %rcx
    subq  $1, %rcx
    leaq  msg(%rip), %rdi  # move msg to %rdi (register for parameter 1)
    movq  $0, %rax          # zero the %rax register. Do this before calling printf.
    call  printf@PLT        # print the string to terminal.
    subq  $1, i(%rip)       # substract 1 from i.
    cmpq  $94, i(%rip)       # compare i to 95
    jne   loop              # if i was not equal to 0, jump to loop.
    /* Program code ends here */
  movl  $0, %eax
  leave
  ret   $0