.data
x1: 		.word 	0
x2: 		.word 	80
.text
begin: 	lw $15,x1
add $15,$15,x2
beqz $15, end
sw $15,x1
end: 	done
