# Note of gdb
### Watch the excution of the program

**next**: go over the function call to the next line of code.
**step**: go into the function call.

### examine variables

**print** VARIABL-NAME
the $## of the result of print is a counter that keeps track of the variables you have examined.

### modify variable

**set** C-STATEMENT

### call functions linked into the program

**call**

### return from function: finish the excution of the function and return the value

**finish** 

##call stack
backtrace:find the list of stack frames below the current frame

### get a backtrace     

**backtrace**: to see the stack below and exmaine the caller-callee relationship

### change stack frame

**frame FRAME_NUMBER**

### examine stack frames

**info frame**: displays information about the current stack frame.
**info locals**: displays the list of local variables and their values for the current stack frame.
**info args**: displays the list of arguments.

## use breakpoints

### set a breakpoint on a line

1. one source file: **break LINE_NUMBER**
2. sevral source files: **break FILE_NAME:LINE_NUMBER**

### set a breakpoint on a C function

**break FUNCTION_NAME**

### set a breakpoint on a C++ function

You must tell break which version of the function you want to break on, even if there is only one. 

**break CLASS_NAME::FUNCTION_NAME(ARGUMENT_TYPE)**

### set a temporary breakpoint.
Temporary breakpoint only stops the pragram once and is then removed.

use the **tbreak** command instead of the **break** command.

### get a list of breakpoints

**info breakpoints**

### skip breakpoints

**ingnore BREAKPOINT_NUMBER NUMBER_OF_TIMES_TO_SKIP**

## use watchpoints

Watchpoints are like breakpoints, but set on **variables**

### set a write watchpoint

**watch VARIABLE_NAME**

the variable watched must be in the current scope. If you want to watch a non-global variable, you must set a breakpoint first. 

### set a read watchpoint

**rwatch**

### set a read/writer watchpoint

**awatch**

### disable watchpoints

**disable WACHTPOINT_NUMBER**

The **info breakpoint** will list all the *breakpoints* and *watchpoints* with their reference numbers.

## advanced gdb features

### examine memory


