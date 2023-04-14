// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vracing_game_top.h for the primary calling header

#include "Vracing_game_top.h"
#include "Vracing_game_top__Syms.h"

//==========

VL_CTOR_IMP(Vracing_game_top) {
    Vracing_game_top__Syms* __restrict vlSymsp = __VlSymsp = new Vracing_game_top__Syms(this, name());
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vracing_game_top::__Vconfigure(Vracing_game_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vracing_game_top::~Vracing_game_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vracing_game_top::_initial__TOP__1(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_initial__TOP__1\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0U] = 0U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[1U] = 0xcU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[2U] = 0xccU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[3U] = 0xfcU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[4U] = 0xecU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[5U] = 0xe0U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[6U] = 0x60U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[7U] = 0x70U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[8U] = 0x30U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[9U] = 0x30U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xaU] = 0x30U;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xbU] = 0x6eU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xcU] = 0xeeU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xdU] = 0xfeU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xeU] = 0xeeU;
    vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray[0xfU] = 0x2eU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0U] = 0U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[1U] = 0xcU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[2U] = 0xccU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[3U] = 0xfcU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[4U] = 0xecU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[5U] = 0xe0U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[6U] = 0x60U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[7U] = 0x70U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[8U] = 0x30U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[9U] = 0x30U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xaU] = 0x30U;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xbU] = 0x6eU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xcU] = 0xeeU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xdU] = 0xfeU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xeU] = 0xeeU;
    vlTOPp->racing_game_top__DOT__car__DOT__bitarray[0xfU] = 0x2eU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0U] = 0U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[1U] = 0xcU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[2U] = 0xccU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[3U] = 0xfcU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[4U] = 0xecU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[5U] = 0xe0U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[6U] = 0x60U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[7U] = 0x70U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[8U] = 0x30U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[9U] = 0x30U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xaU] = 0x30U;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xbU] = 0x6eU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xcU] = 0xeeU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xdU] = 0xfeU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xeU] = 0xeeU;
    vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray[0xfU] = 0x2eU;
    vlTOPp->racing_game_top__DOT__enemy_dir = 0U;
    vlTOPp->racing_game_top__DOT__speed = 0x1fU;
    vlTOPp->racing_game_top__DOT__track_pos = 0U;
    vlTOPp->racing_game_top__DOT__enemy_y = 0x80U;
    vlTOPp->racing_game_top__DOT__enemy_x = 0x80U;
}

