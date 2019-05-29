
module adder(a, b, cin, s, cout);
	input a, b, cin;
	output s, cout;

	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (cin & a) | (cin & b);
endmodule

module full_adder4(A, B, Cin, Sum, Cout);
	input [3:0] A,B;    // four-bit inputs 
	input Cin;           // one-input input carry

	output [3:0] Sum; // five-bit outputs 
	output Cout;

	wire [2:0] carry;   //  internal carry wires

	adder fa0(A[0],B[0],Cin,Sum[0],carry[0]);
	adder fa1(A[1],B[1],carry[0],Sum[1],carry[1]);
	adder fa2(A[2],B[2],carry[1],Sum[2],carry[2]);
	adder fa3(A[3],B[3],carry[2],Sum[3],Cout);
endmodule