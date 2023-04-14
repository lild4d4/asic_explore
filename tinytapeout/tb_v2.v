module tb_v2(

    );
    reg clk;
    reg en;
    reg reset;
    wire [8:0] promedio;
    top_tinytapeout_v2 DUT(clk, en, reset, promedio);
    
    always #500 clk = ~clk;
    
    initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,tb_v2);
    reset = 1;
    clk=0;
    en = 0;
    #1000 en = 1;
    #1500 reset = 0;
    #20000 $finish;
    end
    
endmodule