void Vracing_game_top::_settle__TOP__8(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_settle__TOP__8\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed 
        = ((0x134U == (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)) 
           | (IData)(vlTOPp->reset));
    vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__hmaxxed 
        = (0x134U == (IData)(vlTOPp->sprite_render_test_top__DOT__hpos));
    vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__hmaxxed 
        = (0x134U == (IData)(vlTOPp->racing_game_top__DOT__hpos));
    vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__vmaxxed 
        = ((0x105U == (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)) 
           | (IData)(vlTOPp->reset));
    vlTOPp->sprite_bitmap_top__DOT__display_on = ((0x100U 
                                                   > (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)) 
                                                  & (0xf0U 
                                                     > (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)));
    vlTOPp->racing_game_top__DOT__player_load = ((0x100U 
                                                  <= (IData)(vlTOPp->racing_game_top__DOT__hpos)) 
                                                 & (0x104U 
                                                    > (IData)(vlTOPp->racing_game_top__DOT__hpos)));
    vlTOPp->racing_game_top__DOT__track_shoulder = 
        ((3U == (0x1fU & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                          >> 3U))) | (0x1cU == (0x1fU 
                                                & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                                                   >> 3U))));
    vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__vmaxxed 
        = (0x105U == (IData)(vlTOPp->sprite_render_test_top__DOT__vpos));
    vlTOPp->sprite_render_test_top__DOT__display_on 
        = ((0x100U > (IData)(vlTOPp->sprite_render_test_top__DOT__hpos)) 
           & (0xf0U > (IData)(vlTOPp->sprite_render_test_top__DOT__vpos)));
    vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__vmaxxed 
        = (0x105U == (IData)(vlTOPp->racing_game_top__DOT__vpos));
    vlTOPp->racing_game_top__DOT__display_on = ((0x100U 
                                                 > (IData)(vlTOPp->racing_game_top__DOT__hpos)) 
                                                & (0xf0U 
                                                   > (IData)(vlTOPp->racing_game_top__DOT__vpos)));
    vlTOPp->sprite_render_test_top__DOT__car_sprite_bits 
        = vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray
        [vlTOPp->sprite_render_test_top__DOT__car_sprite_addr];
    vlTOPp->sprite_bitmap_top__DOT__car_gfx = (1U & 
                                               (vlTOPp->sprite_bitmap_top__DOT__car__DOT__bitarray
                                                [vlTOPp->sprite_bitmap_top__DOT__car_sprite_yofs] 
                                                >> 
                                                (7U 
                                                 & ((8U 
                                                     <= (IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs))
                                                     ? 
                                                    ((IData)(0xfU) 
                                                     - (IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs))
                                                     : (IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs)))));
    vlTOPp->racing_game_top__DOT__track_gfx = (((0x1fU 
                                                 & ((IData)(vlTOPp->racing_game_top__DOT__vpos) 
                                                    >> 1U)) 
                                                != 
                                                (0x1fU 
                                                 & ((IData)(vlTOPp->racing_game_top__DOT__track_pos) 
                                                    >> 1U))) 
                                               & ((0U 
                                                   == 
                                                   (7U 
                                                    & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                                                       >> 5U))) 
                                                  | (7U 
                                                     == 
                                                     (7U 
                                                      & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                                                         >> 5U)))));
    vlTOPp->racing_game_top__DOT__enemy_hit_edge = 
        ((0x40U == (IData)(vlTOPp->racing_game_top__DOT__enemy_x)) 
         | (0xc0U == (IData)(vlTOPp->racing_game_top__DOT__enemy_x)));
    vlTOPp->racing_game_top__DOT__car_sprite_bits = 
        vlTOPp->racing_game_top__DOT__car__DOT__bitarray
        [((IData)(vlTOPp->racing_game_top__DOT__player_load)
           ? (IData)(vlTOPp->racing_game_top__DOT__player_sprite_yofs)
           : (IData)(vlTOPp->racing_game_top__DOT__enemy_sprite_yofs))];
    vlTOPp->sprite_render_test_top__02Ergb = ((((IData)(vlTOPp->sprite_render_test_top__DOT__display_on) 
                                                & (0U 
                                                   != (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) 
                                               << 2U) 
                                              | (3U 
                                                 & ((- (IData)((IData)(vlTOPp->sprite_render_test_top__DOT__display_on))) 
                                                    & (- (IData)((IData)(vlTOPp->sprite_render_test_top__DOT__car_gfx))))));
    vlTOPp->sprite_bitmap_top__02Ergb = ((((IData)(vlTOPp->sprite_bitmap_top__DOT__display_on) 
                                           & (IData)(vlTOPp->sprite_bitmap_top__DOT__car_gfx)) 
                                          << 2U) | 
                                         (3U & ((- (IData)((IData)(vlTOPp->sprite_bitmap_top__DOT__display_on))) 
                                                & (- (IData)((IData)(vlTOPp->sprite_bitmap_top__DOT__car_gfx))))));
    vlTOPp->racing_game_top__02Ergb = ((((IData)(vlTOPp->racing_game_top__DOT__display_on) 
                                         & ((IData)(vlTOPp->racing_game_top__DOT__enemy_gfx) 
                                            | (IData)(vlTOPp->racing_game_top__DOT__track_shoulder))) 
                                        << 2U) | ((
                                                   ((IData)(vlTOPp->racing_game_top__DOT__display_on) 
                                                    & ((IData)(vlTOPp->racing_game_top__DOT__player_gfx) 
                                                       | (IData)(vlTOPp->racing_game_top__DOT__track_gfx))) 
                                                   << 1U) 
                                                  | ((IData)(vlTOPp->racing_game_top__DOT__display_on) 
                                                     & (((IData)(vlTOPp->racing_game_top__DOT__player_gfx) 
                                                         | (IData)(vlTOPp->racing_game_top__DOT__enemy_gfx)) 
                                                        | (IData)(vlTOPp->racing_game_top__DOT__track_shoulder)))));
}

void Vracing_game_top::_eval_initial(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_eval_initial\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Evsync 
        = vlTOPp->__VinpClk__TOP__racing_game_top__02Evsync;
    vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Ehpaddle 
        = vlTOPp->sprite_render_test_top__02Ehpaddle;
    vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Evpaddle 
        = vlTOPp->sprite_render_test_top__02Evpaddle;
    vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Eclk 
        = vlTOPp->sprite_render_test_top__02Eclk;
    vlTOPp->__Vclklast__TOP__sprite_bitmap_top__02Eclk 
        = vlTOPp->sprite_bitmap_top__02Eclk;
    vlTOPp->__Vclklast__TOP__racing_game_top__02Eclk 
        = vlTOPp->racing_game_top__02Eclk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sprite_render_test_top__02Evsync 
        = vlTOPp->__VinpClk__TOP__sprite_render_test_top__02Evsync;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__sprite_bitmap_top__02Ehsync 
        = vlTOPp->__VinpClk__TOP__sprite_bitmap_top__02Ehsync;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Ehsync 
        = vlTOPp->__VinpClk__TOP__racing_game_top__02Ehsync;
}

void Vracing_game_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::final\n"); );
    // Variables
    Vracing_game_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vracing_game_top::_eval_settle(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_eval_settle\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__8(vlSymsp);
}

void Vracing_game_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_ctor_var_reset\n"); );
    // Body
    racing_game_top__02Eclk = VL_RAND_RESET_I(1);
    racing_game_top__02Ehpaddle = VL_RAND_RESET_I(1);
    racing_game_top__02Evpaddle = VL_RAND_RESET_I(1);
    racing_game_top__02Ehsync = VL_RAND_RESET_I(1);
    racing_game_top__02Evsync = VL_RAND_RESET_I(1);
    racing_game_top__02Ergb = VL_RAND_RESET_I(3);
    sprite_bitmap_top__02Eclk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    sprite_bitmap_top__02Ehsync = VL_RAND_RESET_I(1);
    sprite_bitmap_top__02Evsync = VL_RAND_RESET_I(1);
    sprite_bitmap_top__02Ergb = VL_RAND_RESET_I(3);
    sprite_render_test_top__02Eclk = VL_RAND_RESET_I(1);
    sprite_render_test_top__02Ehpaddle = VL_RAND_RESET_I(1);
    sprite_render_test_top__02Evpaddle = VL_RAND_RESET_I(1);
    sprite_render_test_top__02Ehsync = VL_RAND_RESET_I(1);
    sprite_render_test_top__02Evsync = VL_RAND_RESET_I(1);
    sprite_render_test_top__02Ergb = VL_RAND_RESET_I(3);
    racing_game_top__DOT__display_on = VL_RAND_RESET_I(1);
    racing_game_top__DOT__hpos = VL_RAND_RESET_I(9);
    racing_game_top__DOT__vpos = VL_RAND_RESET_I(9);
    racing_game_top__DOT__player_x = VL_RAND_RESET_I(8);
    racing_game_top__DOT__player_y = VL_RAND_RESET_I(8);
    racing_game_top__DOT__paddle_x = VL_RAND_RESET_I(8);
    racing_game_top__DOT__paddle_y = VL_RAND_RESET_I(8);
    racing_game_top__DOT__enemy_x = VL_RAND_RESET_I(8);
    racing_game_top__DOT__enemy_y = VL_RAND_RESET_I(8);
    racing_game_top__DOT__enemy_dir = VL_RAND_RESET_I(1);
    racing_game_top__DOT__track_pos = VL_RAND_RESET_I(16);
    racing_game_top__DOT__speed = VL_RAND_RESET_I(8);
    racing_game_top__DOT__player_load = VL_RAND_RESET_I(1);
    racing_game_top__DOT__player_sprite_yofs = VL_RAND_RESET_I(4);
    racing_game_top__DOT__enemy_sprite_yofs = VL_RAND_RESET_I(4);
    racing_game_top__DOT__car_sprite_bits = VL_RAND_RESET_I(8);
    racing_game_top__DOT__player_gfx = VL_RAND_RESET_I(1);
    racing_game_top__DOT__enemy_gfx = VL_RAND_RESET_I(1);
    racing_game_top__DOT__enemy_hit_edge = VL_RAND_RESET_I(1);
    racing_game_top__DOT__frame_collision = VL_RAND_RESET_I(1);
    racing_game_top__DOT__track_shoulder = VL_RAND_RESET_I(1);
    racing_game_top__DOT__track_gfx = VL_RAND_RESET_I(1);
    racing_game_top__DOT__hvsync_gen__DOT__hmaxxed = VL_RAND_RESET_I(1);
    racing_game_top__DOT__hvsync_gen__DOT__vmaxxed = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            racing_game_top__DOT__car__DOT__bitarray[__Vi0] = VL_RAND_RESET_I(8);
    }}
    racing_game_top__DOT__player_renderer__DOT__state = VL_RAND_RESET_I(3);
    racing_game_top__DOT__player_renderer__DOT__ycount = VL_RAND_RESET_I(4);
    racing_game_top__DOT__player_renderer__DOT__xcount = VL_RAND_RESET_I(4);
    racing_game_top__DOT__player_renderer__DOT__outbits = VL_RAND_RESET_I(8);
    racing_game_top__DOT__enemy_renderer__DOT__state = VL_RAND_RESET_I(3);
    racing_game_top__DOT__enemy_renderer__DOT__ycount = VL_RAND_RESET_I(4);
    racing_game_top__DOT__enemy_renderer__DOT__xcount = VL_RAND_RESET_I(4);
    racing_game_top__DOT__enemy_renderer__DOT__outbits = VL_RAND_RESET_I(8);
    sprite_bitmap_top__DOT__display_on = VL_RAND_RESET_I(1);
    sprite_bitmap_top__DOT__hpos = VL_RAND_RESET_I(9);
    sprite_bitmap_top__DOT__vpos = VL_RAND_RESET_I(9);
    sprite_bitmap_top__DOT__car_sprite_xofs = VL_RAND_RESET_I(4);
    sprite_bitmap_top__DOT__car_sprite_yofs = VL_RAND_RESET_I(4);
    sprite_bitmap_top__DOT__car_gfx = VL_RAND_RESET_I(1);
    sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed = VL_RAND_RESET_I(1);
    sprite_bitmap_top__DOT__hvsync_gen__DOT__vmaxxed = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            sprite_bitmap_top__DOT__car__DOT__bitarray[__Vi0] = VL_RAND_RESET_I(8);
    }}
    sprite_render_test_top__DOT__display_on = VL_RAND_RESET_I(1);
    sprite_render_test_top__DOT__hpos = VL_RAND_RESET_I(9);
    sprite_render_test_top__DOT__vpos = VL_RAND_RESET_I(9);
    sprite_render_test_top__DOT__player_x = VL_RAND_RESET_I(8);
    sprite_render_test_top__DOT__player_y = VL_RAND_RESET_I(8);
    sprite_render_test_top__DOT__paddle_x = VL_RAND_RESET_I(8);
    sprite_render_test_top__DOT__paddle_y = VL_RAND_RESET_I(8);
    sprite_render_test_top__DOT__car_sprite_addr = VL_RAND_RESET_I(4);
    sprite_render_test_top__DOT__car_sprite_bits = VL_RAND_RESET_I(8);
    sprite_render_test_top__DOT__car_gfx = VL_RAND_RESET_I(1);
    sprite_render_test_top__DOT__hvsync_gen__DOT__hmaxxed = VL_RAND_RESET_I(1);
    sprite_render_test_top__DOT__hvsync_gen__DOT__vmaxxed = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            sprite_render_test_top__DOT__car__DOT__bitarray[__Vi0] = VL_RAND_RESET_I(8);
    }}
    sprite_render_test_top__DOT__renderer__DOT__state = VL_RAND_RESET_I(3);
    sprite_render_test_top__DOT__renderer__DOT__ycount = VL_RAND_RESET_I(4);
    sprite_render_test_top__DOT__renderer__DOT__xcount = VL_RAND_RESET_I(4);
    sprite_render_test_top__DOT__renderer__DOT__outbits = VL_RAND_RESET_I(8);
    __Vdly__racing_game_top__DOT__enemy_y = VL_RAND_RESET_I(8);
    __Vdly__racing_game_top__DOT__enemy_x = VL_RAND_RESET_I(8);
    __Vdly__racing_game_top__DOT__vpos = VL_RAND_RESET_I(9);
    __Vdly__sprite_bitmap_top__DOT__vpos = VL_RAND_RESET_I(9);
    __Vdly__sprite_render_test_top__DOT__vpos = VL_RAND_RESET_I(9);
    __VinpClk__TOP__racing_game_top__02Evsync = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sprite_render_test_top__02Evsync = VL_RAND_RESET_I(1);
    __VinpClk__TOP__sprite_bitmap_top__02Ehsync = VL_RAND_RESET_I(1);
    __VinpClk__TOP__racing_game_top__02Ehsync = VL_RAND_RESET_I(1);
    __Vchglast__TOP__racing_game_top__02Ehsync = VL_RAND_RESET_I(1);
    __Vchglast__TOP__racing_game_top__02Evsync = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sprite_bitmap_top__02Ehsync = VL_RAND_RESET_I(1);
    __Vchglast__TOP__sprite_render_test_top__02Evsync = VL_RAND_RESET_I(1);
}
