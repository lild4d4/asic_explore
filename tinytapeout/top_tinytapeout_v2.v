module top_tinytapeout_v2(input clk, input en, input reset, output wire [15:0] promedio);

wire out_osc;
wire [15:0] count;
test_ringosc_vargen osc(en, out_osc);
contador #(16) cont(out_osc, en, reset, clk, count);
promedio #(16) prom(clk, reset, en, count, promedio);

endmodule
