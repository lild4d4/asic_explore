`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.11.2022 17:36:58
// Design Name: 
// Module Name: Command_Decoder
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


module Command_Decoder(
    input logic             reset, clk, rx_ready,
    input logic     [7:0]   rx_data,
    
    output logic            weA, weB,
    output logic    [15:0]  address_write,
    output logic    [2:0]   opCode,
    output logic            start
    );

    //FSM states type:
    enum logic [3:0] {IDLE, WAIT_VECTORA1, WAIT_VECTORA2, WRITE_VECTORA, WAIT_VECTORB1, WAIT_VECTORB2, WRITE_VECTORB, WAIT_COMMAND, START} state, nx_state;
    
    
    //FSM state register:
    always_ff @(posedge clk) 
    if (reset) state <= IDLE;
    else state <= nx_state;
    
    //Sincronizacion de la direccion de escritura
    logic [15:0] address_write_aux;
    always_ff @(posedge clk) 
    if (reset) address_write <= 0;
    else address_write <= address_write_aux;
    
    //Sincronizacion OpCode
    logic [2:0] opCode_aux;
    always_ff @(posedge clk) 
    if (reset) opCode <= 0;
    else opCode <= opCode_aux;
    
    //FSM combinational logic:
    always_comb begin
        //declaraciones default
        nx_state = state;
        weA=0;
        weB=0;
        start = 0;
        opCode_aux = opCode;
        address_write_aux = address_write;
        
        //casos de estados
        case(state)
            //espera de la primera trama UART la cual indicara si se quiere escirbir en B, en A 
        	//o si se quiere ingresas un comando de operacion aritmetica
        	IDLE: begin    
        	  if(rx_ready & rx_data == 0) nx_state = WAIT_VECTORA1;
        	  else if(rx_ready & rx_data == 1) nx_state = WAIT_VECTORB1;
        	  else if(rx_ready & rx_data == 2) nx_state = WAIT_COMMAND;
        	end
        	//Espera primeros 8 bits de direccion de escritura sobre vector A
        	WAIT_VECTORA1: begin
        	  if(rx_ready) begin
        	      address_write_aux[7:0]= rx_data;
        	      nx_state = WAIT_VECTORA2;
        	  end
        	end
        	//Espera segundos 8 bits de direccion de escritura sobre vector A
        	WAIT_VECTORA2: begin
        	  if(rx_ready) begin
        	      address_write_aux[15:8]= rx_data;
        	      nx_state = WRITE_VECTORA;
        	  end
        	end
        	//Envio señal de escritura de rx_data sobre A en la direccion address_write
        	WRITE_VECTORA: begin
                   if(rx_ready) begin
                       weA = 1;
                       nx_state = IDLE;
                   end
        	end
        	//Espera primeros 8 bits de direccion de escritura sobre vector B
        	WAIT_VECTORB1: begin
        	  if(rx_ready) begin
        	      address_write_aux[7:0] = rx_data;
        	      nx_state = WAIT_VECTORB2;
        	  end
        	end
        	//Espera segundos 8 bits de direccion de escritura sobre vector B
        	WAIT_VECTORB2: begin
        	  if(rx_ready) begin
        	      address_write_aux[15:8] = rx_data;
        	      nx_state = WRITE_VECTORB;
        	  end
        	end
        	//Envio señal de escritura de rx_data sobre B en la direccion address_write
        	WRITE_VECTORB: begin
                   if(rx_ready) begin
                       weB = 1;
                       nx_state = IDLE;
                   end
        	end
        	//Espera del comando que indica la operacion que se desea realizar
        	WAIT_COMMAND: begin
        	  if(rx_ready) begin
        	      opCode_aux = rx_data;
        	      nx_state = START;
        	  end 
        	end
        	//Envio señal de inicio de la operacion correspondiente a la operacion determinada por el comando anteriormente recibido
        	START: begin
        	  start = 1;
        	  nx_state = IDLE;
        	end
        endcase
    end

endmodule
