##INTRO
###BrainFuck
Brainfuck is a Turing-complete programming language created in 1993 by Urban Müller, and notable for its extreme minimalism. This language consists of eight commands, listed below.

<table>
	<tr><th>command</th><th>meaning</th></tr>
	<tr><td>></td>
		<td>increment the data pointer (to point to the next cell to the right).</td>
	</tr>
	<tr><td><</td>
		<td>decrement the data pointer (to point to the next cell to the left).</td>
	</tr>
	<tr><td>+</td>
		<td>increment (increase by one) the byte at the data pointer.</td>
	</tr>
	<tr><td>-</td>
		<td>decrement (decrease by one) the byte at the data pointer.</td>
	</tr>
	<tr><td>.</td>
		<td>output the byte at the data pointer.</td>
	</tr>
	<tr><td>,</td>
		<td>accept one byte of input, storing its value in the byte at the data pointer.</td>
	<tr><td>[</td>
		<td>if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.</td>
	</tr>
	<tr><td>]</td>
		<td>if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.</td>
	</tr>
</table>

###This Interpreter
This interpreter was made as a product as my beginning level
study of programming language, hence, it is Simple and crude, use an array of 30,000 byte cells and at most accept 1,000 bytes of characters input, not support comment so some examples which was with comments are much possible to cause eceptions. It just test by a limited test set which in the directory *test*.