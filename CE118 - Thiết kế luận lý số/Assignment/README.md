# 
## Table of Contents:
- [Assignment 1: Sequential Circuit & FSM](#heading)
- [Assignment 2: Design Finite State Machine (FSM)](#heading-1)
- [Assignment 3](#heading-2)
- [Assignment 4](#heading-3)
## Assignment 1: Sequential Circuit & FSM
**6.1** (Clock signal) Compute the clock frequency and duty cycle for a clock signal with a width and period of:
- (a) 5 ns and 20 ns
- (b) 10 ns and 100 ns
- (c) 100 ns and 1 ns

**6.3** (SR Latch) Derive an implementation of a clocked SR latch using only:
- (a) NOR gates
- (b) NAND gates
- (c) AND, OR and INVERT gates

**6.4** (Clocked D latch) Design a D latch using only (a) NAND gates and (b) NOR gates, and then compute D-to-Q and CLK-to-Q delays for positive and negative output transitions.

**6.6** (JK flip-flops) Derive the output waveforms of a master-slave JK-flip-flop for the input waveforms depicted in Figure P6.6.

**6.7** (Flip-flops) Using Karnaugh maps, derive the characteristic equations from the characteristic tables of the four flip-flops shown in table 6.1.

**6.9** (Sequenial analysis) Derive a (a) state table and (b) state diagram for the sequential circuit shown in Figure P6.9.

**6.10** (Sequenial analysis) Derive the (a) state/output table and (b) FSM representation of the circuit shown in Figure P6.10. What is the function of this sequential circuit?

**6.11** (Sequenial analysis) Derive (a) excitation equations, (b) a next-state equation, (c) a stable/output table, and (d) a state diagram for the circuit shown in Figure P6.11.

## Assignment 2: Design Finite State Machine (FSM)
**6.16** (Sequential synthesis) Design a counter that counts in the sequence 0, 1, 3, 6, 10, 15
using four (a) D, (b) SR, (c) JK, (d) T flip-flops as memory elements and natural binary
encoding.

**6.18** (Sequential synthesis) Design a parity checker thay counts the number of 1’s in the
input stream. This checker asserts its output Y if it has received an odd number of 1’s
on the input X. An asynchronous Reset signal returns the parity checker into its initial
state. As storage elements use only (a) D, (b) JK and (c) T flip-flops.

**6.19** (Sequential synthesis) Design a recorgnizer that recognizes an input sequence that has
at least three 1’s. The recorgnizer has a single input X and a single output Y, in addition
to an asynchronous Reset signal. The recognizer sets the output Y to 1 if the input signal
X equals 1 at least three clock cycles after Reset was disasserted. For the recognizer
described above:
- a) Devise the state diagram.
- b) Minimize the number of state.
- c) Encoded the states to minimize the combinatorial logic.
- d) Draw a schematic diagram using D flip-flop.

**6.20** (Sequential synthesis) Design a simplified traffic-light controller that switches traffic
lights on a crossing where a north-south (NS) street intersects an east-west (EW) street.
The input to the controller is the WALK button pushed by pedestrians who want to cross
the street. The outputs are two signals NS and EW that control the traffic lights in the
NS and EW directions. When NS or EWW are 0, the red light is on, and when they are 1,
the green lights is on. Where there are no pedestrians, NS = 0 and EW = 1 for 1 minute,
followed by NS = 1 and EW = 0 for 1 minute, and so on. When a WALK button is pushed,
NS and EW both become 1 for a minute when the present minute expires. After that the
NS and EW signals continue alternating. For these traffic-light controller:
- a) Develop a state diagram and a state/output table.
- b) Minimize the number of states.
- c) Encode the states.
- d) Derive a logic schematic.

## Assignment 3: Storage Components
**7.2** (Registers) Design a register with two load signals that enable the loading of data from
two different sources.

**7.3** (Registers) Explain the difference between resetting the register and loading an all-0’s
input into the register.

**7.4** (Register) Design a 16-bit register that can load new data and rotate or shift its content
left or right.

**7.6** (Shift registers) Design a 16-bit register that can perform two operation: (1) load a new
data and (2) swap the most-significant and least-significant bytes.

**7.8** (Counters) Design a binary counter that counts up only in:
- a) Even numbers (0, 2, 4, 6, 8,…)
- b) Odd numbers (1, 3, 5, 7, 9,…)

**7.11** (Counters) Design a decimal counter that counts modulo 1000.

**7.13** (Asynchronous counters) Contrust a 4-bit asynchronous counter using:
- a) D flip-flops
- b) JK flip-flops

**7.14** (Asynchronous counters) Design a decimal modulo-100 asynchronous counter.

**7.15** (Register files) Design an 8 x 4 register file with:
- b) Two write and one read ports
- c) Two write and two read ports

**7.16** (Memories) Design:
- a) 256K x 8 RAM using 265K x 1 RAM chips
- b) 64K x 32 RAM using 64K x 8 RAM chips
- c) 1M x 1 RAM using 265K x 1 RAM chips
- d) 265K x 8 RAM using 64K x 8 RAM chips

**7.17** (Stack) Design a push-down stack with 1K RAM that uses all (1024) words of the 1K RAM

## Assignment 4: Datapath & Controller
Students design circuits for the following two tasks according to the Datapath and Controller model:
- Count the total number of 1 bits out of the given 8 bits
- Circuit to multiply two 4-bit numbers.

Test the design by simulating the results on Quartus.
