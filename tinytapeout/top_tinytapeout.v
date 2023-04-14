module top_tinytapeout(input clk, input en, input reset, output wire [8:0] count);

wire out_osc;
test_ringosc_vargen osc(en, out_osc);
contador cont(out_osc, en, reset, clk, count);

endmodule
