module test_bench();

    // Inputs
    reg [3:0] A;
    reg [3:0] B;
    reg Cin;

    // Outputs
    wire [3:0] Sum;
    wire Cout;

    // Instantiate the Unit Under Test (UUT)
    full_adder4 uut (
        .A(A), 
        .B(B), 
        .Cin(Cin), 
        .Sum(Sum)
    );

  initial  begin
    $display("\t A,\t B,\t Sum");
    $display("---------------------------------------------------------------------");
    $monitor("\t%d, \t%d, \t%d", A, B, Sum); 
  end 

    initial begin
        // Initialize Inputs
        A = 0;    B = 0;     Cin = 0;
        #5   A = 4'b0001;  B = 4'b0001;
        #5   A = 4'b0001;  B = 4'b0010; 
        #5   A = 4'b0011;  B = 4'b0101; 
        #5   A = 4'b0100;  B = 4'b0110;
        #5   A = 4'b0101; B = 4'b0110;
        #5   A = 4'b0110;  B = 4'b0111;
        #5   A = 4'b0111; B = 4'b1000;
        #10  $stop;

   end

endmodule