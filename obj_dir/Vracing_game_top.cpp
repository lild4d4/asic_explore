// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vracing_game_top.h for the primary calling header

#include "Vracing_game_top.h"
#include "Vracing_game_top__Syms.h"

//==========

void Vracing_game_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vracing_game_top::eval\n"); );
    Vracing_game_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("racing_game_top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vracing_game_top::_eval_initial_loop(Vracing_game_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("racing_game_top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__2(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__2\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__racing_game_top__DOT__enemy_dir;
    // Body
    __Vdly__racing_game_top__DOT__enemy_dir = vlTOPp->racing_game_top__DOT__enemy_dir;
    vlTOPp->__Vdly__racing_game_top__DOT__enemy_x = vlTOPp->racing_game_top__DOT__enemy_x;
    vlTOPp->__Vdly__racing_game_top__DOT__enemy_y = vlTOPp->racing_game_top__DOT__enemy_y;
    if (vlTOPp->racing_game_top__DOT__enemy_hit_edge) {
        __Vdly__racing_game_top__DOT__enemy_dir = (1U 
                                                   & (~ (IData)(vlTOPp->racing_game_top__DOT__enemy_dir)));
    }
    vlTOPp->__Vdly__racing_game_top__DOT__enemy_x = 
        (0xffU & (((IData)(vlTOPp->racing_game_top__DOT__enemy_dir) 
                   ^ (IData)(vlTOPp->racing_game_top__DOT__enemy_hit_edge))
                   ? ((IData)(1U) + (IData)(vlTOPp->racing_game_top__DOT__enemy_x))
                   : ((IData)(vlTOPp->racing_game_top__DOT__enemy_x) 
                      - (IData)(1U))));
    vlTOPp->racing_game_top__DOT__track_pos = (0xffffU 
                                               & ((IData)(vlTOPp->racing_game_top__DOT__track_pos) 
                                                  + 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->racing_game_top__DOT__speed) 
                                                      >> 4U))));
    vlTOPp->__Vdly__racing_game_top__DOT__enemy_y = 
        (0xffU & ((IData)(vlTOPp->racing_game_top__DOT__enemy_y) 
                  + (0xfU & ((IData)(vlTOPp->racing_game_top__DOT__speed) 
                             >> 4U))));
    vlTOPp->racing_game_top__DOT__speed = ((IData)(vlTOPp->racing_game_top__DOT__frame_collision)
                                            ? 0x10U
                                            : (0xffU 
                                               & (((IData)(vlTOPp->racing_game_top__DOT__speed) 
                                                   < 
                                                   (0xffU 
                                                    & (~ (IData)(vlTOPp->racing_game_top__DOT__paddle_y))))
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlTOPp->racing_game_top__DOT__speed))
                                                   : 
                                                  ((IData)(vlTOPp->racing_game_top__DOT__speed) 
                                                   - (IData)(1U)))));
    vlTOPp->racing_game_top__DOT__enemy_dir = __Vdly__racing_game_top__DOT__enemy_dir;
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__5(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__5\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__sprite_render_test_top__DOT__renderer__DOT__ycount;
    CData/*2:0*/ __Vdly__sprite_render_test_top__DOT__renderer__DOT__state;
    CData/*3:0*/ __Vdly__sprite_render_test_top__DOT__renderer__DOT__xcount;
    CData/*7:0*/ __Vdly__sprite_render_test_top__DOT__renderer__DOT__outbits;
    // Body
    __Vdly__sprite_render_test_top__DOT__renderer__DOT__outbits 
        = vlTOPp->sprite_render_test_top__DOT__renderer__DOT__outbits;
    __Vdly__sprite_render_test_top__DOT__renderer__DOT__xcount 
        = vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount;
    __Vdly__sprite_render_test_top__DOT__renderer__DOT__ycount 
        = vlTOPp->sprite_render_test_top__DOT__renderer__DOT__ycount;
    __Vdly__sprite_render_test_top__DOT__renderer__DOT__state 
        = vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state;
    vlTOPp->__Vdly__sprite_render_test_top__DOT__vpos 
        = vlTOPp->sprite_render_test_top__DOT__vpos;
    if ((0U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
        __Vdly__sprite_render_test_top__DOT__renderer__DOT__ycount = 0U;
        vlTOPp->sprite_render_test_top__DOT__car_gfx = 0U;
        if (((IData)(vlTOPp->sprite_render_test_top__DOT__player_y) 
             == (IData)(vlTOPp->sprite_render_test_top__DOT__vpos))) {
            __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
            __Vdly__sprite_render_test_top__DOT__renderer__DOT__xcount = 0U;
            vlTOPp->sprite_render_test_top__DOT__car_gfx = 0U;
            if (vlTOPp->sprite_render_test_top__02Ehsync) {
                __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 2U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
                vlTOPp->sprite_render_test_top__DOT__car_sprite_addr 
                    = vlTOPp->sprite_render_test_top__DOT__renderer__DOT__ycount;
                __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 3U;
            } else {
                if ((3U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
                    __Vdly__sprite_render_test_top__DOT__renderer__DOT__outbits 
                        = vlTOPp->sprite_render_test_top__DOT__car_sprite_bits;
                    __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 4U;
                } else {
                    if ((4U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
                        if (((IData)(vlTOPp->sprite_render_test_top__DOT__player_x) 
                             == (IData)(vlTOPp->sprite_render_test_top__DOT__hpos))) {
                            __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 5U;
                        }
                    } else {
                        if ((5U == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) {
                            vlTOPp->sprite_render_test_top__DOT__car_gfx 
                                = (1U & ((IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__outbits) 
                                         >> (7U & (
                                                   (8U 
                                                    > (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount))
                                                    ? (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount)
                                                    : 
                                                   (~ (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount))))));
                            __Vdly__sprite_render_test_top__DOT__renderer__DOT__xcount 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount)));
                            if ((0xfU == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount))) {
                                __Vdly__sprite_render_test_top__DOT__renderer__DOT__ycount 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__ycount)));
                                __Vdly__sprite_render_test_top__DOT__renderer__DOT__state 
                                    = ((0xfU == (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__ycount))
                                        ? 0U : 1U);
                            }
                        } else {
                            __Vdly__sprite_render_test_top__DOT__renderer__DOT__state = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->sprite_render_test_top__02Evsync = ((0xfeU 
                                                 <= (IData)(vlTOPp->sprite_render_test_top__DOT__vpos)) 
                                                & (0x100U 
                                                   >= (IData)(vlTOPp->sprite_render_test_top__DOT__vpos)));
    if ((0x134U == (IData)(vlTOPp->sprite_render_test_top__DOT__hpos))) {
        vlTOPp->__Vdly__sprite_render_test_top__DOT__vpos 
            = ((IData)(vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__vmaxxed)
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->sprite_render_test_top__DOT__vpos))));
    }
    vlTOPp->sprite_render_test_top__DOT__renderer__DOT__ycount 
        = __Vdly__sprite_render_test_top__DOT__renderer__DOT__ycount;
    vlTOPp->sprite_render_test_top__DOT__renderer__DOT__xcount 
        = __Vdly__sprite_render_test_top__DOT__renderer__DOT__xcount;
    vlTOPp->sprite_render_test_top__DOT__renderer__DOT__outbits 
        = __Vdly__sprite_render_test_top__DOT__renderer__DOT__outbits;
    vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state 
        = __Vdly__sprite_render_test_top__DOT__renderer__DOT__state;
    vlTOPp->sprite_render_test_top__DOT__car_sprite_bits 
        = vlTOPp->sprite_render_test_top__DOT__car__DOT__bitarray
        [vlTOPp->sprite_render_test_top__DOT__car_sprite_addr];
    vlTOPp->sprite_render_test_top__02Ehsync = ((0x107U 
                                                 <= (IData)(vlTOPp->sprite_render_test_top__DOT__hpos)) 
                                                & (0x11dU 
                                                   >= (IData)(vlTOPp->sprite_render_test_top__DOT__hpos)));
    vlTOPp->sprite_render_test_top__DOT__hpos = ((IData)(vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__hmaxxed)
                                                  ? 0U
                                                  : 
                                                 (0x1ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->sprite_render_test_top__DOT__hpos))));
    vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__hmaxxed 
        = (0x134U == (IData)(vlTOPp->sprite_render_test_top__DOT__hpos));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__6(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__6\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__sprite_bitmap_top__DOT__car_sprite_xofs;
    // Body
    __Vdly__sprite_bitmap_top__DOT__car_sprite_xofs 
        = vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs;
    vlTOPp->__Vdly__sprite_bitmap_top__DOT__vpos = vlTOPp->sprite_bitmap_top__DOT__vpos;
    if ((0x80U == (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos))) {
        __Vdly__sprite_bitmap_top__DOT__car_sprite_xofs = 0xfU;
    } else {
        if ((0U != (IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs))) {
            __Vdly__sprite_bitmap_top__DOT__car_sprite_xofs 
                = (0xfU & ((IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs) 
                           - (IData)(1U)));
        }
    }
    vlTOPp->sprite_bitmap_top__02Evsync = ((0xfeU <= (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)) 
                                           & (0x100U 
                                              >= (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)));
    if (vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed) {
        vlTOPp->__Vdly__sprite_bitmap_top__DOT__vpos 
            = ((IData)(vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__vmaxxed)
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos))));
    }
    vlTOPp->sprite_bitmap_top__02Ehsync = ((0x107U 
                                            <= (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)) 
                                           & (0x11dU 
                                              >= (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)));
    vlTOPp->sprite_bitmap_top__DOT__hpos = ((IData)(vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed)
                                             ? 0U : 
                                            (0x1ffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos))));
    vlTOPp->sprite_bitmap_top__DOT__car_sprite_xofs 
        = __Vdly__sprite_bitmap_top__DOT__car_sprite_xofs;
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__7(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__7\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__racing_game_top__DOT__player_renderer__DOT__ycount;
    CData/*2:0*/ __Vdly__racing_game_top__DOT__player_renderer__DOT__state;
    CData/*3:0*/ __Vdly__racing_game_top__DOT__player_renderer__DOT__xcount;
    CData/*7:0*/ __Vdly__racing_game_top__DOT__player_renderer__DOT__outbits;
    CData/*3:0*/ __Vdly__racing_game_top__DOT__enemy_renderer__DOT__ycount;
    CData/*2:0*/ __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state;
    CData/*3:0*/ __Vdly__racing_game_top__DOT__enemy_renderer__DOT__xcount;
    CData/*7:0*/ __Vdly__racing_game_top__DOT__enemy_renderer__DOT__outbits;
    SData/*8:0*/ __Vdly__racing_game_top__DOT__hpos;
    // Body
    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__outbits 
        = vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__outbits;
    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__xcount 
        = vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount;
    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state 
        = vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state;
    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__ycount 
        = vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__ycount;
    vlTOPp->__Vdly__racing_game_top__DOT__vpos = vlTOPp->racing_game_top__DOT__vpos;
    __Vdly__racing_game_top__DOT__player_renderer__DOT__outbits 
        = vlTOPp->racing_game_top__DOT__player_renderer__DOT__outbits;
    __Vdly__racing_game_top__DOT__player_renderer__DOT__xcount 
        = vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount;
    __Vdly__racing_game_top__DOT__player_renderer__DOT__state 
        = vlTOPp->racing_game_top__DOT__player_renderer__DOT__state;
    __Vdly__racing_game_top__DOT__player_renderer__DOT__ycount 
        = vlTOPp->racing_game_top__DOT__player_renderer__DOT__ycount;
    __Vdly__racing_game_top__DOT__hpos = vlTOPp->racing_game_top__DOT__hpos;
    if (((IData)(vlTOPp->racing_game_top__DOT__player_gfx) 
         & ((IData)(vlTOPp->racing_game_top__DOT__enemy_gfx) 
            | (IData)(vlTOPp->racing_game_top__DOT__track_gfx)))) {
        vlTOPp->racing_game_top__DOT__frame_collision = 1U;
    } else {
        if (vlTOPp->racing_game_top__02Evsync) {
            vlTOPp->racing_game_top__DOT__frame_collision = 0U;
        }
    }
    vlTOPp->racing_game_top__02Ehsync = ((0x107U <= (IData)(vlTOPp->racing_game_top__DOT__hpos)) 
                                         & (0x11dU 
                                            >= (IData)(vlTOPp->racing_game_top__DOT__hpos)));
    __Vdly__racing_game_top__DOT__hpos = ((IData)(vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__hmaxxed)
                                           ? 0U : (0x1ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->racing_game_top__DOT__hpos))));
    vlTOPp->racing_game_top__02Evsync = ((0xfeU <= (IData)(vlTOPp->racing_game_top__DOT__vpos)) 
                                         & (0x100U 
                                            >= (IData)(vlTOPp->racing_game_top__DOT__vpos)));
    if ((0x134U == (IData)(vlTOPp->racing_game_top__DOT__hpos))) {
        vlTOPp->__Vdly__racing_game_top__DOT__vpos 
            = ((IData)(vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__vmaxxed)
                ? 0U : (0x1ffU & ((IData)(1U) + (IData)(vlTOPp->racing_game_top__DOT__vpos))));
    }
    if ((0U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
        __Vdly__racing_game_top__DOT__enemy_renderer__DOT__ycount = 0U;
        vlTOPp->racing_game_top__DOT__enemy_gfx = 0U;
        if (((IData)(vlTOPp->racing_game_top__DOT__enemy_y) 
             == (IData)(vlTOPp->racing_game_top__DOT__vpos))) {
            __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
            __Vdly__racing_game_top__DOT__enemy_renderer__DOT__xcount = 0U;
            vlTOPp->racing_game_top__DOT__enemy_gfx = 0U;
            if ((0x104U <= (IData)(vlTOPp->racing_game_top__DOT__hpos))) {
                __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 2U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
                vlTOPp->racing_game_top__DOT__enemy_sprite_yofs 
                    = vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__ycount;
                __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 3U;
            } else {
                if ((3U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
                    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__outbits 
                        = vlTOPp->racing_game_top__DOT__car_sprite_bits;
                    __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 4U;
                } else {
                    if ((4U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
                        if (((IData)(vlTOPp->racing_game_top__DOT__enemy_x) 
                             == (IData)(vlTOPp->racing_game_top__DOT__hpos))) {
                            __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 5U;
                        }
                    } else {
                        if ((5U == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state))) {
                            vlTOPp->racing_game_top__DOT__enemy_gfx 
                                = (1U & ((IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__outbits) 
                                         >> (7U & (
                                                   (8U 
                                                    > (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount))
                                                    ? (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount)
                                                    : 
                                                   (~ (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount))))));
                            __Vdly__racing_game_top__DOT__enemy_renderer__DOT__xcount 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount)));
                            if ((0xfU == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount))) {
                                __Vdly__racing_game_top__DOT__enemy_renderer__DOT__ycount 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__ycount)));
                                __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state 
                                    = ((0xfU == (IData)(vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__ycount))
                                        ? 0U : 1U);
                            }
                        } else {
                            __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state = 0U;
                        }
                    }
                }
            }
        }
    }
    if ((0U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
        __Vdly__racing_game_top__DOT__player_renderer__DOT__ycount = 0U;
        vlTOPp->racing_game_top__DOT__player_gfx = 0U;
        if (((IData)(vlTOPp->racing_game_top__DOT__player_y) 
             == (IData)(vlTOPp->racing_game_top__DOT__vpos))) {
            __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
            __Vdly__racing_game_top__DOT__player_renderer__DOT__xcount = 0U;
            vlTOPp->racing_game_top__DOT__player_gfx = 0U;
            if (vlTOPp->racing_game_top__DOT__player_load) {
                __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 2U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
                vlTOPp->racing_game_top__DOT__player_sprite_yofs 
                    = vlTOPp->racing_game_top__DOT__player_renderer__DOT__ycount;
                __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 3U;
            } else {
                if ((3U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
                    __Vdly__racing_game_top__DOT__player_renderer__DOT__outbits 
                        = vlTOPp->racing_game_top__DOT__car_sprite_bits;
                    __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 4U;
                } else {
                    if ((4U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
                        if (((IData)(vlTOPp->racing_game_top__DOT__player_x) 
                             == (IData)(vlTOPp->racing_game_top__DOT__hpos))) {
                            __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 5U;
                        }
                    } else {
                        if ((5U == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__state))) {
                            vlTOPp->racing_game_top__DOT__player_gfx 
                                = (1U & ((IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__outbits) 
                                         >> (7U & (
                                                   (8U 
                                                    > (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount))
                                                    ? (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount)
                                                    : 
                                                   (~ (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount))))));
                            __Vdly__racing_game_top__DOT__player_renderer__DOT__xcount 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount)));
                            if ((0xfU == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount))) {
                                __Vdly__racing_game_top__DOT__player_renderer__DOT__ycount 
                                    = (0xfU & ((IData)(1U) 
                                               + (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__ycount)));
                                __Vdly__racing_game_top__DOT__player_renderer__DOT__state 
                                    = ((0xfU == (IData)(vlTOPp->racing_game_top__DOT__player_renderer__DOT__ycount))
                                        ? 0U : 1U);
                            }
                        } else {
                            __Vdly__racing_game_top__DOT__player_renderer__DOT__state = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__ycount 
        = __Vdly__racing_game_top__DOT__enemy_renderer__DOT__ycount;
    vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__state 
        = __Vdly__racing_game_top__DOT__enemy_renderer__DOT__state;
    vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__xcount 
        = __Vdly__racing_game_top__DOT__enemy_renderer__DOT__xcount;
    vlTOPp->racing_game_top__DOT__enemy_renderer__DOT__outbits 
        = __Vdly__racing_game_top__DOT__enemy_renderer__DOT__outbits;
    vlTOPp->racing_game_top__DOT__player_renderer__DOT__ycount 
        = __Vdly__racing_game_top__DOT__player_renderer__DOT__ycount;
    vlTOPp->racing_game_top__DOT__player_renderer__DOT__state 
        = __Vdly__racing_game_top__DOT__player_renderer__DOT__state;
    vlTOPp->racing_game_top__DOT__player_renderer__DOT__xcount 
        = __Vdly__racing_game_top__DOT__player_renderer__DOT__xcount;
    vlTOPp->racing_game_top__DOT__player_renderer__DOT__outbits 
        = __Vdly__racing_game_top__DOT__player_renderer__DOT__outbits;
    vlTOPp->racing_game_top__DOT__hpos = __Vdly__racing_game_top__DOT__hpos;
    vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__hmaxxed 
        = (0x134U == (IData)(vlTOPp->racing_game_top__DOT__hpos));
    vlTOPp->racing_game_top__DOT__player_load = ((0x100U 
                                                  <= (IData)(vlTOPp->racing_game_top__DOT__hpos)) 
                                                 & (0x104U 
                                                    > (IData)(vlTOPp->racing_game_top__DOT__hpos)));
    vlTOPp->racing_game_top__DOT__track_shoulder = 
        ((3U == (0x1fU & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                          >> 3U))) | (0x1cU == (0x1fU 
                                                & ((IData)(vlTOPp->racing_game_top__DOT__hpos) 
                                                   >> 3U))));
    vlTOPp->racing_game_top__DOT__car_sprite_bits = 
        vlTOPp->racing_game_top__DOT__car__DOT__bitarray
        [((IData)(vlTOPp->racing_game_top__DOT__player_load)
           ? (IData)(vlTOPp->racing_game_top__DOT__player_sprite_yofs)
           : (IData)(vlTOPp->racing_game_top__DOT__enemy_sprite_yofs))];
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__9(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__9\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_render_test_top__DOT__player_y = vlTOPp->sprite_render_test_top__DOT__paddle_y;
    vlTOPp->sprite_render_test_top__DOT__player_x = vlTOPp->sprite_render_test_top__DOT__paddle_x;
}

VL_INLINE_OPT void Vracing_game_top::_combo__TOP__10(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_combo__TOP__10\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__hmaxxed 
        = ((0x134U == (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)) 
           | (IData)(vlTOPp->reset));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__11(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__11\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__sprite_bitmap_top__DOT__car_sprite_yofs;
    // Body
    __Vdly__sprite_bitmap_top__DOT__car_sprite_yofs 
        = vlTOPp->sprite_bitmap_top__DOT__car_sprite_yofs;
    if ((0x80U == (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos))) {
        __Vdly__sprite_bitmap_top__DOT__car_sprite_yofs = 0xfU;
    } else {
        if ((0U != (IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_yofs))) {
            __Vdly__sprite_bitmap_top__DOT__car_sprite_yofs 
                = (0xfU & ((IData)(vlTOPp->sprite_bitmap_top__DOT__car_sprite_yofs) 
                           - (IData)(1U)));
        }
    }
    vlTOPp->sprite_bitmap_top__DOT__car_sprite_yofs 
        = __Vdly__sprite_bitmap_top__DOT__car_sprite_yofs;
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__12(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__12\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ (IData)(vlTOPp->racing_game_top__02Evpaddle)))) {
        vlTOPp->racing_game_top__DOT__paddle_y = (0xffU 
                                                  & (IData)(vlTOPp->racing_game_top__DOT__vpos));
    }
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__13(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__13\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->racing_game_top__DOT__enemy_y = vlTOPp->__Vdly__racing_game_top__DOT__enemy_y;
    vlTOPp->racing_game_top__DOT__enemy_x = vlTOPp->__Vdly__racing_game_top__DOT__enemy_x;
    vlTOPp->racing_game_top__DOT__enemy_hit_edge = 
        ((0x40U == (IData)(vlTOPp->racing_game_top__DOT__enemy_x)) 
         | (0xc0U == (IData)(vlTOPp->racing_game_top__DOT__enemy_x)));
    vlTOPp->racing_game_top__DOT__player_y = 0xb4U;
    vlTOPp->racing_game_top__DOT__player_x = vlTOPp->racing_game_top__DOT__paddle_x;
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__14(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__14\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_render_test_top__DOT__paddle_y = 
        (0xffU & (IData)(vlTOPp->sprite_render_test_top__DOT__vpos));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__15(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__15\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_render_test_top__DOT__paddle_x = 
        (0xffU & (IData)(vlTOPp->sprite_render_test_top__DOT__vpos));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__16(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__16\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_bitmap_top__DOT__vpos = vlTOPp->__Vdly__sprite_bitmap_top__DOT__vpos;
    vlTOPp->sprite_bitmap_top__DOT__display_on = ((0x100U 
                                                   > (IData)(vlTOPp->sprite_bitmap_top__DOT__hpos)) 
                                                  & (0xf0U 
                                                     > (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)));
}

VL_INLINE_OPT void Vracing_game_top::_multiclk__TOP__17(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_multiclk__TOP__17\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->sprite_bitmap_top__02Ergb = ((((IData)(vlTOPp->sprite_bitmap_top__DOT__display_on) 
                                           & (IData)(vlTOPp->sprite_bitmap_top__DOT__car_gfx)) 
                                          << 2U) | 
                                         (3U & ((- (IData)((IData)(vlTOPp->sprite_bitmap_top__DOT__display_on))) 
                                                & (- (IData)((IData)(vlTOPp->sprite_bitmap_top__DOT__car_gfx))))));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__18(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__18\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ (IData)(vlTOPp->racing_game_top__02Ehpaddle)))) {
        vlTOPp->racing_game_top__DOT__paddle_x = (0xffU 
                                                  & (IData)(vlTOPp->racing_game_top__DOT__vpos));
    }
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__19(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__19\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_render_test_top__DOT__vpos = vlTOPp->__Vdly__sprite_render_test_top__DOT__vpos;
    vlTOPp->sprite_render_test_top__DOT__hvsync_gen__DOT__vmaxxed 
        = (0x105U == (IData)(vlTOPp->sprite_render_test_top__DOT__vpos));
    vlTOPp->sprite_render_test_top__DOT__display_on 
        = ((0x100U > (IData)(vlTOPp->sprite_render_test_top__DOT__hpos)) 
           & (0xf0U > (IData)(vlTOPp->sprite_render_test_top__DOT__vpos)));
    vlTOPp->sprite_render_test_top__02Ergb = ((((IData)(vlTOPp->sprite_render_test_top__DOT__display_on) 
                                                & (0U 
                                                   != (IData)(vlTOPp->sprite_render_test_top__DOT__renderer__DOT__state))) 
                                               << 2U) 
                                              | (3U 
                                                 & ((- (IData)((IData)(vlTOPp->sprite_render_test_top__DOT__display_on))) 
                                                    & (- (IData)((IData)(vlTOPp->sprite_render_test_top__DOT__car_gfx))))));
}

VL_INLINE_OPT void Vracing_game_top::_combo__TOP__20(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_combo__TOP__20\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sprite_bitmap_top__DOT__hvsync_gen__DOT__vmaxxed 
        = ((0x105U == (IData)(vlTOPp->sprite_bitmap_top__DOT__vpos)) 
           | (IData)(vlTOPp->reset));
}

VL_INLINE_OPT void Vracing_game_top::_sequent__TOP__21(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_sequent__TOP__21\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->racing_game_top__DOT__vpos = vlTOPp->__Vdly__racing_game_top__DOT__vpos;
    vlTOPp->racing_game_top__DOT__hvsync_gen__DOT__vmaxxed 
        = (0x105U == (IData)(vlTOPp->racing_game_top__DOT__vpos));
    vlTOPp->racing_game_top__DOT__display_on = ((0x100U 
                                                 > (IData)(vlTOPp->racing_game_top__DOT__hpos)) 
                                                & (0xf0U 
                                                   > (IData)(vlTOPp->racing_game_top__DOT__vpos)));
}

VL_INLINE_OPT void Vracing_game_top::_multiclk__TOP__22(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_multiclk__TOP__22\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vracing_game_top::_eval(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_eval\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->__VinpClk__TOP__racing_game_top__02Evsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Evsync)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_render_test_top__02Eclk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_bitmap_top__02Eclk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_bitmap_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((IData)(vlTOPp->racing_game_top__02Eclk) & 
         (~ (IData)(vlTOPp->__Vclklast__TOP__racing_game_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__sprite_render_test_top__02Evsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sprite_render_test_top__02Evsync)))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    vlTOPp->_combo__TOP__10(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__sprite_bitmap_top__02Ehsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sprite_bitmap_top__02Ehsync)))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__racing_game_top__02Ehsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Ehsync)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__racing_game_top__02Evsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Evsync)))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_render_test_top__02Evpaddle) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Evpaddle)))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_render_test_top__02Ehpaddle) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Ehpaddle)))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_bitmap_top__02Eclk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_bitmap_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__16(vlSymsp);
    }
    if ((((IData)(vlTOPp->sprite_bitmap_top__02Eclk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_bitmap_top__02Eclk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__sprite_bitmap_top__02Ehsync) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__sprite_bitmap_top__02Ehsync))))) {
        vlTOPp->_multiclk__TOP__17(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__racing_game_top__02Ehsync) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Ehsync)))) {
        vlTOPp->_sequent__TOP__18(vlSymsp);
    }
    if (((IData)(vlTOPp->sprite_render_test_top__02Eclk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__sprite_render_test_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__19(vlSymsp);
    }
    vlTOPp->_combo__TOP__20(vlSymsp);
    if (((IData)(vlTOPp->racing_game_top__02Eclk) & 
         (~ (IData)(vlTOPp->__Vclklast__TOP__racing_game_top__02Eclk)))) {
        vlTOPp->_sequent__TOP__21(vlSymsp);
    }
    if ((((IData)(vlTOPp->racing_game_top__02Eclk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__racing_game_top__02Eclk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__racing_game_top__02Evsync) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__racing_game_top__02Evsync))))) {
        vlTOPp->_multiclk__TOP__22(vlSymsp);
    }
    // Final
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
    vlTOPp->__VinpClk__TOP__racing_game_top__02Evsync 
        = vlTOPp->racing_game_top__02Evsync;
    vlTOPp->__VinpClk__TOP__sprite_render_test_top__02Evsync 
        = vlTOPp->sprite_render_test_top__02Evsync;
    vlTOPp->__VinpClk__TOP__sprite_bitmap_top__02Ehsync 
        = vlTOPp->sprite_bitmap_top__02Ehsync;
    vlTOPp->__VinpClk__TOP__racing_game_top__02Ehsync 
        = vlTOPp->racing_game_top__02Ehsync;
}

