// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRACING_GAME_TOP_H_
#define _VRACING_GAME_TOP_H_  // guard

#include "verilated.h"

//==========

class Vracing_game_top__Syms;

//----------

VL_MODULE(Vracing_game_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(racing_game_top__02Eclk,0,0);
    VL_OUT8(racing_game_top__02Ehsync,0,0);
    VL_OUT8(racing_game_top__02Evsync,0,0);
    VL_IN8(sprite_bitmap_top__02Eclk,0,0);
    VL_OUT8(sprite_bitmap_top__02Ehsync,0,0);
    VL_IN8(sprite_render_test_top__02Eclk,0,0);
    VL_IN8(sprite_render_test_top__02Ehpaddle,0,0);
    VL_IN8(sprite_render_test_top__02Evpaddle,0,0);
    VL_OUT8(sprite_render_test_top__02Evsync,0,0);
    VL_IN8(racing_game_top__02Ehpaddle,0,0);
    VL_IN8(racing_game_top__02Evpaddle,0,0);
    VL_OUT8(racing_game_top__02Ergb,2,0);
    VL_IN8(reset,0,0);
    VL_OUT8(sprite_bitmap_top__02Evsync,0,0);
    VL_OUT8(sprite_bitmap_top__02Ergb,2,0);
    VL_OUT8(sprite_render_test_top__02Ehsync,0,0);
    VL_OUT8(sprite_render_test_top__02Ergb,2,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ racing_game_top__DOT__display_on;
    CData/*7:0*/ racing_game_top__DOT__player_x;
    CData/*7:0*/ racing_game_top__DOT__player_y;
    CData/*7:0*/ racing_game_top__DOT__paddle_x;
    CData/*7:0*/ racing_game_top__DOT__paddle_y;
    CData/*7:0*/ racing_game_top__DOT__enemy_x;
    CData/*7:0*/ racing_game_top__DOT__enemy_y;
    CData/*0:0*/ racing_game_top__DOT__enemy_dir;
    CData/*7:0*/ racing_game_top__DOT__speed;
    CData/*0:0*/ racing_game_top__DOT__player_load;
    CData/*3:0*/ racing_game_top__DOT__player_sprite_yofs;
    CData/*3:0*/ racing_game_top__DOT__enemy_sprite_yofs;
    CData/*7:0*/ racing_game_top__DOT__car_sprite_bits;
    CData/*0:0*/ racing_game_top__DOT__player_gfx;
    CData/*0:0*/ racing_game_top__DOT__enemy_gfx;
    CData/*0:0*/ racing_game_top__DOT__enemy_hit_edge;
    CData/*0:0*/ racing_game_top__DOT__frame_collision;
    CData/*0:0*/ racing_game_top__DOT__track_shoulder;
    CData/*0:0*/ racing_game_top__DOT__track_gfx;
    CData/*0:0*/ racing_game_top__DOT__hvsync_gen__DOT__hmaxxed;
    CData/*0:0*/ racing_game_top__DOT__hvsync_gen__DOT__vmaxxed;
    CData/*2:0*/ racing_game_top__DOT__player_renderer__DOT__state;
    CData/*3:0*/ racing_game_top__DOT__player_renderer__DOT__ycount;
    CData/*3:0*/ racing_game_top__DOT__player_renderer__DOT__xcount;
    CData/*7:0*/ racing_game_top__DOT__player_renderer__DOT__outbits;
    CData/*2:0*/ racing_game_top__DOT__enemy_renderer__DOT__state;
    CData/*3:0*/ racing_game_top__DOT__enemy_renderer__DOT__ycount;
    CData/*3:0*/ racing_game_top__DOT__enemy_renderer__DOT__xcount;
    CData/*7:0*/ racing_game_top__DOT__enemy_renderer__DOT__outbits;
    CData/*0:0*/ sprite_bitmap_top__DOT__display_on;
    CData/*3:0*/ sprite_bitmap_top__DOT__car_sprite_xofs;
    CData/*3:0*/ sprite_bitmap_top__DOT__car_sprite_yofs;
    CData/*0:0*/ sprite_bitmap_top__DOT__car_gfx;
    CData/*0:0*/ sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed;
    CData/*0:0*/ sprite_bitmap_top__DOT__hvsync_gen__DOT__vmaxxed;
    CData/*0:0*/ sprite_render_test_top__DOT__display_on;
    CData/*7:0*/ sprite_render_test_top__DOT__player_x;
    CData/*7:0*/ sprite_render_test_top__DOT__player_y;
    CData/*7:0*/ sprite_render_test_top__DOT__paddle_x;
    CData/*7:0*/ sprite_render_test_top__DOT__paddle_y;
    CData/*3:0*/ sprite_render_test_top__DOT__car_sprite_addr;
    CData/*7:0*/ sprite_render_test_top__DOT__car_sprite_bits;
    CData/*0:0*/ sprite_render_test_top__DOT__car_gfx;
    CData/*0:0*/ sprite_render_test_top__DOT__hvsync_gen__DOT__hmaxxed;
    CData/*0:0*/ sprite_render_test_top__DOT__hvsync_gen__DOT__vmaxxed;
    CData/*2:0*/ sprite_render_test_top__DOT__renderer__DOT__state;
    CData/*3:0*/ sprite_render_test_top__DOT__renderer__DOT__ycount;
    CData/*3:0*/ sprite_render_test_top__DOT__renderer__DOT__xcount;
    CData/*7:0*/ sprite_render_test_top__DOT__renderer__DOT__outbits;
    SData/*8:0*/ racing_game_top__DOT__hpos;
    SData/*8:0*/ racing_game_top__DOT__vpos;
    SData/*15:0*/ racing_game_top__DOT__track_pos;
    SData/*8:0*/ sprite_bitmap_top__DOT__hpos;
    SData/*8:0*/ sprite_bitmap_top__DOT__vpos;
    SData/*8:0*/ sprite_render_test_top__DOT__hpos;
    SData/*8:0*/ sprite_render_test_top__DOT__vpos;
    CData/*7:0*/ racing_game_top__DOT__car__DOT__bitarray[16];
    CData/*7:0*/ sprite_bitmap_top__DOT__car__DOT__bitarray[16];
    CData/*7:0*/ sprite_render_test_top__DOT__car__DOT__bitarray[16];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ __Vdly__racing_game_top__DOT__enemy_y;
    CData/*7:0*/ __Vdly__racing_game_top__DOT__enemy_x;
    CData/*0:0*/ __VinpClk__TOP__racing_game_top__02Evsync;
    CData/*0:0*/ __VinpClk__TOP__sprite_render_test_top__02Evsync;
    CData/*0:0*/ __VinpClk__TOP__sprite_bitmap_top__02Ehsync;
    CData/*0:0*/ __VinpClk__TOP__racing_game_top__02Ehsync;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__racing_game_top__02Evsync;
    CData/*0:0*/ __Vclklast__TOP__sprite_render_test_top__02Ehpaddle;
    CData/*0:0*/ __Vclklast__TOP__sprite_render_test_top__02Evpaddle;
    CData/*0:0*/ __Vclklast__TOP__sprite_render_test_top__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__sprite_bitmap_top__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__racing_game_top__02Eclk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sprite_render_test_top__02Evsync;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__sprite_bitmap_top__02Ehsync;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__racing_game_top__02Ehsync;
    CData/*0:0*/ __Vchglast__TOP__racing_game_top__02Ehsync;
    CData/*0:0*/ __Vchglast__TOP__racing_game_top__02Evsync;
    CData/*0:0*/ __Vchglast__TOP__sprite_bitmap_top__02Ehsync;
    CData/*0:0*/ __Vchglast__TOP__sprite_render_test_top__02Evsync;
    SData/*8:0*/ __Vdly__racing_game_top__DOT__vpos;
    SData/*8:0*/ __Vdly__sprite_bitmap_top__DOT__vpos;
    SData/*8:0*/ __Vdly__sprite_render_test_top__DOT__vpos;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vracing_game_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vracing_game_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vracing_game_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vracing_game_top();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vracing_game_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vracing_game_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vracing_game_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vracing_game_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__10(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _combo__TOP__20(Vracing_game_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vracing_game_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vracing_game_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vracing_game_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vracing_game_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__17(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__22(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__14(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__16(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__18(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__19(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vracing_game_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__8(Vracing_game_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
