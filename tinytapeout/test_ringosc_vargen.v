`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.03.2023 20:42:16
// Design Name: 
// Module Name: test_ringosc_vargen
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


module test_ringosc_vargen(
    input en,
    output out
    );
   
    localparam etapas = 3;
    
    wire aux_wire [etapas:0];
    
    genvar i;
    generate
    for(i=0; i<etapas; i=i+1) begin
        NOR_2 inv(aux_wire[i+1], aux_wire[i], aux_wire[i]);
    end
    endgenerate
    
    assign aux_wire[0] = out & en;
    assign out = aux_wire[etapas];
    //assign in = out;
endmodule
