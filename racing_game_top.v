module racing_game_top(clk, hsync, vsync, rgb, hpaddle, vpaddle);

  input clk;
  input hpaddle, vpaddle;
  output hsync, vsync;
  output [2:0] rgb;
  wire display_on;
  wire [8:0] hpos;
  wire [8:0] vpos;

  // player car position (set at VSYNC)
  reg [7:0] player_x;
  reg [7:0] player_y;  
  // paddle position (set continuously during frame)
  reg [7:0] paddle_x;
  reg [7:0] paddle_y;
  // enemy car position
  reg [7:0] enemy_x = 128;
  reg [7:0] enemy_y = 128;
  // enemy car direction, 1=right, 0=left
  reg enemy_dir = 0;	
  
  reg [15:0] track_pos = 0;	// player position along track (16 bits)
  reg [7:0] speed = 31;		// player velocity along track (8 bits)
  
  // video sync generator
  hvsync_generator hvsync_gen(
    .clk(clk),
    .reset(0),
    .hsync(hsync),
    .vsync(vsync),
    .display_on(display_on),
    .hpos(hpos),
    .vpos(vpos)
  );
  
  // set paddle registers
  always @(posedge hsync)
    begin
      if (!hpaddle) paddle_x <= vpos[7:0];
      if (!vpaddle) paddle_y <= vpos[7:0];
    end

  
  // select player or enemy access to ROM
  wire player_load = (hpos >= 256) && (hpos < 260);
  wire enemy_load = (hpos >= 260);
  // wire up car sprite ROM
  // multiplex between player and enemy ROM address
  wire [3:0] player_sprite_yofs;
  wire [3:0] enemy_sprite_yofs;
  wire [3:0] car_sprite_yofs = player_load ? player_sprite_yofs : enemy_sprite_yofs;  
  wire [7:0] car_sprite_bits;  
  car_bitmap car(
    .yofs(car_sprite_yofs), 
    .bits(car_sprite_bits));
  
  // signals for player sprite generator
  wire player_vstart = {1'b0,player_y} == vpos;
  wire player_hstart = {1'b0,player_x} == hpos;
  wire player_gfx;
  wire player_is_drawing;

  // signals for enemy sprite generator
  wire enemy_vstart = {1'b0,enemy_y} == vpos;
  wire enemy_hstart = {1'b0,enemy_x} == hpos;
  wire enemy_gfx;
  wire enemy_is_drawing;
  
  // player sprite generator
  sprite_renderer player_renderer(
    .clk(clk),
    .vstart(player_vstart),
    .load(player_load),
    .hstart(player_hstart),
    .rom_addr(player_sprite_yofs),
    .rom_bits(car_sprite_bits),
    .gfx(player_gfx),
    .in_progress(player_is_drawing));

  // enemy sprite generator
  sprite_renderer enemy_renderer(
    .clk(clk),
    .vstart(enemy_vstart),
    .load(enemy_load),
    .hstart(enemy_hstart),
    .rom_addr(enemy_sprite_yofs),
    .rom_bits(car_sprite_bits),
    .gfx(enemy_gfx),
    .in_progress(enemy_is_drawing));

  // signals for enemy bouncing off left/right borders  
  wire enemy_hit_left = (enemy_x == 64);
  wire enemy_hit_right = (enemy_x == 192);
  wire enemy_hit_edge = enemy_hit_left || enemy_hit_right;
  
  // update player, enemy, track counters
  // runs once per frame
  always @(posedge vsync)
    begin
      player_x <= paddle_x;
      player_y <= 180;
      track_pos <= track_pos + {11'b0,speed[7:4]};
      enemy_y <= enemy_y + {3'b0, speed[7:4]};
      if (enemy_hit_edge)
        enemy_dir <= !enemy_dir;
      if (enemy_dir ^ enemy_hit_edge)
        enemy_x <= enemy_x + 1;
      else
        enemy_x <= enemy_x - 1;
      // collision check?
      if (frame_collision)
        speed <= 16;
      else if (speed < ~paddle_y)
        speed <= speed + 1;
      else
        speed <= speed - 1;
    end
  
  // set to 1 when player collides with enemy or track
  reg frame_collision;
  
  always @(posedge clk)
    if (player_gfx && (enemy_gfx || track_gfx))
      frame_collision <= 1;
    else if (vsync)
      frame_collision <= 0;
  
  // track graphics signals
  wire track_offside = (hpos[7:5]==0) || (hpos[7:5]==7);
  wire track_shoulder = (hpos[7:3]==3) || (hpos[7:3]==28);
  wire track_gfx = (vpos[5:1]!=track_pos[5:1]) && track_offside;
  
  // combine signals for RGB output
  wire r = display_on && (player_gfx || enemy_gfx || track_shoulder);
  wire g = display_on && (player_gfx || track_gfx);
  wire b = display_on && (enemy_gfx || track_shoulder);
  assign rgb = {b,g,r};

endmodule

`ifndef HVSYNC_GENERATOR_H
`define HVSYNC_GENERATOR_H

/*
Video sync generator, used to drive a simulated CRT.
To use:
- Wire the hsync and vsync signals to top level outputs
- Add a 3-bit (or more) "rgb" output to the top level
*/

module hvsync_generator(clk, reset, hsync, vsync, display_on, hpos, vpos);

  input clk;
  input reset;
  output reg hsync, vsync;
  output display_on;
  output reg [8:0] hpos;
  output reg [8:0] vpos;

  // declarations for TV-simulator sync parameters
  // horizontal constants
  parameter H_DISPLAY       = 256; // horizontal display width
  parameter H_BACK          =  23; // horizontal left border (back porch)
  parameter H_FRONT         =   7; // horizontal right border (front porch)
  parameter H_SYNC          =  23; // horizontal sync width
  // vertical constants
  parameter V_DISPLAY       = 240; // vertical display height
  parameter V_TOP           =   5; // vertical top border
  parameter V_BOTTOM        =  14; // vertical bottom border
  parameter V_SYNC          =   3; // vertical sync # lines
  // derived constants
  parameter H_SYNC_START    = H_DISPLAY + H_FRONT;
  parameter H_SYNC_END      = H_DISPLAY + H_FRONT + H_SYNC - 1;
  parameter H_MAX           = H_DISPLAY + H_BACK + H_FRONT + H_SYNC - 1;
  parameter V_SYNC_START    = V_DISPLAY + V_BOTTOM;
  parameter V_SYNC_END      = V_DISPLAY + V_BOTTOM + V_SYNC - 1;
  parameter V_MAX           = V_DISPLAY + V_TOP + V_BOTTOM + V_SYNC - 1;

  wire hmaxxed = (hpos == H_MAX) || reset;	// set when hpos is maximum
  wire vmaxxed = (vpos == V_MAX) || reset;	// set when vpos is maximum
  
  // horizontal position counter
  always @(posedge clk)
  begin
    hsync <= (hpos>=H_SYNC_START && hpos<=H_SYNC_END);
    if(hmaxxed)
      hpos <= 0;
    else
      hpos <= hpos + 1;
  end

  // vertical position counter
  always @(posedge clk)
  begin
    vsync <= (vpos>=V_SYNC_START && vpos<=V_SYNC_END);
    if(hmaxxed)
      if (vmaxxed)
        vpos <= 0;
      else
        vpos <= vpos + 1;
  end
  
  // display_on is set when beam is in "safe" visible frame
  assign display_on = (hpos<H_DISPLAY) && (vpos<V_DISPLAY);

endmodule

`endif

`ifndef SPRITE_BITMAP_H
`define SPRITE_BITMAP_H

/*
Simple sprite renderer example.

car_bitmap - ROM for a car sprite.
sprite_bitmap_top - Example sprite rendering module.
*/

module car_bitmap(yofs, bits);
  
  input [3:0] yofs;
  output [7:0] bits;

  reg [7:0] bitarray[0:15];
  
  assign bits = bitarray[yofs];
  
  initial begin/*{w:8,h:16}*/
    bitarray[0] = 8'b0;
    bitarray[1] = 8'b1100;
    bitarray[2] = 8'b11001100;
    bitarray[3] = 8'b11111100;
    bitarray[4] = 8'b11101100;
    bitarray[5] = 8'b11100000;
    bitarray[6] = 8'b1100000;
    bitarray[7] = 8'b1110000;
    bitarray[8] = 8'b110000;
    bitarray[9] = 8'b110000;
    bitarray[10] = 8'b110000;
    bitarray[11] = 8'b1101110;
    bitarray[12] = 8'b11101110;
    bitarray[13] = 8'b11111110;
    bitarray[14] = 8'b11101110;
    bitarray[15] = 8'b101110;
  end
  
endmodule

module sprite_bitmap_top(clk, reset, hsync, vsync, rgb);

  input clk, reset;
  output hsync, vsync;
  output [2:0] rgb;
  wire display_on;
  wire [8:0] hpos;
  wire [8:0] vpos;

  reg sprite_active;
  reg [3:0] car_sprite_xofs;
  reg [3:0] car_sprite_yofs;
  wire [7:0] car_sprite_bits;
  
  reg [8:0] player_x = 128;
  reg [8:0] player_y = 128;
  
  hvsync_generator hvsync_gen(
    .clk(clk),
    .reset(reset),
    .hsync(hsync),
    .vsync(vsync),
    .display_on(display_on),
    .hpos(hpos),
    .vpos(vpos)
  );
  
  car_bitmap car(
    .yofs(car_sprite_yofs), 
    .bits(car_sprite_bits));

  // start Y counter when we hit the top border (player_y)
  always @(posedge hsync)
    if (vpos == player_y)
      car_sprite_yofs <= 15;
    else if (car_sprite_yofs != 0)
      car_sprite_yofs <= car_sprite_yofs - 1;
  
  // restart X counter when we hit the left border (player_x)
  always @(posedge clk)
    if (hpos == player_x)
      car_sprite_xofs <= 15;
    else if (car_sprite_xofs != 0)
      car_sprite_xofs <= car_sprite_xofs - 1;

  // mirror sprite in X direction
  wire [3:0] car_bit = car_sprite_xofs>=8 ? 
                                 15-car_sprite_xofs:
                                 car_sprite_xofs;

  wire car_gfx = car_sprite_bits[car_bit[2:0]];

  wire r = display_on && car_gfx;
  wire g = display_on && car_gfx;
  wire b = display_on && car_gfx;
  assign rgb = {b,g,r};

endmodule

`endif

`ifndef SPRITE_RENDERER_H
`define SPRITE_RENDERER_H   

/*
Displays a 16x16 sprite (8 bits mirrored left/right).
*/

module sprite_renderer(clk, vstart, load, hstart, rom_addr, rom_bits, 
                       gfx, in_progress);
  
  input clk;
  input vstart;		// start drawing (top border)
  input load;		// ok to load sprite data?
  input hstart;		// start drawing scanline (left border)
  output reg [3:0] rom_addr;	// select ROM address
  input [7:0] rom_bits;		// input bits from ROM
  output reg gfx;		// output pixel
  output in_progress;	// 0 if waiting for vstart
  
  reg [2:0] state;	// current state #
  reg [3:0] ycount;	// number of scanlines drawn so far
  reg [3:0] xcount;	// number of horiz. pixels in this line
  
  reg [7:0] outbits;	// register to store bits from ROM
  
  // states for state machine
  localparam WAIT_FOR_VSTART = 0;
  localparam WAIT_FOR_LOAD   = 1;
  localparam LOAD1_SETUP     = 2;
  localparam LOAD1_FETCH     = 3;
  localparam WAIT_FOR_HSTART = 4;
  localparam DRAW            = 5;

  // assign in_progress output bit
  assign in_progress = state != WAIT_FOR_VSTART;

  always @(posedge clk)
    begin
      case (state)
        WAIT_FOR_VSTART: begin
          ycount <= 0; // initialize vertical count
          gfx <= 0; // default pixel value (off)
          // wait for vstart, then next state
          if (vstart)
            state <= WAIT_FOR_LOAD;
        end
        WAIT_FOR_LOAD: begin
          xcount <= 0; // initialize horiz. count
	  gfx <= 0;
          // wait for load, then next state
          if (load)
            state <= LOAD1_SETUP;
        end
        LOAD1_SETUP: begin
          rom_addr <= ycount; // load ROM address
          state <= LOAD1_FETCH;
        end
        LOAD1_FETCH: begin
	  outbits <= rom_bits; // latch bits from ROM
          state <= WAIT_FOR_HSTART;
        end
        WAIT_FOR_HSTART: begin
          // wait for hstart, then start drawing
          if (hstart)
            state <= DRAW;
        end
        DRAW: begin
          // get pixel, mirroring graphics left/right
          gfx <= outbits[xcount<8 ? xcount[2:0] : ~xcount[2:0]];
          xcount <= xcount + 1;
          // finished drawing horizontal slice?
          if (xcount == 15) begin // pre-increment value
            ycount <= ycount + 1;
            // finished drawing sprite?
            if (ycount == 15) // pre-increment value
              state <= WAIT_FOR_VSTART; // done drawing sprite
            else
	      state <= WAIT_FOR_LOAD; // done drawing this scanline
          end
        end
        // unknown state -- reset
        default: begin
          state <= WAIT_FOR_VSTART; 
        end
      endcase
    end
  
endmodule

/// TEST MODULE

module sprite_render_test_top(clk, hsync, vsync, rgb, hpaddle, vpaddle);

  input clk;
  input hpaddle, vpaddle;
  output hsync, vsync;
  output [2:0] rgb;
  wire display_on;
  wire [8:0] hpos;
  wire [8:0] vpos;

  // player position
  reg [7:0] player_x;
  reg [7:0] player_y;
  
  // paddle position
  reg [7:0] paddle_x;
  reg [7:0] paddle_y;
  
  // video sync generator
  hvsync_generator hvsync_gen(
    .clk(clk),
    .reset(0),
    .hsync(hsync),
    .vsync(vsync),
    .display_on(display_on),
    .hpos(hpos),
    .vpos(vpos)
  );
  
  // car bitmap ROM and associated wires
  wire [3:0] car_sprite_addr;
  wire [7:0] car_sprite_bits;
  
  car_bitmap car(
    .yofs(car_sprite_addr), 
    .bits(car_sprite_bits));
   
  // convert player X/Y to 9 bits and compare to CRT hpos/vpos
  wire vstart = {1'b0,player_y} == vpos;
  wire hstart = {1'b0,player_x} == hpos;
  
  wire car_gfx;		// car sprite video signal
  wire in_progress;	// 1 = rendering taking place on scanline

  // sprite renderer module
  sprite_renderer renderer(
    .clk(clk),
    .vstart(vstart),
    .load(hsync),
    .hstart(hstart),
    .rom_addr(car_sprite_addr),
    .rom_bits(car_sprite_bits),
    .gfx(car_gfx),
    .in_progress(in_progress));

  // measure paddle position
  always @(posedge hpaddle)
    paddle_x <= vpos[7:0];

  always @(posedge vpaddle)
    paddle_y <= vpos[7:0];

  always @(posedge vsync)
    begin
      player_x <= paddle_x;
      player_y <= paddle_y;
    end

  // video RGB output
  wire r = display_on && car_gfx;
  wire g = display_on && car_gfx;
  wire b = display_on && in_progress;
  assign rgb = {b,g,r};

endmodule

`endif
