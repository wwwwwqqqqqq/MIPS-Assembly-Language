#Example 2.
 #Prompts the user for one character. Checks whether the 
#character is a digit and prints an appropriate message.

.data
inchar: .space 3
prompt: .asciiz "Type a char: "
yes str: .asciiz "Yes -- It is a digit.\n"
no str: .asciiz "No -- It is not a digit.\n"

.text
.globl main
#Prompt user for character.
main:
li       $v0,4    #Command for print string. 
la       $a0,prompt     #Start addr. of prompt string.
syscall

#Read the character. (We must also read the newline character and
 #provide space for the '\0' character. So, the buffer 
#must be at least 3 characters long.) 
li       $v0, 8       #Command for read string.           
la       $a0, inchar  #Buffer           
li       $a1, 3       #Max. no. of characters (incl. newline)                                 
#to be read = 3 - 1 = 2.           
syscall 

#Check whether the character is a digit. 
lbu      $4, inchar   #Get the character into $4.
li       $5, 48       # 48 is the ASCII code for '0'
li       $6, 57       # 57 is the ASCII code for '9'
blt      $4, $5, no_part  #If ascii code is < 48 or > 57 
bgt      $4, $6, no_part  #it can't be a digit.

#Code to print "yes" answer and stop.  
yes_part:
li       $v0, 4
la       $a0, yes_str 
syscall
li       $v0, 10 
syscall 

#Code to print "no" answer and stop. 
no_part:
li       $v0, 4
la       $a0, no_str 
syscall 
li       $v0, 10
syscall

 