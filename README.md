# Cursed_3D_Spinning_Donut
A 3D Spinning Donut that was implemented using cursed C++ syntax.

<h2>Usage</h2>
Type <code>make</code> command in the Linux terminal to compile and run automatically. (All files shall be in the same directory)<br>
For clearing all compiled objects, use the <code>make clean</code> command.<br><br>
To use the cursed syntax version of Donut.cpp, change the code in line 11 of Makefile from<br>
<code>OBJS = Main.o Donut.o</code><br>
to<br>
<code>OBJS = Main.o CursedDonut.o</code>
