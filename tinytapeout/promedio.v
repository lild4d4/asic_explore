module promedio#(parameter N=4)(
	input clk, reset, en,
	input [N-1:0] in,
	output reg [N-1:0] promedio
); 

reg [3:0] contador;

always @(posedge clk) begin
	if(reset) contador <= 0;
	else if(en) contador <= contador + 1;
end

always @(posedge clk) begin
	if(reset) promedio <= 0;
	else if(contador == 15) promedio <= promedio/15;
	else if(en) promedio <= promedio + in;
end	
	
endmodule
