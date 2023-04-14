`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 22.03.2023 19:30:03
// Design Name: 
// Module Name: tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module tb(

    );
    reg clk;
    reg en;
    reg reset;
    wire [8:0] count;
    top_tinytapeout DUT(clk, en, reset, count);
    
    always #500 clk = ~clk;
    
    initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,tb);
    reset = 1;
    clk=0;
    en = 0;
    #10 reset = 0;
    #1500 en = 1;
    #5000 $finish;
    end
    
endmodule
