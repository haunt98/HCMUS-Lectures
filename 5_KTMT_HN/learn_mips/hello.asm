# Print hello word

	.data
hello_msg:	.asciiz "Hello everyone\n"
bye_msg:	.asciiz "Bye my friends :("

	.text
main:
	# print hello
	la $a0, hello_msg
	add $v0, $zero, 4	# syscall 4 : print string
	syscall

	# print goodbye
	la $a0, bye_msg
	add $v0, $zero, 4
	syscall