VL_INLINE_OPT QData Vracing_game_top::_change_request(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_change_request\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vracing_game_top::_change_request_1(Vracing_game_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_change_request_1\n"); );
    Vracing_game_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->racing_game_top__02Ehsync ^ vlTOPp->__Vchglast__TOP__racing_game_top__02Ehsync)
         | (vlTOPp->racing_game_top__02Evsync ^ vlTOPp->__Vchglast__TOP__racing_game_top__02Evsync)
         | (vlTOPp->sprite_bitmap_top__02Ehsync ^ vlTOPp->__Vchglast__TOP__sprite_bitmap_top__02Ehsync)
         | (vlTOPp->sprite_render_test_top__02Evsync ^ vlTOPp->__Vchglast__TOP__sprite_render_test_top__02Evsync));
    VL_DEBUG_IF( if(__req && ((vlTOPp->racing_game_top__02Ehsync ^ vlTOPp->__Vchglast__TOP__racing_game_top__02Ehsync))) VL_DBG_MSGF("        CHANGE: racing_game_top.v:5: racing_game_top.hsync\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->racing_game_top__02Evsync ^ vlTOPp->__Vchglast__TOP__racing_game_top__02Evsync))) VL_DBG_MSGF("        CHANGE: racing_game_top.v:5: racing_game_top.vsync\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sprite_bitmap_top__02Ehsync ^ vlTOPp->__Vchglast__TOP__sprite_bitmap_top__02Ehsync))) VL_DBG_MSGF("        CHANGE: racing_game_top.v:254: sprite_bitmap_top.hsync\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->sprite_render_test_top__02Evsync ^ vlTOPp->__Vchglast__TOP__sprite_render_test_top__02Evsync))) VL_DBG_MSGF("        CHANGE: racing_game_top.v:407: sprite_render_test_top.vsync\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__racing_game_top__02Ehsync 
        = vlTOPp->racing_game_top__02Ehsync;
    vlTOPp->__Vchglast__TOP__racing_game_top__02Evsync 
        = vlTOPp->racing_game_top__02Evsync;
    vlTOPp->__Vchglast__TOP__sprite_bitmap_top__02Ehsync 
        = vlTOPp->sprite_bitmap_top__02Ehsync;
    vlTOPp->__Vchglast__TOP__sprite_render_test_top__02Evsync 
        = vlTOPp->sprite_render_test_top__02Evsync;
    return __req;
}

#ifdef VL_DEBUG
void Vracing_game_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vracing_game_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((racing_game_top__02Eclk & 0xfeU))) {
        Verilated::overWidthError("racing_game_top.clk");}
    if (VL_UNLIKELY((racing_game_top__02Ehpaddle & 0xfeU))) {
        Verilated::overWidthError("racing_game_top.hpaddle");}
    if (VL_UNLIKELY((racing_game_top__02Evpaddle & 0xfeU))) {
        Verilated::overWidthError("racing_game_top.vpaddle");}
    if (VL_UNLIKELY((sprite_bitmap_top__02Eclk & 0xfeU))) {
        Verilated::overWidthError("sprite_bitmap_top.clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((sprite_render_test_top__02Eclk 
                     & 0xfeU))) {
        Verilated::overWidthError("sprite_render_test_top.clk");}
    if (VL_UNLIKELY((sprite_render_test_top__02Ehpaddle 
                     & 0xfeU))) {
        Verilated::overWidthError("sprite_render_test_top.hpaddle");}
    if (VL_UNLIKELY((sprite_render_test_top__02Evpaddle 
                     & 0xfeU))) {
        Verilated::overWidthError("sprite_render_test_top.vpaddle");}
}
#endif  // VL_DEBUG
