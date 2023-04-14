module contador(input osc_clk, input en, input reset, input clk, output reg [8:0] count);

reg aux;
reg pre_aux;

always @(posedge osc_clk) begin
	if(reset) aux <= 1;
	//else aux <= pre_aux;
end

always @(posedge osc_clk) begin
	if(clk && aux) begin
		aux <= 0;
		count <= 0;
	end
	else if(en) begin
		if(!clk) aux<= 1;
		count <= count + 1;
	end
end

endmodule
