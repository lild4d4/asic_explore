module rdffe(input clk,d,en,rst, output q);
    wire b;
    assign b = en ? d : q;
    sky130_fd_sc_hd__dfrtp_4 dfrtp(
        .D(b),
        .RESET_B(~rst),
        .CLK(clk),
        .Q(q)
    );

endmodule

module sdffe(input clk,d,en,pre, output q);
    wire b;
    assign b = en ? d : q;
    sky130_fd_sc_hd__dfstp_4 dfstp(
        .D(b),
        .SET_B(~pre),
        .CLK(clk),
        .Q(q)
    );
    
endmodule

module inv_with_delay(input A, output Y);
sky130_fd_sc_hd__inv_2 inv(A,B);
endmodule

module nand2_with_delay(input A,input B,output Y);
sky130_fd_sc_hd__nand2_2 nand2(.A(A),.B(B),.Y(Y));
endmodule

module test_ring_osc(input nrst, output osc);

localparam NUM_INVERTERS = 3;

wire [NUM_INVERTERS-1:0] delay_in, delay_out;
wire osc_out;

inv_with_delay idelay [NUM_INVERTERS-1:0] (delay_in, delay_out);
assign delay_in = {delay_out[NUM_INVERTERS-2:0], osc_out};
nand2_with_delay nand2_with_delay(.A(nrst),.B(delay_out[NUM_INVERTERS-1]),.Y(osc_out));

assign osc = osc_out;

endmodule

