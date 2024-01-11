  .text
  .global	main
  .section .data

.Mssg:
  .ascii "HELLO WORLD!\0"
  .section .text

main:
  subq $40,%rsp
  leaq .Mssg(%rip),%rcx
  call puts
  movq $420,%rax
  addq $40,%rsp
  ret
