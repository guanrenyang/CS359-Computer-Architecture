# Experiment Report

## Practice 2: Question Answering

1. How do you pass command line arguments to a program when using gdb?
The command is listed above:
```
run ARG1 ARG2
```
where ARG1 and ARG2 are any argument you want to pass to the program. Of course, you could pass any arguments as you need. 

2. How do you set a breakpoint which only occurs when a set of conditions is true (e.g. when
certain variables are a certain value)?

The commands could the two types below:

```
break LINE_NUMBER if EXPRESSION
```

```
break FUNCTION_NAME if EXPRESSION
```

Explanation: 
$LINE_NUMBER$ is the reference number of the line where the breakpoint is set.
$FUNCTION_NAME$ is the name of the function which the breakpoint is set on.
$EXPRESSION$ is a conditional discriminant.(e.g. You could pass expression $i==0$ to set a breakpoint iff. variable $i$ is equal to zero.)

3. How do you execute the next line of C code in the program after stopping at a breakpoint?

You could excute the next line of C code by command **next** or command **step**.

4. If the next line of code is a function call, you'll execute the whole function call at once if you use your answer to #3. How do you tell GDB that you want to debug the code inside the
function instead?

Answer to the first question: AT ONCE: **next** command.
Answer to the second question: INSIDE: **step** command.

5. How do you resume the program after stopping at a breakpoint?

Using the **continue** command.

6. How can you see the value of a variable (or even an expression like 1+2) in gdb?

The **watch** command can be used to see the value the a variable or an expression.
First step: set a breakpoint or send a signal to terminate the program.
Second step: use the **watch** command to set a watchpoint. 
The command needs to be used in such format:

```
watch EXPRESSION-or-VARIABLE_NAME
```
Last step: use the **continue** command to restart the program. The program will pause at the breakpoint and display the address and variable of the variable.(If the watchpoint is set on an expression, only the address will be displayed.)

7. How do you configure gdb so it prints the value of a variable after every step?

You could use the **print** command after every **next** or **step** command.
The usage of **print** command:
```
print VARIABLE_NAME
```
8. How do you print a list of all variables and their values in the current function?

You could use the **info locals** to see the list of local variables and their values for the current stack frame.

9. How do you exit out of gdb?
You could use the **quit** command the exit out of gdb.

## Practice 3: Right Function format
```
int ll_equal(const node* a, const node* b) {
	while (a != NULL&& b != NULL) {
		if (a->val != b->val)
			return 0;
		a = a->next;
		b = b->next;
	}
	/* lists are equal if a and b are both null */
	return a == b;
}
```
## Practice 4: Core Part of wc.c

```
void wc(FILE *ofile, FILE *infile, char *inname) {
  // your code here:
  
  int byte_count=0;
  int line_count=0;
  int word_count=0;
  
  char last_char=' ';
  char current_char;

  while (last_char!=EOF)
  {
	  if(infile==NULL)
	  	current_char=getchar();
	  else
	  	current_char=getc(infile);

	  if(current_char!=EOF)
	  {
		  byte_count++;
	  }
	  else if(last_char!='\n')
	  {
		  line_count++;
	  }
	  if(current_char=='\n')
	  {
		  line_count++;
	  }
	  if(current_char==' '||current_char=='\n'||current_char=='\t'||current_char==EOF)
	  	if(last_char!=' '&&last_char!='\n'&&last_char!='\t')//when the current character read is space or a '\n', then check if the last read character is a empty character. 
		{
			word_count++;
		}
	  last_char=current_char;
  }
  if(ofile==NULL) // when the out_file is default
  	printf(" %d %d %d %s",line_count,word_count,byte_count,inname);
  else
  {
	  char byte_count_string[10000];
	  char line_count_string[10000];
	  char word_count_string[10000];

	  sprintf(byte_count_string,"%d",byte_count);
	  sprintf(line_count_string,"%d",line_count);
	  sprintf(word_count_string,"%d",word_count);

	  strcat(byte_count_string," ");
	  strcat(line_count_string," ");
	  strcat(word_count_string," ");
	
	  fputs(" ",ofile);
	  fputs(line_count_string,ofile);
	  fputs(byte_count_string,ofile);
	  fputs(word_count_string,ofile);
	  fputs(inname,ofile);
  }
}
```
